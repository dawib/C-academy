

int is_prime(int a)
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

        if (is_prime(n)==1) printf("%d is prime\n", n);
        else printf("%d is composite\n", n);
    }

    return 0;
}
