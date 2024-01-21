//
// Created by National Cyber City on 1/21/2024.
//
#include "stdio.h"
#include "stdlib.h"

void copyFile(const char *sourceFile , const char *destinationFile){

    FILE *source , *destination;

    int ch;

    source = fopen(sourceFile,"rb");
    if(source==NULL){
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
    destination = fopen(destinationFile,"wb");

    if(destination==NULL){
        perror("Error Opening destination file");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    while ((ch= fgetc(source))!=EOF){
        fputc(ch,destination);
    }

    fclose(source);
    fclose(destination);

}

int main(){

    copyFile("source.txt","destination.txt");
    printf("File copied successfully.\n");
    return 0;

}
