#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
void delete_line(int id, string filepath_data, string filepath_new_file){
    
    FILE* file, *temp;
    file = fopen(filepath_data, "r");
    temp = fopen(filepath_new_file, "w");
    
    char buffer[100];
    int delete_line = find(id, filepath_data);
    // if(delete_line == -1){
    //     return 1;
    // }
    delete_line = delete_line + 2;
    bool keep_reading = true;
    int current_line = 1;
    do{
        fgets(buffer, 100, file);
        if(feof(file)){
            keep_reading = false;
            }
        else if(current_line != delete_line){
            fprintf(temp, "%s", buffer);
        }
        current_line++;
    }while(keep_reading);
    remove(filepath_data);
    rename(filepath_new_file, filepath_data);
    fclose(file);
    fclose(temp);
	FILE *fptr1, *fptr2;
	char filename[100], c;
	fptr1 = fopen(filepath_new_file, "r");
	fptr2 = fopen(filepath_data, "w");
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
    remove(filepath_new_file);
}
int insert(string filepath, obj clr, char* filepath_id){
    int id = generate_id(filepath_id);
    FILE *fpt = fopen(filepath, "a");
    int i;
    fprintf(fpt, "%i,", id);
    for(i=0;i<5;i++){
        fprintf(fpt, "%s,",clr[i].val);
    }
    fprintf(fpt, "\n");
    fclose(fpt);
    return id;
}
void update(int id, string filepath_data, string filepath_new_file, obj clr){
    
    FILE* file, *temp;
    file = fopen(filepath_data, "r");
    temp = fopen(filepath_new_file, "w");
    
    char buffer[100];
    int delete_line = find(id, filepath_data);
    // if(delete_line == -1){
    //     return 1;
    // }
    delete_line = delete_line + 2;
    bool keep_reading = true;
    int current_line = 1;
    do{
        fgets(buffer, 100, file);
        if(feof(file)){
            keep_reading = false;
            }
        else if(current_line != delete_line){
            fprintf(temp, "%s", buffer);
        }
        else{
            int i;
            fprintf(temp, "%i,", id);
        for(i=0;i<5;i++){
            fprintf(temp, "%s,",clr[i].val);
            }
        fprintf(temp, "\n");
        }
        current_line++;
    }while(keep_reading);
    remove(filepath_data);
    rename(filepath_new_file, filepath_data);
    fclose(file);
    fclose(temp);
	FILE *fptr1, *fptr2;
	char filename[100], c;
	fptr1 = fopen(filepath_new_file, "r");
	fptr2 = fopen(filepath_data, "w");
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
    remove(filepath_new_file);
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
    obj train1;
    create(train1, "jdk", "mumba", "pne", "150", "15000");
    update(1, "./data/db.csv", "./data/temp.csv", train1);
}