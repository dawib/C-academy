#include<stdio.h>

int T[100000];
int n;

void sortujwybieranie(int n)
{
    int i;
    for(i=n-1; i>0; i--)
    {
        int j;
        int m=0;
        int c;
        for(j=0; j<=i; j++)//znajdywanie indeksu najwiekszego elementu w tablicy
        {
            if(T[m]<T[j]) m=j;
        }

        c=T[i];
        T[i]=T[m];
        T[m]=c;
    }
}

main()
{
    int z;
    int ctrl;
    scanf("%d", &z); //liczba zestawow

    int i;
    for(i=0; i<z; i++)
    {
        //int n;
        int a, b, c;
        ctrl=0;
        scanf("%d", &n); //ilosc liczb

        int j;
        for(j=0; j<n; j++)//wczytanie tablicy liczb
        {
            scanf("%d", &T[j]);
        }

        sortujwybieranie(n);//sortowanie tablicy

        for(j=0; j<n; j++)
        {
            printf("%d ", T[j]);
        }
        printf("\n");


        for(j=0; j<n && ctrl!=1; j++)
        {
            a=j;
            b=j;
            c=n-1;

            do
            {
                if(T[a]+T[b]+T[c]==0)
                {
                    printf("TAK %d %d %d\n", a, b, c);
                    ctrl=1;
                    break;
                }
                else if(T[a]+T[b]+T[c]>0)
                {
                    c--;
                }
                else
                {
                    b++;
                }


            }while(b<c);

            if(T[a]+T[b]+T[c]==0 && ctrl!=1)
            {
                printf("TAK %d %d %d\n", a, b, c);
                ctrl=1;
                break;
            }
        }

        if(ctrl==0) printf("NIE\n");
    }
}

