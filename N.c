#include<stdio.h>
#include<string.h>

typedef struct
{
    int x;
    int y;
}point;

typedef struct
{
    char name[16];
    int salary;
}person;

void readInt(void*);//funkcja czytajaca int
void readPoint(void*);//funkcja czytajaca punkt
void readPerson(void*);//funkcja czytajaca osobe

void readTab(void (*)(), int, int, void*);//funkcja wczytujaca tablice

void showInt(void*);
void showPoint(void*);
void showPerson(void*);

void showTab(void (*)(), int, int, void*);//funkcja wyswiatlajaca tablice

int abs(int*);//wartosc bezwzgledna z liczby

int cmpInt(void*, void*);//zwyczajne porownanie intow
int cmpIntAbs(void*, void*);//porownanie intow po wartosciach bezwzglednych
int cmpPointX(void*, void*);//porownanie punktow po xach
int cmpPointY(void*, void*);//porownanie punktow po yach
int cmpPersonName(void*, void*);//porownanie osob po imionach
int cmpPersonSalary(void*, void*);//porownanie osob po pensjach

int sercz(void*, void*, int, int, int (*)(void*,void*));

main()//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
{
    void (*read[6])(void*)={ readInt, readInt, readPoint, readPoint, readPerson, readPerson };//tablica funkcji wczytujących element

    int siz[6]={ sizeof(int), sizeof(int), sizeof(point), sizeof(point), sizeof(person), sizeof(person) };//tablica rozmiarow odpowiednich danych

    void (*show[6])(void*)={ showInt, showInt, showPoint, showPoint, showPerson, showPerson };//tablica funkcji wyswietlajacych dane

    int (*cmp[6])(void*,void*)={ cmpInt, cmpIntAbs, cmpPointX, cmpPointY, cmpPersonName, cmpPersonSalary };//tablica funkcji porownujacych

    int z; scanf("%d", &z);//ilosc zestawow
    int i, j, k;
    void* x;
    for(i=0; i<z; i++)
    {
        int n; scanf("%d", &n);//ilosc elementow tablicy
        int d; scanf("%d", &d);//rodzaj danych

        void* T=malloc(siz[d]*n);
        readTab(read[d], n, siz[d], T);

        void* a=malloc(siz[d]);

        int m; scanf("%d", &m);//liczba wyszukan
        for(j=0; j<m; j++)
        {
            read[d](a);//wczytanie szukanego elementu

            k=sercz(T, a, n, siz[d], cmp[d]);
            if(k==n) printf("BRAK\n");
            else printf("%d\n", k);
        }

        free(T); free(a);
    }
}//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//funkcja szukajaca-----------------------------------------------------------------------------------------------------------------------------------------------------------
int sercz(void* Tab, void* a, int m, int s, int (*cmp)(void*,void*))
{
    int l=0;
    int p=m;
    int k, c;

    while(l!=p)
    {
        k=(p+l)/2;

        c=cmp(Tab+s*k, a);

        if(c<0) l=k+1;
        else p=k;
    }
    return l;
}

//funkcje wczytujace-------------------------------------------------------------------------------------------------------------------------------------------------------------
void readInt(void* t)
{
    scanf("%d", t);
}

void readPoint(void* t)
{
    scanf("%d", &(((point*)t)->x));
    scanf("%d", &(((point*)t)->y));
}

void readPerson(void* t)
{
    scanf("%s", ((person*)t)->name);
    scanf("%d", &(((person*)t)->salary));
}

void readTab(void (*read)(void*), int m, int s, void* Tab)
{
    int i;
    for(i=0; i<m; i++)
    {
        read(Tab+s*i);
    }
}
//funkcje wyswietlajace------------------------------------------------------------------------------------------------------------------------------------------------------
void showInt(void* a)
{
    int* b=(int*)(a);
    printf("%d::", (*b));
}

void showPoint(void* a)
{
    point* b=(point*)a;
    printf("%d, %d::", b->x, b->y);
}

void showPerson(void* a)
{
    person* b=(person*)a;
    printf("%s %d::", b->name, b->salary);
}

void showTab(void (*show)(void*), int m, int s, void* Tab)
{
    int i;
    for(i=0; i<m; i++)
    {
        show(&(Tab[s*i]));
    }
    printf("\n");
}
//wartosc bezwzgledna----------------------------------------------------------------------------------------------------------------------------------------------------
int abs(int* c)
{
    if(*c>=0) return *c;
    else return -*c;
}
//funkcje porownujace-------------------------------------------------------------------------------------------------------------------------------------------------------
int cmpInt(void* p, void* q)
{
    int* a=(int*)p;
    int* b=(int*)q;

    if(*a<*b) return -1;
    else if(*a==*b) return 0;
    else return 1;
}

int cmpIntAbs(void* p, void* q)
{
    int* a=(int*)p;
    int* b=(int*)q;

    if(abs(a)<abs(b)) return -1;
    else if(abs(a)>abs(b)) return 1;

    if(*a<*b) return -1;
    else if(*a>*b) return 1;

    return 0;
}

int cmpPointX(void* p, void* q)
{
    point* a=(point*)p;
    point* b=(point*)q;

    if((a->x)<(b->x)) return -1;
    else if ((b->x)<(a->x)) return 1;

    if((a->y)<(b->y)) return -1;
    else if ((b->y)<(a->y)) return 1;

    return 0;
}

int cmpPointY(void* p, void* q)
{
    point* a=(point*)p;
    point* b=(point*)q;

    if((a->y)<(b->y)) return -1;
    else if ((b->y)<(a->y)) return 1;

    if((a->x)<(b->x)) return -1;
    else if ((b->x)<(a->x)) return 1;

    return 0;
}

int cmpPersonName(void* p, void* q)
{
    person* a=(person*)p;
    person* b=(person*)q;

    int c=strcmp(a->name, b->name);
    if(c<0) return -1;
    else if(c>0) return 1;

    if( (a->salary)<(b->salary) ) return -1;
    else if( (a->salary)>(b->salary ) )return 1;

    return 0;
}

int cmpPersonSalary(void* p, void* q)
{
    person* a=(person*)p;
    person* b=(person*)q;

    if( (a->salary)<(b->salary) ) return -1;
    else if( (a->salary)>(b->salary) ) return 1;

    int c=strcmp(a->name, b->name);
    if(c<0) return -1;
    else if(c>0) return 1;

    return 0;
}
