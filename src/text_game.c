#include <stdio.h>

#include "asset_manager.c"

int main(int argc, char* argv[]){
    printf("Hello World\n");

    asset_manager_init();
    char** room = asset_load_txt_2dArray("horizontal_room.txt");

    printf("\n\nRet!\n");
    for(int i = 0; room != NULL && room[i] != NULL;i++){
        printf("%s%s%s\n", room[i], room[i],room[i]);
    }
}