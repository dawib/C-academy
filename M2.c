#include<stdio.h>
#include<stdlib.h>

void wczytaj(int **M, int a, int b)
{
    int i;
    for(i=0; i<a; i++)
    {
        int j;
        for(j=0; j<b; j++)
        {
            scanf("%d", *(M+i)+j);
        }
    }
}

void wypisz(int **M, int a, int b)
{
    int i;
    for(i=0; i<a; i++)
    {
        int j;
        for(j=0; j<b; j++)
        {
            printf("%03d ", *(*(M+i)+j));
        }
        printf("\n");
    }
}

main()
{
   int z;//ilosc zestawow
   scanf("%d", &z);
   int i;
   for(i=0; i<z; i++)
   {
       int m, n;//inicjalizacja pierwszej macierzy--------------------------------------------------------------------------------------------------
       scanf("%d", &m);//ilosc wierszy pierwszej macierzy
       scanf("%d", &n);//ilosc kolumn pierwszej macierzy

       int *a=malloc(m*n*sizeof(int));
       int **A=malloc(m*sizeof(int*));
       int j;
       for(j=0; j<m; j++)
       {
           *(A+j)=a+n*j;
       }

       wczytaj(A, m, n);

       int x, y;//inicjalizacja drugiej macierzy-----------------------------------------------------------------------------------------------------
       scanf("%d", &x);//ilosc wierszy drugiej macierzy
       scanf("%d", &y);//ilosc kolumn drugiej macierzy

       int *b=malloc(x*y*sizeof(int));
       int **B=malloc(x*sizeof(int*));
       for(j=0; j<x; j++)
       {
           *(B+j)=b+y*j;
       }

       wczytaj(B, x, y);

       if(n!=x)//jesli wymiary sa nieodpowiednie i nie da sie pomnozyc-------------------------------------------------------------------------------
       {
           printf("ERROR\n");
           free(a); free(A); free(b); free(B);
           continue;
       }

       int *c=malloc(m*y*sizeof(int));//inicjalizacja macierzy wyjsciowej-----------------------------------------------------------------------------
       int **C=malloc(m*sizeof(int*));
       for(j=0; j<m; j++)
       {
           *(C+j)=c+y*j;
       }
       for(j=0; j<m; j++)//wypelnianie jej zerami--------------------------------------------------------------------------
       {
           int k;
           for(k=0; k<y; k++)
           {
               *(*(C+j)+k)=0;
           }
       }

       for(j=0; j<m; j++)//wymnazanie A i B i zapisywanie wyniku do C----------------------------------------------------------------------------------
       {
           int k;
           for(k=0; k<n; k++)
           {
               int l;
               for(l=0; l<y; l++)
               {
                    *(*(C+j)+l)=(*(*(C+j)+l)+(*(*(A+j)+k)**(*(B+k)+l))%1000)%1000;
               }
           }
       }

       wypisz(C, m, y);//wyswietlenie wyniku-----------------------------------------------------------------------------------------------------------

       free(a); free(A); free(b); free(B); free(c); free(C);//zwalnianie pamiêci-----------------------------------------------------------------------
   }
}
