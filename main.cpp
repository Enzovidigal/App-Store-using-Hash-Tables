#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defn.h"
//#include "prime.cc"

using namespace std;

//declared object
app_info* appInfo = new app_info[sizeof(appInfo)*2];

//declared functions

int main(int argc, char* argv[]) {
    char categoriesNumber[12]; //number of app categories
    char categoryName[255]; //name of each category
    char appsNumber[12]; //number of apps to add to myAppStore

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

    for (int i=0; i<atoi(appsNumber);i++){
        
    }


    return 0;
}
