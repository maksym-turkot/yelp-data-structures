#ifndef SEARCH_H
#define SEARCH_H

/*
 * file: search.h
 * --------------
 * Searches passed array list based on different parameters.
 *
 * author: Max Turkot
 * version: 10/30/21
 */

#include "ArrayList.h"
#include "LinkedList.h"

/*
 * Searches the array based on specified parameters for matches. Returns a list of elements
 * matching all parameters.
 *
 * ArrayList*: pointer to an array list to search.
 * char*:  desired city.
 * char*:  desired cost.
 * char*:  desired categories.
 * return: pointer to an array list with found elements.
 */
extern ArrayList *search(ArrayList*, char*, char*, char*);

/*
 * Searches for restaurants matching the city.
 *
 * ArrayList*: pointer to an array list to search.
 * char*:      string of a desired city name.
 * return:     pointer to an array list with found elements.
 */
extern ArrayList *searchCity(ArrayList*, char*);

/*
 * Searches for restaurants with cost that does not exceed specified value. 
 *
 * ArrayList*: pointer ro an array list to search.
 * char*:      string of a maximum cost.
 * return:     pointer to an array list with found elements.
 */
extern ArrayList *searchCost(ArrayList*, char*);

/*
 * Searches for restaurants that have at least one of the specified categories.
 *
 * ArrayList*:  pointer ro an array list to search.
 * LinkedList*: pointer to a list of desired categories.
 * return:      pointer to an array list with found elements.
 */
extern ArrayList *searchCategory(ArrayList*, LinkedList*);

/*
 * Merges two array list into one that only contains elements appearing in both lists.
 *
 * ArrayList*: pointer to the first array list to merge.
 * ArrayList*: pointer to the second array list to merge.
 * return:     pointer to a merger array list.
 */
extern ArrayList *merge(ArrayList*, ArrayList*);

/*
 * Creates a linked list of strings from a single comma-separated string.
 *
 * char*:  string read from a file containing csv.
 * return: a linked list of strings of categories.
 */
extern LinkedList *stringToList(char*);

#endif
