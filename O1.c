#include<stdio.h>

main()
{
    int z; scanf("%d", &z);//ilosc zestawow danych
    int a; int b;//liczby ktorych nwd bedziemy szukac
    int k;//wielokrotnik nwd
    int i;
    for(i=0; i<z; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        k=0;
        while(a!=b)
        {
            if((a&1)==0 && (b&1)==0)
            {
                k++;
                a=a>>1;
                b=b>>1;
            }
            else if((a&1)==0)
            {
                a=a>>1;
            }
            else if((b&1)==0)
            {
                b=b>>1;
            }
            else if(a>b)
            {
                a=(a-b)>>1;
            }
            else
            {
                b=(b-a)>>1;
            }
        }

        a=a<<k;
        printf("%d\n", a);
    }
}
