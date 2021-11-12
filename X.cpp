#include<iostream>
using namespace std;

class person
{
    string name;
    int age;
    int p;
    person *next;
public:
    person(string s, int a, int q) { name=s; age=a; p=q; next=NULL; }
    person() { next=NULL; }

    friend class list;
};

class list
{
    person* first;
    //person* last;
    int age;
public:
    list()  { first=new person; first->next=NULL; age=200; }
    ~list() { clear(); delete first; }

    void add(string s, int a, int q)//dodawanie osob do listy
    {
        if(a>=age)//jesli nasza osoba ma odpowiedni wiek
        {
            person* temp=new person(s,a,q);//deklarujemy nasza osobe
            temp->next=first->next;//doklejamy ja za glowa
            first->next=temp;//doklejamy do niej glowe
        }
        else//jesli nie ma
        {
            person* in=new person(s,a,q);//deklarujemy nasza osobe
            person* temp=first;
            while(temp->next!=NULL) temp=temp->next;//przechodzimy do konca listy

            temp->next=in;//doklejamy dotychczasowy ostatni element do tempa
        }
    }

    void insert(string s, int a, int q, int n)//wstawiamy osobe na pozycje n
    {
        if(n<=0) { cout<<"ERROR"<<endl; return; }//jesli pozycja jest zle podana zwracamy error

        person* temp=first;//tempem bedziemy poruszac sie po liscie
        person* in=new person(s, a, q);//nasza nowa osoba

        for(int i=1; i<n; i++)//przechodzimy o n-1 pozycji
        {
            temp=temp->next;//--
            if(temp==NULL) { cout<<"ERROR"<<endl; delete in; return; }//jesli w ktoryms momencie opuscimy liste to zglaszamy blad
        }

        in->next=temp->next;//ustawiamy nastepnik tempa jako nastepnik ina
        temp->next=in;//ustawiamy ina jako nastepnik tempa
    }

    void dequeue()//pierwsza osoba na liscie cos sobie kupuje
    {
        if(first->next==NULL) { cout<<"ERROR"<<endl; return; }//jesli lista jest pusta
        person* temp=first->next;//robimy wskaznik na pierwsza osobe
        first->next=temp->next;//ustawiamy glowe zeby wskazywala na druga osobe
        delete temp;//usuwamy pierwsza osobe
    }

    void resign()//ostatnia osoba w kolejce sie usuwa
    {
        if(first->next==NULL) { cout<<"ERROR"<<endl; return; }
        person* temp=first;
        person* prev;//chcemy miec tez wskaznik na przedostatnia osobe
        while(temp->next!=NULL) { prev=temp; temp=temp->next; }//przechodzimy tempem do ostatniej osoby

        prev->next=NULL; delete temp;
    }

    void kick(string s, int a)//wyrzucamy osoby o imieniu s i wieku a
    {
        person* temp=first->next;//bedziemy tym przechodzic po liscie
        person* prev=first;
        person* del;//do zapamietania usuwanej osoby
        bool did=false;//do pamietania czy kogos usunelismy

        while(temp!=NULL)
        {
            if(temp->name==s and temp->age==a)
            {
                prev->next=temp->next;
                del=temp;
                temp=temp->next;
                delete del;
                did=true;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }

        if(!did) cout<<"ERROR"<<endl;
    }

    void print()//drukowanie listy
    {
        if(first->next==NULL) { cout<<"EMPTY"<<endl<<endl; return; }//jesli po glowie nic nie ma to piszemy ze lista jest pusta

        person* temp=first->next;//ustawiamy tempa na pierwszy element po glowie
        while(temp!=NULL)//dopoki nie dojdziemy do konca listy
        {
            cout<<temp->name<<" "<<temp->age<<" "<<temp->p<<endl;//wypisujemy aktualnego tempa
            //if(temp->age==70 and temp->p==345) cout<<endl;
            temp=temp->next;//przesuwamy sie dalej po liscie
        }
        cout<<endl;
    }

    void ch_age(int a)//zmiana wieku specjalnego na a
    {
        if(a>age) { age=a; return; }//jesli wiek jest wiekszy badz rowny jak do tej pory to nie dzieje sie nic
        age=a;

        person* in=first;//za ta osobe wstawiamy naszego delikwenta
        person* bef=first;//zeby pamietac poprzednika delikwenta
        person* temp=bef->next;//kandydat na delikwenta
        person* mode=temp;//delikwent

        while(temp!=NULL)
        {
            if(temp->age>=age)
            {
                temp=temp->next;
                bef->next=temp;

                mode->next=in->next;
                in->next=mode;

                in=mode;
                mode=temp;

                while(bef->next!=temp) bef=bef->next;
            }
            else
            {
                bef=temp;
                temp=temp->next;
                mode=temp;
            }
        }
    }

    void lack(int q)//kolejke opuszczaja osoby ktore czekaly na produkt q
    {
        person* temp=first->next;//do przechodzenia po liscie
        person* prev=first;//do pamietania poprzednika tempa
        person* del;//do usuwania

        while(temp!=NULL)
        {
            if(temp->p==q)
            {
                del=temp;
                prev->next=temp->next;
                temp=temp->next;
                delete del;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }
    }

    void reverse()//kolejka sie odwraca
    {
        if(first->next==NULL) { cout<<"EMPTY"<<endl<<endl; return; }
        person* head=new person;//robimy nowa glowe
        person* last=NULL;

        while(first->next!=NULL)
        {
            head->next=first->next;
            first->next=(first->next)->next;
            (head->next)->next=last;
            last=head->next;
        }

        person* del=first;
        first=head;
        delete del;
    }

    void clear()//kolejka pustoszeje
    {
        person* temp;
        while(first->next!=NULL)
        {
            temp=first;
            first=first->next;
            delete temp;
        }
    }
};

int main()
{
    list L;
    int z; cin>>z;//liczba zestawow
    for(int i=0; i<z; i++)
    {
        int n, w; cin>>n>>w;//liczba operacji na liscie i wiek uprawniajacy do wpychania sie na poczatek
        L.ch_age(w); string ord;//polecenie
        for(int j=0; j<n; j++)
        {
            //cout<<j<<": ";
            cin>>ord;
            switch(ord[0])
            {
            case 'N':
                {
                    string s; int a, q; cin>>s>>a>>q;
                    L.add(s,a,q); break;
                }
            case 'I':
                {
                    string s; int a, q, n; cin>>s>>a>>n>>q;
                    L.insert(s,a,q,n); break;
                }
            case 'B': { L.dequeue(); break; }
            case 'D':
                {
                    string s; int a; cin>>s>>a;
                    L.kick(s,a); break;
                }
            case 'P': { L.print(); break; }
            case 'L':
                {
                    int q; cin>>q;
                    L.lack(q); break;
                }
            case 'R':
                {
                    switch(ord[2])
                    {
                        case 'S': { L.resign(); break; }
                        case 'V': { L.reverse(); break; }
                    }
                    break;
                }
            case 'C':
                {
                    switch(ord[1])
                    {
                    case 'H':
                        {
                            int a; cin>>a;
                            L.ch_age(a); break;
                        }
                    case 'L':
                        {
                            L.clear(); break;
                        }
                    }
                    break;
                }
            }
        }
        L.clear();
    }
}
