#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct bstnode {
	int item;
	struct bstnode *left;
	struct bstnode *right;
};

struct bst {
	struct bstnode *root;
	int count;
};

struct bst *bst_create(void)
{
	struct bst *t = malloc(sizeof(struct bst));
	t->root = NULL;
	t->count = 0;
	return t;
}

void destroy(struct bstnode *node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		free(node);
	}
}

void bst_destroy(struct bst *t)
{
	destroy(t->root);
	free(t);
}

int bst_searchhelp(struct bstnode *node, int val)
{
	if(node == NULL) return 0;
	if(node->item == val) return 1;
	if(node->item > val) return bst_searchhelp(node->left, val);
	else return bst_searchhelp(node->right, val);
}

int bst_search(struct bst *t, int val)
{
	return bst_searchhelp(t->root, val);
}



void left(struct bstnode *node, int num){
	if(num < node->item){
		if(node->left == NULL){
			struct bstnode *newnode = malloc(sizeof(struct bstnode));
			newnode->item =  num;
			newnode->left = newnode->right = NULL;
			node->left = newnode;
			return;
		}
		else{
			return left(node->left, num);
		}
	}
	if(num > node->item){
		if(node->right == NULL){
			struct bstnode *newnode = malloc(sizeof(struct bstnode));
			newnode->item =  num;
			newnode->left = newnode->right = NULL;
			node->right = newnode;
			return;
		}
		else{
			return left(node->right, num);
		}
	}
}

void bst_insert(int num, struct bst *t) // idk actually ngl
{
	
	if(bst_search(t, num) == 1) return;
	t->count += 1;
	if(t->root == NULL){
		struct bstnode *newnode = malloc(sizeof(struct bstnode));
		newnode->item = num;
		newnode->left = NULL;
		newnode->right = NULL;
		t->root = newnode;
		return;
	}
	// struct bstnode *node;
	// if(num < t->root->item){
	// 	node = t->root->left;
	// }
	// if(num > t->root->item){
	// 	node = t->root->right;
	// }
	return left(t->root, num);
}


void print(struct bstnode *node)
{
	if (node)
	{
		print(node->left);
		printf("%d ", node->item);
		print(node->right);
	}
}

void bst_print(struct bst *t)
{
	if (t->root)
	{
		print(t->root);
		printf("\n");
	}
}


int bst_min(struct bst *t)
{
	struct bstnode *current = t->root;
	while(current->left != NULL){
		current = current->left;
	}
	return (current->item);
}


int bst_max(struct bst *t)
{
	struct bstnode *node = t->root;

	while(node->right != NULL){
		node = node->right;
	}
	return (node->item);
}

int bst_heighthelp(struct bstnode *node)
{
	if(node == NULL) return -1;
	int left = bst_heighthelp(node->left);
	int right = bst_heighthelp(node->right);
	if(left > right) return left + 1;
	return right + 1;
	
}

int bst_height(struct bst *t)
{
	return bst_heighthelp(t->root);
}