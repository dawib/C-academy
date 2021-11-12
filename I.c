#include<stdio.h>
#include<string.h>

char rejestr[61];
char liczba1[61];
char liczba2[62];

long long int convp2d(int p)//zamienia liczbe zapisana w systemie p na liczbe w systemie dziesietnym
{
    if(liczba1[0]=='0') return 0;
    long long int l;
    if (liczba1[0]<='9' && '0'<=liczba1[0]) l=liczba1[0]-'0';
    else l=liczba1[0]+10-'A';
    //printf("%d", l);
    int i;
    for(i=1; i<strlen(liczba1); i++)
    {
        l*=p;
        if (liczba1[i]<='9' && '0'<=liczba1[i]) l+=liczba1[i]-'0';
        else l+=liczba1[i]-'A'+10;

    }
    //printf("%lld:\n", l);
    return l;
}

void convd2q(int q, long long int l)//zmienia liczbe zapisana w systemie dziesietnym na liczbe w systemie q
{
    //printf("%d\n", l);
    if(l==0)
    {
        liczba1[0]='0';
        liczba1[1]=NULL;
        return;
    }
    int i;
    for(i=0; l!=0; i++)
    {
        //printf("%d:", l%q);
        if(l%q<10) liczba2[i]='0'+l%q;
        else liczba2[i]='A'+l%q-10;
        //printf("%c:", liczba2[i]);
        //printf("%d:", l);
        l/=q;
    }

    int r=i-1;
    for(i=0; i<=r; i++)
    {
        liczba1[i]=liczba2[r-i];
        //printf("%c", liczba1[i]);
    }
    liczba1[i]=NULL;
}

void zapisz_dod(long long int x, int r)//zapisuje odatnia liczbe w rejestrze
{
    int i;
    for(i=0; i<r; i++)
    {
        rejestr[r-1-i]='0'+x%2;
        x/=2;
    }
    if(rejestr[0]=='1' || x!=0) rejestr[0]='2';
}

void zapisz_ujemn(long long int x, int r)//zapisuje ujamna liczbe w rejestrze
{
    zapisz_dod(-x-1, r);

    int i;
    for(i=0; i<r; i++)
    {
        if(rejestr[i]=='0') rejestr[i]='1';
        else if(rejestr[i]=='1') rejestr[i]='0';
    }
}

long long int odczytaj_rejestr()
{
    long long int l=rejestr[1]-'0';
    int i;
    for(i=2;i<strlen(rejestr); i++)
    {
        l*=2;
        l+=rejestr[i]-'0';
    }

    return l;
}

void drukuj_rejestr(int r)//wysyla zawartosc rejestru na standardowe wyjscie
{
    if(rejestr[0]=='2')
    {
        printf("ERROR\n");
        return;
    }
    int i;
    for(i=0; i<r; i++)
    {
        printf("%c", rejestr[i]);
    }
    printf("\n");
}

main()
{
    int z;
    int i;
    scanf("%d", &z);//liczba zestawow
    for(i=0; i<z; i++)
    {
        char polecenie[11];//co chcemy zrobic
        scanf("%s", polecenie);

        switch(polecenie[0])
        {
            case 'C'://CONVERT- zmienia liczbe z systemu p w system q
                {
                    int p, q;
                    scanf("%d", &p);//pierwotny system liczbowy
                    scanf("%d", &q);//wyjsciowy system liczbowy

                    scanf("%s", liczba1);

                    convd2q(q, convp2d(p));
                    printf("%s\n", liczba1);

                    break;
                }

            case 'W'://WRITE- zapisuje liczbe jako kod w rejestrze komputera
                {
                    int r;//dlugosc rejestru
                    scanf("%d", &r);

                    long long int x;//liczba ktora chcemy zapisac
                    scanf("%lli", &x);

                    if(x>=0) zapisz_dod(x, r);
                    else zapisz_ujemn(x, r);

                    drukuj_rejestr(r);

                    break;
                }

            case 'R'://READ- odczytuje liczbe zapisana jako kod w rejestrze
                {
                    scanf("%s", rejestr);

                    if(rejestr[0]=='1')
                    {
                        int j;
                        for(j=0; j<strlen(rejestr); j++)
                        {
                            if(rejestr[j]=='0') rejestr[j]='1';
                            else rejestr[j]='0';
                        }

                        printf("%lli\n", -odczytaj_rejestr()-1);
                    }

                    else
                    {
                        printf("%lli\n", odczytaj_rejestr());
                    }
                }
        }
    }
}
