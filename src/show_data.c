#include <gtk-3.0/gtk/gtk.h>
#include <string.h>

#include "header.h"

#define NUM_DATA 3

typedef struct data {
        char website[30];
        char mail[50];
        char username[30];
        char password[50];
}addData;

static void dash(int *max);
static void *find_max(addData addData[]);
static void space_char(int max,int wordSize);

void show_data(){

    addData addData[NUM_DATA] = {
        //{"website","mail","username","password"}
        {"paypal.com","mail@gmail.com","UsErName122","azertyuiopqsd"},
        {"github.com","mymail@prontonmail.com","GLAchJK","JKLAJJzz"},
        {"windows_pc1","/","admin","1234"}
        //add data here (don't forget to change the value of NUM_DATA !)
    };

    int *max = find_max(addData);
    g_print("\n\n");
    g_print("|   WEBSITE");space_char(max[0],7);
    g_print("|   MAIL");space_char(max[1],4);
    g_print("|   USERNAME");space_char(max[2],8);
    g_print("|   PASSWORD");space_char(max[3],8);g_print("|\n");
 
    dash(max);

    for(int i = 0; i<NUM_DATA;i++){
        g_print("|   %s",addData[i].website);space_char(max[0],strlen(addData[i].website));
        g_print("|   %s",addData[i].mail);space_char(max[1],strlen(addData[i].mail));
        g_print("|   %s",addData[i].username);space_char(max[2],strlen(addData[i].username));
        g_print("|   %s",addData[i].password);space_char(max[3],strlen(addData[i].password));g_print("|\n");
    }
    g_print("\n\n");
}

static void *find_max(addData addData[]){
    static int max[4]={0,0,0,0};

    for(int i = 0; i<NUM_DATA; i++){
        if(strlen(addData[i].website)>max[0])
            max[0]=strlen(addData[i].website);

        if(strlen(addData[i].mail)>max[1])
            max[1]=strlen(addData[i].mail);

        if(strlen(addData[i].username)>max[2])
            max[2]=strlen(addData[i].username);

        if(strlen(addData[i].password)>max[3])
            max[3]=strlen(addData[i].password);
    }
    return max;
}
static void dash(int *max){
    g_print("|   ----------");space_char(max[0],10);
    g_print("|   ----------");space_char(max[1],10);
    g_print("|   ----------");space_char(max[2],10);
    g_print("|   ----------");space_char(max[3],10);
    g_print("|\n");
}
static void space_char(int max,int wordSize){
    //3->number of space_chars
    int space_char=0;
    int i=0;
    space_char=(max-wordSize)+3;
    while(space_char>i){
        g_print(" ");//space
        i++;
    }
}