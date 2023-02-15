/*
 * file: BinaryTree.c
 * ------------------
 * Implements binary tree data structure to store array lists of restaurants grouped into
 * nodes depending on the ordering rule. Functionality includes creating, insertind in, 
 * removing from, and creting string of information stored in a binary tree.
 *
 * author: Max Turkot
 * version: 12/11/21
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"

/*
 * Initialyzes binary tree. Sets all fields to initial values.
 *
 * order:  tree ordering rule (NAME or LOCATION).
 * return: pointer to a created binary tree.
 */
BinaryTree *createBinaryTree(TreeOrder order) {
  BinaryTree *bt = (BinaryTree*)malloc(sizeof(BinaryTree));
  bt->root  = 0;
  bt->order = order;
  bt->size  = 0;

  return bt;
}

/*
 * Creates a bt node to hold pointer to an array list of restaurants. Sets fields to initial 
 * values, creates an array list and inserts first restaurant in that list.
 *
 * *restaurant: pointer to a restaurant to be added to the array list.
 * return:      pointer to a created bt node.
 */
BTNode *createBTNode(Restaurant *restaurant) {
  BTNode *node = (BTNode*)malloc(sizeof(BTNode));

  node->left  = 0;
  node->right = 0;
  node->restaurants = createArrayList();
  insert(node->restaurants, restaurant);

  return node;
}

/*
 * Manages insertion of a new element. If tree is empty, root is created. If not, depending on 
 * the ordering rule node is inserted.
 *
 * *bt:        pointer to a binery tree to insert in.
 * *resturant: pointer to a restaurant to insert.
 */
void insertInBinaryTree(BinaryTree *bt, Restaurant *restaurant) {
  if (bt->size == 0) { // Check if tree is empty.
    bt->root = createBTNode(restaurant);
  } else { // Insert based on ordering rule.
    if (bt->order == NAME) { // If ordering rule set to name.
      insertNodeName(bt->root, restaurant);
    } else if (bt->order == LOCATION) { // If ordering fule set to location.
      insertNodeCity(bt->root, restaurant);
    } else { // If ordering rule is unknown.
      printf("Unknown order rule: %d", bt->order);
    }
  }
  bt->size++;
}

/*
 * Inserts an element in a binary tree ordered by name. If name is less than that of current 
 * node and node has no left child, insert as a left child. If not, pass insertion to the 
 * left child. Same procedure if name is greater than that of a node, but on the right node.
 * If names are equal, insert element in the array list of current node.
 *
 * *parent:     pointer to a root of binary tree.
 * *restaurant: pointer to a restaurant to insert.
 */
void insertNodeName(BTNode *parent, Restaurant *restaurant) {
  char *restaurantName = restaurant->name;
  char *parentName     = getRestaurant(parent->restaurants, 0)->name;

  int diff = strcmp(restaurantName, parentName);

  if (diff > 0) { // If new restaurant name is greater than that of node.
    if (parent->right == 0) { // If no right child.
      parent->right = createBTNode(restaurant);
    } else { // Pass insertion to right child.
      insertNodeName(parent->right, restaurant);
    }
  } else if (diff < 0) { // If new restaurant name is less than that of node.
    if (parent->left == 0) { // If no left child.
      parent->left = createBTNode(restaurant);
    } else { // Pass insertion to left child.
      insertNodeName(parent->left, restaurant);
    }
  } else { // Insert in the array list of node.
    insert(parent->restaurants, restaurant);
  }
}

/*
 * Inserts an element in a binary tree ordered by location. If location is less than that of 
 * current node and node has no left child, insert as a left child. If not, pass insertion to 
 * the left child. Same procedure if location is greater than that of a node, but on the right 
 * node. If locations are equal, insert element in the array list of current node.
 *
 * *parent      pointer to a root of binary tree.
 * *restaurant: pointer to a restaurant to insert.
 */
void insertNodeCity(BTNode *parent, Restaurant *restaurant) {
  char *restaurantCity = restaurant->city;
  char *parentCity     = getRestaurant(parent->restaurants, 0)->city;
  int  diff            = strcmp(restaurantCity, parentCity);

  if (diff > 0) { // If new restaurant location is greater than that of node.
    if (parent->right == 0) { // If no right child.
      parent->right = createBTNode(restaurant);
    } else { // Pass insertion to right child.
      insertNodeCity(parent->right, restaurant);
    }
  } else if (diff < 0) { // If new restaurant location is less than that of node.
    if (parent->left == 0) { // If no left child.
      parent->left = createBTNode(restaurant);
    } else { // Pass insertion to left child.
      insertNodeCity(parent->left, restaurant);
    }
  } else { // Insert in the array list of node.
    insert(parent->restaurants, restaurant);
  }
}

/*
 * Creates a string with information about elements stored. Calls inOrder() to traverse the 
 * tree and gather information.
 *
 * *bt:    pointer to a binary tree.
 * return: string with information about elements stored in the binary tree.
 */
