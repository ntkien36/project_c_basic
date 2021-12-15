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
    char *p1 = (*(song*)a)->name;
    char *p2 = (*(song*)b)->name;
    return strcmp(p1,p2);
}
int compare_singer(const void *a, const void *b){
    char *p1 = (*(song*)a)->singer;
    char *p2 = (*(song*)b)->singer;
    return strcmp(p1,p2);
}
int compare_musician(const void *a, const void *b){
    char *p1 = (*(song*)a)->musician;
    char *p2 = (*(song*)b)->musician;
    return strcmp(p1,p2);
}
int compare_year(const void *a, const void *b){
    char *p1 = (*(song*)a)->year;
    char *p2 = (*(song*)b)->year;
    int t1, t2;
    sscanf(p1, "%d", &t1);
    sscanf(p2, "%d", &t2);
    return t1-t2;
}