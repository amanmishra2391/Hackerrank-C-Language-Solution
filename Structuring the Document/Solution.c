#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

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

struct document get_document(char* text) {
    int para = 1;
    struct document doc;
    para += Count(text,'\n');
    doc.data = malloc(para * sizeof(struct paragraph));
    doc.paragraph_count = para;
    for (int i=0,j=0,x=0; i < para; i++){
        int sent = 0;
        char *Para = "";
        for (;text[j]!='\n' && text[j]!='\0'; j++);
        Para = substr(text,x,j);
        x = j + 1;
        sent += Count(Para, '.');
        
        doc.data[i].data = malloc(sent * sizeof(struct sentence));
        doc.data[i].sentence_count = sent;
        for(int k=0,l=0,y=0; k < sent; k++ ){
            int word =1;
            char *Sent = "";
            for(; Para[l]!='.' && Para[l]!='\0'; l++);
            Sent = substr(Para,y,l);
            y = l+1;
            word += Count(Sent, ' ');
            doc.data[i].data[k].data = malloc(word * (sizeof(struct word)));
            doc.data[i].data[k].word_count = word;

            for (int m=0,n=0,z=0; m < word; m++){
                char *Word = "";
                for (;Sent[n]!=' ' && Sent[n]!='\0'; n++);
                Word = substr(Sent,z,n);
                z = n+1;
                doc.data[i].data[k].data[m].data = malloc((strlen(Word)+1)*sizeof(char));
                doc.data[i].data[k].data[m].data = substr(Word,0,strlen(Word));
                n++;
            }
            l++;
            
        }
        j++;        
        
    }
    return doc;

}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}