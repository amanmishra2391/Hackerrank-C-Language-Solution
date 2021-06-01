#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];

}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];

}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];

}

int Count(char* str, char ch){
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (ch == str[i])
            ++count;
    }
    return count;
}

char * substr(char * s, int x, int y)
{
    char * ret = malloc(strlen(s) + 1);
    char * p = ret;
    char * q = &s[x];

    assert(ret != NULL);

    while(x  < y)
    {
        *p++ = *q++;
        x ++; 
    }

    *p++ = '\0';

    return ret;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 


void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

char**** get_document(char* text){
    int para = 1;
    char ****document;
    para += Count(text,'\n');
    document = malloc(para * sizeof(char***));
    for (int i=0,j=0,x=0; i < para; i++){
        int sent = 0;
        char *Para = "";
        for (;text[j]!='\n' && text[j]!='\0'; j++);
        Para = substr(text,x,j);
        x = j + 1;
        sent += Count(Para, '.');
        document[i] = malloc(sent* sizeof(char**));
        
        for(int k=0,l=0,y=0; k < sent; k++ ){
            int word =1;
            char *Sent = "";
            for(; Para[l]!='.' && Para[l]!='\0'; l++);
            Sent = substr(Para,y,l);
            y = l+1;
            word += Count(Sent, ' ');
            document[i][k] = malloc(word * (sizeof(char*)));

            for (int m=0,n=0,z=0; m < word; m++){
                char *Word = "";
                for (;Sent[n]!=' ' && Sent[n]!='\0'; n++);
                Word = substr(Sent,z,n);
                z = n+1;
                document[i][k][m] = malloc((strlen(Word)+1)*sizeof(char));
                document[i][k][m] = substr(Word,0,strlen(Word));
                n++;
            }
            l++;
            
        }
        j++;        
        
    }
    return document;

}



int main() 
{
    char* text = get_input_text();

    int q;
    scanf("%d", &q);

    char**** document = get_document(text);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}