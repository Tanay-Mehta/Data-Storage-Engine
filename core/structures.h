#ifndef STRUCTURES_H
#define STRUCTURES_H


typedef char* string;

typedef struct keyval{
    char *key;
    char *val;
}keyval;

typedef struct keyval obj[20];

typedef struct dbid{
    string value[20];
}obid;




#endif