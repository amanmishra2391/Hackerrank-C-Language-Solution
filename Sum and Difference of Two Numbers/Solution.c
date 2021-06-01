#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a,b,SI,DI;
    float x,y,SF,DF;
    scanf("%d%d",&a,&b);
    scanf("%f%f",&x,&y);
    SI=a+b;
    DI=a-b;
    SF=x+y;
    DF=x-y;
    printf("%d %d",SI,DI);
    printf("\n%0.1f %0.1f",SF,DF);
    return 0;
}
