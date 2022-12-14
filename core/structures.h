#ifndef STRUCTURES_H
#define STRUCTURES_H



typedef char* string;

typedef struct keyval{
    char *key;
    char *val;
}keyval;

typedef struct keyval obj[20];
typedef string dbid[20];

void drop(string filepath_id, string filepath_data);
int insert(string filepath, obj clr, char* filepath_id);
void create(obj clr ,char* TrainName, char*Source, char*Destination, char* Duration, char*Total_Seats);
int generate_id(char *filepath);
string find_row(string filepath, int no);
int find(int id, char*filepath);
void delete_line(int id, string filepath_data, string filepath_new_file);
void update(int id, string filepath_data, string filepath_new_file, obj clr);

#endif