#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int str_length(char arr[]) {
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

int main() {
    // variables
    char key[27];
    char plain_text[256];
    char cypher_text[256];
    int i = 0, j = ARRAY_SIZE(key);

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
    printf("Enter phrase you wanted encrypted: ");
    fgets(plain_text, 255, stdin);

    // cipher user text

    // output plain text and cipher text
    return 0;
}
