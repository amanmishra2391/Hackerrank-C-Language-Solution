#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
int Max_And=0,Max_Or=0,Max_Xor=0;
for (int a =1;a<n;a++)
{
    int temp;
    for (int b=a+1;b<=n;b++)
    {
        temp=a&b;
        if (temp>Max_And && temp<k)
        {
            Max_And=temp;
        }
        temp=a|b;
        if (temp>Max_Or && temp<k)
        {
            Max_Or=temp;
        }
        temp=a^b;
        if (temp>Max_Xor && temp<k)
        {
            Max_Xor=temp;
        }
    } 
}
printf("%d\n%d\n%d",Max_And,Max_Or,Max_Xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
