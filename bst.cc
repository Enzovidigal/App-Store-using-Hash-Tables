#include <string.h>
#include "defn.h"

bst* insert(bst* root, app_info appInfo)
{
    if (root==NULL)
    {
        root = new bst;
        // Insert the first node, if root is NULL.
        root->record = appInfo;
        return root;
    }

    // Insert data.
    if (strcmp(appInfo.app_name, root->record.app_name)<0)
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = insert(root->left, appInfo);
    }

    else{

        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = insert(root->right, appInfo);
    }
    return root;
}

