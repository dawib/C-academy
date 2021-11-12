#include<iostream>
#include<string>
using namespace std;

void search(string text, string pattern, int& n);

main()
{
    string text;
    string word;

    int z;
    cin>>z;
    getline(cin, text);
    int i, n;
    for(i=0; i<z; i++)
    {
        cin.sync();
        getline(cin, text);
        getline(cin, word);
        n=-1;
        search(text, word, n);

        if(n==-1) cout<<"NIE"<<endl;
        else cout<<"TAK "<<n<<endl;
    }
}

int f(string t, char c, int p)
{
    if(c=='?') return p;
    else return t.find(c, p);
}

void search(string text, string pattern, int& n)
{
    int L=text.size(); int D=pattern.size();
    //if(D>L) return;
    int c=0;int i=0; int pos=-1; int j; int bos; int k;
    if(pattern[0]=='\0')
    {
        n=0; return;
    }
    if(pattern[0]=='*')
    {
        while(1)
        {
            if(pos==-1) pos++;
            else pos=f(text, ' ', pos+1);

            if(pos==string::npos)// or L-pos+1<D)
            {
                n=-1;
                return;
            }

            for(i=1; i<L and text[pos+i]!=' '; i++);
            //cout<<pos<<","<<i<<endl<<text.substr(pos, i)<<" "<<pattern.substr(1)<<endl;
            search(text.substr(pos, i), pattern.substr(1), n);

            if(n>=0)
            {
                if(pos==0) n=pos;
                else n=pos+1;
                return;
            }
        }
    }

    while(1)
    {
        k=0; i=0;
        pos=f(text, pattern[0], pos+1);
        if(pos==string::npos or pos>=L)// or L-pos<D)
        {
            n=-1;
            return;
        }

        if(text[pos]==' ') continue;

        for(j=1; j<D; j++)
        {
            if(pattern[j]=='*')
            {
                if(j==D-1) break;

                for(i=0; pos+i+j<L and text[pos+i+j]!=' ';)i++;

                //cout<<text.substr(pos+j, i)<<" "<<pattern.substr(j+1)<<endl;

                search(text.substr(pos+j, i), pattern.substr(j+1), n);
                //cout<<k<<endl;
                if(n==-1) k=1;
                break;
            }
            if(pos+j==L)
            {
                k=1; break;
            }
            if(pattern[j]=='?')
            {
                if(text[pos+j]==' ')
                {
                    k=1; break;
                }
                else continue;
            }

            if(pattern[j]!=text[pos+j])
            {
                k=1;
                break;
            }
        }

        if(k==0)
        {
            n=pos;
            //cout<<n<<endl;
            return;
        }
    }
}
