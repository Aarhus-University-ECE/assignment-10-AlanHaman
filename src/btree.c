#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  struct tree_node *t = malloc(sizeof(x));
  t-> item = x;

  return x;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  if (t==NULL){
    return 0;
  }
 
  if (t->item > x)
  {
    return remove (t->left);
  }
  if (t->item > x)
  {
    return remove (t->right);
  }
  else if (t->item==x) 
  {
    t=NULL;
  }
  return NULL;
}

int Contains(int x, struct tree_node *t) {
  if (t==NULL){
    return 0;
  }
  // Return true if the tree t contains item x. Return false otherwise.
 
  if (t->item > x)
  {
    return Contains (x,t->left);
  }
  if (t->item > x)
  {
    return Contains (x,t->right);
  }
  else if (t->item==x) 
  {
    return 1;
  }
  
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
    if (Full(t)==1) {
      t-> left = NULL;
      t-> right = NULL;
  }
  
  return NULL;
}

int Empty(struct tree_node *t) {
  // Test if empty
  if (t== NULL){
    return 1;
  }
    else
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  if (t==NULL){
  return 0;
  }
  else 
  return 1;
}
