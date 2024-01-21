//
// Created by National Cyber City on 1/21/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int number;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fscanf(file, "%d", &number) != EOF) {
        printf("%d\n", number);
    }

    fclose(file);
    return 0;
}
