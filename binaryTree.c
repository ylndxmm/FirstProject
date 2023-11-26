#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node_type {
	char data;
	struct node_type* lchild;
	struct node_type* rchild;
}node_type;
typedef struct tree_type {
	struct node_type* root;
	int num;
}tree_type;

void read(char* ch)
{
	scanf_s("%c",ch);
	getchar();
}

node_type* create_node(char ch)
{
	node_type* p;
	p = (node_type*)malloc(sizeof(node_type));
	p->data = ch;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

node_type* create_root()
{
	node_type* p;
	printf("请输入根节点：");
	char ch;
	read(&ch);
	p = create_node(ch);
	return p;
}

void create_tree(node_type* root)
{
	/*node_type* p;
	char ch;
	read(&ch);
	if (ch == ' ')
		return NULL;
	p = create_node(ch);
	printf("输入%c左子树：",p->data);
	p->lchild = create_tree();
	printf("输入%c右子树：",p->data);
	p->rchild = create_tree();
	return p;*/
	char ch;
	node_type* temp;
	temp = (node_type*)malloc(sizeof(node_type));

	printf("请输入%c的左子树：",root->data);
	read(&ch);
	temp = NULL;
	if(ch!=' ')
		temp = create_node(ch);
	root->lchild = temp;
	if (root->lchild != NULL)
		create_tree(root->lchild);

	printf("请输入%c的右子树：",root->data);
	read(&ch);
	temp = NULL;
	if (ch != ' ')
		temp = create_node(ch);
	root->rchild = temp;
	if (root->rchild != NULL)
		create_tree(root->rchild);
}

void inorder(node_type*root)
{
	if (root->lchild != NULL)
		inorder(root->lchild);
	printf("%c ", root->data);
	if (root->rchild != NULL)
		inorder(root->rchild);
}

void preorder(node_type* root)
{
	printf("%c ", root->data);
	if (root->lchild != NULL)
		preorder(root->lchild);
	if (root->rchild != NULL)
		preorder(root->rchild);
}

void postorder(node_type* root)
{
	if (root->lchild != NULL)
		postorder(root->lchild);
	if (root->rchild != NULL)
		postorder(root->rchild);
	printf("%c ", root->data);
}

node_type* Binary_Sort_Tree_Insert(node_type*root, node_type* new_node)
{
	node_type* p;
	p = root;
	while (p != NULL)
	{
		if (p->data > new_node->data)
		{
			if (p->lchild == NULL)
			{
				p->lchild = new_node;
				break;
			}
			else
				p = p->lchild;
		}
		else
		{
			if (p->rchild == NULL)
			{
				p->rchild = new_node;
				break;
			}
			else
				p = p->rchild;
		}
	}
	return root;
}

int MAX(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int Tree_High(node_type* root)
{
	int tree_high = 0;
	if (root == NULL)
		return 0;
	else
		tree_high++;
	if(root->lchild!=NULL||root->rchild!=NULL)
		tree_high = tree_high + MAX(Tree_High(root->lchild), Tree_High(root->rchild));
	return tree_high;
}

node_type* FanXu(node_type* root)
{
	node_type* temp;
	if (root != NULL)
	{
		temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
	}
	if (root->lchild != NULL)
		FanXu(root->lchild);
	if (root->rchild != NULL)
		FanXu(root->rchild);
	return root;
}

void main()
{
	node_type* root, * new_node;
	root = (node_type*)malloc(sizeof(node_type));
	root = create_root();
	printf("输入一组无序数：");
	for (int i = 0;; i++)
	{
		char x;
		read(&x);
		if (x == '\n')
			break;
		new_node = create_node(x);
		Binary_Sort_Tree_Insert(root, new_node);
	}
	FanXu(root);
	printf("反序后中序遍历的结果为：");
	inorder(root);
}