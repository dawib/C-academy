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
        //sortowanie tablicy------------------------------------------------------------------------------------------------------------------------------------------
        //char C[11];
        //char L[11];
        klient SW;
        //float c;
        for(j=1; j<n; j++)
        {
            int x=j;
            SW=T[j];
            while(x>0 && strcmp(SW.lown, T[x-1].lown)<0)//sortowanie po nazwiskach zapisanych malymi literami
            {
                T[x]=T[x-1];

                x--;
            }

            while(x>0 && strcmp(SW.nazwisko, T[x-1].nazwisko)<0 && strcmp(SW.lown, T[x-1].lown)==0)//sortowanie po zwyklych nazwiskach
            {
                T[x]=T[x-1];

                x--;
            }
            T[x]=SW;
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
