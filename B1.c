#include<stdio.h>



main()
{
    //const int R=10001;
    int sito[10000001] = {0};
    //printf("ok");
    sito[0]=1;
    sito[1]=1;
    //przygotowanie sita
    int i;
    for(i=2; i<10000001; i++)
    {
        if(sito[i]==0)
        {
            int j;
            for(j=i; j*i<10000001; j++)
            {
                sito[j*i]=1;
            }
        }
    }
    //printf("ok");
    for(i=1; i<10000001; i++)
    {
        sito[i]=sito[i-1]+sito[i];
    }
    //mamy przygotowane sito

    int z, a, b;
    scanf("%d", &z);

    for(i=0; i<z; i++)
    {
        scanf("%d", &a); scanf("%d", &b);
        printf("%d\n", (b+1)-sito[b]-(a-sito[a-1]));
    }
}
