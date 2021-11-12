#include<stdio.h>
#include<string.h>

void read(FILE*);
void flush(FILE*);
void suck(FILE*);
void put(FILE*, int, int*, int*);
void print(char*, int);

char bufor[8];
char T[11];

main(int n, char* arg[])//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    switch(arg[3][0])
    {
    case '1'://========================================================================================================================
        {
             FILE* IN=fopen(arg[1], "rt");
             FILE* OUT=fopen(arg[2], "wb");
             strcpy(T, "22222222");
             int i=0;//ktory bit tablicy czytamy
             int j=0;//ile bitow bufora mamy zapisane
             char ctrl=0;

             while(1)
             {
                 if(i==8)
                 {
                     flush(OUT);
                     //print(bufor, 8);
                     i=0;
                 }

                 if(T[j]=='2')
                 {
                     read(IN);//jak zapisalismy znak to czytamy nowy
                     j=0;
                     if(feof(IN)!=0) break;//jak skonczyl nam sie plik to wychodzimy z petli
                 }


                 bufor[i]=T[j]-'0';
                 i++; j++;
             }
             //print(bufor, i);
             if(i>0) for(;i<=7;i++) {bufor[i]=0; ctrl=1;}
             //print(bufor, i);
             if(ctrl==1) flush(OUT);

            fclose(IN); fclose(OUT);
            break;
        }
    case '2'://========================================================================================================================
        {
            FILE* IN=fopen(arg[1], "rb");
            FILE* OUT=fopen(arg[2], "wt");
            int i=0; int j=8; int a=0;

            while(1)
            {
                if(j==8)
                {
                    suck(IN);
                    //printf("sucked\n");
                    //print(bufor, 8);
                    j=0;
                }
                if(feof(IN)!=0) break;
                //printf("not broken\n");
                T[i]=bufor[j];
                a+=T[i]*(1<<i);
                //printf("%d:%d ", i+1, a);
                j++;
                put(OUT, i+1, &a, &i);
            }

            fclose(IN); fclose(OUT);
        }
    }


}//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

void print(char* t, int n)//==================================================================================================================
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d", t[i]);
    }
    printf("\n");
}

void flush(FILE* f)//==================================================================================================================
{
    //print(bufor, 8);
    unsigned char a=0;
    int i;
    for(i=0; i<8; i++)
    {
        a+=(bufor[7-i]*1<<i);
    }

    fputc(a, f);
    //printf("%d ", a);
    return;
}

void read(FILE* f)//==================================================================================================================
{
    char c;
    c=fgetc(f);
    //printf("%c", c);

    switch(c)
    {
        case 'a': {strcpy(T, "1110222222");break;}
        case 'b': {strcpy(T, "1000111222");break;}
        case 'c': {strcpy(T, "1011122222");break;}
        case 'd': {strcpy(T, "1000011122");break;}
        case 'e': {strcpy(T, "1001222222");break;}
        case 'f': {strcpy(T, "1000100222");break;}
        case 'g': {strcpy(T, "1000110222");break;}
        case 'h': {strcpy(T, "1000101222");break;}
        case 'i': {strcpy(T, "1100222222");break;}
        case 'j': {strcpy(T, "1111102222");break;}
        case 'k': {strcpy(T, "0001122222");break;}
        case 'l': {strcpy(T, "1000001222");break;}
        case 'm': {strcpy(T, "1000000222");break;}
        case 'n': {strcpy(T, "0101222222");break;}
        case 'o': {strcpy(T, "1010222222");break;}
        case 'p': {strcpy(T, "0001022222");break;}
        case 'q': {strcpy(T, "1000010012");break;}
        case 'r': {strcpy(T, "0100222222");break;}
        case 's': {strcpy(T, "1101122222");break;}
        case 't': {strcpy(T, "1101022222");break;}
        case 'u': {strcpy(T, "1111112222");break;}
        case 'v': {strcpy(T, "1000010002");break;}
        case 'w': {strcpy(T, "1111022222");break;}
        case 'x': {strcpy(T, "1000010122");break;}
        case 'y': {strcpy(T, "1011022222");break;}
        case 'z': {strcpy(T, "0010222222");break;}
        case ' ': {strcpy(T, "0111222222");break;}
        case '.': {strcpy(T, "0110222222");break;}
        case '\n': {strcpy(T, "0011222222");break;}
    }

    //printf("%s ", T);
}//========================================================================================================================================================

void suck(FILE* f)
{
    unsigned char c;
    c=fgetc(f);
    //printf("%d ", c);
    int i;
    for(i=7; i>=0; i--)
    {
        bufor[i]=c%2;
        c=c>>1;
    }
}

void put(FILE* f, int k, int* a, int* i)
{
    if(k<4) {*i=*i+1; return;}
    int c=0;
    //switch(*a)
    //{
        if(*a==7)
            {
                if(k==4){
                fputc('a', f);
                *i=0; *a=0; c=1;
                }
            }
        else if(*a==113)
            {
                if(k==7){
                fputc('b', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==29)
            {
                if(k==5){
                fputc('c', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==225)
            {
                if(k==8){
                fputc('d', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==9)
            {
                if(k==4) {
                fputc('e', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==17)
            {
                if(k==7){
                fputc('f', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==49)
            {
                if(k==7){
                fputc('g', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==81)
            {
                if(k==7){
                fputc('h', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==3)
            {
                if(k==4){
                fputc('i', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==31)
            {
                if(k==6){
                fputc('j', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==24)
            {
                if(k==5){
                fputc('k', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==65)
            {
                if(k==7){
                fputc('l', f);
                *i=0;c=1;
                *a=0;
               }
            }
        else if(*a==1)
            {
                if(k==7){
                fputc('m', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==10)
            {
                if(k==4){
                fputc('n', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==5)
            {
                if(k==4){
                fputc('o', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==8)
            {
                if(k==5){
                fputc('p', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==289)
            {
                if(k==9){
                fputc('q', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==2)
            {
                if(k==4){
                fputc('r', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==27)
            {
                if(k==5){
                fputc('s', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==11)
            {
                if(k==5){
                fputc('t', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==63)
            {
                if(k==6){
                fputc('u', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==33)
            {
                if(k==9){
                fputc('v', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==15)
            {
                if(k==5){
                fputc('w', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==161)
            {
                if(k==8){
                fputc('x', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==13)
            {
                if(k==5){
                fputc('y', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==4)
            {
                if(k==4){
                fputc('z', f);
                *i=0;
                *a=0;c=1;
                }
            }
        else if(*a==14)
            {
                if(k==4){
                fputc(' ', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==6)
            {
                if(k==4){
                fputc('.', f);
                *i=0;c=1;
                *a=0;
                }
            }
        else if(*a==12)
            {
                if(k==4){
                fputc('\n', f);
                *i=0;
                *a=0;c=1;
                }
            }
        if(c==0) *i=*i+1;

}
