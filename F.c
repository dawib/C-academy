#include<stdio.h>
#include<string.h>

char nawiasy[51];
char podnawias[51];
int klamry[50][2];

int czypoprawnenawiasy()
{
    int control=0;
    int j;
    int lent=strlen(nawiasy);
    for(j=0; j<lent; j++)
    {
        if(nawiasy[j]=='(') control++;
        else control--;
        if(control<0) return 0;
    }

    if(control) return 0;
    else return 1;
}

int czypoprawnypodnawias(int a, int b)
{
    int j;
    int control=0;
    //int lent=strlen(nawiasy);
    for(j=a; j<b+1; j++)
    {
        if(nawiasy[j]=='(') control++;
        else control--;
        if(control<0) return 0;
    }

    if(control) return 0;
    else return 1;
}

void pokazpodnawias(int a, int b)
{
    int j;
    int lent=strlen(nawiasy);
    for(j=0; j<=lent; j++)
    {
        if(j==a) printf("[");
        if(j==b+1) printf("]");
        printf("%c", nawiasy[j]);
    }
    printf("\n");
}

main()
{
    int n, i;
    scanf("%d", &n);//wczytanie liczby zapytan

    for(i=0; i<n; i++)
    {
        int j;
        scanf("%s", nawiasy);
        //printf("%d", strlen(nawiasy));
        if(czypoprawnenawiasy()) printf("TAK\n");
        else printf("NIE\n");
        int len=strlen(nawiasy);
        int x, y;
        int c=0;
        for(x=0; x<len; x++)
        {
            for(y=x+1; y<len; y++)
            {
                if(czypoprawnypodnawias(x,y))
                {
                    klamry[c][0]=x;
                    klamry[c][1]=y;
                    c++;
                }
                //else printf("F");
            }
        }
        printf("%d\n", c);
        for(j=0; j<c; j++)
        {
            pokazpodnawias(klamry[j][0], klamry[j][1]);
        }
    }
}
