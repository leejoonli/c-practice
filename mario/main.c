#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height;
    printf("Enter height: ");
    scanf("%d", &height);
    if(height > 8) {
        printf("height must not exceed 8");
        return 1;
    }
    for(int i = 0; i < height; i++) {
        for(int j = height - 1; j > i; j--) {
            printf(" ");
        }
        for(int j = -1; j < i; j++) {
            printf("#");
        }
        for(int k = 0; k < 2; k++) {
            printf(" ");
        }
        for(int l = 0; l <= i; l++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
