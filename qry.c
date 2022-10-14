#include <stdio.h>
#include "core/structures.h"
// string filepath, obj object
// fprintf(fpt, "hello");
    // // 
void insert(string filepath, obj clr, int no_of_keywal_in_obj){
    FILE *fpt = fopen(filepath, "a");
    int i;
    for(i=0;i<20;i++){
        fprintf(fpt, "%s\n",clr[no_of_keywal_in_obj].val);
    }
    fclose(fpt);
}


int main(void){
    //"./data/db.csv"
    obj clr;
    clr[0].val = "hello";
    clr[1].val = "Tanay";
    clr[2].val = "I";
    clr[3].val = "am";
    clr[4].val = "raj";
    clr[5].val = "I";
    clr[6].val = "would";
    clr[7].val = "love";
    clr[8].val = "to";
    clr[9].val = "play";
    clr[10].val = "with";
    clr[11].val = "you";
    clr[12].val = "i";
    clr[13].val = "would";
    clr[14].val = "challenge";
    clr[15].val = "you";
    clr[16].val = "to a";
    clr[17].val = "match";
    clr[18].val = "in";
    clr[19].val = "basketball";
    insert("./data/db.csv", clr, 20);
    
}