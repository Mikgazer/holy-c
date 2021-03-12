#include "tree.h"

tree cons_tree(element e, tree l, tree r)
/* costruisce un albero che ha nella radice e; per sottoalberi
sinistro e destro l ed r rispettivamente */
{
	tree t;
	t = (NODO *) malloc(sizeof(NODO));
	t->value = e; 
	t->left = l; 
	t->right = r;
	return (t);
}

void showTree(tree t)
{
	if (t != NULL)
	{
		printf("%c", t->value);
		showTree(t->left);
		showTree(t->right);
	}
}

void preorder(tree t)
{
	if (t != NULL)
	{
		printf("%c", t->value);
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(tree t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%c", t->value);
	}
}

void inorder(tree t)
{
	if (t != NULL)
	{
		inorder(t->left);
		printf("%c", t->value);
		inorder(t->right);
	}
}

boolean member(element e, tree t)
{
	if (t == NULL) return false;
	else
		if (e == t->value) return true;
		else
			if (member(e, t->left)) return true;
			else return member(e, t->right);
}

int nnodi(tree t) {
	if (t == NULL) return 0;
	else
		return (1 + nnodi(t->left) + nnodi(t->left));
}

int height_aux(tree t)
{
	if (empty(t)) return 0;
	else return (1 + max(height_aux(left(t)),
		height_aux(right(t))));
}

int height(tree t)
{
	if (empty(t)) return 0;
	else return (max(height_aux(left(t)),
		height_aux(right(t))));
}

boolean empty(tree t) {
	if (t == NULL) return true;
	else return false;
}

element root(tree t)
/* restituisce la radice dell'albero t */
{
	if (empty(t)) abort();
	else return(t->value);
}
tree left(tree t)
/* restituisce il sottoalbero sinistro */
{
	if (empty(t)) return(NULL);
	else return(t->left);
}
tree right(tree t)
/* restituisce il sottoalbero destro */
{
	if (empty(t)) return(NULL);
	else return(t->right);
}

tree emptytree(void)
/* inizializza un albero vuoto */
{
	return NULL;
}

/* albero binario di ricerca senza duplicazioni */
tree ord_ins(element e, tree t)
{

	if (empty(t)) /* inserimento */
		return cons_tree(e, emptytree(), emptytree());
	else
	{
		if (isLess(e, root(t)))
			t->left = ord_ins(e, left(t));
		else 
			t->right = ord_ins(e, right(t));
		return t;
	}
}
