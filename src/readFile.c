/*
 * File: readFile.c
 * ----------------
 * Reads information about restaurants from a file and stores them in an array list.
 *
 * author: Max Turkot
 * version: 12/10/21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"

/*
 * Reads data about restaurants from a file with a passed name. Reads file line by line, and 
 * depending on the line counter, stores line's value in corresponding restaurant's field. If 
 * file cannot be opened, prints an arror. Data is stored in binary trees.
 * 
 * fileName: name of file to be read.
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binary tree with LOCATION ordering rule.
 */
void readFile(char *fileName, BinaryTree *btName, BinaryTree *btCity) {
  FILE *file = fopen(fileName, "r");
  char *name         = malloc(64 * sizeof(char));
  char *city         = malloc(64 * sizeof(char));
  char *categories   = malloc(64 * sizeof(char));
  char *cost         = malloc(64 * sizeof(char));
  float rank         = 0;
  int reviewers      = 0;
  int lineCnt        = 0;

  if (file == NULL) { // Check if file wasn't opened.
    perror("In readFile.c");
  } 
 
  char *line = 0;
  size_t len = 0;

  while(getline(&line, &len, file) != -1) { // Read file line by line.
    switch(lineCnt % 8) { // Check what line is being read.
      case 0:
        strcpy(name, line);
        name[strcspn(name, "\n")] = 0; 
	      break;
      case 1:
        strcpy(city, line);
        city[strcspn(city, "\n")] = 0; 
        break;
      case 2:
        strcpy(categories, line);
        categories[strcspn(categories, "\n")] = 0; 
        break;
      case 3:
        // whenOpen todo
        // name[strcspn(name, "\n")] = 0; 
	      break;
      case 4:
        strcpy(cost, line);
        cost[strcspn(cost, "\n")] = 0; 
        break;
      case 5:
        rank = atof(line);
        break;
      case 6:
        reviewers = atoi(line);
        
        saveInsert(btName, btCity, name, city, categories, cost, rank, reviewers);
	      break;
    }
    lineCnt++;
  }
  fclose(file);
  free(line);
  free(name);
  free(city);
  free(cost);
}

/*
 * Creates a linked list of strings from a single comma-space-separated string.
 *
 * *categories: string read from a file containing comma-space-separated values.
 * return:      a linked list of strings of categories.
 */
LinkedList *makeCategoryList(char *categories) {
  LinkedList *categoryList = createLinkedList();
  char *token;
  char *toSplit = categories;
  char *toSave;

  while((token = strtok_r(toSplit, ",", &toSplit))) { // Read next token.
    if (token[0] == ' ') { // If token contains a space at the front.
      for (int i = 0; i < strlen(token) - 1; i++) { // Shift characters one to the left.
        token[i] = token[i + 1];
      }
      token[strlen(token) - 1] = 0;
    }
    toSave = malloc(64 * sizeof(char));
    strcpy(toSave, token);
    insertInLinkedList(categoryList, toSave);
  }
  return categoryList;  
}

/*
 * Saves a restaurant with read parameters and stores in binary trees.
 *
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binary tree with LOCATION ordering rule.
 * *name:       name of a restaurant.
 * *city:       city where restaurant is located.
 * *categories: string of restaurant's food categories.
 * *
 * *cost:       how expensive restaurant is ($, $$, $$$).
 * rank:        restaurant's rank from 0.0 to 5.0
 * reviewers:   number of people who rated the restaurant.
 */
void saveInsert(BinaryTree *btName, BinaryTree *btCity, char *name, char *city, 
    char *categories, char *cost, float rank, int reviewers) {
  LinkedList *categoryList = makeCategoryList(categories);
  Restaurant *restaurant = initRestaurant(name, city, categoryList, cost, rank, reviewers); 
  
  insertInBinaryTree(btName, restaurant);
  insertInBinaryTree(btCity, restaurant);
}
