#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main() {
    // variables
    char *cypher;
    int i = 0, j;

    // get cypher input
    printf("Enter cypher key: \n");
    fgets(cypher, 27, stdin);
    /*printf("%s\n", cypher);*/
    for(i = 0; i < 27; i++) {
        printf("%c", cypher[i]);
    }

    // check cypher input
        // check length on input
        // check if input has any char that isn't a letter in the alphabet

    // get user text

    // cipher user text

    // output plain text and cipher text
    return 0;
}
