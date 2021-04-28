---
name: 'Task 3: Make `addItem()` work as a `Set` add item'
about: Task 3 for Students
title: 'Task 3: Make `addItem()` work as a `Set` add item'
labels: enhancement
assignees: ''

---

**Description**

You should already have a version of `addItem()` that works to pass some of the unit tests for this member function.  However, this function needs to be modified so that it correctly maintains the items as a set of items.  In a set, each item in the set should be unique.  Thus when you add items to the set, you need to make sure before you add a new item that it doesn't already exist in the set before you add it in potentially a second or more times.

**Suggested Solution**

You need to search the current set of items and silently ignore any request to add an item that already exists in the set.

**Additional Requirements**

- You are required to practice code reuse and reuse your `containsItem()` member function in the implementation of this task.


