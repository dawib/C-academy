#include<iostream>
using namespace std;

class point
{
    int x;
    int y;

public:
    point(int a=0, int b=0) {x=a; y=b;}

    int getX() {return x;}
    int getY() {return y;}
    void set(int a, int b) {x=a; y=b;}
    void print() {cout<<x<<" "<<y<<endl;}
};

class queue
{
    point* t;//tablica
    int Nmax;//dlugosc kolejki
    int N;//ilosc elementow
    int i;//indeks pierwszego elementu
public:
    queue(int n=15) { t=new point[n]; Nmax=n; N=0; i=0; }//konstruktor ustawiajacy ilosc elementow kolejki na n(domyslnie 15)
    ~queue() { delete [] t; }

    void enqueue(point& x);//dostawianie elementu na koniec kolejki
    point dequeue();//wyciagamy pierwszy element z kolejki
    point front();//sprawdzamy pierwszy element z kolejki
    bool empty() { return (N==0); }
    bool full() { return (N==Nmax); }
    void clear() { i=0; N=0; };
    void resize(int n);
};
//======================================================================================================================================================

int M[2002][2002];//mapa
point V[2002][2002];//mapka do sprawdzania czy dane pole bylo juz odwiedzone: w X zapisujemy numer myszy ktora pierwsza je odwiedzila a w Y po ilu krokach
queue Q(4000000);//kolejka dla punktow czekajacych na przegladniecie

void read(int, int);//wczytanie mapy
void show(int, int);//wyswietlenie mapy

main()//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
{

    int z; cin>>z;//ilosc zestawow danych
    for(int i=0; i<z; i++)
    {
        Q.clear();
        int m,n; cin>>n; cin>>m;//rozmiar mapy
        read(n, m);//wczytujemy mape

        point A, W(-1,-1);
        int x, y, a, b;
        //bool cheese_found=0;
        while(!Q.empty())//dopoki zadna mysz nie znalazla sera
        {
            A=Q.dequeue(); x=A.getX(); y=A.getY();
            //cout<<x<<" "<<y<<endl;
            if(M[x][y]==3)
            {
                W=V[x][y];
                break;
            }

            a=V[x][y].getX(); b=V[x][y].getY();

            int k=-1, l=0, t;
            for(int j=0; j<4; j++)
            {
                if(V[x+k][y+l].getX()==0 and (M[x+k][y+l]==0 or M[x+k][y+l]==3))
                {
                    //cout<<x+k<<"::"<<y+l<<endl;
                    A.set(x+k,y+l);
                    Q.enqueue(A);
                    V[x+k][y+l].set(a, b+1);
                }
                t=l; l=-k; k=t;
            }
        }

        W.print();
    }
}//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

void read(int n, int m)
{
    int a; point A;
    for(int j=0; j<m+2; j++) { M[0][j]=2; V[0][j].set(1,0); }//ograniczamy mape z gory sciana

    for(int i=1; i<n+1; i++)
    {
        M[i][0]=2;//stawiamy z lewej sciane
        for(int j=1; j<m+1; j++)//wczytujemy wiersz
        {
            cin>>a;
            if(a>3)
            {
                A.set(i,j);
                Q.enqueue(A);
                V[i][j].set(a,0);
            }
            else V[i][j].set(0,0);
            M[i][j]=a;
        }
        M[i][m+1]=2;//stawiamy z prawej sciane
    }

    for(int j=0; j<m+2; j++) { M[n+1][j]=2; V[n+1][j].set(1,0); }//ograniczamy mape z dolu sciana
}

void show(int n, int m)
{
    for(int i=0; i<n+2; i++)
    {
        for(int j=0; j<m+2; j++) cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

//======================================================================================================================================================
void queue::enqueue(point& x)
{
    if(N<Nmax)//jesli elementow jest mniej niz maksymalna ilosc
    {
        t[(i+N)%Nmax]=x;//
        N++;//zwiekszamy ilosc elementow
    }
}

point queue::dequeue()
{
    point a;
    if(N>0)//jesli kolejka jest niepusta
    {
        a=t[i];
        i=(i+1)%Nmax; N--;
    }
    return a;
}

point queue::front()
{
    point a;
    if(N==0) return a;//jesli kolejka jest pusta zwracamy 0 0
    return t[i];
}

void queue::resize(int n)
{
    if(n>Nmax)
    {
        point* temp=t;
        t=new point[n];

        for(int j=0; j<N; j++)
        {
            t[j]=temp[(i+j)%Nmax];
        }

        delete [] temp;
        Nmax=n;
        i=0;
    }
}
