#include<stdio.h>

#define N 500000

//int czynpier[N];//tabela z czynnikami pierwszymi
//int czywyk[N];//tabela pokazujaca czy dana liczba pojawila sie juz w ciagu
int mag[N];//magiczny ciag
int pozycje[N];//tablica z pozycjami liczb

int nwd(int a, int b)
{
    int c;
    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

main()
{
    //ustawianie poczatkowe potrzebnych tablic------------------------------------------------------
    int i, j;

    for(i=0; i<N; i++)
    {
        pozycje[i]=0;
    }
    //printf("%d\n", nwd(2,3));
    printf("tablice gotowe\n");

    //uzupelnianie magicznego ciagu--------------------------------------------------------------------
    mag[0]=1; pozycje[1]=0;
    mag[1]=2; pozycje[2]=1;
    for(i=2; i<N; i++)
    {
        for(j=1; ;j++)
        {
            if(pozycje[j]==0 && nwd(j, mag[i-1])!=1 && j!=mag[i-1])
            {
                mag[i]=j;
                pozycje[j]=i;
                //czywyk[j]=1;
                //printf("%d::", j);
                break;
            }
        }
    }
    printf("magiczny ciag gotowy\n");
    //wlasciwa czesc programu-------------------------------------------------------------------------
    int z;//licza zapytan
    int a;
    scanf("%d", &z);
    for(i=0; i<z; i++)
    {
        scanf("%d", &a);
        printf("%d\n", pozycje[a]);
    }
}
