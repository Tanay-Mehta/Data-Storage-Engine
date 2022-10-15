#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
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
void insert(string filepath, obj clr, int no_of_keywal_in_obj){
    int id = generate_id();
    FILE *fpt = fopen(filepath, "a");
    int i;
    fprintf(fpt, "%i,", id);
    for(i=0;i<no_of_keywal_in_obj;i++){
        fprintf(fpt, "%s,",clr[i].val);
    }
    fprintf(fpt, "\n");
    fclose(fpt);
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
    obj clr;  
    create(clr, "1011", "mumbai", "kolkata");
    insert("./data/db.csv", clr, 3);
}