#include<iostream>
using namespace std;

class mono
{
    long long int coef;
    long long int deg;
    mono* next;
    mono* prev;
public:
    mono(long long int c, long long int d): coef(c), deg(d), next(NULL), prev(NULL) { }// { coef=c; deg=d; next=NULL; prev=NULL; }
    mono() { next=NULL; prev=NULL; }

    friend class poly;
};

class poly
{
    mono* first;
    mono* last;

public:
    poly() { first=new mono; last=new mono; first->next=last; last->prev=first; first->deg=-1; last->deg=-1; }
    ~poly(){ clear(); delete first; delete last; }

    void print_asc()//drukuje wielomian wedlg rosnacych wspolczynnikow
    {
        mono* temp=first->next;
        if(temp==last) { cout<<"EMPTY"<<endl; return; }

        if(temp->deg==0)       cout<<temp->coef;
        else if(temp->coef==1) cout<<"x";
        else if(temp->coef==-1)cout<<"-x";
        else                   cout<<temp->coef<<"x";

        if(temp->deg>1) cout<<"^"<<temp->deg;
        temp=temp->next;

        while(temp!=last)
        {
            if(temp->coef==1)      cout<<"+x";
            else if(temp->coef==-1)cout<<"-x";
            else if(temp->coef>0)  cout<<"+"<<temp->coef<<"x";
            else                   cout<<temp->coef<<"x";

            if(temp->deg>1)        cout<<"^"<<temp->deg;

            temp=temp->next;
        }

        cout<<endl;
    }

    void print_desc()//drukuje wielomian wedlug malejacych wspolczynnikow
    {
        mono* temp=last->prev;
        if(temp==first) { cout<<"EMPTY"<<endl; return; }

        if(temp->deg==0)       cout<<temp->coef;
        else if(temp->coef==1) cout<<"x";
        else if(temp->coef==-1)cout<<"-x";
        else                   cout<<temp->coef<<"x";

        if(temp->deg>1) cout<<"^"<<temp->deg;
        temp=temp->prev;

        while(temp!=first)
        {
            if(temp->deg==0)
            {
                if(temp->coef>0) cout<<"+"<<temp->coef;
                else             cout<<temp->coef;
            }
            else
            {
                if(temp->coef==1)      cout<<"+x";
                else if(temp->coef==-1)cout<<"-x";
                else if(temp->coef>0)  cout<<"+"<<temp->coef<<"x";
                else                   cout<<temp->coef<<"x";

                if(temp->deg>1)        cout<<"^"<<temp->deg;
            }

            temp=temp->prev;
        }

        cout<<endl;
    }