char *toStringBinaryTree(BinaryTree *bt) {
  if (bt->root != 0) { // If tree is not empty.
    char *printbuf = (char*)malloc(1024 * bt->size);
    strcpy(printbuf, "");
  
    inOrder(bt->root, printbuf);

    printbuf[strlen(printbuf) - 1] = 0;

    return printbuf;
  } else { // Return null.
    return (char*) 0;
  }
}

/*
 * Traverses binary tree and appends node information to a string. First appends data fo the 
 * left child, that that of the node, and then information of the right child.
 * 
 * *node: pointer to a root of binary tree.
 * *p:    string to append information to.
 */
void inOrder(BTNode *node, char *p) {
  if (node->left != 0) { // If left child is not empty.
    inOrder(node->left, p);
  }
  
  strcat(p, toStringArrayList(node->restaurants));

  if (node->right != 0) { // If right child is not empty.
    inOrder(node->right, p);
  }
}

/*
 * Searches binary tree for a node that contains elements with mathing name. Calls recursive 
 * searchBTName().
 *
 * *bt:    pointer to a binary tree to search.
 * *name:  name to be searched for.
 * return: pointer to a found node, NULL otherwise.
 */
BTNode *searchBTName(BinaryTree *bt, char *name) {
  return searchBTNodeName(bt->root, name);
}

/*
 * Searches binary tree for a node that contains elements with mathing location. Calls 
 * recursive searchBTLoc().
 *
 * *bt:    pointer to a binary tree to search.
 * *loc:   location to be searched for.
 * return: pointer to a found node, NULL otherwise.
 */
BTNode *searchBTLoc(BinaryTree *bt, char *loc) {
  return searchBTNodeLoc(bt->root, loc);
}

/*
 * Recursively traverses binary tree searching for node that contains elements with matching
 * name. Chooses next node to examine based on the name.
 *
 * *node:  pointer to the root of binary tree.
 * *name:  name to be searched for.
 * return: pointer to a found node, NULL otherwise.
 */
BTNode *searchBTNodeName(BTNode *node, char *name) {
  if (node != NULL) {
    char *nodeName = getRestaurant(node->restaurants, 0)->name;
    nodeName[strcspn(nodeName, "\r")] = 0;
    int diff = strcmp(name, nodeName);
  
    if (diff == 0) { // If names match.
      return node;
    } else if (diff < 0) { // If name is less than that of node.
      return searchBTNodeName(node->left, name);
    } else { // Examine right node.
      return searchBTNodeName(node->right, name);
    }
  }
  return NULL; 
}

/*
 * Recursively traverses binary tree searching for node that contains elements with matching
 * location. Chooses next node to examine based on the location.
 *
 * *node:  pointer to the root of binary tree.
 * *city:  city to be searched for.
 * return: pointer to a found node, NULL otherwise.
 */
BTNode *searchBTNodeLoc(BTNode *node, char *city) {
  if (node != NULL) {
    char *nodeCity = getRestaurant(node->restaurants, 0)->city;
    nodeCity[strcspn(nodeCity, "\r")] = 0;
    int diff = strcmp(city, nodeCity);
  
    if (diff == 0) { // If locations match.
      return node;
    } else if (diff < 0) { // If location is less than that of node.
      return searchBTNodeLoc(node->left, city);
    } else { // Examine right node.
      return searchBTNodeLoc(node->right, city);
    }
  }
  return NULL; 
}

/*
 * Gets parent of a node located in a binaty tree with ordering rule by name. Compares if 
 * given subroot is a parent of the node and examines node deeper in the tree if neede.
 *
 * *sub:   pointer to a root of a subtree.
 * *node:  pointer to a node parent of which sould be found.
 * return: pointer to a found node, NULL otherwise.
 */
BTNode *getParentBTName(BTNode *sub, BTNode *node) {
  char *nodeName = getRestaurant(node->restaurants, 0)->name;
  char *subName  = getRestaurant(sub->restaurants,  0)->name;
  int  diff      = strcmp(nodeName, subName);

  if (sub == NULL) { // If subroot is null.
    return NULL;
  }

  if (sub->left == node || sub->right == node) { // If node is either child of the subroot.
     return sub;
  }

  if (diff < 0) { // If name is less than that of the subroot.
    return getParentBTName(sub->left, node);
  } else { // Examine right node.
    return getParentBTName(sub->right, node);
  }
}

/*
 * Gets parent of a node located in a binaty tree with ordering rule by location. Compares if
 * given subroot is a parent of the node and examines node deeper in the tree if neede.
 *
 * *sub:   pointer to a root of a subtree.
 * *node:  pointer to a node parent of which sould be found.
 * return: pointer to a found node, NULL otherwise.
 */
