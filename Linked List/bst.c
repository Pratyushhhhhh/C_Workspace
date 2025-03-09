#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int data;
    struct bst *left ,*right;
}bst;
 
bst *insert(bst *root,int key)
{
    if(root==NULL)
    {
        bst *temp=(bst*)malloc(sizeof(bst));
        temp->left=temp->right=NULL;
        temp->data=key;
        return temp;
    }
    if (key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    else
        printf("Duplicates are not allowed");
    
    return root;
}
bst *inorderpre(bst*root)//inorder predecessor is always rightmost child of LST
{
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
bst *delete(bst *root,int value)
{
    bst*pred;
    if(root==NULL)
    {
    return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(value<root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=delete(root->right,value);
    }
    else{
        pred=inorderpre(root);
        root->data=pred->data;
        root->left=delete(root->left,pred->data);
    }
 return root;
}
void preorder(bst *root)
{
    if(root==NULL)
    return;
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(bst *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}
void postorder(bst *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
}
bst* search(bst *root,int val)
{
    while(root!=NULL&&root->data!=val)
    root=val<root->data?root->left:root->right;
    return root;
}
int findceil(bst *root,int key)
{
    int ceil=-1;
    while (root!=NULL)
    {
        if(key==root->data)
        {
            ceil=root->data;
            return ceil;
        }
        if (key>root->data)
        {
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
        
    }
    return ceil;
    }
void kth_small_large(bst *root, int *cs, int k, int *sm, int *cl, int kl, int *lr) {
    if (root == NULL)
        return;

    // Find k-th largest (right-root-left traversal)
    kth_small_large(root->right, cs, k, sm, cl, kl, lr);

    (*cl)++; // Increment largest counter
    if (*cl == kl) {
        *lr = root->data;
    }

    (*cs)++; // Increment smallest counter
    if (*cs == k) {
        *sm = root->data;
    }

    // Find k-th smallest (left-root-right traversal)
    kth_small_large(root->left, cs, k, sm, cl, kl, lr);
}
int countNodes(bst *root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    bst *root= NULL;
    printf("Enter 8 values\n");
    int n;
    for(int i=0;i<8;i++)
    {
        scanf("%d",&n);
        root=insert(root,n);
    }
    preorder(root);
    printf("\n");
    inorder(root);   
    printf("\n");
    postorder(root);
    int k=2;
    int cs=0,cl=0;
    int sm,lr;
    int n2=countNodes(root);
    /*
    int kl=n2-k;//(bst *root, int *cs, int k, int *sm, int *cl, int kl, int *lr
    kth_small_large(root,&cs,k,&sm,&cl,kl,&lr);
    printf("Kth smallest element is %d\n",sm);
     printf("Kth largest element is %d\n",lr);
    if(search(root,50)==NULL){
        printf("\nNot found\n");
    }
    else
        printf("\nFound\n");
    int x=findceil(root,8);
    printf("Ceil is %d\n",x);
*/
printf("Enter node to be deleted");
int y;
scanf("%d",&y);
root=delete(root,y);
inorder(root);
}

