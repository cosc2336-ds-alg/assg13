---
name: 'Task 5: Implement `operatorUnion()` Member Function'
about: Task 5 for Students
title: 'Task 5: Implement `operatorUnion()` Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the `operatorUnion()` member function.  This function is a `void` function, it doesn't return an explicit result.  However, as a side effect of calling this member function on a set, the set will be modified to be the union of the set and of another set supplied as a parameter.  Thus this functions takes a single paramter which is another `Set` instance that should be used to calculate the union between this set and the other one.

**Suggested Solution**

The union of two sets are all of the items that appear either in `this` set or the other set, or is in both sets.

You should reuse the existing member function to implement this task.  When in the scope of member functions of C++ classes, you can access the private member variables of any `Set` including the set you pass in as a parameter to this function.  You should iterate through all of the items of the other set and simply add them to `this` set, reusing the `addItem()` method, which should ignore requests to add in items that are already in the set.


**Additional Requirements**

- You must practice code reuse and reuse appropriate member functions in the implementation of `operatorUnion()`
- The parameter to this function should not be changed as a result of calling this member function, only `this` set is changed by the union operation.  Thus you are required to declare the parameter to be a constant parameter of this function.


