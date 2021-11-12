#include<stdio.h>
#include<string.h>

#define N 1000000
char pasy[1000000][13];

main()
{
    int z, i;
    scanf("%d", &z);//liczba zestawow danych

    for(i=0; i<z; i++)
    {
        int n, j, zakup=0, control1=0, control2=0;
        scanf("%d", &n);//liczba pasow flagi

        char kolor1[13]="";
        char kolor2[13]="";


        for(j=0; j<n; j++)//wczytanie kolorow flagi
        {
            scanf("%s", pasy[j]);
        }

        int k=0;
        char lider[13]="";
        for(j=0; j<n; j=j+2)//znajdywanie kandydata na lidera wsrod pasow parzystych
        {
            //printf("%d\n", pasy[i]);
            if(k==0)
            {
                strcpy(lider, pasy[j]);
                k++;
                continue;
            }

            if(strcmp(lider, pasy[j])==0) k++;
            else k--;
        }
        //printf("::%d %s\n", k, lider);

        k=0;
        for(j=0; j<n; j+=2)//sprawdzanie czy kandydat jest liderem
        {
            if(strcmp(lider, pasy[j])==0) k++;
            //printf("%s %d\n", pasy[j], k);
        }
        if(k>n/4)
            {
                strcpy(kolor1, lider);//zapisanie pierwszego koloru
                control1=1;
            }
        else zakup++;
        //printf("::%d %s\n", k, kolor1);

        k=0;
        for(j=1; j<n; j+=2)//znajdywanie kandydata na lidera wsrod pasow nieparzystych
        {
            if(k==0)
            {
                strcpy(lider, pasy[j]);
                k++;
                continue;
            }

            if(strcmp(lider, pasy[j])==0) k++;
            else k--;
        }

        k=0;
        for(j=1; j<n; j+=2)//sprawdzanie czy kandydat jest liderem
        {
            if(strcmp(lider, pasy[j])==0) k++;
        }
        if(k>n/4)
            {
                strcpy(kolor2, lider);//zapisanie drgiego koloru
                control2=1;
            }
        else zakup++;

        if(strcmp(kolor1, kolor2)==0 && strcmp("", kolor1)!=0) printf("JEDNA %s", kolor1);
        else
        {
            switch(zakup)
            {
                case 0: printf("TAK "); break;
                case 1: printf("JEDNA "); break;
                case 2: printf("NIE"); break;
            }
            //printf("%d\n", control1);
            //printf("%d\n", control2);
            //scanf("%s", kolor2);

            if(control1==1) printf("%s ", kolor1);
            if(control2==1) printf("%s", kolor2);

        }
        printf("\n");

    }
}
