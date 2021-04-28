# source files in this project (for beautification)
PROJECT_NAME=assg02

test_src  = tests-main.cpp \
	    $(PROJECT_NAME)-tests.cpp \
	    Set.cpp
debug_src = $(PROJECT_NAME)-main.cpp \
	    Set.cpp

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include include/Makefile.inc
