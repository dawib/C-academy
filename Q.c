#include<stdio.h>

typedef struct
{
    int x;
    int y;
}kier;

void wczytaj(char M[42][42], int, int);
void pokaz(char M[42][42], int, int);
char f(int, int, int, int, char M[42][42], int, int, char, int, int, int, int);
void trasa();

int droga[1601][2];
int indeks;

main()//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    char T[42][42];//mapa

    int z; scanf("%d", &z);//ilosc zestawow
    int n, m;//rozmiar mapy, wiersze, kolumny
    int i, j;
    int a, b, c, d;//start i cel
    char e;

    /*for(j=0; j<42; j++)
    {
        T[0][j]=1;
    }
    for(i=0; i<42; i++)
    {
        T[i][0]=1;
    }*/
    //pokaz(T, 42, 42);
    for(i=0; i<z; i++)
    {
        scanf("%d %d", &n, &m);

        scanf("%d %d %d %d", &a, &b, &c, &d);

        wczytaj(T, n, m);
        //pokaz(T, n, m);
        indeks=0;
        e=f(a, b, c, d, T, n, m, 1, 1, 0, a, b);
        if(e)
        {
            printf("TAK %d\n", indeks+1);
            trasa();
        }
        else
        {
            printf("NIE\n");
            //trasa();
        }
    }
}//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

void trasa()
{
    int i;
    for(i=0; i<indeks; i++)
    {
        printf("%d %d, ", droga[i][0], droga[i][1]);
    }
    printf("%d %d\n", droga[indeks][0], droga[indeks][1]);
}

void wczytaj(char M[42][42], int n, int m)//==============================================================================================================================
{
    int i, j;
    for(j=0; j<=m+1; j++) M[0][j]=1;

    for(i=1; i<=n; i++)
    {
        M[i][0]=1;
        for(j=1; j<=m; j++)
        {
            scanf("%d", &(M[i][j]));
        }
        M[i][m+1]=1;
    }
    for(j=0; j<=m+1; j++) M[n+1][j]=1;
}

void pokaz(char M[42][42], int n, int m)//===================================================================================================================================
{
    int i,j;
    for(i=0; i<=n+1; i++)
    {
        for(j=0; j<=m+1; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void pole(int a, int b, char M[42][42])
{
    printf("  %d  \n%d %d %d\n  %d\n", M[a-1][b], M[a][b-1], M[a][b], M[a][b+1], M[a+1][b]);
}

char f(int a, int b, int c, int d, char M[42][42], int n, int m, char l, int x, int y, int A, int B)//==========================================================================
//a, b-pole na ktorym stoimy; c, d-cel; M-mapa; n,m-rozmiary mapy; l-czy mamy line; x,y-kierunek przemieszczania sie; A,B-start
{
    //pole(a, b, M);
    //printf("--%d %d\ni:%d\n2,1:%d\n\n", a, b, indeks, M[3][1]);

    droga[indeks][0]=a; droga[indeks][1]=b;
    char sw=M[a][b];
    if(sw==2) l=0;
    char z;
    if(a==c && b==d) return 1;//jesli jestesmy u celu to znaczy ze sie da dojsc

    if(M[a][b]==0)
    {
        M[a][b]=1;//zaznaczamy pole jako odwiedzone
    }
    //sprawdzamy czy mozemy dalej isc w tym kierunku-------------------------------------------------------------------------------------------------------------------------

    if( M[a+x][b+y]==0 )//jezeli mozna wejsc na nastepne pole
    {
        indeks++;
        z=f(a+x, b+y, c, d, M, n, m, l, x, y, A, B);
        if(z==0) indeks--;


        if(a==A && b==B)
        {
            if(z==1)
            {
                M[a][b]=sw;
                return z;
            }
        }
        else
        {
            M[a][b]=sw;
            return z;
        }
    }

    if( M[a+x][b+y]==2 && l==1 )//co jesli na nastepnym polu jest przepasc ale mamy line
    {
        indeks++;
        z=f(a+x, b+y, c, d, M, n, m, 0, x, y, A, B);
        if(z==0) indeks--;


        if(a==A && b==B)
        {
            if(z==1)
            {
                M[a][b]=sw;
                return z;
            }
        }
        else
        {
            M[a][b]=sw;
            return z;
        }
    }
    //teraz co jesli nie da sie dalej isc

    if( M[a+y][b-x]==0 )//drugi kierunek------------------------------------------------------------------------------------------------------------------------------
    {
        indeks++;
        z=f(a+y, b-x, c, d, M, n, m, l, y, -x, A, B);
        if(z==0) indeks--;
        if(z==1)
        {
            M[a][b]=sw;
            return 1;
        }
    }

    if( M[a+y][b-x]==2 && l==1 )
    {
        indeks++;
        z=f(a+y, b-x, c, d, M, n, m, 0, y, -x, A, B);
        if(z==0) indeks--;
        if(z==1)
        {
            M[a][b]=sw;
            return 1;
        }
    }
//printf("2 zajete\n");
    if( M[a-x][b-y]==0 )//trzeci kierunek----------------------------------------------------------------------------------------------------------------------
    {
        indeks++;
        z=f(a-x, b-y, c, d, M, n, m, l, -x, -y, A, B);
        if(z==0) indeks--;
        if(z==1)
        {
            M[a][b]=sw;
            return 1;
        }
    }

    if( M[a-x][b-y]==2 && l==1 )
    {
        indeks++;
        z=f(a-x, b-y, c, d, M, n, m, 0, -x, -y, A, B);
        if(z==0) indeks--;
        if(z==1)
        {
            M[a][b]=sw;
            return 1;
        }
    }

    if( M[a-y][b+x]==0 )//czwarty kierunek---------------------------------------------------------------------------------------------------------------------------
    {
        indeks++;
        z=f(a-y, b+x, c, d, M, n, m, l, -y, x, A, B);
        if(z==0)
        {
            M[a][b]=sw;
            indeks--;
        }
        if(z==1)
        {
            M[a][b]=sw;
            return 1;
        }
    }

    if( M[a-y][b+x]==2 && l==1 )
    {
        indeks++;
        z=f(a-y, b+x, c, d, M, n, m, 0, -y, x, A, B);
        if(z==0)
        {
            M[a][b]=sw;
            indeks--;
        }
        if(z==1)
        {
            M[a][b]=sw;
            return 1;
        }
    }
    M[a][b]=sw;
    //printf("k: %d,%d; %d\n\n", a, b, M[3][1]);
    return 0;
}
