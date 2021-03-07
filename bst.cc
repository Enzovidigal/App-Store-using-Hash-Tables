#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

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
        insert(root->left, appInfo);
    }
    else{

        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        insert(root->right, appInfo);
    }

    return root;


}

