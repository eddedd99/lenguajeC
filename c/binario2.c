#include "stdio.h"

int main(int argc,char* argv[]) {
    FILE *fp = fopen("path_to_file.bin","wb");
    if(fp == NULL) {
        printf("error creating file");
        return -1;
    }
    int val = 4;
    fwrite((const void*) & val,sizeof(int),1,fp);
    fclose(fp);
    return 0;
}
