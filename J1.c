#include<stdio.h>

typedef struct
{
    int il;
    char spec[301];
}pracownik;

int potegamod1000(int x, int k)
{
    if(k==0) return 1;

    if(k%2==1) return (x*potegamod1000(x, k/2)*potegamod1000(x, k/2))%1000;
    else return (potegamod1000(x, k/2)*potegamod1000(x, k/2))%1000;
}

main()
{
    pracownik prac[301];

    int z;
    scanf("%d", &z);//ilosc zestawow danych
    int i;
    for(i=0; i<z; i++)
    {
        int n, m, t, u, h;
        scanf("%d", &n);//ilosc pracownikow
        scanf("%d", &m);//ilosc specjalizacji
        scanf("%d", &t);//wymagana ilosc wspolnych specjalizacji
        scanf("%d", &u);//wymagana ilosc pracownikow z ktorymi sie dzieli specjalizacje
        scanf("%d", &h);//ilosc zadan do przydzielenie

        int p=0;//ilosc uniwersalnych pracownikow

        int j;
        for(j=0; j<n; j++)
        {
            scanf("%s", prac[j].spec);
            prac[j].il=0;
        }

        int S=0;//ilosc uniwersalnych pracownikow

        for(j=0; j<n-1; j++)//dla kazdego pracownika
        {
            int k;
            for(k=j+1; k<n; k++)//sprawdzamy jego relacje z kazdym innym pracownikiem
            {
                int l;
                int s=0;
                for(l=0; l<m; l++)//zliczajac wspolne specjalizacje
                {
                    if(prac[j].spec[l]=='1' && prac[k].spec[l]=='1') s++;
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
            if(prac[j].il>=u) S++;
        }

        printf("%d %03d\n", S, potegamod1000(S, h));
    }
}
