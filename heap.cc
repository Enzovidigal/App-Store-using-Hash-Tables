#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

int node_counter(bst* root){
    if (root==NULL)
    {
        return 0;
    }
    else {
        int count_left = node_counter(root->left);
        int count_right = node_counter(root->right);
        return count_left + count_right + 1;
    }
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


