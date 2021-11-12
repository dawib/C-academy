#include<stdio.h>

int nwd(int,int);

main()
{
    int z; scanf("%d", &z);//ilosc zestawow danych
    int a; int b;//liczby ktorych nwd bedziemy szukac
    int i;
    for(i=0; i<z; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);

        printf("%d\n", nwd(a,b));
    }
}

int nwd(int x, int y)
{
    if(x==y) return x;

    else if((x&1)==0 && (y&1)==0)
    {
        x=x>>1; y=y>>1;
        return (nwd(x, y))<<1;
    }

    else if((x&1)==0)
    {
        x=x>>1;
        return nwd(x, y);
    }

    else if((y&1)==0)
    {
        y=y>>1;
        return nwd(x, y);
    }

    else if(x>y)
    {
        x=(x-y)>>1;
        return nwd(x, y);
    }

    else
    {
        y=(y-x)>>1;
        return nwd(x, y);
    }
}
