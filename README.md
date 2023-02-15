# Complex Data Structure Simulation of Yelp  App

Program focuses on providing information to people who are trying to find a restaurant, simulating a subset of Yelp app features. It reads restaurant data from a file storing it in a binary search trees and linked lists. User may interact with the system by printing restaurant information, adding, retrieving, and removing restaurants. 

## How to start
Run make command, and then run created p2 executable.

## How to use: 
Available commands include:
- `print` or `p`:     prints all restaurants in the knowledge base.
- `add` or `a`:      adds a new restaurant to all indexing structures.
- `write` of `w`:    writes restaurants in the knowledge base to a file.
- `remove` or `r`: removes restaurant(s) from all indexing structures, including duplicates.
- `exit` or `x`:       exits the program. 

## Features implemented
- Restaurants are saved to two binary search trees, ordered by name and location, respectively.
- Print command prints restaurants, sorted by name (from the first binary tree).
- Add command takes parameters, each on new line, to add a new restaurant to both binary trees.
- Write command writes restaurants to the file, sorted by name (from the first binary tree).
- Remove command removes restaurants that match by name and location from all indexing structures (array lists of both trees), and removes the node from each tree once the array lists are empty. Duplicates in the array lists are also removed.