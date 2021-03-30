#include <string.h>
#include <iostream>
#include "defn.h"

using namespace std;

//declared functions
int hashFunction(char* key, int m);
int findPrime(int m);

int findPrime(int m){
    int k = 2*m;
    while (!testForPrime(k)){
        k++;
    }
    return k;
}

hash_table_entry** hashArray(int m){
    int k = findPrime(m);
    hash_table_entry** table = new hash_table_entry*[k];
    for (int i = 0; i < k; i++){
        table[i]=NULL;
    }
    return table;
}

void insertHT(hash_table_entry **t, bst* root, char* appName, int m){
    int p;

    hash_table_entry *oldHead;
    hash_table_entry *entry = new hash_table_entry[sizeof(findPrime(m))];

    while(strcmp(appName,root->record.app_name)!=0) {
        if (strcmp(appName, root->record.app_name) > 0) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    entry->app_node = root;
    strcpy(entry->app_name, root->record.app_name);
    entry->next=NULL;

    p = hashFunction(root->record.app_name,m); // Turns out we don’t need to use m; hash() uses it

    oldHead = t[p];
    t[p] = entry;
    t[p]->next = oldHead;
    entry = NULL;
    delete(entry);
    delete(oldHead);
}


int hashFunction(char* key, int m){
    int sum_ascii = 0;

    int i=0;
    while(key[i]!='\0'){
        sum_ascii = sum_ascii + int(key[i]);
        i++;
    }

    return sum_ascii % findPrime(m);
}

void freeHash(hash_table_entry** t, int m){
    for (int i=0; i<findPrime(m); i++) {
        delete(t[i]);
    }
}
