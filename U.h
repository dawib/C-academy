class point
{
    int x;
    int y;

public:
    point(int a=0, int b=0) {x=a; y=b;}

    int getX() {return x;}
    int getY() {return y;}
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

    void enqueue(point& x)//dostawianie elementu na koniec kolejki
    {
        if(N<Nmax)//jesli elementow jest mniej niz maksymalna ilosc
        {
            t[(i+N)%Nmax]=x;//
            N++;//zwiekszamy ilosc elementow
        }
    }

    point dequeue()//wyciagamy pierwszy element z kolejki
    {
        point a;
        if(N>0)//jesli kolejka jest niepusta
        {
            a=t[i];
            i=(i+1)%Nmax; N--;
        }
        return a;
    }

    point front()//sprawdzamy pierwszy element z kolejki
    {
        point a;
        if(N==0) return a;//jesli kolejka jest pusta zwracamy 0 0
        return t[i];
    }

    bool empty() { return (N==0); }
    bool full() { return (N==Nmax); }

    void clear() { i=0; N=0; }

    void resize(int n)
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

    /*void show()
    {
        for(int j=0; j<Nmax; j++)
        {
            if(j==i) { cout<<":"; t[j].print(); }
            else if(j==(i+N-1)%Nmax) { cout<<"-"; t[j].print(); }
            else t[j].print();
        }
    }*/

    ~queue() { delete [] t; }
};

class stack
{
    long long* t;//tablica elementow
    int Nmax;//maksymalna ilosc elementow
    int i;//indeks pierwszego wolnego miejsca i rownoczesnie ilosc elementow

public:
    stack(int n=15) { t=new long long[n]; Nmax=n; i=0; }

    void push(long long &x)
    {
        if(i<Nmax)
        {
            t[i]=x; i++;
        }
    }

    long long pop()
    {
        if(i==0) return 0;
        i--;
        return t[i];
    }

    long long top()
    {
        if(i==0) return 0;
        return t[i-1];
    }

    bool empty() { return (i==0); }
    bool full() { return (i==Nmax); }

    void clear() { i=0; }

    void resize(int n)
    {
        if(n>Nmax)
        {
            long long* temp=t;
            t=new long long[n];

            for(int j=0; j<i; j++)
            {
                t[j]=temp[j];
            }

            delete [] temp;
            Nmax=n;
        }
    }

    ~stack() { delete [] t; }
};
