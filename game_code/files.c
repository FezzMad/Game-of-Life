#include <stdlib.h>
#include <stdio.h>

#include "files.h"

char *fileToStr(char *path) {
    char *string = calloc(100, sizeof(char));
    int size = 100;
    FILE *file = fopen(path, "r");
    if (file != NULL) {
        char ch = ' ';
        int i = 0;
        while (ch != EOF) {
            ch = fgetc(file);
            if (ch != EOF) {
                if (i == size) {
                    string = realloc(string, (i * 2));
                    size *= 2;
                }
                string[i] = ch;
                i++;
            }
        }
        fclose(file);
    } else {
        printf("n/a\n");
        string = NULL;
    }
    return string;
}