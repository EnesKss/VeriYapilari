#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *right;
    struct node *left;
    int data;
};
typedef struct node *BTREE;

void inorder(BTREE root){
    if(root != NULL){
        inorder(root->left);
        printf("%4d",root->data);
        inorder(root->right);
    }
}
BTREE newnode(int x){
    BTREE p =(BTREE)malloc(sizeof(struct node));
    p->data=x;
    p->left=p->right=NULL;
}

void preorder(BTREE root){
    if(root !=NULL){
    printf("%4d",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void postorder(BTREE root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%4d",root->data);
    }
}
BTREE insert(BTREE root,int x){
    if(root==NULL) root=newnode(x);
    else{
        if(x<root->data){
            root->left=insert(root->left,x);
        }
        else{
            root->right=insert(root->right,x);
        }
    }
    return root;
}

int main()
{
    BTREE myroot =NULL;
    int x;
    scanf("%d",&x);
    while (x!=-1){
        myroot=insert(myroot,x);
        scanf("%d",&x);
    }
    inorder(myroot);
    printf("\n");
    postorder(myroot);
    printf("\n");
    preorder(myroot);

    return 0;
}
