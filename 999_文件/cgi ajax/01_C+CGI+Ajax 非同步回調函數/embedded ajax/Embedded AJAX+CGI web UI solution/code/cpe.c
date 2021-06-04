#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
typedef struct {               
    char *name;                 
    char *val;                  
} input;
 
FILE *fp, *fopen();
char freq[10]="1.23";
char username[10]="jemic";
 
char *ReadStdin(FILE *f, char stop, int *len)
{
    int wsize;
    char *word;
    int x;
 
    wsize = 102400;
    x=0;
    word = (char *) malloc(sizeof(char) * (wsize + 1));
 
    while(1) {
        word[x] = (char)fgetc(f);
        if( x==wsize) {
            word[x+1] = '\0';
            wsize+=102400;
            word = (char *)realloc(word,sizeof(char)*(wsize+1));
        }
        --(*len);
        if((word[x] == stop) || (feof(f)) || (!(*len))) {
            if(word[x] != stop) x++;
            word[x] = '\0';
            return word;
        }
        ++x;
    }
}
        
char *ReadString(char *f, char stop, int *len)
{
    int wsize;
    char *word;
    int x;
 
    wsize = 102400;
    x=0;
    word = (char *) malloc(sizeof(char) * (wsize + 1));
 
    while(1) {
        word[x] = *f;
    f++;
        if( x==wsize) {
            word[x+1] = '\0';
            wsize+=102400;
            word = (char *)realloc(word,sizeof(char)*(wsize+1));
        }
        --(*len);
        if((word[x] == stop) || (!(*len))) {
            if(word[x] != stop) x++;
            word[x] = '\0';
            return word;
        }
        ++x;
    }
}
      
 
char *ReadData(char *line, char stop)
{
    int i = 0, j;
    char *word = (char *) malloc(sizeof(char) * (strlen(line) + 1));
 
    for(i=0; ((line[i]) && (line[i] != stop)); i++)
        word[i] = line[i];
 
    word[i] = '\0';
    if(line[i]) ++i;
    j=0;
 
    while(line[j++] = line[i++]);
    return word;
}
 
int main(int argc, char *argv[])
{
        input inputs[256];
    register int i=0;
    char *query_string=NULL;
    int len=0,qlen=0,repIndex=0;
    
    
    qlen=strlen(getenv("QUERY_STRING"));
    query_string=getenv("QUERY_STRING");
    
    if (qlen!=0)//deal with method get 
    {
        
        fprintf(stdout, "Content-Type: text/html\r\n\r\n");
        
        for(i=0;qlen>0; i++)
    {
        inputs[i].val = ReadString(query_string,'&',&qlen);
            repIndex=i;
            query_string+=strlen(inputs[i].val)+1;
    }
        
        for (i=0;i<=repIndex;i++)
        {
            if (strcmp(inputs[i].val,"freq")==0) fprintf(stdout,"%s=%s&",inputs[i].val,freq);
            if (strcmp(inputs[i].val,"username")==0) fprintf(stdout,"%s=%s&",inputs[i].val,username);
        }
        
        return 0;
    }
        if (qlen==0)//deal with method set
    {
        len = atoi(getenv("CONTENT_LENGTH"));
        for(i=0;len && (!feof(stdin)); i++) 
        {
                    inputs[i].val = ReadStdin(stdin,'&',&len); 
                    inputs[i].name = ReadData(inputs[i].val,'=');
            repIndex=i;  
            }
        fprintf(stdout, "Content-Type: text/html\r\n\r\n");
        for (i=0;i<=repIndex;i++)
        {
            
            if (strcmp(inputs[i].name,"freq")==0) 
            {
                strncpy(freq,inputs[i].val,10);
                fprintf(stdout,"%s=%s&",inputs[i].name,freq);
            }
            if (strcmp(inputs[i].name,"username")==0)
                        {
                                strncpy(username,inputs[i].val,10);
                                fprintf(stdout,"%s=%s&",inputs[i].name,username);
                        }
 
        }
        
        return 0;
    }
    else
    {
        fprintf(stdout, "Content-Type: text/html\r\n\r\n");
        return 0;
    }
}