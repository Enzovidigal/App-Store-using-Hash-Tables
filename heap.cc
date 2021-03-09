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

float* build_Max_Heap(float* heapArray, int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(heapArray, n, i);
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



