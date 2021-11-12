#include<stdio.h>

int kw(int a)
{
    return (a*a)%1000;
}

typedef struct
{
    int il;
    int spec[625];
}pracownik;

int potegamod1000(int x, int k)
{
    if(k==0) return 1;

    if(k%2==1) return (x*kw(potegamod1000(x, k/2)))%1000;
    else return (kw(potegamod1000(x, k/2)))%1000;
}

/*int potega(int x, int k)
{
    if(k==0) return 1;

    if(k%2==1) return x*potega(x, k/2)*potega(x, k/2);
    else return potega(x, k/2)*potega(x, k/2);
}*/

main()
{
    //tablica pracownikow
    int i;
    int tab[65536];//tablica mowiaca ile jedynek ma kazda z liczb
    int z;
    scanf("%d", &z);//ilosc zestawow danych

    int j;
    tab[0]=0;
    tab[1]=1;
    for(j=2; j<65536; j++)//wypelnianie tablicy jedynek
    {
        tab[j]=tab[j/2]+j%2;
    }

    for(i=0; i<z; i++)
    {
        pracownik prac[301]={0};
        int n, m, t, u, h;
        scanf("%d", &n);//ilosc pracownikow
        scanf("%d", &m);//ilosc specjalizacji
        scanf("%d", &t);//wymagana ilosc wspolnych specjalizacji
        scanf("%d", &u);//wymagana ilosc pracownikow z ktorymi sie dzieli specjalizacje
        scanf("%d", &h);//ilosc zadan do przydzielenie

        int p=0;//ilosc uniwersalnych pracownikow

        char C[10001];
        //char c;
        for(j=0; j<n; j++)//odczytywanie specjalizacji pracownikow
        {
            scanf("%s", C);
            int x=0;//ilosc sczytanych specjalizacji
            int k=0;
            int l=0;
            /*for(x=0; x<m; x++)
            {
                if(l==16)
                {
                    k++;
                    l=0;
                }

                prac[j].spec[k]+=(C[x]-'0')*(1<<l);
                l++;
            }*/

            for(k=0; k<m/16+1; k++)
            {
                int l=0;
                while(l<16 && x<m)
                {
                    prac[j].spec[k]+=(C[x]-'0')*(1<<l);

                    l++; x++;
                }
            }
        }

        int S=0;//ilosc uniwersalnych pracownikow

        for(j=0; j<n-1; j++)//dla kazdego pracownika
        {
            int k;
            for(k=j+1; k<n; k++)//sprawdzamy jego relacje z kazdym innym pracownikiem
            {
                int l;
                int s=0;//il wspolnych specjalizacji
                for(l=0; l<(m+15)/16; l++)//zliczajac wspolne specjalizacje
                {
                    s+=tab[prac[j].spec[l]&prac[k].spec[l]];
                }
                if (s>=t)
                {
                    prac[k].il++;
                    prac[j].il++;
                }
            }
        }

        for(j=0; j<n; j++)
        {
            //printf("%d\n", prac[j].il);
            if(prac[j].il>=u) S++;
        }

        printf("%d %03d\n", S, potegamod1000(S, h));
    }
}
