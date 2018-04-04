class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size(),c=(n+m)&1,k=(n+m+1)/2;
        int sa=-1,sb=-1;
        n--,m--;
        while(1)
        {
            if(sa==n&&c)
                return b[sb+k]*1.0;
            else if(sa==n)
                return (b[sb+k]+b[sb+k+1])/2.0;
            if(sb==m&&c)
                return a[sa+k]*1.0;
            else if(sb==m)
                return (a[sa+k]+a[sa+k+1])/2.0;
            if(k==1)
            {
                if(c)
                    return min(a[sa+1],b[sb+1])*1.0;
                else
                {
                    if(a[sa+1]<b[sb+1])
                    {
                        if(sa+2<=n)
                            return (min(a[sa+2],b[sb+1])+a[sa+1])/2.0;
                        else
                            return (a[sa+1]+b[sb+1])/2.0;
                    }
                    else
                    {
                        if(sb+2<=m)
                            return (min(a[sa+1],b[sb+2])+b[sb+1])/2.0;
                        return (a[sa+1]+b[sb+1])/2.0;
                    }
                }
            }
            int i=min(k/2,n-sa),j=k-i;
            if(j>m-sb)
                j=m-sb,i=k-j;
            if(a[sa+i]<=b[sb+j])
                k-=i,sa+=i;
            else
                k-=j,sb+=j;
        }
        
    }
};