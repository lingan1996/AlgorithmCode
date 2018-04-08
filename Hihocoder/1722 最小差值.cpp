//hash邪教代码
#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned int UU;
typedef pair<int,int> PII;
const double eps=1e-8;
const double pi=acos(-1.0);
const int K=5e5+7;
const int mod=1e9+7;


UU hs1[K],hs2[K],p[K],base;
char ss[K];

UU get_hash1(int l,int r)
{
    if(l>r) return 0;
    return hs1[r]-hs1[l-1]*p[r-l+1];
}
UU get_hash2(int l,int r)
{
    if(l>r) return 0;
    return hs2[l]-hs2[r+1]*p[r-l+1];
}

int main(void)
{
    int ans=0;
    base=mod;
    scanf("%s",ss+1);
    p[0]=1;
    for(int i=1;i<K;i++)
        p[i]=p[i-1]*base;
    int len=strlen(ss+1),mid=(len-1)/2;
    for(int i=1;i<=len;i++)
        hs1[i]=hs1[i-1]*base+ss[i]-'a';
    for(int i=len;i;i--)
        hs2[i]=hs2[i+1]*base+ss[i]-'a';
    for(int i=1;i<=len;i++)
    if(len&1)
    {
        UU ta,tb;
        if(i<=mid)
        {
            ta=get_hash1(1,i-1)*p[mid-i+1]+get_hash1(i+1,mid+1);
            tb=get_hash2(mid+2,len);
        }
        else if(i==mid+1)
        {
            ta=get_hash1(1,mid);
            tb=get_hash2(mid+2,len);
        }
        else
        {
            ta=get_hash1(1,mid);
            tb=get_hash2(mid+2,i-1)+get_hash2(i+1,len)*p[i-1-mid-2+1];
        }
        if(ta==tb)
        {
            ans=i;break;
        }
    }
    else
    {
        UU ta,tb;
        if(i<=mid)
        {
            ta=get_hash1(1,i-1)*p[mid+1-i]+get_hash1(i+1,mid+1);
            tb=get_hash2(mid+3,len);
        }
        else if(i==mid+1||i==mid+2)
        {
            ta=get_hash1(1,mid);
            tb=get_hash2(mid+3,len);
        }
        else
        {
            ta=get_hash1(1,mid);
            tb=get_hash2(mid+2,i-1)+get_hash2(i+1,len)*p[i-1-mid-2+1];
        }
        if(ta==tb)
        {
            ans=i;break;
        }
    }
    printf("%d\n",ans);
    return 0;
}