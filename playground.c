#include "database.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct keyval{
    // key: char[20], val char[20]
    char key[20];
    char val[20];
}keyval;

char* find(keyval* key2, char *v){

    char *data = serialize(key2->val);
    char *str = strstr(data,v);
    if(str!=NULL){
        printf("substring is present in mainstring \nremaining string is %s", str);
    }
    else{
        return 0;
    }
    return str;
}
keyval *project(char *filepath, char *tablename){
    keyval *key1 = NULL;
    key1->key = tablename;
    key1->value = filepath;
    printf("created project for %C", tablename);
    return key1;
}
int main(void){
    char l;
    l = 'l';
    char *hello;
    key2 = project("./data/db.txt", "hello");
    node* head = filter(key2, 'l');
    // printf("%s", fil);
    
}