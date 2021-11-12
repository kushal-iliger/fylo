#include <stdio.h>
#include <string.h>

int main() {

    char secret[100] = "exercise failed";
    char buf[200];
	char secret1;

    printf("Enter your name:\n");
    gets(buf);
    strcpy(secret, buf);
    printf(secret);
    printf("\n");
}
