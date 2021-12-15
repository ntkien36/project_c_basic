#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct song_t{
    char *name;
    char *singer;
    char *musician;
    char *year;
}*song;
void Add(song a, char *name, char *singer, char *musician, char *year){
    a->name = strdup(name);
    a->singer = strdup(singer);
    a->musician = strdup(musician);
    a->year = strdup(year);
}
void PrintASong(song a){
    printf("%30s", a->name);
    printf("%30s",a->singer);
    printf("%30s",a->musician);
    printf("%30s\n",a->year);
}
void process(char *line, song a){
    char *name;
    char *singer;
    char *musician;
    char *year;
    name = strtok(line,"#*\n");
    singer = strtok(NULL,"#*\n");
    musician = strtok(NULL,"#*\n");
    year = strtok(NULL,"#*\n");
    Add(a,name,singer,musician,year);
}
void PrintSong(song *a, int count){
    for(int i=0; i<count; i++){
        PrintASong(a[i]);
    }
}
int compare_name(const void *a, const void *b){
    song t1 = (song)a;
    song t2 = (song)b;
    return strcmp(t1->name,t2->name);
}
int compare_i(const void *a, const void *b){
    int x1,x2;
    song t1 = (song)a;
    song t2 = (song)b;
    sscanf(t1->year,"%d",&x1);
    sscanf(t2->year,"%d",&x2);
    return x1-x2;
}