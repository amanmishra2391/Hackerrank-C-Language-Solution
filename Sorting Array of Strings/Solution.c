#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int count_unique_char(const char* str) {

    int hash[26] = { 0 };
    int i, c = 0;

    for (i = 0; i < strlen(str); ++i) {
        hash[str[i] - 97] = 1;
    }
    for (i = 0; i < 26; ++i) {
        c += hash[i];
    }

    return c;

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int x,y;
    x = count_unique_char(a);
    y = count_unique_char(b);
    if (x == y){
        return lexicographic_sort(a, b);
    }
    return (int) x > y;
    
}

int sort_by_length(const char* a, const char* b) {
    int x,y;
    x = strlen(a);
    y = strlen(b);
    if (x == y){
        return lexicographic_sort(a, b);
    }
    return (int) x > y;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i=0; i < len -1; i++){
        int index = i;
        for (int j= i+1; j < len; j++){
            if (cmp_func(arr[index],arr[j]) > 0){
                index = j;
            }
        }
        char *temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}