#include<iostream>
using namespace std;
#include "U.h"

int main()
{
ios_base::sync_with_stdio(false);
  
point A;
point B(5,8);
cout << A.getX() << " " << A.getY() << endl;
B.print();
stack S1;
for (long long  i=0; i<20; ++i) S1.push(i);
cout << S1.top() << " ";
if (S1.full()) cout << "tak" << endl; else cout << "nie" << endl;
S1.resize(50);
cout << S1.pop() << " ";
S1.clear();
if (S1.empty()) cout << "tak" << endl; else cout << "nie" << endl;
for (long long  i=20; i<30; ++i) S1.push(i);
cout << S1.top() << " ";
if (S1.full()) cout << "tak" << endl; else cout << "nie" << endl;
stack S2(100);
for (long long  i=0; i<30; ++i) S2.push(i);
for (int i=0; i<10; ++i) cout << S2.pop() << " " ;
cout << endl;
 
queue Q1;
Q1.dequeue();
Q1.front();

cout << "tutaj" << endl;

for (int i=1; i<20; ++i) { point p(i,i); Q1.enqueue( p ); };
cout << Q1.front().getX() << " ";

if (Q1.full()) cout << "tak" << endl; else cout << "nie" << endl;
cout << "resize(16)" << endl;
Q1.resize(16);
if (Q1.full()) cout << "tak" << endl; else cout << "nie" << endl;

for (int i=0; i<35; ++i) { point p(i,i); Q1.enqueue( p ); };
cout << "czy jestem pełna?" << endl;
if (Q1.full()) cout << "tak" << endl; else cout << "nie" << endl;

for (int i=0; i<50; ++i) {
point a = Q1.dequeue(); cout << a.getX()<< " " << a.getY()<< " ";
}
cout << "czy jestem pusta?" << endl;

if (Q1.empty()) cout << "tak" << endl; else cout << "nie" << endl;

for (int i=30; i<39; ++i) { point p(i,i); Q1.enqueue( p ); };
if (Q1.full()) cout << "tak" << endl; else cout << "nie" << endl;
cout << Q1.front().getY() << " " << endl;

queue Q2(100);
if (Q2.empty()) cout << "tak" << endl; else cout << "nie" << endl;
for (int i=1; i<51; ++i) { point p(i,i); Q2.enqueue( p ); };
Q2.resize(200);
for (int i=0; i<10; ++i) {
point a = Q2.dequeue(); cout << a.getX()<< " " << a.getY()<< " ";
}
return 0;

}
