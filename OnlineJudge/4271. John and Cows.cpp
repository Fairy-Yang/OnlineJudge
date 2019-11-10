#include<algorithm>
#include<iostream>
using namespace std;

char rooms[100000];
int Johns[100000];

int main()
{
    while(true){
    int n, k;
    cin>>n>>k;  //n = rooms, k = cows;

    Johns[k] = -1;

    for(int i=0; i<n; ++i)
    {
        cin>>rooms[i];
    }

    int i, j, s; 
    bool flag=true;
    int distence, minimum=n;
    for(i=0;i<n-k; ++i)
    {
        s = i;
        for(j=0; j<k+1; ++j)
        {
            for(;s<n;++s)
            {
                if(rooms[s] == '0')
                {
                    Johns[j] = s;
                    ++s;
                    break;
                }
            }
            if(s==n && Johns[k]==-1) {flag=false; break;}
        }
        if(!flag) continue;
         distence = max(Johns[k/2] - Johns[0], Johns[k] - Johns[k/2]);
        if(k%2!=0)
        {
            if(distence > max(Johns[k/2+1] - Johns[0], Johns[k] - Johns[k/2+1]))
                distence = max(Johns[k/2+1] - Johns[0], Johns[k] - Johns[k/2+1]);
        }
        
        if(minimum > distence)
            minimum = distence;
        Johns[k]=-1;
    }
    cout<<minimum;
    }
    return 0;
}