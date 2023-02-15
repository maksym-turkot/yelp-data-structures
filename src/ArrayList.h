#ifndef ARRAYLIST_H
#define ARRAYLIST_H

/*
 * file: ArrayList.h
 * -----------------
 * Implements array list data structure. Functionality includes creating, inserting in,
 * duplicating, searching, removing from, and printing elements stored in the list.
 *
 * author: Max Turkot
 * version: 12/11/21
 */

#include "Restaurant.h"

typedef struct { // Define ArrayList data structure to hold restaurants.
  Restaurant **restaurants;
  int space;
  int size;
} ArrayList;

/*
 * Initialyzes array list to store ten individual restaurant pointers.
 *
 * return: created array list of restaurant pointers.
 */
extern ArrayList *createArrayList();

/*
 * Gets total number of available memory locations.
 *
 * ArrayList*: pointer to a target array list.
 * return:     space in array list.
 */
extern int getSpace(ArrayList*);

/*
 * Gets number of elements currently in the list.
 *
 * ArrayList*: pointer to a target array list.
 * return:     number of elements in the list.
 */
extern int getSize(ArrayList*);

/*
 * Returns restaurant with a specified index.
 * 
 * *ArrayList: target array list.
 * int:        index of target element pointer.
 * return: pointer to a Restaurant with a specified index.
 */
extern Restaurant *getRestaurant(ArrayList*, int);

/*
 * Inserts new element pointer at the back of the array list. If array list is full, doubles 
 * the size of the list before inserting a new element pointer.
 *
 * ArrayList*: pointer to a target array list.
 * restaurant: pointer to an element to be inserted in the list.
 */
extern void insert(ArrayList*, Restaurant*);

/*
 * Copies given number of element pointers from one linked list to another.
 * 
 * Restaurant**: pointer to an array of element pointers to copy from.
 * Restaurant**: pointer to an array of element pointers to copy to.
 * int:          number of element pointers to copy.
 */
extern void copy(Restaurant**, Restaurant**, int);

/*
 * Prints information about a given element pointed to in the array list.
 * 
 * ArrayList*: pointer to array list containing the element pointer.
 * int:        index of the element pointer in the array list.
 */
extern void printOne(ArrayList*, int);

/*
 * Prints information about all elements pointed to in the array list.
 *
 * ArrayList*: pointer to array list to be printed.
 */
extern void printAll(ArrayList*);

/*
 * Creates a string with information about elements of the list.
 *
 * ArrayList*: pointer to an array list.
 * return:     string with information about elements of the list.
 */
extern char* toStringArrayList(ArrayList*);

/*
 * Duplicates existing array list with all of its contents.
 * 
 * ArrayList*: pointer to an array list to duplicate.
 * return:     pointer to a duplicated array list.
 */
extern ArrayList *duplicateAL(ArrayList*);

/*
 * Removes an element that matches by name and city from array list.
 *
 * ArrayList*: pointer to an array list to remove from.
 * char*:      name of element to be removed.
 * char*:      location of element to ve removed.
 * int:        1 if its the first element to be removed from the list, 0 otherwise.
 * return:     0 if removal was successfull, -1 otherwise.
 */
extern int removeAL(ArrayList*, char*, char*, int);

/*
 * Searches for an element that matches by name and city in the array list.
 *
 * ArrayList*: pointer to an array list to search.
 * char*:      name of element to search for.
 * char*:      location of element to search for.
 * return:     -1 if element was not found, index of the element in the array list otherwise.
 */
extern int findRestaurant(ArrayList*, char*, char*);

#endif
