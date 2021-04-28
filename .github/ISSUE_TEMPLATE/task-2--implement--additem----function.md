---
name: 'Task 2: Implement `addItem()` Member Function'
about: Task 2 for Students
title: 'Task 2: Implement `addItem()` Member Function'
labels: enhancement
assignees: ''

---

**Description**

The second task is to implement the `addItem()` member function.  Though additionally, while implementing this function, you need to complete the correct implementation of the first 4 member functions that should only contain stub implementations at the moment.  The `addItem()` functions takes an integer parameters as input.  It is a `void` function, it does not return a result.

**Suggested Solution**

You should implement this method in 2 stages, so you can work on the accessor methods in small steps.  An obvious first step is to just get the `setSize` count correct.  If this is correct after adding an item, you should be able to implement methods like `getSetSize()` and `isEmpty()` correctly.

But as a second step you will need to get the item added correctly to the array of items currently in the set.  Once this is done you should be able to implement the other two methods `containsItem()` and `str()`.

**Additional Requirements**

- `addItems()` is required to add items to the set and maintain them in the order they were
  added.
