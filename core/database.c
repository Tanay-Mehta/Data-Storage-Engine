#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(void){
    // obj train1;
    // int id = generate_id("../data/id.txt", "../data/db.txt");
    // create(train1, "1011", "mumbai", "pune");
    // insert("../data/db.csv", train1, "../data/id.txt");
    string hello = find(3, "../data/db.csv");
    printf("%s", hello);
    // drop("../data/id.txt", "../data/db.csv");
}