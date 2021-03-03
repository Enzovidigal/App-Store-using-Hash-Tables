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
    char categoriesNumber[12];
    fgets(categoriesNumber, sizeof(categoriesNumber), stdin);
    cout << categoriesNumber;


    
    return 0;
}
