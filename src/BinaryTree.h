#ifndef BINARYTREE_H
#define BINARYTREE_H

/*
 * file: BinaryTree.h
 * ------------------
 * Implements binary tree data structure to store array lists of restaurants grouped into
 * nodes depending on the ordering rule. Functionality includes creating, insertind in, 
 * removing from, and creting string of information stored in a binary tree.
 * 
 * author: Max Turkot
 * version: 12/11/21
 */

#include <stdbool.h>
#include "ArrayList.h"

typedef enum { // Define categories of tree ordering rule.
  NAME, LOCATION
} TreeOrder;

typedef struct BTNode{ // Define binary tree node to hold pointer to array list of elements.
  struct BTNode *left;
  struct BTNode *right;
  char *name;
  ArrayList *restaurants;
} BTNode;

typedef struct { // Define binary tree element.
  BTNode *root;
  TreeOrder order;
  int size;
} BinaryTree;

/*
 * Initialyzes binary tree.
 *
 * TreeOrder: tree ordering rule (NAME or LOCATION).
 * return:    pointer to a created binary tree.
 */
extern BinaryTree *createBinaryTree(TreeOrder);

/*
 * Creates a bt node to hold pointer to an array list of restaurants.
 *
 * Restaurant*: pointer to a restaurant to be added to the array list.
 * return:      pointer to a created bt node.
 */
extern BTNode *createBTNode(Restaurant*);

/*
 * Manages insertion of a new element.
 *
 * BinaryTree*: pointer to a binery tree to insert in.
 * Resturant*:  pointer to a restaurant to insert.
 */
extern void insertInBinaryTree(BinaryTree*, Restaurant*);

/*
 * Inserts an element in a binary tree ordered by name.
 *
 * BTNode*      pointer to a root of binary tree.
 * Restaurant*: pointer to a restaurant to insert.
 */
extern void insertNodeName(BTNode*, Restaurant*);

/*
 * Inserts an element in a binary tree ordered by location.
 *
 * BTNode*      pointer to a root of binary tree.
 * Restaurant*: pointer to a restaurant to insert.
 */
extern void insertNodeCity(BTNode*, Restaurant*);

/*
 * Creates a string with information about elements stored.
 *
 * BinaryTree*: pointer to a binary tree.
 * return:      string with information about elements stored in the binary tree.
 */
extern char *toStringBinaryTree(BinaryTree*);

/*
 * Traverses binary tree and appends node information to a string.
 * 
 * BTNode*: pointer to a root of binary tree.
 * char*:   string to append information to.
 */
extern void inOrder(BTNode*, char*);

/*
 * Recursively searches binary tree for a node that contains elements with mathing name.
 *
 * BinaryTree*: pointer to a binary tree to search.
 * char*:       name to be searched for.
 * return:      pointer to a found node, NULL otherwise.
 */
extern BTNode *searchBTName(BinaryTree*, char*);

/*
 * Recursively searches binary tree for a node that contains elements with mathing location.
 *
 * BinaryTree*: pointer to a binary tree to search.
 * char*:       location to be searched for.
 * return:      pointer to a found node, NULL otherwise.
 */
extern BTNode *searchBTLoc(BinaryTree*, char*);

/*
 * Recursively traverses binary tree searching for node that contains elements with matching 
 * name.
 *
 * BTNode*: pointer to the root of binary tree.
 * char*:   name to be searched for.
 * return:  pointer to a found node, NULL otherwise.
 */
extern BTNode *searchBTNodeName(BTNode*, char*);

/*
 * Recursively traverses binary tree searching for node that contains elements with matching 
 * location.
 *
 * BTNode*: pointer to the root of binary tree.
 * char*:   location to be searched for.
 * return:  pointer to a found node, NULL otherwise.
 */
extern BTNode *searchBTNodeLoc(BTNode*, char*);

/*
 * Gets parent of a node located in a binaty tree with ordering rule by name.
 * 
 * BTNode*: pointer to a root of a subtree.
 * BTNode*: pointer to a node parent of which sould be found.
 * return:  pointer to a found node, NULL otherwise.
 */
extern BTNode *getParentBTName(BTNode*, BTNode*);

/*
 * Gets parent of a node located in a binaty tree with ordering rule by location.
 * 
 * BTNode*: pointer to a root of a subtree.
 * BTNode*: pointer to a node parent of which sould be found.
 * return:  pointer to a found node, NULL otherwise.
 */
extern BTNode *getParentBTLoc(BTNode*, BTNode*);

/*
 * Removes an element from a binary tree that matches by name and location.
 * 
 * BinaryTree*: pointer to a binary tree from which element must be removed.
 * char*:       name that elements must match.
 * char*:       location that elemetns must match.
 */
extern void removeBT(BinaryTree*, char*, char*);

/*
 * Removes element from a binary tree that matches by name and location with an 
 * ordering rule by name. If node still contains elements, it is not removed.
 *
 * BinaryTree*: pointer to a binary tree from which elemetn must be removed.
 * char*:       name that elements must match.
 * char*:       location that elements must match.
 */
extern void removeBTName(BinaryTree*, char*, char*);

/*
 * Removes element from a binary tree that matches by name and location with an 
 * ordering rule by location. If node still contains elements, it is not removed.
 *
 * BinaryTree*: pointer to a binary tree from which elemetn must be removed.
 * char*:       name that elements must match.
 * char*:       location that elements must match.
 */
extern void removeBTLoc(BinaryTree*, char*, char*);

/*
 * Recirsively removes node from a binary tree.
 * 
 * BinaryTree*: pointer to a binary tree from which node must be removed.
 * BTNode*:     pointer to a parent of node to be removed.
 * BTNode*:     pointer to the node to be removed.
 * return:      -1 if node was equal to NULL, 0 upon successful execution.
 */
extern int removeBTNode(BinaryTree*, BTNode*, BTNode*);

#endif
