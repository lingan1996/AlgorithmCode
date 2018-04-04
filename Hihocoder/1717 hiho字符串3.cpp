#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int,int> PII;
const double eps=1e-8;
const double pi=acos(-1.0);
const int K=1e5+7;
const int mod=1e9+7;

char nt[200];
LL p[100];
//end 51
void dfs(int n,LL k,char ca,char cb)
{
    if(k==1)
    {
        printf("%c\n",ca);
        return ;
    }
    else if(k==2)
    {
        printf("%c\n",cb);
        return ;
    }
    if(p[51-n]<k)
        dfs(n+1,k-=p[51-n],cb,nt[cb]);
    else
        dfs(n+1,k,ca,nt[ca]);
}

int main(void)
{
    LL k,T;
    cin>>T;
    p[0]=1;
    for(int i=1;i<=50;i++)
        p[i]=p[i-1]*2;
    nt['h']='i';
    nt['i']='o';
    nt['o']='h';
    while(T--)
        cin>>k,dfs(2,k,'h','i');
    return 0;
}