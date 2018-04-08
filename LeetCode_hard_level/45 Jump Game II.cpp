class Solution {
public:
    int n,mi[100007];
    void add(int x,int v)
    {
        while(x<=n) mi[x]=min(mi[x],v),x+=x&-x;
    }
    int get_mi(int x)
    {
        int ret=0x3f3f3f3f;
        while(x) ret=min(mi[x],ret),x-=x&-x;
        return ret;
    }
    int jump(vector<int>& nums) {
        int dp[100007],ans=0x3f3f3f3f;
        memset(mi,0x3f3f3f3f,sizeof mi);
        memset(dp,0x3f3f3f3f,sizeof dp);
        dp[0]=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            dp[i]=min(dp[i],get_mi(n-i));
            if(i+nums[i]<n&&dp[i+nums[i]]>dp[i]+1)
            {
                dp[i+nums[i]]=min(dp[i+nums[i]],dp[i]+1),add(n-i-nums[i],dp[i]+1);
            }
            else if(i+nums[i]>=n)
                add(1,dp[i]+1);
        }
        return dp[n-1];
    }
};