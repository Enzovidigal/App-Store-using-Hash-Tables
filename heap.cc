#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

//counts number of nodes in the bst
int node_counter(bst* root){
    if (root==NULL)
    {
        return 0;
    }

    else {
        //counts number of nodes in the left side of the tree
        int count_left = node_counter(root->left);

        //counts number of nodes in the right side of the tree
        int count_right = node_counter(root->right);

        //return sum
        return count_left + count_right + 1;
    }
}

float* build_Max_Heap(float* heapArray, int length)
{
    // Index of last non-leaf node
    int startIdx = (length / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(heapArray, length, i);
    }

    return heapArray;
}

void heapify(float* heapArray, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && heapArray[l] > heapArray[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && heapArray[r] > heapArray[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);

        // Recursively heapify the affected sub-tree
        heapify(heapArray, n, largest);
    }
}



