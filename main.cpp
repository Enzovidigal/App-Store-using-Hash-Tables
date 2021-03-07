#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defn.h"
//#include "bst.cc"
//#include "prime.cc"

using namespace std;

//declared object
app_info* appInfo = new app_info[sizeof(appInfo)*2];
bst* root;

//declared functions

int main(int argc, char* argv[]) {
    char categoriesNumber[12]; //number of app categories
    char categoryName[25]; //name of each category
    char appsNumber[12]; //number of apps to add to myAppStore
    char appName[100]; //name of each app
    char version[10]; //version of each app
    char size[10];
    char units[4];
    char price[10];


    //reads the first line in the text file and gets the number of categories
    fgets(categoriesNumber, sizeof(categoriesNumber), stdin);

    //declare categories object
    categories* cat_name = new categories[atoi(categoriesNumber)];

    //initializes category object
    for (int i=0; i<atoi(categoriesNumber);i++){
        fgets(categoryName, sizeof(categoryName), stdin);
        strcpy(cat_name[i].category, categoryName);
        cat_name[i].root=NULL;
        cout << cat_name[i].category;
    }


    fgets(appsNumber, sizeof(appsNumber), stdin);

    cout << appsNumber;

    for (int i=0; i < atoi(appsNumber);i++){
            // store each app on the object appinfo
            fgets(categoryName, sizeof(categoryName), stdin);
            strcpy(appInfo[i].category,categoryName);

            fgets(appName, sizeof(appName), stdin);
            strcpy(appInfo[i].app_name,appName);

            fgets(version, sizeof(version), stdin);
            strcpy(appInfo[i].version,version);

            fgets(size, sizeof(size), stdin);
            appInfo[i].size = atof(size);

            fgets(units, sizeof(units), stdin);
            strcpy(appInfo[i].units,units);

            fgets(price, sizeof(price), stdin);
            appInfo[i].price = atof(price);

            //organizing binary search tree
            root = insert(root, appInfo[i]);
    }

    traverse(root);
    return 0;
}
