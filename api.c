#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
#include <string.h>

void drop(string filepath_id, string filepath_data){
    int id = 0;
    char str[100];
    FILE* ptr1;
    ptr1 = fopen(filepath_data, "r");
    string first_line = fgets(str, 100, ptr1);
    fclose(ptr1);
    FILE *ptr2;
    ptr2 = fopen(filepath_data, "w");
    fprintf(ptr2, "%s", first_line);
    FILE* ptr;
    ptr = fopen(filepath_id, "w");
    fprintf(ptr, "%d", id);
    fclose(ptr);

}
int insert(string filepath, obj clr, char* filepath_id){
    int id = generate_id(filepath_id);
    FILE *fpt = fopen(filepath, "a");
    int i;
    fprintf(fpt, "%i,", id);
    for(i=0;i<6;i++){
        fprintf(fpt, "%s,",clr[i].val);
    }
    fprintf(fpt, "\n");
    fclose(fpt);
    return id;
}

void create(obj clr ,char* TrainName, char*Source, char*Destination, char* Duration, char*Total_Seats){
    clr[0].key = "Train_Name";
    clr[0].val = TrainName;
    clr[1].key = "Source";
    clr[1].val = Source;
    clr[2].key = "Destination";
    clr[2].val = Destination;
    clr[3].key = "Duration";
    clr[3].val = Duration;
    clr[4].key = "Total_Seats";
    clr[4].val = Total_Seats;

}
int generate_id(char *filepath){
    FILE *fpt = fopen(filepath, "r");
    int id = 0;
    fscanf (fpt, "%d", &id);
    id++;
    fclose(fpt);
    FILE *fptr = fopen(filepath, "w");
    fprintf(fptr, "%d", id);
    fclose(fptr);
    return(id);
}
int main(void){
    drop("./data/id.txt", "./data/db.csv");
}