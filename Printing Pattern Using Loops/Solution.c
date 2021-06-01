#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a = n - i;
        for (int j=n; j> a; j--){
            printf("%d ",j);
        }
        
        for (int j=1; j< 2*a; j++){
            printf("%d ",a);
        }
        
        for (int j = a+1; j <=n; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    
    for(int i=2; i<=n; i++){
        for (int j=n; j> i; j--){
            printf("%d ",j);
        }
        
        for (int j=1; j< 2*i; j++){
            printf("%d ",i);
        }
        
        for (int j = i+1; j <=n; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    
  	// Complete the code to print the pattern.
    return 0;
}