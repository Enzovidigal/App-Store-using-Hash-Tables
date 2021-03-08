#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defn.h"

using namespace std;

#define CELLS_LEN 30 // size of double pointer
#define MAX_LEN 255 // size of single pointer

//declared object
app_info* appInfo = new app_info[sizeof(appInfo)*255];

int main(int argc, char* argv[]) {
    char categoriesNumber[15]; //number of app categories
    char categoryName[25]; //name of each category
    char appsNumber[15]; //number of apps to add to myAppStore
    char appName[50]; //name of each app
    char version[10]; //version of each app
    char size[10]; //size of each app
    char units[4]; //MB or GB
    char price[50]; //price of each app
    int index = 0;  //index of category
    char queriesNumber[10]; //number of queries to be read
    char query_str[255]; //full query
    int count; //counts if category doesn't exist


    //reads the first line in the text file and gets the number of categories
    fgets(categoriesNumber, sizeof(categoriesNumber), stdin);

    //declare categories object
    categories* cat_name = new categories[sizeof(cat_name)*255];



    //initializes category object
    for (int i=0; i<atoi(categoriesNumber);i++){
        fgets(categoryName, sizeof(categoryName), stdin);

        //removes newline
        //categoryName[strcspn(categoryName, "\n")] = '\0';

        strcpy(cat_name[i].category, categoryName);
        cat_name[i].root=NULL;
    }
    //gets number of apps to be stored
    fgets(appsNumber, sizeof(appsNumber), stdin);


    //loops until all apps are in myAppStore
    for (int i=0; i < atoi(appsNumber);i++){
        // store each app on the object appinfo

        //gets category name
        fgets(categoryName, sizeof(categoryName), stdin);
        strcpy(appInfo[i].category,categoryName);

        //gets app name
        fgets(appName, sizeof(appName), stdin);
        strcpy(appInfo[i].app_name,appName);

        //gets version
        fgets(version, sizeof(version), stdin);
        strcpy(appInfo[i].version,version);

        //gets size
        fgets(size, sizeof(size), stdin);
        appInfo[i].size = atof(size);

        //gets unit
        fgets(units, sizeof(units), stdin);
        strcpy(appInfo[i].units,units);

        //gets price
        fgets(price, sizeof(price), stdin);
        appInfo[i].price = atof(price);


        //finds the index in which category name is stored
        for (int j =0; j<atoi(categoriesNumber); j++){
            if (strcmp(cat_name[j].category, categoryName)==0){
                index=j;
            }
        }

        //inserts in binary search tree
        cat_name[index].root = insert(cat_name[index].root , appInfo[i]);
    }

    // gets number of queries to be read
    fgets(queriesNumber, sizeof(queriesNumber), stdin);

    // runs and executes each query
    for (int i = 0; i < atoi(queriesNumber); i++) {

        //gets the number of queries
        fgets(query_str, sizeof(query_str), stdin);
        cout << query_str;

        //gets the first command of the query
        string token = strtok(query_str, " ");
        string *cells = new string[sizeof(CELLS_LEN)*2];
        cells[0] = token;

        //checks if the first command is "print-apps"
        if (cells[0]== "print-apps") {
            token = strtok(NULL, " ");
            cells[1] = token;

            //finds name of the category
            token = strtok(NULL, """");
            token.erase(0,1);
            token.erase( token.end()-2, token.end()-1);
            //token.erase(token.end()-1,token.end());
            cells[2] = token;

            //finds index of category
            count = 0;
            for (int j =0 ; j < atoi(categoriesNumber); j++){
                if (cat_name[j].category == cells[2]){
                    index=j;
                }
                else{
                    count++;
                }
            }

            //prints out if category does not exist
            if (count==atoi(categoriesNumber)){
                cout << "Category " << cells[2] << " not found." << endl;
                cout << endl;
            }

            else{
                //prints out if there are no apps in category
                if (cat_name[index].root==NULL){
                    cout << "Category " << cat_name[index].category << " no apps found." << endl;
                }
                //prints apps
                else{
                    cout << "Category: " << cat_name[index].category << endl;
                    traverse(cat_name[index].root);
                }
            }
        }

        //checks if the first command is "find"
        else if (cells[0]== "find"){
            token = strtok(NULL, " ");
            cells[1] = token;

            //checks if the second command is "max"
            if (cells[1]=="max"){
                cout << "DONE";
            }
        }
    }
    return 0;
}
