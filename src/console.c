/*
 * file: console.c
 * ------------
 * Runs the console interface.
 *
 * author: Max Turkot
 * version: 12/11/21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"
#include "readFile.h"
#include "writeFile.h"
#include "search.h"

/*
 * Runs console with a while loop. Available commands:
 * x: exit
 * p: print list of restaurant in the knowledge base
 * s: search for restaurants based on entered criteria
 * a: add a new restarurant
 * w: write restaurants to a file
 * r: remove restaurant from all indexing structures
 * Any other character command will produce an error and 
 * wait for a new command.
 *
 * *btName: pointer to a binary tree with NAME ordering rule.
 * *btCity: pointer to a binary tree with LOCATION ordering rule.
 */
void runConsole(BinaryTree *btName, BinaryTree *btCity) {
  ArrayList *result;
  char *input = malloc(64 * sizeof(char));
  int match;
  int noMatch;
  int someMatch;
  char *city;
  char *categories;
  char *cost;
  // time

  printf("Welcome to mini-Yelp\n");
  
  while(1) { // Run input loop.
    printf("> ");
    fgets(input, 64, stdin);
    input[strcspn(input, "\n")] = 0; 
    
    if (strcmp(input, "print") == 0 || strcmp(input, "p") == 0) { // Identify print.
      printf("\nrestaurants:\n\n");
      printf("%s", toStringBinaryTree(btName));
      printf("\nprint finished\n");
    } else if (strcmp(input, "search") == 0 || strcmp(input, "s") == 0) { // Identify search.
      printf("enter search criteria:\n");
      getParam(&city, &cost, &categories);
      // result = search(arrayList, city, cost, categories);
      printf("\nresults:\n\n");
      // printAll(result);
      printf("search finished\n");
    } else if (strcmp(input, "add") == 0 || strcmp(input, "a") == 0) { // Identify add.
      addRestaurant(btName, btCity);
      printf("\nrestaurant added\n");
    } else if (strcmp(input, "write") == 0 || strcmp(input, "w") == 0) { // Identify write.
      callWrite(btName);
      printf("\nwrite finished\n");
    } else if (strcmp(input, "remove") == 0 || strcmp(input, "r") == 0) { // Identify remove.
      callRemove(btName, btCity);
      printf("\nremove finished\n");
    } else if (strcmp(input, "exit") == 0 || strcmp(input, "x") == 0) { // Identify exit.
      printf("exiting...\n");
      break;  
    } else { // Command unknown.
      printf("%s: command not found\n", input);
    }
  }
}

/*
 * Queries the user for parameters. Initiates and stores entered values.
 *
 * **city:       pointer to the string of restaurant's city.
 * **cost:       pointer to the string of restaurant's cost.
 * **categories: pointer to the string of restaurant's categories.
 */
void getParam(char **city, char **cost, char **categories) {
  char* cityEdit;
  char* costEdit;
  char* categoriesEdit;
  *city       = malloc(64 * sizeof(char));
  *cost       = malloc(64 * sizeof(char));
  *categories = malloc(64 * sizeof(char));

  printf("- city: ");
  fgets(*city, 64, stdin);

  cityEdit = *city;
  cityEdit[strcspn(cityEdit, "\n")] = 0; 
  strcpy(*city, cityEdit);

  printf("- cost: ");
  fgets(*cost, 64, stdin);

  costEdit = *cost;
  costEdit[strcspn(costEdit, "\n")] = 0;
  strcpy(*cost, costEdit);

  printf("- categories: ");
  fgets(*categories, 64, stdin);

  categoriesEdit = *categories;
  categoriesEdit[strcspn(categoriesEdit, "\n")] = 0;
  strcpy(*categories, categoriesEdit);
}

/*
 * Adds a new restaurant to the indexing structures. Prompts user for restaurant paramenters, 
 * creates a restaurant, and inserts it into indexing structures.
 * 
 * *btName: pointer to a binary tree with NAME ordering rule.
 * *btCity: pointer to a binary tree with LOCATION ordering rule.
 */
void addRestaurant(BinaryTree *btName, BinaryTree *btCity) {
  char *name       = malloc(64 * sizeof(char));
  char *city       = malloc(64 * sizeof(char));
  char *categ = malloc(64 * sizeof(char));
  char *cost       = malloc(6  * sizeof(char));
  char *rankStr    = malloc(6  * sizeof(char));
  char *reviewsStr = malloc(16 * sizeof(char));
  int rank;
  int reviews;
  LinkedList *categList;

  printf("- name: ");
  fgets(name, 64, stdin);
  name[strcspn(name, "\n")]   = 0;

  printf("- city: ");
  fgets(city, 64, stdin);
  city[strcspn(city, "\n")]   = 0;

  printf("- categories: ");
  fgets(categ, 64, stdin);
  categ[strcspn(categ, "\n")] = 0;

  printf("- cost: ");
  fgets(cost, 6, stdin);
  cost[strcspn(cost, "\n")]   = 0;
  
  printf("- rank: ");
  fgets(rankStr, 6, stdin);

  printf("- reviews: ");
  fgets(reviewsStr, 6, stdin);
  
  categList = makeCategoryList(categ);
  rank = atof(rankStr);
  reviews = atof(reviewsStr);
  Restaurant *restaurant = initRestaurant(name, city, categList, cost, rank, reviews);
  
  insertInBinaryTree(btName, restaurant);
  insertInBinaryTree(btCity, restaurant);
}

/*
 * Calls write funciton to write restaurants to a file. Prompts for filename of a new file.
 *
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 */
void callWrite(BinaryTree *btName) {
  char *fileName = malloc(64 * sizeof(char));
  char *string = toStringBinaryTree(btName);

  printf("- file name: ");
  fgets(fileName, 64, stdin);
  fileName[strcspn(fileName, "\n")] = 0;

  writeFile(fileName, string);
}

/*
 * Calls remove funciton to remove element from indexing structures. Prompts for name and
 * location of an element to remove. Calls removeBT() funciton for each binary tree.
 *
 * btName: pointer to a binary tree with NAME ordering rule.
 * btLocation: pointer to a binery tree with LOCATION ordering rule.
 */
void callRemove(BinaryTree *btName, BinaryTree *btCity) {
  char *name     = malloc(64 * sizeof(char));
  char *location = malloc(64 * sizeof(char));

  printf("- name: ");
  fgets(name, 64, stdin);
  name[strcspn(name, "\n")] = 0;
  
  printf("- location: ");
  fgets(location, 64, stdin);
  location[strcspn(location, "\n")] = 0;

  removeBT(btName, name, location);
  removeBT(btCity, name, location);
}
