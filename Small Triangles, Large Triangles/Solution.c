#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double getArea(triangle tri){
    float s = ((float)(tri.a + tri.b + tri.c)) / 2;
    return sqrt(s*(s-tri.a)*(s-tri.b)*(s-tri.c));
}

void sort_by_area(triangle* tr, int n) {
    
    for (int i = 0; i < n-1; i++){
        int index = i;
        for (int j= i+1; j < n; j++){
            if (getArea(tr[index]) > getArea(tr[j])){
                index = j;
            }
        }
        triangle abc = tr[i];
        tr[i] = tr[index];
        tr[index] = abc;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}