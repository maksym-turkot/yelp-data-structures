#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
 * file: LinkedList.h
 * ------------------
 * Implements linked list data structure. Functionality includes creating, pushing to, and 
 * printing elements stored in the list.
 *
 * author: Max Turkot
 * version: 12/10/21
 */

#include <stdbool.h>

typedef struct Node{ // Define node structore to hold data.
  struct Node* next;
  struct Node* prev;
  char* data;
} Node;

typedef struct { // Define Linked list structure to store head, tail pointers and list size. 
  Node *head;
  Node *tail;
  int size;
} LinkedList;

/*
 * Initialyzes linked list. Allocates memory for the structure. Sets head and tail node
 * pointers equal to zero.
 *
 * return: pointer to created linked list.
 */
extern LinkedList *createLinkedList();

/*
 * Gets head pointer of a linked list.
 *
 * LinkedList*: pointer to a target linked list.
 * return:      pointer to head of a list.
 */
extern Node *getHead(LinkedList*);

/*
 * Gets tail pointer of a linked list.
 *
 * LinkedList*: pointer to a target linked list.
 * return:      pointer to head of a list.
 */
extern Node *getTail(LinkedList*);

/*
 * Creates a node to store data.
 *
 * char*:  data to be stored.
 * return: pointer to a node storing passed data.
 */
extern Node *createNode(char*);

/*
 * Inserts a new node with data at the end of a linked list.
 *
 * LinkedList*: pointer to a linked list where to insert data.
 * char*:       data to be stored in a linked list.
 */
extern void insertInLinkedList(LinkedList*, char*);

/*
 * Prints data stored in a single node.
 *
 * Node*: pointer to a node with data.
 * bool:  true if node is last in the list.
 */
extern void printNodeData(Node*, bool);

/*
 * Prints all elements stored in a linked list.
 *
 * LinkedList*: linked list to print.
 */
extern void printLinkedList(LinkedList*);

/*
 * Creates a string with information about elements of the list.
 *
 * LinkedList*: pointer to a linked list.
 * return:      string with information about elements of the list.
 */
extern char *toStringLinkedList(LinkedList*);

/*
 * Creates a string with information stored in the node.
 *
 * Node*:  pointer to a node.
 * bool:   true if node contains the last element of the list.
 * return: string with information stored in the node.
 */
extern char *toStringNodeData(Node*, bool);

#endif
