#include <string.h>
#include <iostream>


/*
void insertHT( struct node **T, int k, int m ){
    int p;
    struct node *oldHead;
    p = hash( k ); // Turns out we don’t need to use m; hash() uses it
    oldHead = T[ p ];
    T[ p ] = (struct node *) malloc( sizeof( struct node ) );
    T[ p ]->key = k;T[ p ]->next = oldHead;
}
 */