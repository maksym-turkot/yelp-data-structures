#ifndef READFILE_H
#define READFILE_H

/*
 * File: readFile.h
 * ----------------
 * Reads information about restaurants from a file and stores them in an array list.
 *
 * author: Max Turkot
 * version: 12/10/21
 */
#include "ArrayList.h"
#include "LinkedList.h"
#include "BinaryTree.h"

/*
 * Reads data about restaurants from a file with a passed name. If file cannot be opened, 
 * prints an arror. Data is stored in binary trees.
 *
 * char*: name of file to be read.
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binary tree with LOCATION ordering rule.
 */
extern void readFile(char*, BinaryTree*, BinaryTree*);

/*
 * Creates a linked list of strings from a single comma-space-separated string.
 *
 * char*: string read from a file containing comma-space-separated values.
 * return:      a linked list of strings of categories.
 */
extern LinkedList *makeCategoryList(char*);

/*
 * Saves a restaurant with read parameters and stores in in binary trees.
 *
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binary tree with LOCATION ordering rule.
 * char*:       name of a restaurant.
 * char*:       city where restaurant is located.
 * char*:       string of restaurant's food categories.
 * *
 * char*:       how expensive restaurant is ($, $$, $$$).
 * float:       restaurant's rank from 0.0 to 5.0
 * int:         number of people who rated the restaurant.
 */
extern void saveInsert(BinaryTree*, BinaryTree*, char*, char*, char*, char*, float, int);

#endif
