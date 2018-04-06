class Solution {
public:
    string a,b;
    int la,lb,ans=0;
    map<pair<int,int>,int>hs;
    
    void dfs(int x,int y)
    {
        if(hs[make_pair(x,y)])
            return;
        else
            hs[make_pair(x,y)]=1;
        if(x==la&&y==lb)
        {
            ans=1;return ;
        }
        else if(x==la||ans)
            return;
        else if(y==lb)
        {
            ans=1;
            for(int i=x;i<la&&ans;i++)
            if(a[i]!='*')
                ans=0;
            return;
        }
        if(a[x]=='?')
            dfs(x+1,y+1);
        else if(a[x]=='*')
            while(y<=lb)
                dfs(x+1,y++);
        else if(a[x]==b[y])
            dfs(x+1,y+1);
    }
    
    bool isMatch(string s, string p) {
        b=s,a=p;
        la=a.size(),lb=b.size();
        dfs(0,0);
        return ans==1;
    }
};