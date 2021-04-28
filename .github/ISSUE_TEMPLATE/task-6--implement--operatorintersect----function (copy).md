---
name: 'Task 6: Implement `operatorIntersect()` Function'
about: Task 6 for Students
title: 'Task 6: Implement `operatorIntersect()` Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the `operatorIntersect()` member function.  This function is similar in implementation to the previous `operatorUnion()` though slightly more difficult because of one issue.  This function has the same signature as the `operatorUnion()`, it is a `void` function that takes another `Set` as its input parameter.

**Suggested Solution**

The intersection of two sets are just that items that appear both in `this` set and in the other set.

You should reuse the existing member function to implement this task.  This member function is more difficult than the union.  The suggested solution is to iterate through all items of `this` set, and remove any items from `this` set that are not also in the other set.  You need to be careful when reusing the member method to remove an item, if you are iterating through the items when you call the function to remove an item, you can accidently skip or loose track of the items.  It is suggested that you iterate through `this` sets items in reverse order, which will make it much more straight forward to correctly remove items without interference.

**Additional Requirements**

- You must practice code reuse and reuse appropriate member functions in the implementation of `operatorIntersect()`
- The parameter to this function should not be changed as a result of calling this member function, only `this` set is changed by the union operation.  Thus you are required to declare the parameter to be a constant parameter of this function.


