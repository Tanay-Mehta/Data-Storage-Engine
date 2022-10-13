#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../database.h"
//return text file in a string array
char* serialize(char* filepath){
    int i = 0, line = 5;
    char *ch;
    ch = (char*)malloc(100 * sizeof(char));

    FILE *myfile;
    myfile = fopen(filepath,"r");
    if (myfile== NULL)
    {
    printf("can not open file \n");
    myfile = fopen(filepath,"w");
    return ch;
    }
    while(line--){
    fscanf(myfile,"%s",ch);
    i++;
    }  
    fclose(myfile);
    return ch;
}  
//print string in a reverse order
int deserialize(string filepath){
    FILE *fp;
    int ft,i=0;
    fp = fopen(filepath, "r");
    if(fp==NULL)
    {
        printf("ERROR");
        return 0;
    }
    fseek(fp,0,SEEK_END);
    ft=ftell(fp);
    while(i<ft)
    {
        i++;
        fseek(fp,-i,SEEK_END);
        printf("%c",fgetc(fp));
    }
    fclose(fp);
    return 0;
}

