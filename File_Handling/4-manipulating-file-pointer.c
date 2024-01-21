//
// Created by National Cyber City on 1/21/2024.
//

#include "stdio.h"
#include "stdlib.h"

int main(){

    FILE *file;
    long int pos;

    file = fopen("destination.txt","r+");

    if(file==NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fputs("Hello,World!",file);
    rewind(file);

    char buffer[50];
    fgets(buffer,50,file);
    printf("Content: %s\n",buffer);

    fseek(file,7,SEEK_SET);

    pos = ftell(file);

    printf("Current position: %ld\n",pos);

    fclose(file);

    return 0;

}