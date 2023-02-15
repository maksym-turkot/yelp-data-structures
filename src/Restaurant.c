/*
 * file: Restaurant.c
 * ------------------
 * Implements a Restaurant structure with printing functionality.
 * 
 * author: Max Turkot
 * version: 12/10/21
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Restaurant.h"

/*
 * Initialyzes a pointed Restaurant structure. Allocates space and sets fields equal to passed 
 * parameters.
 *
 * *name:       name of a restaurant.
 * *city:       city where restaurant is located.
 * *categories: pointer to restaurant's food categories linked list. 
 * *
 * *cost:       how expensive restaurant is ($, $$, $$$).
 * rank:        restaurant's rank from 0.0 to 5.0
 * reviewers:   number of people who rated the restaurant.
 * return:      pointer to a restaurant struct.
 */
Restaurant *initRestaurant(char *name, char* city, LinkedList *categories, 
    // LinkedList *whenOpen, 
    char *cost, float rank, int reviewers) {
  Restaurant *restaurant = malloc(sizeof(Restaurant));

  restaurant->name = (char*)malloc(64*sizeof(char));
  restaurant->city = (char*)malloc(64*sizeof(char));
  restaurant->cost = (char*)malloc(64*sizeof(char));
  strcpy(restaurant->name, name);
  strcpy(restaurant->city, city);
  restaurant->categories = categories;
  // restaurant->whenOpen   = whenOpen;
  strcpy(restaurant->cost, cost);
  restaurant->rank       = rank;
  restaurant->reviewers  = reviewers;

  return restaurant; 
}

/*
 * Prints restaurant's information to the console.
 * 
 * restaurant: restaurant to be printed.
 */
void printRestaurant(Restaurant restaurant) {
  printf("%s\n", restaurant.name);
  printf("%s\n", restaurant.city);
  printLinkedList(restaurant.categories);
  // printf("%s\n", restaurant.whenOpen);
  printf("%s\n", restaurant.cost);
  printf("%0.1f\n", restaurant.rank);
  printf("%d\n", restaurant.reviewers);
  printf("\n");
}

/*
 * Creates a string with information about the restaurant. Concatenates all fields into a 
 * single string.
 *
 * *restaurant: pointer to the restaurant.
 * return:     string with information about the restaurant.
 */
char *toStringRestaurant(Restaurant *restaurant) {
  char *printbuf = (char*)malloc(1024 * sizeof(char));
  char *s = (char*)malloc(3* sizeof(int));
  strcpy(printbuf, "");

  strcat(printbuf, restaurant->name);
  strcat(printbuf, "\n");
  strcat(printbuf, restaurant->city);
  strcat(printbuf, "\n");
  strcat(printbuf, toStringLinkedList(restaurant->categories));
  strcat(printbuf, "\n");
  strcat(printbuf, restaurant->cost);
  strcat(printbuf, "\n");

  sprintf(s, "%0.1f", restaurant->rank);
  strcat(printbuf, s);
  strcat(printbuf, "\n");

  sprintf(s, "%d", restaurant->reviewers);
  strcat(printbuf, s);
  strcat(printbuf, "\n");
  strcat(printbuf, "\n");

  return printbuf;
}
