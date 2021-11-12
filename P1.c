#include<stdio.h>
#include<string.h>

char f(char*, int, int, int);
int abs(int);

char sito[1111112]={0};
main()//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    int i, j, d, x, a;
    //wypelnienie sita eratostenesa--------------------------------------------------------------------------------------------------------------------------
    sito[0]=1;
    sito[1]=1;
    for(i=2; i<1111111; i++)
    {
        if(sito[i]==0)
        {
            for(j=i; j*i<1111111 && j*i>0; j++)
            {
                sito[j*i]=1;
            }
        }
    }
    //sito gotowe--------------------------------------------------------------------------------------------------------------------------------------------

    char liczba[11];
    int z; scanf("%d", &z);//ilosc zestawow

    for(i=0; i<z; i++)
    {
        scanf("%s", liczba);
        d=strlen(liczba);
        sscanf(liczba,"%d", &a);

        x=f(liczba, a, d, 0);

        if(x==0) printf("NIE\n");
        else printf("TAK %s\n", liczba);
    }
}//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

int abs(int a)
{
    if(a>=0) return a;
    else return -a;
}

char f(char* t, int a, int n, int k)//t-permutowana tablica, n-dlugosc tej tablicy, k-od ktorego wyrazu permutujemy
{
    int b, x, l, sw;
    char c;

    if(k==n-1)//sprawdzamy tablice jak siê po niej przepermutujemy
    {
        sscanf(t,"%d", &b);

        x=abs(a-b)/9;

        if(x>1111111) return 0;

        if(sito[x]==0) return 1;
        return 0;
    }

    for(l=k; l<n; l++)
    {
        sw=t[k];
        t[k]=t[l];
        t[l]=sw;

        c=f(t, a, n, k+1);
        if(c==1) return 1;

        sw=t[k];
        t[k]=t[l];
        t[l]=sw;
    }

    return 0;
}
