//2. DELETE A NODE  FROM AN AVL TREE.

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
	int ht;
};
struct node* insert(struct node *, int);
struct node* Delete(struct node *, int);
void preorder(struct node *);
void inorder(struct node *);
int height(struct node *);
struct node* rotateright(struct node *);
struct node* rotateleft(struct node *);
struct node* RR(struct node *);
struct node* LL(struct node *);
struct node* LR(struct node *);
struct node* RL(struct node *);
int BF(struct node *);

int main()
{
	struct node *root = NULL;
	int x, n, i, op;
	do {
		printf("**MAIN MENU**\n");
		printf("\n1. Insert:");
		printf("\n2. Delete:");
		printf("\n3. Display:");
		printf("\n4. Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				printf("\nEnter tree data:");
				scanf("%d", &x);
				root = insert(root, x);
				break;
			case 2:
				printf("\nEnter a data:");
				scanf("%d", &x);
				root = Delete(root, x);
				break;
			case 3:
				printf("\n\nInorder sequence:\n");
				inorder(root);
				printf("\n");
				break;
		}
	} while (op != 4);
	return 0;
}

struct node* insert(struct node *T, int x)
{
	if (T == NULL)
	{
		T = (struct node *) malloc(sizeof(struct node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}
	else
	if (x > T->data)
	{
		T->right = insert(T->right, x);
		if (BF(T) == -2)
			if (x > T->right->data)
				T = RR(T);
			else
				T = RL(T);
	}
	else
	if (x < T->data)
	{
		T->left = insert(T->left, x);
		if (BF(T) == 2)
			if (x < T->left->data)
				T = LL(T);
			else
				T = LR(T);
	}

	T->ht = height(T);
	return (T);
}

struct node* Delete(struct node *T, int x)
{
	struct node * p;
	if (T == NULL)
	{
		return NULL;
	}
	else
	if (x > T->data)
	{
		T->right = Delete(T->right, x);
		if (BF(T) == 2)
			if (BF(T->left) >= 0)
				T = LL(T);
			else
				T = LR(T);
	}
	else
	if (x < T->data)
	{
		T->left = Delete(T->left, x);
		if (BF(T) == -2)
			if (BF(T->right) <= 0)
				T = RR(T);
			else
				T = RL(T);
	}
	else
	{
		if (T->right != NULL)
		{
			p = T->right;
			while (p->left != NULL)
				p = p->left;
			T->data = p->data;
			T->right = Delete(T->right, p->data);
			if (BF(T) == 2)
				if (BF(T->left) >= 0)
					T = LL(T);
				else
					T = LR(T);
		}
		else
			return (T->left);
	}

	T->ht = height(T);
	return (T);
}

int height(struct node *T)
{
	int lh, rh;
	if (T == NULL)
		return (0);
	if (T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;
	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;
	if (lh > rh)
		return (lh);
	return (rh);
}

struct node* rotateright(struct node *x)
{
	struct node * y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return (y);
}

struct node* rotateleft(struct node *x)
{
	struct node * y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);
	return (y);
}

struct node* RR(struct node *T)
{
	T = rotateleft(T);
	return (T);
}

struct node* LL(struct node *T)
{
	T = rotateright(T);
	return (T);
}

struct node* LR(struct node *T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);
	return (T);
}

struct node* RL(struct node *T)
{
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return (T);
}

int BF(struct node *T)
{
	int lh, rh;
	if (T == NULL)
		return (0);

	if (T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;

	return (lh - rh);
}

void inorder(struct node *T)
{
	if (T != NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d), ", T->data, BF(T));
		inorder(T->right);
	}
}