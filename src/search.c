/*
 * file: search.c
 * --------------
 * Searches passed array list based on different parameters. Search results for each parameter 
 * are merged and returned as a linked list of elements matching the criteria.
 *
 * author: Max Turkot
 * version: 10/30/21
 */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "search.h"

/*
 * Searches the array based on specified parameters for matches. Returns a list of elements 
 * matching all parameters.
 *
 * *data:       pointer to an array list to search.
 * *city:       desired city.
 * *cost:       desired cost.
 * *categories: pointer to a list of desired categories.
 * return:      pointer to an array list with found elements.
 */
ArrayList *search(ArrayList *data, char* city, char* cost, char *categories) {
  LinkedList *categoryList = stringToList(categories);
  ArrayList  *foundCity;
  ArrayList  *foundCost;
  ArrayList  *foundCategory;
  ArrayList  *result;

  if (strcmp(city, "*") == 0) { // Copy all elements if user doesn't care about city.
    foundCity = data;
  } else {
    foundCity = searchCity(data, city);
  } 
  if (strcmp(cost, "*") == 0) { // Copy all elements if user doesn't care about cost.
    foundCost = data;
  } else {
    foundCost = searchCost(data, cost);
  }
  if (strcmp(categories, "*") == 0) { // Copy all elements if user doesn't care about category.
    foundCategory = data;
  } else {
    foundCategory = searchCategory(data, categoryList);
  }

  result = merge(foundCity, foundCost);
  result = merge(result, foundCategory);
  return result;
}

/*
 * Searches for restaurants matching the city and saves them in an array list.
 *
 * *data:  pointer to an array list to search.
 * *city:  string of a desired city name.
 * return: pointer to an array list with found elements.
 */
ArrayList *searchCity(ArrayList *data, char *city) {
  ArrayList *foundCity = createArrayList();
  
  for(int i = 0; i < getSize(data); i++) { // Iterate over element pointers in array list.
    Restaurant *curr = getRestaurant(data, i);

    if (strcmp(curr->city, city) == 0) { // Check if restaurant's city matches.
      insert(foundCity, curr); 
    } 
  }

  return foundCity;
}

/*
 * Searches for restaurants with cost that does not exceed specified value and saves them in 
 * an array list.
 * 
 * *data:  pointer ro an array list to search.
 * *cost:  string of a maximum cost.
 * return: pointer to an array list with found elements.
 */
ArrayList *searchCost(ArrayList *data, char *cost) {
  ArrayList *foundCost = createArrayList();
  
  for (int i = 0; i < getSize(data); i++) { // Iterate over element pointers in array list.
    Restaurant *curr = getRestaurant(data, i);
    
    if (strcmp(cost, "$$$") == 0) { // If prise limit is maximum, save all elements.
      insert(foundCost, curr);
    } else if (strcmp(cost, "$$") == 0) {
      if (strcmp(curr->cost, "$$$") != 0) { // Save all but most expensive restaurants.
        insert(foundCost, curr);
      }
    } else if (strcmp(cost, "$") == 0) {
      if (strcmp(curr->cost, "$") == 0) { // Save only the cheapest restaurants.
        insert(foundCost, curr);
      }
    }
  }
  return foundCost;
}

/*
 * Searches for restaurants that have at least one of the specified categories.
 * 
 * *data:     pointer to an array list to search.
 * *category: pointer to a list of desired categories.
 * return:    pointer to an array list with found elements.
 */
ArrayList *searchCategory(ArrayList *data, LinkedList *categoryList) {
  ArrayList *foundCategory = createArrayList();
  
  for (int restIndex = 0; restIndex < getSize(data); restIndex++) { // Iterate restaurants.
    Restaurant *currRest = getRestaurant(data, restIndex);
    Node *currCat        = currRest->categories->head;

    while (currCat != 0) { // Iterate restaurant category nodes.
      Node *currList = categoryList->head;
      bool found = false;

      while (currList != 0) { // Iterate desired category nodes.
	if (strcmp(currCat->data, currList->data) == 0) { // Compare categories.
          insert(foundCategory, currRest);
	  found = true;
	}
	currList = currList->next;
      }
      if (found) { // Current restaurant was already added.
        break;
      }
      currCat = currCat->next;
    } 
  }
  return foundCategory;
}

/*
 * Merges two array list into one that only contains elements appearing in both lists. 
 * Iterates over each element pair and compairs element pointers.
 *
 * *one:   pointer to the first array list to merge.
 * *two:   pointer to the second array list to merge.
 * return: pointer to a merger array list.
 */
ArrayList *merge(ArrayList *one, ArrayList *two) {
  ArrayList *result = createArrayList();

  for (int i = 0; i < getSize(one); i++) { // Iterate over elements of the firs array list.
    Restaurant *currOne = getRestaurant(one, i);

    for (int j = 0; j < getSize(two); j++) { // Iterate over elements of the second array list.
      Restaurant *currTwo = getRestaurant(two, j);
      
      if (currOne == currTwo) { // If pointers match, add to a new array list.
        insert(result, currOne); 
      }
    }
  }  
  return result;
}

/*
 * Creates a linked list of strings from a single comma-separated string.
 *
 * *string: string read from a file containing csv.
 * return:  a linked list of strings of categories.
 */
LinkedList *stringToList(char* string) {
  LinkedList *list = createLinkedList();
  char *token;
  char *toSplit = string;
  char *toSave;

  while((token = strtok_r(toSplit, ",", &toSplit))) { // Read next token.
    toSave = malloc(64 * sizeof(char));
    strcpy(toSave, token);
    insertInLinkedList(list, toSave);
  }
  return list;
}