BTNode *getParentBTLoc(BTNode *sub, BTNode *node) {
  char *nodeCity = getRestaurant(node->restaurants, 0)->city;
  char *subCity  = getRestaurant(sub->restaurants,  0)->city;
  int  diff      = strcmp(nodeCity, subCity);

  if (sub == NULL) { // If subroot is null.
    return NULL;
  }

  if (sub->left == node || sub->right == node) { // If node is either child of the subroot.
     return sub;
  }

  if (diff < 0) { // If location is less than that of the subroot.
    return getParentBTLoc(sub->left, node);
  } else { // Examine right node.
    return getParentBTLoc(sub->right, node);
  }
}

/*
 * Removes an element from a binary tree that matches by name and location. Picks appropriate 
 * removal function based on the ordering rule.
 *
 * *bt:       pointer to a binary tree from which element must be removed.
 * *name:     name that elements must match.
 * *location: location that elemetns must match.
 */
void removeBT(BinaryTree *bt, char *name, char *location) {
  if (bt->order == NAME) { // If ordering rule set to name.
    removeBTName(bt, name, location);
  } else if (bt->order == LOCATION) { // If ordering fule set to location.
    removeBTLoc(bt, name, location);
  } else { // Ordering rule is unknown.
    printf("Unknown order rule: %d", bt->order);
  }
}

/*
 * Removes element from a binary tree that matches by name and location with an
 * ordering rule by name. Element is first removed from an array list. If node still contains 
 * elements, it is not removed. Otherwise, recursive node removal method is called.
 *
 * *bt:       pointer to a binary tree from which elemetn must be removed.
 * *name:     name that elements must match.
 * *location: location that elements must match.
 */
void removeBTName(BinaryTree *bt, char *name, char *location) {
  BTNode *node   = searchBTName(bt, name);
  BTNode *parent;
  int result = 0;

  if (node == NULL) { // If node with passed name was not found.
    printf("no results for this name\n");
    return;
  }

  parent = getParentBTName(bt->root, node);
  
  result = removeAL(node->restaurants, name, location, 1); 

  if (result == -1) { // If element was not found in the array list.
    printf("restaurant not found\n");
    return;
  }

  if (getSize(node->restaurants) != 0) { // If array list still contains elements.
    return; 
  }

  // free(node->restaurants);
  removeBTNode(bt, parent, node);
  // free(node);
}

/*
 * Removes element from a binary tree that matches by name and location with an
 * ordering rule by location. Element is first removed from an array list. If node still 
 * contains elements, it is not removed. Otherwise, recursive node removal method is called.
 *
 * *bt:       pointer to a binary tree from which elemetn must be removed.
 * *name:     name that elements must match.
 * *location: location that elements must match.
 */
void removeBTLoc(BinaryTree *bt, char *name, char *location) {
  BTNode *node   = searchBTLoc(bt, location);
  BTNode *parent;
  int result = 0;

  if (node == NULL) { //If node with passed city was not found.
    printf("no results for this location\n");
    return;
  }

  parent = getParentBTLoc(bt->root, node);
  
  result = removeAL(node->restaurants, name, location, 1); 

  if (result == -1) { // If element was not found in the array list.
    printf("restaurant not found\n");
    return;
  }

  if (getSize(node->restaurants) != 0) { // If array list still contains elements.
    return; 
  }

  // free(node->restaurants);
  removeBTNode(bt, parent, node);
  // free(node);
}

/*
 * Recirsively removes node from a binary tree. Covers four cases, where node has 2 children, 
 * is a root wiht a single child, is a node with a single left child, or a node with a sigle 
 * right child or a leaf.
 *
 * *bt:     pointer to a binary tree from which node must be removed.
 * *parent: pointer to a parent of node to be removed.
 * *node:   pointer to the node to be removed.
 * return:  -1 if node was equal to NULL, 0 upon successful execution.
 */
int removeBTNode(BinaryTree *bt, BTNode *parent, BTNode *node) {
  if (node == NULL) { // If node to be removed is null.
    return -1;
  }

  if (node->left != NULL && node->right != NULL) { // Case 1: If node has two children.
    BTNode *succNode = node->right;
    BTNode *succParent = node;

    while (succNode->left != NULL) { // Iterate through successor's children to pick a node.
      succParent = succNode;
      succNode = succNode->left;
    }

    node->restaurants = duplicateAL(succNode->restaurants);
    removeBTNode(bt, succParent, succNode);
  } else if (node == bt->root) { // Case 2: If node is a root with a single child.
    if (node->left != NULL) { // If root has only left child.
      bt->root = node->left;
    } else { // Root only has right child.
      bt->root = node->right;
    }
  } else if (node->left != NULL) { // Case 3: Node has a single left child.
    if (parent->left == node) { // If node is its parents left child.
      parent->left = node->left;
    } else { // Node is its parents right child.
      parent->right = node->left;
    }
  } else { // Case 4: Node has a single right child or is a leaf.
    if (parent->left == node) { // Node is its parent's left child.
      parent->left = node->right;
    } else { // Node is its parent's right child.
      parent->right = node->right;
    }
  }
  return 0;
}