    void derivate()//przeksztalca wielomian na jego pochodna
    {
        mono* temp=first->next;
        while(temp!=last)
        {
            if(temp->deg==0)//jesli jednomian jest stala to go usuwamy
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                mono* del=temp;
                temp=temp->next;
                delete del;
            }
            else
            {
                temp->coef=temp->coef*temp->deg;
                temp->deg=temp->deg-1;
                temp=temp->next;
            }
        }
    }

    mono* add(mono* M, mono* b)//dodaje do wielomianu jednomian zaczynajac szukanie od podanego miejsca
    {
        mono* temp=b;
        while(temp->next!=last && temp->next->deg<M->deg) temp=temp->next;

        if(temp->next->deg==M->deg)
        {
            temp->next->coef+=M->coef;
            if(temp->next->coef==0)
            {
                mono* del=temp->next;
                temp->next=del->next;
                del->next->prev=temp;
                delete del;
            }
            return temp->next;
        }

        mono* in=new mono;
        in->coef=M->coef; in->deg=M->deg;
        in->next=temp->next; in->prev=temp;
        temp->next->prev=in; temp->next=in;

        return in;
    }

    void add(mono* M)//dodaje do wielomianu jednomian zaczynajac szukanie miejsca od poczatku
    {
        //cout<<"adding..."<<endl;
        if(M->coef==0) { cout<<"ADD OK"<<endl; return; }
        mono* temp=first;
        while(temp->next!=last && temp->next->deg<M->deg) temp=temp->next;

        if(temp->next->deg==M->deg)
        {
            temp->next->coef+=M->coef;
            if(temp->next->coef==0)
            {
                mono* del=temp->next;
                temp->next=del->next;
                del->next->prev=temp;
                delete del;
            }
            cout<<"ADD OK"<<endl;
            return;
        }
        //cout<<"no such degree- creating new one..."<<endl;
        mono* in=new mono;
        in->coef=M->coef; in->deg=M->deg;
        in->next=temp->next; in->prev=temp;
        temp->next->prev=in; temp->next=in;
        cout<<"ADD OK"<<endl;
    }

    void add(poly& W)//dodaje do wielomianu inny wielomian
    {
        mono* temp=W.first;//dodawany jednomian
        temp=temp->next;
        mono* b=first->next;//przed ktorym jednomianem dodajemy
        mono* del;
        //if(temp==last) { cout<<"ADD OK"<<endl; return; }
        while(temp!=W.last)
        {
            while(b->deg<temp->deg && b!=last) b=b->next;//przechodzimy po naszym wielomianie szukajac wiekszego stopnia niz ma dodawany jednomian

            if(b->deg==temp->deg)//jesli znaleziony ma ten sam stopien co dodawany
            {
                b->coef=b->coef+temp->coef;
                if(b->coef==0)//jesli wspolczynniki sie wyzerowaly
                {
                    b->prev->next=b->next;
                    b->next->prev=b->prev;
                    del=b;
                    b=b->next;
                    delete del;
                }

                temp=temp->next;
            }
            else
            {
                mono* added=new mono(temp->coef, temp->deg);
                added->prev=b->prev; added->next=b;
                b->prev=added; added->prev->next=added;

                temp=temp->next;
            }
        }
        cout<<"ADD OK"<<endl;
    }

    void min()
    {
        if(first->next==last) { cout<<"ERROR"<<endl; return; }
        cout<<first->next->coef<<endl;
    }

    void max()
    {
        if(first->next==last) { cout<<"ERROR"<<endl; return; }
        cout<<last->prev->coef<<endl;
    }

    void multi(long long int c)
    {
        if(c==0) { clear(); cout<<"MULTI OK"<<endl; return; }

        mono* temp=first->next;
        while(temp!=last)
        {
            temp->coef*=c;
            temp=temp->next;
        }

        cout<<"MULTI OK"<<endl;
    }

    void multi(poly& W)
    {
        if(first->next==last) { cout<<"MULTI OK"<<endl; return; }//jesli wielomian jest pusty to zostawiamy go pustego
        if(W.first->next==W.last) { clear(); cout<<"MULTI OK"<<endl; return; }//jesli drugi wielomian jest pusty to pierwszy tez zerujemy

        mono* head=new mono(0, -1);//glowa wielomianu wynikoweg
        mono* tail=new mono(0, -1);//ogon wielomianu wynikowego
        head->next=tail;
        tail->prev=head;

        mono* IN=head;
        mono* in=head;

        mono* del;//do usuwania jednomianow

        long long int d;
        long long int c;

        mono* Mf=first->next; //do przechodzenia po naszym wielomianie
        mono* Wf=W.first->next;//do przechodzenia po drugim wielomianie

        while(Mf!=last)
        {
            Wf=W.first->next;
            while( IN->next->deg<=Mf->deg+Wf->deg and IN->next!=tail ) IN=IN->next;
            in=IN;

            while(Wf!=W.last)
            {
                //mono* score=new mono( Mf->coef*Wf->coef, Mf->deg+Wf->deg );
                d=Mf->deg+Wf->deg;
                c=Mf->coef*Wf->coef;

                while( in->next->deg<=d and in->next!=tail ) in=in->next;

                if(d==in->deg)
                {
                    if(c+in->coef==0)
                    {
                        //cout<<"cos sie upraszcza..."<<endl;
                        del=in;
                        in=in->prev;
                        in->next=del->next;
                        del->next->prev=in;
                        delete del;
                    }
                    else
                    {
                        in->coef=in->coef+c;
                        //in=in->next;
                    }
                    //delete score;
                }
                else
                {
                    mono* score=new mono( c, d );

                    in->next->prev=score;
                    score->next=in->next;
                    score->prev=in;
                    in->next=score;
                }

                Wf=Wf->next;

                //for(mono* i=head->next; i->next!=NULL; i=i->next) cout<<i->coef<<"x^"<<i->deg<<"+";
                //cout<<endl;
            }
            Mf=Mf->next;
        }

        clear();
        delete first; delete last;
        first=head; last=tail;

        cout<<"MULTI OK"<<endl;
    }

    void clean()//czysci wielomian
    {
        if(first->next==last) { cout<<"EMPTY"<<endl; return; }
        mono* temp;
        mono* del;
        while(first->next!=last)
        {
            temp=first->next;
            first->next=temp->next;
            temp->next->prev=first;
            del=temp;
            temp=temp->next;
            delete del;
        }
        cout<<"CLEAN OK"<<endl;
    }

    void clear()//usuwa wielomian
    {
        //if(first->next==last) { cout<<"EMPTY"<<endl; return; }
        mono* temp;
        mono* del;
        while(first->next!=last)
        {
            temp=first->next;
            first->next=temp->next;
            temp->next->prev=first;
            del=temp;
            delete del;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //poly T[30];
    //cout<<'Z'-'A';
    int z; cin>>z;//ilosc zestawow
    for(int i=0; i<z; i++)
    {
        poly T[26];
        int n; cin>>n;//ilosc instrukcji
        string s;//polecenie
        char id, id1, id2;//identyfikator wielomianu
        long long int a, b;//wcpolczynnik i stopien
        for(int j=0; j<n; j++)
        {
            cin>>s;
            cin>>id;
            id=id-'A';

            if(s=="PRINT_ASC")
            {
                T[id].print_asc();
            }
            if(s=="PRINT_DESC")
            {
                T[id].print_desc();
            }
            if(s=="DERIVATIVE")
            {
                T[id].derivate();
            }
            if(s=="ADD_MONO")
            {
                cin>>a>>b;//a-stopien b-wspolczynnik
                mono M(b,a);
                T[id].add(&M);
            }
            if(s=="ADD")
            {
                cin>>id1; id1=id1-'A';
                T[id].add(T[id1]);
            }
            if(s=="MULTI_CONST")
            {
                cin>>a;
                T[id].multi(a);
            }
            if(s=="MULTI")
            {
                cin>>id1; id1=id1-'A';
                T[id].multi(T[id1]);
            }
            if(s=="MIN")
            {
                T[id].min();
            }
            if(s=="MAX")
            {
                T[id].max();
            }
            if(s=="CLEAN")
            {
                T[id].clean();
            }
        }
        //delete [] T;
    }
}
