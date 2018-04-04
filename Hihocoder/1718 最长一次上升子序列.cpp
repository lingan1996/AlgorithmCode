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

int dp[K],sp[K];

int main(void)
{
    int n,ca=1,cb=1;
    cin>>n;
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        if(i==1)
        {
            dp[1]=sp[1]=-x;
            continue;
        }
        x=-x;
        if(sp[cb]<=x)
            sp[++cb]=x;
        else
            sp[upper_bound(sp+1,sp+1+cb,x)-sp]=x;
        if(dp[ca]>x)
        {
            cb=max(cb,ca+1);
            for(int j=ca+1;j>=1;j--)
            if(sp[j]>x)
                sp[j]=x;
            else
                break;
        }
        if(dp[ca]<=x)
            dp[++ca]=x;
        else
            dp[upper_bound(dp+1,dp+1+ca,x)-dp]=x;
    }
    printf("%d\n",max(ca,cb));
    return 0;
}