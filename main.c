#include "base_array.c"
#include "cgen/ext/io.h"
#include "menu.c"
int main(){
    FILE *f_count = fopen("song.txt","r");
    int count = 1;
    char tmp;
    while(!feof(f_count)){
        fscanf(f_count, "%c",&tmp);
        if(tmp == '\n') count++;
    }
    fclose(f_count);


    FILE *f = fopen("song.txt","r");
    char *line = NULL;
    song *list = calloc(count, sizeof(song));
    int i = 0;
    while(cgetline(&line,0,f)){
        list[i] = malloc(sizeof(struct song_t));
        process(line,list[i]);
        i++;
    }
    int choice = 0;
    int choice_1;
    while(choice != 5){
        Menu();
        printf("Nhap vao lua chon cua ban: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            Thuoctinh();
            printf("Nhap vao lua chon cua ban: ");
            scanf("%d",&choice_1);
            if(choice_1 == 1)qsort(list,count,sizeof(song),compare_name);
            else if(choice_1 == 2) qsort(list,count,sizeof(song),compare_singer);
            else if(choice_1 == 3) qsort(list,count,sizeof(song),compare_musician);
            else if(choice_1 == 4) qsort(list,count,sizeof(song),compare_year);
            Head();
            PrintSong(list,count);
            break;
            case 2: printf("Hello world");
        }
    }
    fclose(f);
}