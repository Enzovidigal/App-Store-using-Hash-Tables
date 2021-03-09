#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

// inserts category object in the bst
bst* insert(bst* root, app_info appInfo)
{
    //checks if the root is NULL
    if (root==NULL)
    {
        root = new bst;
        root->record = appInfo;
        return root;
    }

    //checks the alphabetical order of the app names and inserts into the bst
    if (strcmp(appInfo.app_name, root->record.app_name) < 0)
        root->left = insert(root->left, appInfo);

    else
        root->right = insert(root->right, appInfo);

    return root;
}

//prints out apps trough in order traversal
void traversePrintApps(bst* root)
{
    //checks if root is NULL
    if (root==NULL) {
        return;
    }

    //in order traversal
    traversePrintApps(root->left);
    cout << "\t" << root->record.app_name;
    traversePrintApps(root->right);
}

float* traverse_heap(bst* root, float* heap_array, int i)
{
    //checks if root is NULL
    if (root==NULL) {
        return heap_array;
    }

    //in order traversal
    traverse_heap(root->left, heap_array, i--);
    heap_array[i] = root->record.price;
    traverse_heap(root->right, heap_array, i--);

    return heap_array;
}

void traversePrintMax(bst* root, float rootMaxHeap)
{
    //checks if root is NULL
    if (root==NULL) {
        return;
    }

    //in order traversal
    traversePrintMax(root->left, rootMaxHeap);
    if (root->record.price==rootMaxHeap){
        cout << "\t" << root->record.app_name;
    }
    traversePrintMax(root->right, rootMaxHeap);
}

