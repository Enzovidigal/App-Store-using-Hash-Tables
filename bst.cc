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
void traverse(bst* root)
{
    //checks if root is NULL
    if (root==NULL) {
        return;
    }

    //in order traversal
    traverse(root->left);
    cout << "\t" << root->record.app_name;
    traverse(root->right);
}

