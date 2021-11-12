#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *secret_file = "secret_file.txt";

int linksToSecret(char *fn) {

    char buf[512];

    int count = readlink(fn, buf,sizeof(buf);
    if (count > 0) {
        buf[count] = '\0';
        if (strncmp(buf, secret_file, strlen(secret_file) - 1) == 0) {
            return 1;
        } else {
            return 0;
        }
    }

}

int main() {

    char input[100];
    char fileName[100];
    printf("Enter the name of the file to read from\n");
    fgets(fileName, sizeof(fileName), stdin);

    fileName[strlen(fileName) - 1] = '\0';

    if (strncmp(fileName, secret_file, strlen(secret_file)) == 0 ||
            linksToSecret(fileName) == 1) {
        printf("You are not allowed to access %s or symbolic links to it!\n", secret_file);
    } else {
        printf("Waiting for user input...\n");
        fgets(input, sizeof(input), stdin);

        FILE *fp = fopen(fileName, "r");
        if (fp != NULL) {
            char ch;
            while ((ch = fgetc(fp)) != EOF)
                printf("%c", ch);
            fclose(fp);
        } else {
            printf("You must provide an existing file you may access!\n");
        }
    }

}
