# Circular LinkedList Implementation

Here! I have implemented a *Circular Linked List* in C++ by using OOP. A circular linked list is a variation of a linked list where the last node points back to the first node, creating a circular structure.

---

## Features of Circular LinkedList

1.  **Node Structure**:
    - Each node contains:
    - `data` - the value of the node.
    - `next` - a pointer to the next node.

2. **Circular Nature**:
    - The `next` of the last node points to the first node, forming a loop.

3. **Operations**:
  - **Create Node**: Add a node to the list.        
  - **InsertNode**: Insert a node at start of the list.        
  - **InsertAtposition**: Insert a node at specific position.         
  - **InsertBetween**: Insert a node between after a specific value.
  - **DeleteNode**: Delete a node with specific value.
  - **Display**: Print all elements in the circular linked list.

  ---

  ## How it works
  1. **Circular Linking**: 
     - When adding or deleting nodes, the last node's `next` is updated to point to the first node, maintaining the circular structure.
  2. **Traversal**:
     - Start from the node after the`next` (head node) and loop back until you reach the starting node again.
  3. **Edge Cases**: 
     - Handle Cases for:      
       - Empty Lists.      
       - Singly-node lists.      
       - Adding or removing nodes at different positions (beginning, middle, or end).      