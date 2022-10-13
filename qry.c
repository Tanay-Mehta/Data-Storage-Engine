#include "database.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//struct node define
typedef struct node{
    char data;
    struct node *next;
}node;
//new node function define
node *newnode(char v){
    node *n1 = malloc(sizeof(node));
    n1->next = NULL;
    n1->data = v;
    return n1;
}
//find a substring in the data
char* find(char *filepath, char *v){
    char *data = serialize(filepath);
    char *str = strstr(data,v);
    if(str!=NULL){
        printf("substring is present in mainstring \nremaining string is %s", str);
    }
    else{
        return 0;
    }
    return str;
}
//wasnt sure what to do in project function so just created a key value pair
struct keyval *project(char *filepath){
    struct keyval *key1 = NULL;
    key1->key = NULL;
    key1->val = filepath;
    printf("created project for %C", filepath);
    return key1;
}
//filtered all characters except specified into a separate linked list
node* filter(char *filepath, char v){
    char *data = serialize(filepath);
    int i;
    node *head = newnode('a');
    node* n1;
    for(i=0;i<20;i++){
        if(data[i]!=v){
            // printf("yes");
            if(head->next == NULL){
                n1 = newnode(data[i]);
                head->next = n1;
            }
            else{
                node *headref = head;
                while(headref->next != NULL){
                    headref = headref->next;
                }
                n1 = newnode(data[i]);
                headref->next = n1;
            }
        }
    }
    node *headref1 = head;
    headref1 = headref1->next;
    while(headref1!=NULL){
        printf("%c", headref1->data);
        headref1 = headref1->next;
    }
    return head;
}
//filtered all characters specified
node *group(char *filepath, char v){
        char *data = serialize(filepath);
    int i;
    node *head = newnode('a');
    node* n1;
    for(i=0;i<20;i++){
        if(data[i]!=v){
            if(head->next == NULL){
                n1 = newnode(data[i]);
                head->next = n1;
            }
            else{
                node *headref = head;
                while(headref->next != NULL){
                    headref = headref->next;
                }
                n1 = newnode(data[i]);
                headref->next = n1;
            }
        }
    }
    node *headref1 = head;
    headref1 = headref1->next;
    while(headref1!=NULL){
        printf("%c", headref1->data);
        headref1 = headref1->next;
    }
    return head;
}
//main function
int main(void){
    return 0;
}










