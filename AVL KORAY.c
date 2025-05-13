#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node*left;
	struct node*right;
	int data;
	int height;
};
typedef struct node avltree;

avltree*newnode(int data)
{
	avltree*root=(avltree*)malloc(sizeof(avltree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	root->height=0;
	return root;
}
int height(avltree*root)
{
	if(root==NULL)
		return -1;
	int leftH,rightH;
	leftH=height(root->left);
	rightH=height(root->right);
	if(rightH>leftH)
		return rightH+1;
	else
		return leftH+1;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

avltree*insert(avltree*root,int data)
{
	if(root==NULL)
		return newnode(data);
	if(data>root->data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
	return root;
}
avltree*rightrotate(avltree*root)
{
	avltree*temp=root->left;
	root->left=temp->right;
	temp->right=root;
	root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}
avltree*leftrotate(avltree*root)
{
	avltree*temp=root->right;
	root->right=temp->left;
	temp->left=root;
	root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}
avltree*rightleftrotate(avltree*z)
{
	z->right=rightrotate(z->right);
	return leftrotate(z);
}
avltree*leftrightrotate(avltree*z)
{
	z->left=leftrotate(z->left);
	return rightrotate(z);
}

avltree*insertToAVL(avltree*tree,int data)
{
	if(tree!=NULL)
	{
		if(data<tree->data)
			tree->left=insertToAVL(tree->left,data);
		else if(data>tree->data)
			tree->right=insertToAVL(tree->right,data);
		else
			return tree;

		tree->height=max(height(tree->left),height(tree->right))+1;

		if(height(tree->left)-height(tree->right)>1&&data<tree->left->data)
			return rightrotate(tree->left);
		if(height(tree->left)-height(tree->right)>1&&data>tree->left->data)
			return leftrightrotate(tree);
		if(height(tree->left)-height(tree->right)<-1&&data>tree->right->data)
			return leftrotate(tree->right);
		if(height(tree->left)-height(tree->right)<-1&&data<tree->right->data)
			return rightleftrotate(tree);
	}
	else
		tree=newnode(data);
	return tree;
}


void preorder(avltree*root)
{
	if(root!=NULL)
	{
		printf("%3d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


int main()
{
	avltree*p=NULL;
	int i,adet,deger,ekl;
	printf("agaca kac adet dugum ekleyeceksiniz : ");
	scanf("%d",&adet);
	for(i=0;i<adet;i++)
	{
		printf("eklenecek degeri giriniz : ");
		scanf("%d",&deger);
		p=insert(p,deger);
	}
	printf("eklenecek dugumun degerini giriniz : ");
	scanf("%d",&ekl);
	preorder(p);
	p=insertToAVL(p,ekl);
	printf("\n");
	preorder(p);




	return 0;
}
