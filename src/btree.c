#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node* Insert(int x, struct tree_node* t) {
	// Insert item x into the tree t

	if (t == NULL) {
		struct tree_node* temp = malloc(sizeof(struct tree_node));
		temp->item = x;
		temp->left = NULL;
		temp->right = NULL;
		t = temp;
		printf("%d\n", t->item);
		return temp;
	}

	if (x == t->item) {
		struct tree_node* temp = malloc(sizeof(struct tree_node));
		temp->item = x;
		temp->left = t->left;
		temp->right = NULL;
		t->left = temp;
		return t;
	}

	if (x < t->item) {
		t->left = Insert(x, t->left);
		return t;
	} else if (x > t->item) {
		t->right = Insert(x, t->right);
		return t;
	}
}

struct tree_node* Remove(int x, struct tree_node* t) {
	// Remove one item from the tree t



	if (t == NULL) {
		return t;
	}

	if (Contains(x, t) == 0) {
		return t;
	} else {

		if (x == t->item) {

			if (t->left == NULL && t->right == NULL) {
				struct tree_node* temp = t->right;
				free(t);
				return temp;
			}

			if (t->left == NULL && t->right != NULL) {
				struct tree_node* temp = t->right;
				free(t);
				return temp;
			}
			/*Same concept, but for left child existing*/
			if (t->right == NULL && t->left != NULL) {
				struct tree_node* temp = t->left;
				free(t);
				return temp;
			}
			else if (t->left != NULL && t->right != NULL) {
				struct tree_node* temp = t->right;
				while (temp->left != NULL) {
					temp = temp->left;
				}
				t->item = temp->item;
				// Remove(x, temp);
				free(temp);
				return t;
			}
		}
		
		else if (x < t->item) {
			t->left = Remove(x, t->left);
			return t;
		} else if (x > t->item) {
			t->right = Remove(x, t->right);
			return t;
		}
	}
}

int Contains(int x, struct tree_node* t) {

	

	
	while (t != NULL) {
		printf("%d -> ", t->item); // For aesthetics and testing
		if (x == t->item) {
			return 1;
		}

		if (x < t->item) {
			t = t->left;
		} else if (x > t->item) {
			t = t->right;
		}
	}
	printf("\n"); // FOr aesthetics
	return 0;
}

struct tree_node* Initialize(struct tree_node* t) {
	// Create an empty tree
	t = NULL;
	return t;
}

int Empty(struct tree_node* t) {
	if (t == NULL) {
		return 1;
	}
	return 0;
}

int Full(struct tree_node* t) {
	return 0;
}
