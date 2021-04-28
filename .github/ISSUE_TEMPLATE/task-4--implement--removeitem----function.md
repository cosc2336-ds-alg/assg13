---
name: 'Task 4: Implement `removeItem()` Function'
about: Task 4 for Students
title: 'Task 4: Implement `removeItem()` Function'
labels: enhancement
assignees: ''

---

**Description**

Implement the `removeItem()` member function.  This function should work in a similar manner to `addItem()`.  You first need to check if the requested item is in the set that is being removed.  If it is not, you should silently just ignore the request to remove the nonexistent item.  Only if it is in the set should you then remove it.

**Suggested Solution**

The set is maintained internally as an unorderd array (list) of unique values.  You have to search for the item location and remove it from the array.  You should use shifting of values to remove the item from the array.

**Additional Requirements**

- You are required to practice code reuse when testing if the item to be removed is currently in the set or not.
- You are required to use shifting to implement the item removal.

