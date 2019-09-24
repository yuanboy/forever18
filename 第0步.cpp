#include<stdio.h>
using namespace std;
void hello(char one, FILE*fp )
{
    char letter;
    int num=0, ret;
    while(!feof(fp)){
        if(letter==one)
            num++;
#if 0
        fscanf(fp, "%c", &letter);
#else
        ret = fscanf(fp, "%c", &letter);
        if (ret == EOF)
            break;
#endif
    }
    printf("%c:%d  ", one, num);

    return ;
}

int main()
{
    FILE *fp;
    if((fp=fopen("C:\\Users\\LENOVO\\Desktop\\english.txt", "r"))==NULL){
        printf("Cannot open the file!\n");
        //exit(0);
        return -1;
    }

    char str[26];
    int i=0;
    str[0]='a';

    for (i=0; i<26; i++){
        //str[i+1]=str[i]+1;
        str[i] = 'a' + i;
        // printf("str[%d]=%c ", i, str[i]);
        hello(str[i], fp);
        rewind(fp);
    }
    fclose(fp);

    return 0;
}

