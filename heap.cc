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

//builds a max heap from an array
float* build_Max_Heap(float* heapArray, int n)
{
    //gets parent of leaf node
    int indexNode = (n/2) - 1;

    //loops from indexNode to 0
    for (int i = indexNode; i >= 0; i--) {
        //calls max-heapify function
        max_heapify(heapArray, i, n);
    }

    //returns max heap
    return heapArray;
}

void max_heapify(float* heapArray, int i, int n)
{
    //initializes positions of the heap
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left<n && heapArray[left]>heapArray[largest])
        largest = left;

    if (right<n && heapArray[right]>heapArray[largest])
        largest = right;

    //checks if largest at the root
    if (largest != i) {
        //swaps largest node with root
        swap(heapArray[i], heapArray[largest]);


        max_heapify(heapArray, n, largest);
    }
}



