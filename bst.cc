#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

bst* insert(bst* root, app_info appInfo)
{
    if (root==NULL)
    {
        root = new bst;
        root->record = appInfo;
        return root;
    }

    if (strcmp(appInfo.app_name, root->record.app_name) < 0)
        root->left = insert(root->left, appInfo);

    else
        root->right = insert(root->right, appInfo);

    return root;
}

void traverse(bst* root)
{
    if (root==NULL)
        return;

    traverse(root->left);
    cout << root->record.app_name << endl;
    traverse(root->right);
}

