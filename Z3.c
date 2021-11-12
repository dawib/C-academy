#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct//struktura przechowuj¹ca nazwisko klienta i ile wydal
    {
        char nazwisko[11];
        char lown[11];
        float wydane;
    } klient;

klient T[60000];

main()
{
    int z, i;
    scanf("%d", &z);

    int knut[11];
    knut[0]=1;
    for(i=1; i<11; i++)
    {
        knut[i]=3*knut[i-1]+1;
    }

    for(i=0; i<z; i++)
    {
        //wczytanie danych-----------------------------------------------------------------------------------------------------------------------------------------------------
        int n;//n-l transakcji, p-prog wydanyych pieniedzy
        int p;
        scanf("%d", &n);
        scanf("%d", &p);

        int j;
        for(j=0; j<n; j++)//zapisanie nazwisk malymi literami
        {
            scanf("%s", T[j].nazwisko);
            scanf("%f", &T[j].wydane);

            int k;
            for(k=0; k<strlen(T[j].nazwisko); k++)
            {
                T[j].lown[k]=tolower(T[j].nazwisko[k]);
            }
            T[j].lown[k]=NULL;
        }
        //znalezienie pierwszego knuta---------------------------------------
        j=0;
        while(knut[j]<=(n+2)/3)
        {
            j++;
        }
        j--;
        int x=j;
        //sortowanie tablicy------------------------------------------------------------------------------------------------------------------------------------------
        klient SW;

        for(;j>=0; j--)//male litery
        {
            int k;
            for(k=0; k<knut[j]; k++)
            {
                int l;
                for(l=k; l<n; l+=knut[j])
                {
                    SW=T[l];
                    int y=l;

                    while( y-knut[j]>=0 && strcmp(SW.lown, T[y-knut[j]].lown)<0 )
                    {
                        T[y]=T[y-knut[j]];
                        y-=knut[j];
                    }

                    T[y]=SW;
                }
            }
        }

        for(j=x ;j>=0; j--)//duze litery
        {
            int k;
            for(k=0; k<knut[j]; k++)
            {
                int l;
                for(l=k; l<n; l+=knut[j])
                {
                    SW=T[l];
                    int y=l;

                    while( y-knut[j]>=0 && strcmp(SW.nazwisko, T[y-knut[j]].nazwisko)<0 && strcmp(SW.lown, T[x-1].lown)==0 )
                    {
                        T[y]=T[y-knut[j]];
                        y-=knut[j];
                    }

                    T[y]=SW;
                }
            }
        }

        for(j=n-2; j>=0; j--)//posumowanie wydanych kwot---------------------------------------------------------------------------------------------------------------------
        {
            if(strcmp(T[j].lown,T[j+1].lown)==0)
            {
                T[j].wydane+=T[j+1].wydane;
                T[j+1].wydane=-1;
            }
        }

        /*for(j=0; j<n; j++)
        {
            printf("%s %s %.2f\n", T[j].nazwisko, T[j].lown, T[j].wydane);
        }*/
        //wypisanie stalych klientow-------------------------------------------------------------------------------------------------------------------------------------------
        printf("%d\n", p);
        for(j=0; j<n; j++)
        {
            if(T[j].wydane>=p)
            {
                printf("%s %.2f\n", T[j].nazwisko, T[j].wydane);
            }
        }
    }
}

