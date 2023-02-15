/*
 * file: main.c
 * ------------
 * Initiates the knowledge base of restaurants from a file and 
 * runs the console interface.
 *
 * author: Max Turkot
 * version: 12/10/21
 */

#include "main.h"
#include "ArrayList.h"
#include "BinaryTree.h"
#include "console.h"
#include "readFile.h"

/*
 * Initiates binary trees of restaruants using readFile from restaurants.txt file. Calls 
 * console.
 */
int main() {
  BinaryTree *btName = createBinaryTree(NAME);
  BinaryTree *btCity = createBinaryTree(LOCATION);
  readFile("restaurants.txt", btName, btCity);

  runConsole(btName, btCity);

  return 0;
}
