#include <stdio.h>
#include <stdlib.h>
#include "../lib/seed.h"



typedef struct node {
	int key;
	struct node *left;
	struct node *right ;
	int height;
} node;

int get_height(node *root) {
	if (root == NULL){
		return -1;
	}
	return root-> height ;
}

int check_balance(node *root){
	if(abs(get_height(root -> left) - get_height(root -> right)) < 2)
		return 1 ;
	return 0;
}


node * alloc_node ( int data ) {
	node *temp = NULL;
	temp = malloc(sizeof(node));
	temp -> key = data;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> height = 0;
	return temp;

}
int max (int a, int b){
	return a > b ? a : b;
}
int set_height(node * root) {
	root -> height = max(get_height(root -> left), get_height (root -> right)) + 1;
	return root -> height ;
}

node * re_balance(node *root) {



}
node *left_rotate(node *root){
	node * temp;
	node *sub1;
	temp = root -> right;
	sub1 = temp -> left;
	temp -> left = root;
	root -> right = sub1;
	set_height(root);
	set_height(temp);
        return temp;	
}
node *right_rotate(node *root){
	node * temp;
	node *sub1;
	temp = root -> left ;
	sub1 = temp -> right;
	temp -> right = root;
	root -> left = sub1;
	set_height(root);
	set_height(temp);
        return temp;	
}
node *insert(node * root, int data) {
	if(root == NULL)
		return alloc_node(data);
	if(data < root -> key) {
		root -> left = insert (root -> left, data);
	}else if (data > root -> key) {
		root -> right = insert (root -> right, data);
	}
	set_height(root);
	if( !check_balance(root) ) {
		if (root -> left && data < root -> left -> key) {
			return right_rotate(root);
		}
		if (root -> right && data > root -> right -> key) {
			return left_rotate(root);
		}
		if (root -> right && data < root -> right -> key) {
			root -> right = right_rotate(root -> right);
			return left_rotate(root);
		}
		if (root -> left && data > root -> left -> key) {
			root -> left = left_rotate(root -> left);
			return right_rotate(root);
		}
	}
	return root;
}
node * find_successor(node *root) {
	node *temp = root -> right ;
	while (temp != NULL && temp -> left != NULL)
		temp = temp -> left ;
	return temp;
}
node *delete(node *root, int data){
	node *temp = NULL;
	int key ;
	if(root == NULL) {
		return NULL;
	}
	if(data < root -> key) {
		root -> left = delete (root -> left, data)  ;
		return root;
	} 

	set_height(root);

	if( !check_balance(root) ) {
		if (root -> left && data < root -> left -> key) {
			return right_rotate(root);
		}
		if (root -> right && data > root -> right -> key) {
			return left_rotate(root);
		}
		if (root -> right && data < root -> right -> key) {
			root -> right = right_rotate(root -> right);
			return left_rotate(root);
		}
		if (root -> left && data > root -> left -> key) {
			root -> left = left_rotate(root -> left);
			return right_rotate(root);
		}
	}
	return root;
}

int print(node *root) {
	if(root == NULL) {
		return ;
	}
	printf ("%d\n", root -> key);
	print(root -> left);
	print (root -> right);
	return 1;
}
int _print_t(node *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 10;
    int i;

    if (!tree) return 0;

    sprintf(b, "(%04d)", tree->key);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

int print_t(node *tree)
{
    char s[20][255];
    int i;
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

#define MAX_NODES 25

int main(int argc, char *argv[])
{
	int array[MAX_NODES], i;
	node *root = NULL;
	for(i=0; i < MAX_NODES; i++) {
		array[i] = i;
		printf ("%d\t", array[i]);
	}
	printf("\n");
	for(i=0; i < MAX_NODES; i++) {
		root = insert(root, array[i]);
	}
	print(root);
	printf("\n");
	delete(root, array[5]);
	delete(root, array[7]);
	delete(root, array[17]);
	delete(root, array[14]);
	delete(root, array[19]);
	print(root);
	printf("\n");
}

