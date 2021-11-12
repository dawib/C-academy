#include<stdio.h>
#include<string.h>
//#include<errno.h>

char isGood(const char*, const char*);//sprawdzanie czy slowo jest slowem specjalnym
char alnum(char);

main(int n, char* arg[])//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    if(n<4) return 1;//jesli jest za malo argumentow to przerywamy program

    FILE* IN=fopen(arg[1], "rt");
    //printf("in\n");
    FILE* OUT=fopen(arg[2], "wt");

    //printf("out\n");

    if(IN==NULL) return 2;//jesli plik wejsciowy nie otworzyl sie jak trzeba to przerywamy program

    int lineCount=1;//licznik linii
    int wordCount=0;//licznik slow
    int goodCount=0;//licznik slow dobrych
    int m;

    char read[32];//pomocniczy string do czytania wyrazow
    read[0]='\0';
    char special[32];
    char c;//czytany znak
    char inside=0;//pamietanie czy jestesmy wewnatrz slowa
    int i=0;
    char comm=0;
    char d;

    for(i=0; arg[3][i]!='\0'; i++)
    {
        special[i]=tolower(arg[3][i]);
    }
    special[i]='\0';

    i=0;
    while(feof(IN)==0)//------------------------------------------------------------------------------------------------------------------
    {
        c=fgetc(IN);
        d=alnum(c);

        //printf("%c", c);

        if(c=='/')
        {
            c=fgetc(IN);
            if(c=='*')
            {
                comm++;
                continue;
            }
            else
            {
                ungetc(c, IN);
                c='/';
            }
        }

        if(c=='*' && comm>0)
        {
            c=fgetc(IN);
            if(c=='/')
            {
                comm--;
                continue;
            }
            else
            {
                ungetc(c, IN);
                c='*';
            }
        }

        if(comm==0)//jesli nie jestesmy w komentarzu........................................................................................
        {
            if(d>0)//jesli przeczytalismy znak alfanumeryczny
            {
                if(inside==0 && d==2)//jesli zaczyna sie slowo
                {
                        inside=1;
                        wordCount++;
                        i=0;
                }
            }
            else
            {
                if(inside==1)
                {
                    inside=0;
                    read[i]='\0';

                    if(isGood(read, special)==1)
                    {
                        goodCount++;
                        fprintf(OUT, "Linia %d: %s\n", lineCount, read);
                    }
                }
            }

            if(c=='\n') lineCount++; //printf("L:%d\n", lineCount);}

            if(inside==1)
            {
                read[i]=tolower(c);
                if(31>i) i++;
                else i=31;
            }
        }
    }//------------------------------------------------------------------------------------------------------------------

    fprintf(OUT, "Wyrazy: %d\nWyrazy specjalne: %d", wordCount, goodCount);

    fclose(IN); fclose(OUT);//zamykamy pliki
}//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

char alnum(char c)//sprawdzanie czy znak jest litera cyfra czy czyms innym===================================================================================
{
    if(c>=48 && c<=57) return 1;

    if(c>=65 && c<=90) return 2;

    if(c>=97 && c<=122) return 2;

    return 0;
}

char isGood(const char* A, const char* S)//sprawdzanie czy wyraz jest wyrazem dobrym=========================================================================
{
    int a=strlen(A); int s=strlen(S); int d=a-s;

    if(d<-1 || d>1) return 0;

    int i,j;
    int diff=0;//ilosc roznych liter

    if(d==0)
    {
        for(i=0; i<a; i++)
        {
            if(A[i]!=S[i]) diff++;
            if(diff>1) return 0;
        }
    }

    if(d==-1)
    {
        diff=0;
        i=0; j=0;
        while(i<a && j<s)
        {
            if(A[i]!=S[j])
            {
                diff++;
                j++;
            }
            else
            {
                i++; j++;
            }
            if(diff>1) return 0;
        }
    }

    if(d==1)
    {
        diff=0;
        i=0; j=0;
        while(i<a && j<s)
        {
            if(A[i]!=S[j])
            {
                diff++;
                i++;
            }
            else
            {
                i++; j++;
            }
            if(diff>1) return 0;
        }
    }

    return 1;
}
