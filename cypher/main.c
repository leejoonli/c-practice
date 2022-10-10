#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void cypher(char* plain, char* cypher) {
    int i = 0;
    while(plain[i] != '\0') {
        cypher[i] = plain[i] + 1;
        i++;
    }
    cypher[i-1] = '\0';
    return;
}

int main() {
    // variables
    /*char key[27];*/
    char plain_text[256];
    char cypher_text[256];
    int j = ARRAY_SIZE(plain_text);

    // get user string input
    printf("Enter text you wish to be encoded: \n");
    fgets(plain_text, j, stdin);

    // cipher user text
    cypher(plain_text, cypher_text);

    // output plain text and cipher text
    printf("Plain text: %s", plain_text);
    printf("Cypher text: %s", cypher_text);

    return 0;
}
