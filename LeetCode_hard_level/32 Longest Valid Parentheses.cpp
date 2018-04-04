class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length(),ans=0,dp[100000];
        memset(dp,0,sizeof dp);
        for(int i=1;i<len;i++)
        if(s[i]==')'&&s[i-1-dp[i-1]]=='(')
        {
            if(i-1-dp[i-1]-1>=0)
                dp[i]+=dp[i-1-dp[i-1]-1];
            ans=max(dp[i]+=2+dp[i-1],ans);
        }
        return ans;
    }
};