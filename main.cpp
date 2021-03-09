#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defn.h"

using namespace std;

#define CELLS_LEN 30 // size of double pointer

//declared object
app_info* appInfo = new app_info[sizeof(appInfo)*255];

int main(int argc, char* argv[]) {
    char categoriesNumber[15]; //number of app categories
    char categoryName[100]; //name of each category
    char appsNumber[15]; //number of apps to add to myAppStore
    char appName[200]; //name of each app
    char version[20]; //version of each app
    char size[10]; //size of each app
    char units[4]; //MB or GB
    char price[50]; //price of each app
    int index = 0;  //index of category
    char queriesNumber[10]; //number of queries to be read
    char query_str[255]; //full query
    int count; //counts if category doesn't exist
    string tempName; //name of each category without quotes

    //reads the first line in the text file and gets the number of categories
    fgets(categoriesNumber, sizeof(categoriesNumber), stdin);

    //declare categories object
    categories* cat_name = new categories[sizeof(cat_name)*255];

    //initializes category object
    for (int i=0; i<atoi(categoriesNumber);i++){
        fgets(categoryName, sizeof(categoryName), stdin);

        //removes newline
        categoryName[strcspn(categoryName, "\n")] = '\0';

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
        categoryName[strcspn(categoryName, "\n")] = '\0';
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
            cells[2] = token;
            cells[2].erase(cells[2].end()-1, cells[2].end());

            token.erase(0,1);
            token.erase( token.end()-2, token.end()-1);
            token.erase(token.end()-1,token.end());
            tempName = token;

            //finds index of category
            count = 0;
            for (int j =0 ; j < atoi(categoriesNumber); j++){
                if (cat_name[j].category == tempName){
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
                    cout << "Category " << cells[2] << " no apps found." << endl;
                    cout << endl;
                }
                //prints apps
                else{
                    cout << "Category: " << cells[2] << endl;
                    traversePrintApps(cat_name[index].root);
                    cout << endl;
                }
            }
        }

        //checks if the first command is "find"
        else if (cells[0]== "find"){
            token = strtok(NULL, " ");
            cells[1] = token;

            //checks if the second command is "max"
            if (cells[1]=="max"){

                token = strtok(NULL, " ");
                cells[2] = token;

                token = strtok(NULL, " ");
                cells[3] = token;

                //finds name of the category
                token = strtok(NULL, """");
                cells[4] = token;
                cells[4].erase(cells[4].end()-1, cells[4].end());

                token.erase(0,1);
                token.erase( token.end()-2, token.end()-1);
                token.erase(token.end()-1,token.end());
                tempName = token;

                //finds index of category
                count = 0;
                for (int j =0 ; j < atoi(categoriesNumber); j++){
                    if (cat_name[j].category == tempName){
                        index=j;
                    }
                    else{
                        count++;
                    }
                }

                //builds heap array
                float* price_heap = new float[node_counter(cat_name[index].root)];

                //initializes heap array of prices
                price_heap = traverse_heap(cat_name[index].root, price_heap, node_counter(cat_name[index].root));

                //builds max heap
                price_heap = build_Max_Heap(price_heap, node_counter(cat_name[index].root));

                //prints out if category does not exist
                if (count==atoi(categoriesNumber)){
                    cout << "Category " << cells[4] << " not found." << endl;
                    cout << endl;
                }

                else{
                    //prints out if there are no apps in category
                    if (cat_name[index].root==NULL){
                        cout << "Category " << cells[4] << " no apps found." << endl;
                        cout << endl;
                    }
                    //prints apps
                    else{
                        //prints nodes with max price
                        cout << "Category: " << cells[4] << endl;
                        traversePrintMax(cat_name[index].root, price_heap[0]);
                        cout << endl;
                    }
                }
            }
        }
    }
    return 0;
}
