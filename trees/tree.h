#include "element.h"
typedef struct NODO
{
	element value;
	struct nodo *left, *right;
} NODO;

typedef NODO * tree;


/*PRIMITIVE*/
boolean empty(tree);
tree emptytree(void);
element root(tree);
tree left(tree);
tree right(tree);
tree cons_tree(element, tree, tree);

/*DERIVATE*/
tree ord_ins(element, tree);
boolean member(element, tree);
element sum(tree);
void showTree(tree);
void preorder(tree);
void postorder(tree);
void inorder(tree);
int height(tree t);
int nnodes(tree);
//int balance(tree t);
