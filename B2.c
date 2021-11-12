#include<stdio.h>
#include<math.h>

#define N 10000001

int dzielnik[N];
int dosk[N];

long long int pot(int a, int b)
{
    long long int s=1;
    int i;
    for(i=0; i<b; i++)
    {
        s*=a;
    }
    return s;
}

void rozloznapierwsze(int a)
{
    while(a>1)
    {
        printf("%d, ", dzielnik[a]);
        a/=dzielnik[a];
    }
    printf("\n");
}

long long int sigma(int a)
{
    long long int s=1, S=1;
    int d=dzielnik[a], i=1;
    //if(d==a) return 1;
    while(a!=1)
    {

        while(d==dzielnik[a])
        {

            //printf("%d\n", s);
            //printf("..%d\n", pot(d, i));
            s+=pot(d, i);
            i++; a=a/dzielnik[a];
            //printf("%d\n", s);
        }

        d=dzielnik[a]; i=1;

        S*=s;
        //printf(":::%d\n", S);
        s=1;

    }

    return S;
}

main()
{
    int i;
    for(i=0; i<N; i++)
    {
        dzielnik[i]=i;
        dosk[i]=0;
    }


    for(i=2; i*i<N && i*i>0; i++)
    {
        //printf("%d\n", i);
        if(dzielnik[i]==i)
        {
            int j;
            for(j=i; j*i<N && j*i>0; j++)
            {
                dzielnik[j*i]=i;
            }
        }
    }

    dosk[0]=0; dosk[1]=0;
    for(i=2; i<N; i++)
    {
        if((dzielnik[i/dzielnik[i]]==i/dzielnik[i] && dzielnik[i]!=i && dzielnik[i]!=i/dzielnik[i]) || (dzielnik[i]*dzielnik[i]*dzielnik[i]==i)) dosk[i]=1;
        //else dosk[i]=dosk[i-1]+dosk[i];
    }

    for(i=2; i<N; i++)
    {
        dosk[i]=dosk[i]+dosk[i-1];
    }


    int z, a, b;
    scanf("%d", &z);
    for(i=0; i<z; i++)
    {
        scanf("%d", &a); scanf("%d", &b);
        printf("%d ", dosk[b]-dosk[a-1]);
        int k, l=0;
        /*for(k=a; k<=b; k++)
        {
            l+=dosk[k];
            printf("%d:%d-%d\n", k, dosk[k], l);
            if(dosk[k]==1) rozloznapierwsze(k);
        }*/
        if(sigma(a)==(long long int)2*a) printf("TAK "); else printf("NIE ");
        if(sigma(b)==(long long int)2*b) printf("TAK\n"); else printf("NIE\n");
        //printf("%d", sigma(a)-a);
    }
}
