#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void serialize(string filepath){
    FILE* ptr;
    char ch;
 
    // Opening file in reading mode
    ptr = fopen(filepath, "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
 
    // Closing the file
    fclose(ptr);
    return 0;
}
void deserialize(char* x)
{
 
    // Opening the path entered by user
    FILE* fp = fopen(x, "a+");
 
    // If file is not found then return
    if (fp == NULL) {
        printf("Unable to open file\n");
        return;
    }
 
    // To store the content
    char buf[100];
    int a[MAX], s = 0, c = 0, l;
 
    // Explicitly inserting a newline
    // at the end, so that o/p doesn't
    // get effected.
    fprintf(fp, " \n");
    rewind(fp);
 
    // Adding current length so far +
    // previous length of a line in
    // array such that we have starting
    // indices of upcoming lines
    while (!feof(fp)) {
        fgets(buf, sizeof(buf), fp);
        l = strlen(buf);
        a = s += l;
    }
 
    // Move the pointer back to 0th index
    rewind(fp);
    c -= 1;
 
    // Print the contents
    while (c >= 0) {
        fseek(fp, a, 0);
        fgets(buf, sizeof(buf), fp);
        printf("%s", buf);
        c--;
    }
    return ;
}
int main(void){
    return 0;
}