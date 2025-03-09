#include <stdio.h>
#include <stdlib.h>
// Definition of the Binary Search Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
// Function to find the node with the second highest data
void findSecondHighest(struct Node *root, int *count, int *secondHighest)
{
    if (root == NULL || *count >= 2)
    {
        return;
    }
    findSecondHighest(root->right, count, secondHighest); // Traverse right subtree
    (*count)++;
    if (*count == 2)
    {
        *secondHighest = root->data;
        return;
    }
    findSecondHighest(root->left, count, secondHighest); // Traverse left subtree
}
// Function to find the minimum value node in a BST
struct Node *findMin(struct Node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node to be deleted found
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to count total number of nodes with a common parent
int countNodesWithCommonParent(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (root->left != NULL && root->right != NULL)
    {
        count = 2;
    }
    else if (root->left != NULL || root->right != NULL)
    {
        count = 1;
    }
    return count + countNodesWithCommonParent(root->left) + countNodesWithCommonParent(root->right);
}

// Function to find the height of the BST
int findHeight(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to count total number of nodes on the left-hand side of the root
int countLeftNodes(struct Node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return 0;
    }
    int count = 0;
    struct Node *temp = root->left;
    while (temp != NULL)
    {
        count++;
        temp = (temp->left != NULL) ? temp->left : temp->right;
    }
    return count;
}

// Function to perform in-order traversal
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main menu-driven program
int main()
{
    struct Node *root = NULL;
    int choice, data, secondHighest, count, key;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Find Second Highest Data\n");
        printf("3. Delete a Node\n");
        printf("4. Count Nodes with Common Parent\n");
        printf("5. Find Height of BST\n");
        printf("6. Count Nodes on Left-Hand Side of Root\n");
        printf("7. Display In-Order Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            secondHighest = -1;
            count = 0;
            findSecondHighest(root, &count, &secondHighest);
            if (count >= 2)
            {
                printf("Second highest data: %d\n", secondHighest);
            }
            else
            {
                printf("Not enough nodes to determine the second highest.\n");
            }
            break;
        case 3:
            printf("Enter the node to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 4:
            count = countNodesWithCommonParent(root);
            printf("Total nodes with common parent: %d\n", count);
            break;
        case 5:
            printf("Height of BST: %d\n", findHeight(root));
            break;
        case 6:
            printf("Total nodes on left-hand side of root: %d\n", countLeftNodes(root));
            break;
        case 7:
            printf("In-order Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 8:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
