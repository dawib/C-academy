#include<stdio.h>//program liczy ile liczb podzielnych przez 11, dlugosci k mozna ulozyc z n-elementowego zbioru

long long int silnia[13];

void f(char*, char*, int, int, int, int, int, long long int*);
void show(char*, int);
void f2(char*, int, int, int, long long int*, int, int, int, long long int);
void dolicz(char*, char*, int, long long int*);

main()//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    char T[30];//tablica cyfr z ktorych ukladamy liczby
    char P[30]={0};//tablica w ktorej zaznaczamy wybrane elementy
    int i, j;//indeksy
    long long int W;//tymczasowy wynik dla zestawu
    int n, k;//n-ilosc cyfr, k-dlugosc szukanych liczb
    int z; scanf("%d", &z);//ilosc zestawow danych

    //uzupelnienie tablicy silni---------------------------------------------------------------------------------------------------------------------------------------------
    silnia[0]=1;
    for(i=1; i<13; i++)
    {
        silnia[i]=i*silnia[i-1];
        //printf("%lld\n", silnia[i]);
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    for(i=0; i<z; i++)
    {
        W=0;//zerujemy licznik liczb

        scanf("%d", &n); scanf("%d", &k);//wczytanie n i k
        for(j=0; j<n; j++)//wczytanie tablicy cyfr
        {
            scanf("%d", T+j);
        }

        f(T, P, n, k, k, 0, 0, &W);

        printf("%lld\n", W);
    }
}//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

void f(char* t, char* p, int n, int K, int k, int i, int j, long long int* w)
//wybieranie cyfr
//t-tablica cyfr, p-tablica w ktorej zaznaczamy wybrane cyfry, n-dlugosc tych tablic
//K-ilucyfrowa ma byc liczba, k-ile jeszcze cyfr jest do wybrania
//i-od ktorego indeksu wybieramy, w-adres do zapisywanie wynikow
{
    if(k==0)//gdy mamy wybrane ile trzeba
    {
        //show(p, K);
        f2(p, K, K/2, 0, w, 0, 0, 0, 0);
        return;
    }

    if(i==n)//gdy mamy za malo
    {
        return;
    }

    p[j]=t[i];//wybieramy element i
    f(t, p, n, K, k-1, i+1, j+1, w);

    //nie wybieramy elementu i
    f(t, p, n, K, k, i+1, j, w);

    return;
}

void f2(char* p, int m, int k, int i, long long int* w, int a, int b, int d, long long int S)
//wyvbieranie polowy z wybranych juz cyfr
{
    //printf("i:%d k:%d, a:%d b:%d d:%d S:%lld\n", i, k, a, b, d, S);
    if(k==0)//gdy mamy wybrane ile trzeba
    {
        //show(t,p,n);
        //printf("a:%d b:%d d:%d S:%lld\n", a, b, d, S);
        if(i==m)
        {
            if(S%11==0) *w=*w+silnia[b]*(a-d)*silnia[a-1];//dodaj do wyniku
            return;
        }
        else//nie wybiermay elementu
        {
            if(p[i]==0) f2(p, m, k, i+1, w, a+1, b, d+1, S+p[i]);
            else        f2(p, m, k, i+1, w, a+1, b, d, S+p[i]);
            return;
        }
    }

    if(i==m) return;//gdy mamy wybrane za malo

                        f2(p, m, k-1, i+1, w, a, b+1, d, S-p[i]);//wybieramy element

    //nie wybieramy tego elementu
    if(p[i]==0)         f2(p, m, k, i+1, w, a+1, b, d+1, S+p[i]);
    else                f2(p, m, k, i+1, w, a+1, b, d, S+p[i]);

    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void dolicz(char* t, char*p, int n, long long int* w)
//sprawdza czy podzielne przez 11 i dodaje do wyniku
{
    int i;
    int a=0, b=0, d=0;
    long long int S=0;
    for(i=0; i<n; i++)
    {
        if(p[i]==2)
        {
            S+=t[i];
            b++;
        }
        if(p[i]==1)
        {
            S-=t[i];
            a++;
            if(t[i]==0) d++;
        }
    }

    if(S%11==0)//jesli suma na parzystych rowna sie sumie na nieparzystych
    {
        *w=*w+silnia[b]*(a-d)*silnia[a-1];
    }

    return;
}

void show(char* t, int n)//wyswietla tablice z wybranymi cyframi
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}
