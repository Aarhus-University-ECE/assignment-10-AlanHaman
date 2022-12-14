#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this

  // if/ else statement
  if(p == NULL) {
    return;

    //else we print the value of the node we are at, so print_list(p->next).
  } else {
    printf("%d ", p->value);
    print_list(p->next);

    return;
  }
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
  // if else statement, where if p=NULL we return 0
  if(p == NULL){
    return 0;

  // else we time the p-value with it self and add it with sum_squares(p->next)
  } else {
    return p->value*p->value + sum_squares(p->next);
  }

  return -1;
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3
  //If else statment, where if p is NULL we return NULL
  if (p == NULL) {
    return NULL;

    // else we run make_node, where the value is f of p->value and then map (p->next,f) as the next pointer
  } else {
    return make_node(f(p->value),map(p->next, f));
  } 
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
