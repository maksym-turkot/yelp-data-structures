/*
 * file: ArrayList.c
 * -----------------
 * Implements array list data structure. Functionality includes creating, inserting in, 
 * duplicating, searching, removing from, and printing elements stored in the list.
 *
 * author: Max Turkot
 * version: 12/11/21
 */

#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

/*
 * Initialyzes array list. Allocates memory for the structure and ten individual element 
 * pointers. Sets space and size fields equal to zero. Space is total memory locations, size is 
 * occupied memory locations.
 *
 * return: pointer to a created array list.
 */
ArrayList *createArrayList() {
  ArrayList *arrayList;
  arrayList = malloc(sizeof(ArrayList));
  arrayList->restaurants = (Restaurant**)calloc(10, sizeof(Restaurant*));
  arrayList->space = 10;
  arrayList->size = 0;

  return arrayList;
}

/*
 * Gets total number of available memory locations.
 *
 * *arrayList: pointer to a target array list.
 * return:     space in array list.
 */
int getSpace(ArrayList *arrayList) {
  return arrayList->space;
}

/*
 * Gets number of element pointers corrently in the list.
 * 
 * *arrayList: pointer to a target array list.
 * return:     number of elements pointers in the list.
 */
int getSize(ArrayList *arrayList) {
  return arrayList->size;
}

/*
 * Returns restaurant with a specified index.
 * 
 * *arrayList: pointer to a target array list.
 * index:      index of target element pointer.
 */
Restaurant *getRestaurant(ArrayList *arrayList, int index) {
  return arrayList->restaurants[index];
}

/*
 * Inserts a new element pointer at the back of the array list. If array list is full, copies 
 * its element pointers to a new array list of double size, and adds new element at the end of 
 * a new list.
 *
 * *arrayList: pointer to a target array list.
 * restaurant: pointer to an element to be inserted in the list.
 */
void insert(ArrayList *arrayList, Restaurant *restaurant) {
  if (getSize(arrayList) == getSpace(arrayList)) { // Check if list is full.
    Restaurant **restaurants = (Restaurant**)calloc(getSpace(arrayList) * 2, 
      sizeof(Restaurant*));

    copy(arrayList->restaurants, restaurants, getSpace(arrayList));
    arrayList->restaurants = restaurants;
    arrayList->space = getSpace(arrayList) * 2;
  }

  arrayList->restaurants[getSize(arrayList)] = restaurant;
  arrayList->size++;
}

/*
 * Copies given number of element pointers from one array list to another.
 * 
 * **src:  pointer to an array of element pointers to copy from.
 * **dest: pointer to an array of element pointers to copy to.
 * num:    number of element pointers to copy.
 */
void copy(Restaurant **src, Restaurant **dest, int num) {
  for (int i = 0; i < num; i++) { // Iterate over memory locations in both lists.
    *dest = *src;
    src++;
    dest++;
  } 
}

/*
 * Prints information about a particular element pointed to in the array list.
 * 
 * *arrayList: pointer to an array list containing the element pointer.
 * index:      index of the element pointer in the array list.
 */
void printOne(ArrayList *arrayList, int index) {
  printRestaurant(*(arrayList->restaurants[index]));
}

/*
 * Prints information about all elements pointed to in the array list.
 *
 * *arrayList: pointer to an array list to be printed.
 */
void printAll(ArrayList *arrayList) {
  for (int i = 0; i < getSize(arrayList); i++) { // Iterate over element pointers in array list.
    printOne(arrayList, i);
  }
}

/*
 * Creates a string with information about elements of the list.
 * Calls toStringRestaurant in a loop and concatenates results.
 *
 * *arrayList: pointer to an array list.
 * return:     string with information about elements of the list.
 */
char *toStringArrayList(ArrayList *arrayList) {
  char *printbuf = (char*)malloc(1024 * arrayList->size);
  strcpy(printbuf, "");

  for (int i = 0; i < getSize(arrayList); i++) { // Add each restaurant to string.
    strcat(printbuf, toStringRestaurant(arrayList->restaurants[i]));
  }

  return printbuf;
}

/*
 * Duplicates existing array list with all of its contents. Creates a new array list and 
 * iteratevly inserts elements from the first list into the new one.
 *
 * *source: pointer to an array list to duplicate.
 * return:  pointer to a duplicated array list.
 */
ArrayList *duplicateAL(ArrayList *source) {
  ArrayList *target = createArrayList();

  for (int i = 0; i < getSize(source); i++) { // Insert elements from old list into new one. 
    insert(target, getRestaurant(source, i));
  }

  return target;
}

/*
 * Removes an element that matches by name and city from array list. Compares each elements' 
 * name and location to the desired values, and removes an element if match occurs. All 
 * elements to the right are shifted by one to the left. If removal is successful, algorithm 
 * recurses to check if there is another element with the same parameters.
 *
 * *al:       pointer to an array list to remove from.
 * *name:     name of element to be removed.
 * *locaiton: location of element to ve removed.
 * first:     1 if its the first element to be removed from the list, 0 otherwise.
 * return:    0 if removal was successfull, -1 otherwise.
 */
int removeAL(ArrayList *al, char *name, char *location, int first) {
  int target = findRestaurant(al, name, location);

  if (target == -1) { // If element was not found. 
    if (first == 1) { // If this was the first iteration.
      return -1;
    }
    return 0;
  }

  for (int i = target; i < getSize(al); i++) { // Shift elements to the left.
    if (i + 1 == getSpace(al)) { // If last element was reached.
      al->restaurants[i] = NULL;
      continue;
    }
    al->restaurants[i] = al->restaurants[i + 1];
  }
  al->size--;

  removeAL(al, name, location, 0);

  return 0;
}

 /*
 * Searches for an element that matches by name and city in the array list. Compares each 
 * element's parameters to desired values until match was detected. Then, returns index of 
 * located element. If no match occurs, returns -1.
 *
 * *al:       pointer to an array list to search.
 * *name:     name of element to search for.
 * *location: location of element to search for.
 * return:    -1 if element was not found, index of the element in the array list otherwise.
 */
int findRestaurant(ArrayList *al, char *name, char *location) {
  char *nodeName;
  char *nodeLoc;
  int diffName = 0;
  int diffLoc  = 0;
  Restaurant *curr;

  for (int i = 0; i < getSize(al); i++) { // Compare parameters of each element in the list.
    curr = getRestaurant(al, i);
    nodeName = curr->name;
    nodeLoc  = curr->city;
    nodeName[strcspn(nodeName, "\r")] = 0;
    nodeLoc[strcspn(nodeLoc, "\r")] = 0;

    diffName = strcmp(name, nodeName);
    diffLoc  = strcmp(location, nodeLoc);
    
    if (diffName == 0 && diffLoc == 0) { // If match found, return index of the element.
      return i;
    }
  } 
  return -1;
}
