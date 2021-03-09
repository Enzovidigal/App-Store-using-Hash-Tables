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

    //returns tree
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

//converts bst to heap using in order traversal
float* traverse_heap(bst* root, float* heap_array)
{
    //checks if root is NULL
    if (root==NULL) {
        return 0;
    }

    //in order traversal
    traverse_heap(root->left, heap_array);
    heap_array[global_index++] = root->record.price;
    traverse_heap(root->right, heap_array);

    //returns heap array
    return heap_array;
}

//prints out apps with max price trough in order traversal
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

