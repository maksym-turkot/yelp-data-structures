#ifndef CONSOLE_H
#define CONSOLE_H

/*
 * file: console.h
 * ------------
 * Runs the console interface.
 *
 * author: Max Turkot
 * version: 12/11/21
 */

#include "ArrayList.h"
#include "BinaryTree.h"

/*
 * Runs console interface. Available commands:
 * x: exit
 * p: print list of restaurant in the knowledge base
 * s: search for restaurants based on entered criteria
 * a: add a new restarurant
 * w: write restaurants to a file
 * r: remove restaurant from all indexing structures
 * Any other character command will produce an error and
 * wait for a new command.
 *
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binary tree with LOCATION ordering rule.
 */
extern void runConsole(BinaryTree*, BinaryTree*);

/*
 * Queries the user for parameters.
 *
 * char**: pointer to the string of restaurant's city.
 * char**: pointer to the string of restaurant's cost.
 * char*8: pointer to the string of restaurant's categories.
 */
extern void getParam(char**, char**, char**);

/*
 * Adds a new restaurant to the indexing structures.
 * 
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binary tree with LOCATION ordering rule.
 */
extern void addRestaurant(BinaryTree*, BinaryTree*);

/*
 * Calls write funciton to write restaurants to a file. Prompts for filename of a new file.
 * 
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 */
extern void callWrite(BinaryTree*);

/*
 * Calls remove funciton to remove element from indexing structures. Prompts for name and 
 * location of an element to remove.
 * 
 * BinaryTree*: pointer to a binary tree with NAME ordering rule.
 * BinaryTree*: pointer to a binery tree with LOCATION ordering rule.
 */
extern void callRemove(BinaryTree*, BinaryTree*);

#endif
