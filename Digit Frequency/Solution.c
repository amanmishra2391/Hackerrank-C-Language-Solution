#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *num = malloc(1024 * sizeof(char));
    scanf("%s",num);
    num = realloc(num, strlen(num)+1);
    int a[10];
    for (int i = 0; i < 10; i++){
        a[i] = 0;
    }
    
    for (int i = 0; i < strlen(num); i++){
        switch (num[i]) {
        case '0': a[0] += 1;
        break;
        case '1': a[1] += 1;
        break;
        case '2': a[2] += 1;
        break;
        case '3': a[3] += 1;
        break;
        case '4': a[4] += 1;
        break;
        case '5': a[5] += 1;
        break;
        case '6': a[6] += 1;
        break;
        case '7': a[7] += 1;
        break;
        case '8': a[8] += 1;
        break;
        case '9': a[9] += 1;
        break;
        }
    }
    
    for (int i=0; i < 10; i++){
        printf("%d ",a[i]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
