

int czypierwsza(int a)
{
    int j;
    for(j=2; j*j<=a; j++)
    {
        if(a%j==0) return 0;
    }

    return 1;
}

main()
{
    int z;
    scanf("%d", &z);


    int i;
    for(i=0; i<z; i++)
    {
        int n;

        scanf("%d", &n);

        if (czypierwsza(n)==1) printf("%d jest pierwsza\n", n);
        else printf("%d jest zlozona\n", n);
    }

    return 0;
}
