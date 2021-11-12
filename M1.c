#include<stdio.h>



main()
{
    int z;//ilosc zestawow
    scanf("%d", &z);
    int i, j, k;
    for(i=0; i<z; i++)
    {
        int n;//ilosc cukierkow
        scanf("%d", &n);
        int *cuk=malloc(n*sizeof(int));//inicjalizacja tablicy cukierkow

        int m;//ilosc smakow
        scanf("%d", &m);
        int *smakl=calloc(m, sizeof(int));//inicjalizacja tablicy do sprawdzania smakow po lewej
        int *smakp=calloc(m, sizeof(int));//inicjalizacja tablicy do sprawdzania smakow po prawej

        for(j=0; j<n; j++)//wczytanie tablicy cukierkow
        {
            scanf("%d", cuk+j);
        }

        int L=0; int PM=0;
        int P=0; int LM=0;
        int M=0; int jM;
        k=0;
        while(*(smakp+*(cuk+k+1))==0 && k<n-2)//uzupelnienie tablicy smakow po prawej
        {
            *(smakp+*(cuk+k+1))=1;
            k++;
        }
        P=k;

        for(j=1; j<n-1; j++)//uzupelnienie P i L
        {
            *(smakl+*(cuk+j-1))+=1;
            *(smakp+*(cuk+j))-=1;

            while(*(smakl+*(cuk+j-1))>1)//znalezienie L
            {
                *(smakl+*(cuk+L))-=1;
                L++;
            }

            while(P<n-1 && *(smakp+*(cuk+P+1))==0)//znalezienie P
            {
                P++;
                *(smakp+*(cuk+P))+=1;
            }
            if(P-L>M)
            {
                M=P-L;
                jM=j;
                PM=P;
                LM=L;
            }
        }
        printf("%d %d %d\n", jM, jM-LM, PM-jM);
        free(cuk); free(smakl); free(smakp);
    }
}
