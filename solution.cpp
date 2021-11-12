#include<iostream>
#include<string>
using namespace std;
#include "U.h"

/*
enqueue(point x) – dodaje obiekt x do kolejki. Jesli kolejka jest pe³na, funkcja nie robi nic.
empty – zwraca true, jesli kolejka jest pusta

dequeue() – wyjmuje pierwszy obiekt x z kolejki i zwraca jego wartosc. Jesli kolejka jest pusta, funkcja zwraca punkt (0, 0).

front() – zwraca wartosc elementu pierwszego w kolejce. Jesli kolejka jest pusta, funkcja zwraca punkt (0, 0).
full – zwraca true, jesli kolejka jest pe³na
clear() – czysci kolejke
resize() – zmienia liczbe elementów jakie kolejka moze przechowywac.
*/

int main()
{
   int z, a;
   long long x, y;
   string s;
   
   cin >> z;
   while (z--)
   {
      queue Q;
      cin >> a;
      while (a--)
      {      
         cin >> s;
         switch(s[1])
         {
            case 'e': 
               if (s[2]=='m') { if (Q.empty()) cout << "EMPTY" << endl; else cout << "NO" << endl; }
               else 
               {
                  cin >> x >> y;
		  point p(x,y);
                  Q.enqueue( p );
               }
               break;
            case 'd': 
               {  
                  Q.dequeue().print();
                  break;
               }
            case 'f': 
               {  
                  if (s[2]=='u') { if (Q.full()) cout << "FULL" << endl; else cout << "NO" << endl; }
                  else  Q.front().print();   
                  break;                               
               }
            case 'c':                  
               Q.clear();
               break;
            case 'r':
               int r;  
               cin >> r;  
               Q.resize(r);
         };
      }  
   }
   return 0;
}

/*
Klasa stack
push(long long &x) – wk³ada element x stos. Jesli stos jest pe³ny, funkcja
nie robi nic.
pop() – wyjmuje element x ze szczytu stosu i zwraca jego wartosc. Jesli
stos jest pusty, funkcja zwraca wartosc 0.
top() – zwraca wartosc elementu ze szczytu stosu. Jesli stos jest pusty,
funkcja zwraca wartosc 0.
empty – zwraca true, jesli stos jest pusty.
full – zwraca true, jesli stos jest pe³ny.
clear() – czysci stos.
resize() – zmienia liczbe elementów jakie stos moze przechowac.
*/
