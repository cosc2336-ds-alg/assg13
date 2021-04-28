# compiler flags, tools and include variables
GCC_FLAGS=-Wall -Werror -pedantic -g
GCC=g++
INC=-Iinclude

BEAUTIFIER=uncrustify
BEAUTIFIER_FLAGS=-c config/uncrustify.cfg --replace --no-backup

DOC=doxygen
DOC_FLAGS=config/Doxyfile

PANDOC=pandoc
PANDOC_FLAGS=-s --variable geometry:margin=0.75in --variable urlcolor:NavyBlue --variable colorlinks:true
PANDOC_HIGHLIGHT=--highlight-style tango

RM=rm -rf

SRC_DIR := src
OBJ_DIR := obj
DOC_DIR := doc
BIN_DIR := .
TEST_TARGET=$(BIN_DIR)/test
DEBUG_TARGET=$(BIN_DIR)/debug


# sources and objects needed to be linked together for unit test executable
test_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(test_src))
test_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(test_src))

# objects needed to be linked together for main/debug executable
debug_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(debug_src))
debug_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(debug_src))

# pdf files for assignment description documentation
assg_doc := $(patsubst %.pdf, $(DOC_DIR)/%.pdf, $(assg_doc))

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##                (test and debug)
##
.PHONY : all
all : $(TEST_TARGET) $(DEBUG_TARGET)


## test         : Build and link together unit test executable
##
$(TEST_TARGET) : $(test_obj) $(template_files)
	$(GCC) $(GCC_FLAGS) $(test_obj) -o $@


## debug        : Build and link together debug executable
##
$(DEBUG_TARGET) : $(debug_obj) $(template_files)
	$(GCC) $(GCC_FLAGS) $(debug_obj) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INC) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $@

## run          : Run the unit tests showing successful tests
##
run : $(TEST_TARGET)
	./$(TEST_TARGET) --use-colour yes


## beautify     : Run the code beautifier by hand if needed
##
.PHONY : beautify
beautify :
	$(BEAUTIFIER) $(BEAUTIFIER_FLAGS) include/*.hpp src/*.cpp


## refdocs      : Create doxygen reference documentation from
##                doc comments.
##
.PHONY : refdocs
refdocs :
	@echo "Generating doxygen documentation..."
	$(DOC) $(DOC_FLAGS) 2>&1 | grep -A 1 warning | egrep -v "assg.*\.md" | grep -v "Found unknown command" | grep -v "Searching for include" | sed -e "s|${PWD}/||g"


## assgdocs     : Create assignment description documentation from
##                README.md project markdown file.
##
.PHONY : assgdocs
assgdocs : $(assg_doc)

$(assg_doc) : README.md
	${PANDOC} ${PANDOC_FLAGS} ${PANDOC_HIGHLIGHT} -o $@ $^


## submit       : Create a tared and compressed file of
##                assignment files for submission
##
.PHONY : submit
submit :: beautify
	tar cvfz $(PROJECT_NAME).tar.gz include src

## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(TEST_TARGET) $(DEBUG_TARGET) *.o *.gch
	$(RM) output html latex
	$(RM) $(OBJ_DIR)


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile include/Makefile.inc
	@sed -n 's/^##//p' $^
