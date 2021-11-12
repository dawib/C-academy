#include<stdio.h>

char M[5][5]={0};
int X, Y;//pole w ktore komputer robi ruch
int G=0;

char move(char);//wybieranie najlepszego ruchu przez danego gracza
void show();//wyswietlanie planszy
void player();//wczytywanie ruchu gracza
char full();//sprawdzanie czy plansza jest pelna
void scan();//wczytywanie gotowego stanu planszy

main()//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    char z;
    while(1)
    {
        system("cls");
        show();

        if( M[1][1]==1 && M[1][2]==1 && M[1][3]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[2][1]==1 && M[2][2]==1 && M[2][3]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[3][1]==1 && M[3][2]==1 && M[3][3]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[1][1]==1 && M[2][1]==1 && M[3][1]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[1][2]==1 && M[2][2]==1 && M[3][2]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[1][3]==1 && M[2][3]==1 && M[3][3]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[1][1]==1 && M[2][2]==1 && M[3][3]==1 ) { printf("Wygrywa Gracz"); return 0; }
        if( M[1][3]==1 && M[2][2]==1 && M[3][1]==1 ) { printf("Wygrywa Gracz"); return 0; }

        if( M[1][1]==2 && M[1][2]==2 && M[1][3]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[2][1]==2 && M[2][2]==2 && M[2][3]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[3][1]==2 && M[3][2]==2 && M[3][3]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[1][1]==2 && M[2][1]==2 && M[3][1]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[1][2]==2 && M[2][2]==2 && M[3][2]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[1][3]==2 && M[2][3]==2 && M[3][3]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[1][1]==2 && M[2][2]==2 && M[3][3]==2 ) { printf("Wygrywa Komputer"); return 0; }
        if( M[1][3]==2 && M[2][2]==2 && M[3][1]==2 ) { printf("Wygrywa Komputer"); return 0; }

        player();
        system("cls");
        show();
        z=full();
        if( z==1 ) { printf("Remis"); return 0; }
        system("timeout 1 > nul");

        move(2);

        if(X==G/3+1 && Y==G%3+1)
        {
            while(M[(G+1)/3+1][(G+1)%3+1]!=0)
            {
                G++;
            }
        }

        M[X][Y]=2;
    }
}//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

void player()//wczytanie ruchu gracza================================================================================================================
{
    int x, y;
    scanf("%d %d", &x, &y);
    if(x<1 || y<1 || x>3 || y>3 || M[x][y]!=0)//co jesli ruch jest niepoprawny
    {
        printf("niepoprawny ruch!\n");
        player();//wczytujemy jeszcze raz
    }
    else M[x][y]=1;
}

void zero()//zerowanie planszy============================================================================================================================================
{
    int i, j;
    for(i=1; i<4; i++)
    {
        for(j=1; j<4; j++)
        {
            M[i][j]=0;
        }
    }
}

void scan()//wczytanie gotowej planszy============================================================================================================================================
{
    int i, j;
    for(i=1; i<4; i++)
    {
        for(j=1; j<4; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
}
void show()//wyswietlenie stanu planszy================================================================================================================
{
    int i, j;
    for(i=1; i<4; i++)
    {
        for(j=1; j<4; j++)
        {
            if(M[i][j]==1) printf("O");
            if(M[i][j]==2) printf("X");
            if(M[i][j]==0) printf("_");
        }
        printf("\n");
    }
    printf("\n");
}

char full()//sprawdzenie czy plansza jest pelna================================================================================================================
{
    int i, j;
    for(i=1; i<4; i++)
    {
        for(j=1; j<4; j++)
        {
            if( M[i][j]==0 ) return 0;
        }
    }
    return 1;
}

char move(char p)//wybranie najlepszego ruchu przez komputer================================================================================================================
{
    if( M[1][1]==p && M[1][2]==p && M[1][3]==p ) return p;//sprawdzamy czy obecna sytuacja nie jest konczaca---------------------------------------------------------------
    if( M[2][1]==p && M[2][2]==p && M[2][3]==p ) return p;
    if( M[3][1]==p && M[3][2]==p && M[3][3]==p ) return p;
    if( M[1][1]==p && M[2][1]==p && M[3][1]==p ) return p;
    if( M[1][2]==p && M[2][2]==p && M[3][2]==p ) return p;
    if( M[1][3]==p && M[2][3]==p && M[3][3]==p ) return p;
    if( M[1][1]==p && M[2][2]==p && M[3][3]==p ) return p;
    if( M[1][3]==p && M[2][2]==p && M[3][1]==p ) return p;

    if( M[1][1]==3-p && M[1][2]==3-p && M[1][3]==3-p ) return 3-p;
    if( M[2][1]==3-p && M[2][2]==3-p && M[2][3]==3-p ) return 3-p;
    if( M[3][1]==3-p && M[3][2]==3-p && M[3][3]==3-p ) return 3-p;
    if( M[1][1]==3-p && M[2][1]==3-p && M[3][1]==3-p ) return 3-p;
    if( M[1][2]==3-p && M[2][2]==3-p && M[3][2]==3-p ) return 3-p;
    if( M[1][3]==3-p && M[2][3]==3-p && M[3][3]==3-p ) return 3-p;
    if( M[1][1]==3-p && M[2][2]==3-p && M[3][3]==3-p ) return 3-p;
    if( M[1][3]==3-p && M[2][2]==3-p && M[3][1]==3-p ) return 3-p;

    if ( full()==1 ) return 0;//-------------------------------------------------------------------------------------------------------------------------------------------

    int i, j;
    char t=3-p;
    char x;
    int I=0, J=0;

    for(i=1; i<4; i++)//przegladamy wolne pola i probujemy wykonac w nich ruch----------------------------------------------------------------------------------------
    {
        for(j=1; j<4; j++)
        {
            if(M[i][j]==0)
            {
                M[i][j]=p;

                x=move(3-p);//oceniamy sytuacje po wykonaniu ruchu

                M[i][j]=0;

                if(x==p)//jesli wygrywamy to robimy ten ruch
                {
                    X=i;
                    Y=j;
                    return p;
                }

                if(x==0)//jesli remis to pamietamy na przyszlosc
                {
                    t=0;
                    I=i; J=j;
                }
            }
        }
    }

    if(I==0)//jesli sytuacja jest przegrywajaca to robimy dowolny ruch w wolne miejsce
    {
        X=G/3+1;
        Y=G%3+1;
    }
    else//jesli byl remis to robimy ruch w miejsce ktore nam go daje
    {
        X=I;
        Y=J;
    }
    return t;
}
