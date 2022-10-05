#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int str_length(char arr[]) {
    int i;
    for(i = 0; arr[i] != '\0'; ++i);
    return i;
}

int str_letter(char arr[]) {
    for(int i = 0; arr[i] != '\0'; i++) {
        if((arr[i] < 64 && arr[i] > 91) || arr[i] < 96 && arr[i] > 123) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // variables
    char cypher[27];
    int i = 0, j = ARRAY_SIZE(cypher), k;

    // get cypher input
    printf("Enter cypher key: \n");
    fgets(cypher, j, stdin);
    /*printf("%s\n", cypher);
    for(i = 0; i < j; i++) {
        printf("%c", cypher[i]);
    }*/

    // check cypher input
        // check length on input
    /*if(str_length(cypher) - 1 != 27) {
        printf("Cypher key needs to be 26 characters");
        return 1;
    }*/
        // check if input has any char that isn't a letter in the alphabet
    if(str_letter(cypher) == 1) {
        printf("Cypher key must contain only letters\n");
        return 1;
    }


    // get user text

    // cipher user text

    // output plain text and cipher text
    return 0;
}
