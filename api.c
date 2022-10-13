#include "database.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

string create(string filepath){
    struct keyval *key1 = NULL;
    key1->key = NULL;
    key1->val = filepath;
    printf("created project for %C", filepath);
    return key1;
}
//wasnt sure what to do in create function so just created a key value pair
//to insert in the file
void insert(string tablename, char* info){
    char *data = serialize(tablename);
    FILE *myfile = fopen(tablename,"a");
    fprintf(myfile, info);
    fclose(myfile);
}
//to update the file
void update(string tablename, int id, char info){
    char *data = serialize(tablename);
    data[id] = info;
    FILE *myfile = fopen(tablename,"w");
    fprintf(myfile,data);

}
//to remove a specific char from the string
void removeChar(char * str, char charToRemmove){
    int i, j;
    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == charToRemmove)
        {
            for(j=i; j<len; j++)
            {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
}
//remove a specific char from data
void delete(string tablename, int id){
    char *data = serialize(tablename);
    removeChar(data, data[id]);
    FILE *myfile = fopen(tablename,"w");
    fprintf(myfile,data);
}
//main code
int main(void){
    return 0;


}