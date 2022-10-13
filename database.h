#ifndef DATABASE_H
#define DATABASE_H
//defining functions
char* serialize(char* filepath);
//defining structs
struct keyval{
    int key;
    char *val;
};
//defining typedef 
typedef struct keyval* obj;
typedef char* string;
//end
#endif