class Solution {
public:
    int firstMissingPositive(vector<int>& num) {
        int ff=-1e9-7,n=num.size(),ans=n+1;
        for(int i=0;i<n;i++)
        if(num[i]<=0)
            continue;
        else
        {
            for(int j=num[i],t;j>0&&j<=n;t=num[j-1],num[j-1]=ff,j=t)
                ;
        }
        for(int i=0;i<n;i++)
        if(num[i]!=ff)
        {
            ans=i+1;
            break;
        }
        return ans;
    }
};