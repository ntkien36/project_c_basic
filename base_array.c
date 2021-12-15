#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef CGEN_IO_BUF_SIZE
  #define CGEN_DEFAULT_IO_BUFF_SIZE
  #define CGEN_IO_BUF_SIZE 1024
#endif  // CGEN_IO_BUF_SIZE
static char *cgetline(char **lineptr, long n, FILE *inp) {
  char buff[CGEN_IO_BUF_SIZE];
  long idx = 0, len, tmp;

  while (fgets(buff, CGEN_IO_BUF_SIZE, inp)) {
    len = strlen(buff);
    tmp = idx + len + 1;
    if (tmp > n) {
      *lineptr = realloc(*lineptr, tmp);
      if (*lineptr == NULL) {
        return NULL;  // Lỗi cấp phát bộ nhớ
      }
      n = tmp;
    }
    if (idx == 0) {
      *lineptr[0] = 0;
    }
    strcat(*lineptr, buff);
    idx += len;
    if (buff[len - 1] == '\n') {
      break;
    }
  }
  return idx > 0? *lineptr: NULL;
}
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