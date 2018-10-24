/* Manage the assets */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void asset_manager_init(){
    printf("[good to go!]\n");
}

static long am_get_ln_count(char* chars){
    long len = 1;
    for(int i = 0; i < strlen(chars);i++){
        if(chars[i] == '\n' || chars[i] == '\r'){
            len++;
        }
    }

    return len;
}

char** asset_load_txt_2dArray(char* asset_name){
    char* name = malloc(sizeof(asset_name) + 8);
    sprintf(name, "assets/%s", asset_name);
    FILE* f = fopen(name, "r");
    if(f == NULL || f <= 0){
        printf("Unable to open file %s\n", name);
        exit(1);
    }
    printf("File %s open\n", name);

    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    rewind(f);
    printf("Size is %ld\n", fileSize);

    char* buf = malloc(sizeof(char*) * fileSize + 1);
    long readSize = fread(buf, 1, fileSize, f);
    buf[fileSize] = '\0';
    if(readSize != fileSize){
        // Something broke
        printf("OOPS!\n");
        exit(2);
    }

    long cnt = am_get_ln_count(buf);
    printf("Count is %ld\n", cnt);
    char** retval = malloc(1000);

    int arrayIdx = 0;
    for(long i = 0; i <= fileSize;i++){
        int start = i;
        int end = i;
        for(int z = i; z <= fileSize;z++){
            end = z;
            if(buf[z] == '\n' || buf[z] == '\r'){
                end = z;
                z = fileSize;
            }
        }

        retval[arrayIdx] = malloc(1000);
        for(int z = start; z < end;z++){
            retval[arrayIdx][end] = '\0';
            retval[arrayIdx][z - start] = buf[z];
        }
        arrayIdx++;
        i = end;
    }

    free(name);
    free(buf);
    fclose(f);
    return retval;
}