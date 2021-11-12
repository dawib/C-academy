#include<iostream>
#include<cstdio>
using namespace std;

class stack
{
    long long* t;//tablica elementow
    int Nmax;//maksymalna ilosc elementow
    int i;//indeks pierwszego wolnego miejsca i rownoczesnie ilosc elementow

public:
    stack(int n=15) { t=new long long[n]; Nmax=n; i=0; }
    ~stack() { delete [] t; }

    void push(long long x) { if(i<Nmax) { t[i]=x; i++; } }
    long long pop() { if(i==0) return 0; else { i--; return t[i]; } }
    long long top() { if(i==0) return 0; else return t[i-1]; }
    bool empty() { return (i==0); }
    bool full() { return (i==Nmax); }
    void clear() { i=0; }
    void resize(int);
};
//=========================================================================================================================================================================

int priority(char);
long long pow(long long,long long);

main()//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
{
    long long val[26];//tablica z wartosciami liter
    string form;//liczone wyrazenie
    stack S(100000);

    int z; cin>>z;//liczba zestawow
    for(int i=0; i<z; i++)
    {
        for(int j=0; j<26; j++) cin>>val[j];//wczytujemy wartosci liter
        int w; cin>>w;//liczba wyrazen
        for(int q=0; q<w; q++)//jedno wyrazenie============================================================================================================================
        {
            cin>>form;//wczytujemy wyrazenie do policzenia
            int l=form.length(), prior=0;//dlugosc naszego wyrazenia
            string ont_form="";//wyrazenie zapisane w ONT
            char a, b;
            int k;

            S.clear();
            for(int j=0; j<l; j++)//przechodzimy przez nasze wyrazenie zapisujac je w ONT----------------------------------------------------------------------------------
            {
                a=form[j]; k=priority(a);//czytamy znak z wyrazenia

                if(k==0) ont_form+=a;//cout<<a;//jesli jest litera
                else if(k<4)//jesli jest operatorem
                {
                    while(priority((char)S.top())>=k and (char)S.top()!='(') ont_form+=(char)S.pop();//cout<<(char)S.pop();
                    S.push((long long)a);
                }
                else//jesli jest nawiasem
                {
                    if(a=='(') S.push((long long)a);
                    else
                    {
                        while((char)S.top()!='(') ont_form+=(char)S.pop();//cout<<(char)S.pop();
                        S.pop();
                    }
                }
            }
            while(!S.empty()) ont_form+=(char)S.pop();
            cout<<ont_form<<endl;//----------------------------------------------------------------------------------------------------------------------------------------

            l=ont_form.length();
            long long x, y, s=0;
            S.clear();
            for(int j=0; j<l; j++)//obliczamy wartosc wyrazenia------------------------------------------------------------------------------------------------------------
            {
                a=ont_form[j]; k=priority(a);
                switch(k)
                {
                case 0:
                    {
                        S.push((long long)val[a-'a']); break;
                    }
                case 1:
                    {
                        if(a=='-')
                        {
                            x=S.pop();
                            y=S.pop();
                            s=y-x;
                            S.push(s);
                        }
                        else
                        {
                            x=S.pop();
                            y=S.pop();
                            s=y+x;
                            S.push(s);
                        }
                        break;
                    }
                case 2:
                    {
                        if(a=='*')
                        {
                            x=S.pop();
                            y=S.pop();
                            s=y*x;
                            S.push(s);
                        }
                        else
                        {
                            x=S.pop();
                            y=S.pop();
                            s=(x==0)?0:y/x;
                            S.push(s);
                        }
                        break;
                    }
                case 3:
                    {
                        x=S.pop();
                        y=S.pop();
                        s=pow(y, x);
                        S.push(s);
                        break;
                    }
                }
                //cout<<":"<<S.top()<<endl;
            }
            s=S.pop();
            cout<<s<<endl;
        }
    }
}//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

long long pow(long long a,long long b)
{
    if(b<=0) return 1;
    long long w=pow(a, b/2);
    if(b%2==0) return w*w;
    else return a*w*w;
}

int priority(char c)
{
    switch(c)
    {
        case '-': return 1;
        case '+': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        case '(': return 4;
        case ')': return 4;
    }
    return 0;
}

//=========================================================================================================================================================================
void stack::resize(int n)
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
