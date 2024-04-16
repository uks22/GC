#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*middle;
    struct node*right;
};
struct node*insert(struct node*root,int d)
{
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=d;
        root->left=root->right=NULL;      
    }
    else
    {
        if(root->data<d)
        {
            root->right=insert(root->right,d);
        }
        else if(root->data>d)
        {
            root->left=insert(root->left,d);
        }
    }
    return root;
}
void morristraversal(struct node*root)
{
    if(root==NULL)return;
    struct node*curr=root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            printf("%d ",curr->data);
            curr=curr->right;
        }
        else
        {
            struct node*l=curr->left;
            while(l->right&&l->right!=curr)
            {
                l=l->right;
            }
            if(l->right)
            {
                l->right=NULL;
                printf("%d ",curr->data);
                curr=curr->right;
            }
            else
            {
                l->right=curr;
                curr=curr->left;
            }
        }
    }
}

void main()
{
    int n;
    scanf("%d",&n);
    struct node*root=NULL;
    for(int i=0;i<n;i++)
    {
        int d;
        scanf("%d",&d);
        root=insert(root,d);
    }
    morristraversal(root);
}