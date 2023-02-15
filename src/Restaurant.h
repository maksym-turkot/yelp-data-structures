#ifndef RESTAURANT_H
#define RESTAURANT_H

/*
 * file: Restaurant.h
 * ------------------
 * Implements a Restaurant structure with printing functionality.
 * 
 * author: Max Turkot
 * version: 12/10/21
 */

#include "LinkedList.h"

typedef struct { // Define restaurant structure with appropriate field.
  char* name;
  char* city;
  LinkedList *categories;
  // LinkedList *whenOpen;
  char* cost;
  float rank;
  int reviewers;
} Restaurant;

/*
 * Initialyzes a pointed Restaurant structure.
 *
 * char*:       name of a restaurant.
 * char*:       city where restaurant is located.
 * LinkedList*: pointer to restaurant's food categories linked list.
 * *
 * char*:       how expensive restaurant is ($, $$, $$$).
 * float:       restaurant's rank from 0.0 to 5.0
 * int:         number of people who rated the restaurant.
 * return:      pointer to a restaurant struct.
 */
extern Restaurant *initRestaurant(char*, char*, LinkedList*, 
    //LinkedList*, 
    char*, float, int);

/*
 * Prints restaurant's information to the console.
 * 
 * Restaurant: restaurant to be printed.
 */
extern void printRestaurant(Restaurant);

/*
 * Creates a string with information about the restaurant.
 *
 * Restaurant*: pointer to the restaurant.
 * return:      string with information about the restaurant.
 */
extern char* toStringRestaurant(Restaurant*);

#endif
