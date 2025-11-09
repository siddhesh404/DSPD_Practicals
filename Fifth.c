#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *root = NULL;

struct node *createnode(){
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter any data : ");
    scanf("%d",&x);
    newnode->data = x;
    if(x==0) return 0;
    else{
        printf("\nEnter left node data : ");
        newnode->left = createnode();
        printf("\nEnter right node data : ");
        newnode->right = createnode();
        return newnode;
    }
}

void preorder(struct node *root){
    if(root==0) return;
    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root==0) return;
    else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root==0) return;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    printf("Creating a tree..");
    root = createnode();
    printf("\nPreorder Traversal : ");
    preorder(root);
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\nPostorder Traversal : ");
    postorder(root);
    return 0;
}