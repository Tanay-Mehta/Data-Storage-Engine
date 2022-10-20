#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
#include <string.h>

int generate_id(){
    string filepath = "./data/id.txt";
    FILE *fpt = fopen(filepath, "r");
    int id = 0;
    fscanf (fpt, "%d", &id);
    id++;
    printf("%d", id);
    fclose(fpt);
    FILE *fptr = fopen(filepath, "w");
    fprintf(fptr, "%d", id);
    fclose(fptr);
    return(id);
}
string find_row(string filepath, int no){
    int i;
    FILE* pFile;
    char data[100];
    pFile = fopen (filepath , "r");
    string row_data;
    for(i=0;i<no;i++){
        row_data = fgets(data, 100, pFile);
    }
    row_data = fgets(data, 100, pFile);
    printf("%s", row_data);
    fclose (pFile);
    return row_data;

}
string find(int id, char*filepath){
    char str[20];

    FILE* pFile;
    pFile = fopen (filepath , "r");
    int i;
    int c;
    int f;
    string row_data;
    for(i=0;i<3;i++){
        string data = fgets(str, 2, pFile);
        c = atoi(str);
        if(c==id){
            row_data = find_row(filepath, i);
        }
        data = fgets(str, 100, pFile);
    }
    // printf("%s", str);
    fclose (pFile);
    return row_data;

}
int insert(string filepath, obj clr, int no_of_keywal_in_obj){
    int id = generate_id();
    FILE *fpt = fopen(filepath, "a");
    int i;
    fprintf(fpt, "%i,", id);
    for(i=0;i<no_of_keywal_in_obj;i++){
        fprintf(fpt, "%s,",clr[i].val);
    }
    fprintf(fpt, "\n");
    fclose(fpt);
    return id;
}
void create(obj clr ,char* TrainID, char*Source, char*Destination){
    clr[0].key = "TrainID";
    clr[0].val = TrainID;
    clr[1].key = "Source";
    clr[1].val = Source;
    clr[2].key = "Destination";
    clr[2].val = Destination;
}
int main(void){  
    // obj clr;  
    string row_data = find(3, "./data/db.csv");
    printf("%s", row_data);
    // create(clr, "1011", "mumbai", "kolkata");
    // insert("./data/db.csv", clr, 3);
}