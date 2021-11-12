#include<iostream>
using namespace std;

int main()
{
    int z; cin>>z;//liczba zestawow
    while(z--)
    {
        int n; cin>>n;//liczba budynkow
        short miasto[1000000];
        for(int i=0; i<n; i++) cin>>miasto[i];

        int d=0;
        int a=100000;
        int Z=0, k, K=0;

        for(int j=0; n-j>d; j++)
        {
            if(miasto[j]>=a) continue;
            a=miasto[j];
            for(k=n-1; k>j and miasto[k]<=miasto[j]; k--);

            //cout<<j<<":"<<k<<endl;
            if(k-j>d) { Z=j; K=k; d=K-Z; }
        }
        if(d==0) cout<<"NIE"<<endl;
        else cout<<Z<<" "<<K<<endl;
    }

    return 0;
}
