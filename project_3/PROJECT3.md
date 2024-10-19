# Lab Report: Implementation of an Unsorted Linked List in C++

## Introduction

In this lab, we implemented an unsorted linked list in C++. A linked list is a fundamental data structure that consists of a sequence of nodes, where each node contains two main components: a key (or identifier) and data (the value associated with the key). Additionally, each node has a pointer that references the next node in the sequence. This structure allows for efficient dynamic memory allocation, as linked lists can easily grow and shrink in size, unlike arrays which have a fixed size.

The primary objectives of this lab were to:
- Understand the mechanics of linked lists and their operations.
- Gain hands-on experience with C++ programming, focusing on pointers and dynamic memory management.
- Implement various functionalities of a linked list, including insertion, deletion, searching, and displaying the list items.

### Key Operations Implemented:
1. **Insertion**: Adding a new node to the end of the list.
2. **Deletion**: Removing a node based on its key.
3. **Search**: Locating a node by its key and retrieving its data.
4. **Print**: Displaying all nodes in the list.
5. **Clear**: Removing all nodes from the list.
6. **List Length**: Returning the number of nodes present in the list.

## Output Screenshots and Explanations

### Screenshot 1: Initial List Creation

![Initial List Creation](/project_3/Screenshot%202024-10-19%20at%2012.36.33 AM.png)

*Explanation*: This screenshot displays the output after initializing the linked list and inserting several items. The output format shows the keys and associated data of each node in the list. The successful addition of items is confirmed as the output reflects the correct key-data pairs:



### Screenshot 2: Deleting Items from the List

![Deleting Items](/project_3/Screenshot%202024-10-19%20at%2012.36.54 AM.png)

*Explanation*: This screenshot illustrates the deletion functionality of our linked list. The output before and after the deletion of specific items is shown, allowing us to verify that the delete operation works correctly. The test cases include deleting the last, first, and a middle item. For example, deleting the last item results in the following:

This confirms that the item with key `5` was successfully removed.

### Screenshot 3: Searching for Items in the List

![Searching for Items](/project_3/Screenshot%202024-10-19%20at%2012.37.24 AM.png)

*Explanation*: This screenshot shows the results of the search functionality, where we attempt to locate specific keys in the linked list. The output indicates the results of searching for both existing and non-existing keys:

This demonstrates that the search function is functioning correctly, returning the data associated with the found key and notifying us when a key is not present.

## Conclusion

The implementation of an unsorted linked list in C++ was successful, achieving all intended functionalities. We thoroughly explored key operations, including insertion, deletion, searching, and displaying list items. 

Through this lab, we developed a deeper understanding of the following concepts:
- **Dynamic Memory Management**: We used pointers to dynamically allocate and deallocate memory, which is a core concept in C++ programming.
- **Data Structures**: We gained insight into the advantages and disadvantages of using linked lists compared to arrays, such as ease of insertion and deletion, but with potential overhead due to dynamic memory allocation.
- **Debugging Techniques**: Throughout the implementation, we encountered and resolved various issues, enhancing our debugging skills in C++.



