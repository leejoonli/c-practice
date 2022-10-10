#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/*int str_length(char arr[]) {
    int i;
    for(i = 0; arr[i] != '\0'; ++i);
    return i;
}

int str_letter(char arr[], int arr_length) {
    // check string for non letters
    for(int i = 0; i < arr_length; i++) {
        if(arr[i] == '\0' && i == 26) {
            break;
        }
        else if(arr[i] < 65 || (arr[i] > 90 && arr[i] < 97) || arr[i] > 122) {
            return 1;
        }
    }
    // lower case string
    for(int i = 0; i < arr_length; i++) {
        if(arr[i] < 97) {
            arr[i] = arr[i] + 32;
        }
    }
    return 0;
}

char* test(char *ptr) {
    printf("Enter phrase you wanted encrypted: \n");
    printf("before fgets\n");
    fgets(ptr, sizeof(256), stdin);
    printf("after fgets\n");
    printf("%c", *ptr);
    return ptr;
}*/

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

    /*
    // maybe try this:
    char userInput[6][160];
    fgets(userInput[0], 160, stdin);
    fgets(userInput[1], 160, stdin);

    // get cypher input
    printf("Enter cypher key: \n");
    fgets(key, j, stdin);

    // check cypher input
        // check length on input
    if(str_length(key) != 26) {
        printf("Cypher key needs to be 26 characters");
        return 1;
    }
        // check if input has any char that isn't a letter in the alphabet
    if(str_letter(key, j) == 1) {
        printf("Cypher key must contain only letters\n");
        return 1;
    }

    // get user text
    test(plain_text);
    fgets(plain_text, 255, stdin);
    */

    // cipher user text
    cypher(plain_text, cypher_text);

    // output plain text and cipher text
    printf("Plain text: %s", plain_text);
    printf("Cypher text: %s", cypher_text);

    return 0;
}
