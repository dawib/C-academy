#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

char alnum(char);
bool isGood(const char*, const char*);

main(int n, char *arg[])
{
    if(n<4) return 1;//za malo argumentow

    fstream IN; fstream OUT;
    IN.open(arg[1], ios::in); OUT.open(arg[2], ios::out);

    if(!IN.is_open()) return 2;//niepoprawnie otwarty plik

    int line=1;//licznik linii
    int word=0;//licznik wyrazow
    int good=0;//licznik dobrych wyrazow

    char read[32]; read[0]='\0';//pomocniczy string do czytania wyrazow
    char special[32];

    int i=0;
    char c;
    bool in=false;
    char comm=0;
    char d;

    for(i=0; arg[3][i]!='\0'; i++)
    {
        special[i]=tolower(arg[3][i]);
    }
    special[i]='\0';

    i=0;
    while(c!=EOF)
    {
        c=IN.get();
        d=alnum(c);

        if(c=='/')
        {
            c=IN.get();
            if(c=='*')
            {
                comm++;
                continue;
            }
            else
            {
                IN.putback(c);
                c='/';
            }
        }

        if(c=='*' && comm>0)
        {
            c=IN.get();
            if(c=='/')
            {
                comm--;
                continue;
            }
            else
            {
                IN.putback(c);
                c='*';
            }
        }

        if(comm==0)//jesli nie jestesmy w komentarzu........................................................................................
        {
            if(d>0)//jesli przeczytalismy znak alfanumeryczny
            {
                if(!in && d==2)//jesli zaczyna sie slowo
                {
                        in=true;
                        word++;
                        i=0;
                }
            }
            else
            {
                if(in)
                {
                    in=false;
                    read[i]='\0';

                    if(isGood(read, special)==1)
                    {
                        good++;
                        OUT<<"Linia "<<line<<": "<<read<<endl;
                    }
                }
            }

            if(c=='\n') line++;

            if(in)
            {
                read[i]=tolower(c);
                if(31>i) i++;
                else i=31;
            }
        }
    }

    OUT<<"Wyrazy: "<<word<<endl<<"Wyrazy specjalne: "<<good;

    IN.close(); OUT.close();
}

char alnum(char c)//sprawdzanie czy znak jest litera cyfra czy czyms innym===================================================================================
{
    if(c>=48 && c<=57) return 1;

    if(c>=65 && c<=90) return 2;

    if(c>=97 && c<=122) return 2;

    return 0;
}

bool isGood(const char* A, const char* S)//sprawdzanie czy wyraz jest wyrazem dobrym=========================================================================
{
    int a=strlen(A); int s=strlen(S); int d=a-s;

    if(d<-1 || d>1) return false;

    int i,j;
    int diff=0;//ilosc roznych liter

    if(d==0)
    {
        for(i=0; i<a; i++)
        {
            if(A[i]!=S[i]) diff++;
            if(diff>1) return false;
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
            if(diff>1) return false;
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
            if(diff>1) return false;
        }
    }

    return true;
}

