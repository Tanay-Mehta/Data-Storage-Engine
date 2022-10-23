#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
#include <string.h>


string find_row(string filepath, int no){
    int i;
    FILE* pFile;
    char data[100];
    pFile = fopen (filepath , "r");
    string row_data;
    row_data = fgets(data, 100, pFile);
    for(i=0;i<no;i++){
        row_data = fgets(data, 100, pFile);
    }
    row_data = fgets(data, 100, pFile);
    // printf("%s", row_data);
    fclose(pFile);
    return row_data;

}
int find(int id, char*filepath){
    char str[1000];
    FILE* pFile;
    pFile = fopen (filepath , "r");
    int i;
    int c;
    int f;
    string row_data;
    string data = fgets(str, 100, pFile);
    for(i=0;i<3;i++){
        data = fgets(str, 2, pFile);
        c = atoi(str);
        if(c==id){
            return i;
        }
        data = fgets(str, 100, pFile);
    }
    // printf("%s", str);
    fclose (pFile);
    printf("no id found");
    return -2;
}