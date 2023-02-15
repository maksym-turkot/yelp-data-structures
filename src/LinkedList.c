/*
 * file: LinkedList.c
 * ------------------
 * Implements linked list data structure. Functionality includes creating, pushing to, and 
 * printing elements stored in the list.
 *
 * author: Max Turkot
 * version: 12/10/21
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

/*
 * Initialyzes array list. Allocates memory for the structure. Sets head and tail node 
 * pointers equal to zero.
 * 
 * return: pointer to created linked list.
 */
LinkedList *createLinkedList() {
  LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
  linkedList->head = 0;
  linkedList->tail = 0;
  linkedList->size = 0;
  return linkedList;
}

/*
 * Gets head pointer of a linked list.
 *
 * *linkedList: pointer to a target linked list.
 * return:      pointer to head of a list.
 */
Node *getHead(LinkedList *linkedList) {
  return linkedList->head;
}

/*
 * Gets tail pointer of a linked list.
 *
 * *linkedList: pointer to a target linked list.
 * return:      pointer to head of a list.
 */
Node *getTail(LinkedList *linkedList) {
  return linkedList->tail;
}

/*
 * Creates a node to store data.
 * 
 * *data:  data to be stored.
 * return: pointer to a node storing passed data.
 */
Node *createNode(char *data) {
  Node *node = (Node*)malloc(sizeof(Node));
  
  node->next = 0;
  node->prev = 0;
  node->data = data;

  return node;
}

/*
 * Inserts a new node with data at the end of a linked list.
 *
 * *linkedList: pointer to a linked list where to insert data.
 * *data:       data to be stored in a linked list.
 */
void insertInLinkedList(LinkedList *linkedList, char *data) {
  Node *node = createNode(data);
  Node *head = getHead(linkedList);
  Node *tail = getTail(linkedList);

  if (head == 0) { // Check if linked list is empty.
    head = node;
    tail = node;
  } else { // Insert a node at the end of a list.
    tail->next = node;
    node->prev = tail;
    tail = node;
  }

  linkedList->head = head;
  linkedList->tail = tail;

  linkedList->size++;
}

/*
 * Prints data stored in a single node.
 *
 * *node: pointer to a node with data.
 * last:  true if node is last in the list.
 */
void printNodeData(Node *node, bool last) {
  if (last) { // If element is last, end of line.
    printf("%s\n", node->data);
  } else { // Print element followed by a delimeter.
    printf("%s, ", node->data);
  }
}

/*
 * Prints all elements stored in a linked list.
 * 
 * *linkedList: linked list to print.
 */
void printLinkedList(LinkedList *linkedList) {
  Node *curr = linkedList->head;
  bool last = false;

  while(curr != 0) { // Iterates through nodes.
    if (curr->next == 0) { // Second-to-last node reached.
      last = true;
    }
    printNodeData(curr, last);
    curr = curr->next;
  }
}

/*
 * Creates a string with information about elements of the list. Traverses the list, calling 
 * toStringNodeData() to get string of each node's data, concatenating the results.
 *
 * *linkedList: pointer to a linked list.
 * return:      string with information about elements of the list.
 */
char* toStringLinkedList(LinkedList *linkedList) {
  Node *curr = linkedList->head;
  bool last = false;
  char *printbuf = (char*)malloc(512 * linkedList->size);
  strcpy(printbuf, "");

  while(curr != 0) { // Iterates through nodes.
    if (curr->next == 0) { // Second-to-last node reached.
      last = true;
    }
    strcat(printbuf, toStringNodeData(curr, last));
    curr = curr->next;
  }

  return printbuf;
}

/*
 * Creates a string with information stored in the node. If element is last in the list, 
 * adds a newline character after data. If not, adds a delimeter after data.
 *
 * node*:  pointer to a node.
 * last:   true if node contains the last element of the list.
 * return: string with information stored in the node.
 */
char *toStringNodeData(Node *node, bool last) {
  char *printbuf = (char*)malloc(512 * sizeof(char));
  strcpy(printbuf, "");
  
  if (last) { // If element is last, end of line.
    strcat(printbuf, node->data);
  } else { // Element followed by a delimeter.
    strcat(printbuf, node->data);
    strcat(printbuf, ", ");
  }
  return printbuf;
}
