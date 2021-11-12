#include<stdio.h>

#define N 1000001
int kaszt[N];

main()
{
    int z, i;
    scanf("%d", &z);
    for(i=0; i<z; i++)
    {
        int k, j, s;
        scanf("%d", &k);
        scanf("%d", &kaszt[0]);
        for(j=1; j<k; j++)
        {
            scanf("%d", &s);
            kaszt[j]=kaszt[j-1]+s;
        }

        int q;
        scanf("%d", &q);
        for(j=0; j<q; j++)
        {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);

            int l=0;
            int p=k;

            while(l!=p)
            {
                s=(p+l)/2;
                if(kaszt[s]>b) p=s;
                else l=s+1;
            }

            b=l;

            l=-1;
            p=k-1;

            while(l!=p)
            {
                s=(l+p+1)/2;
                if(kaszt[s]<a) l=s;
                else p=s-1;
            }

            a=l;

            printf("%d\n", b-a-1);
        }

    }
}
