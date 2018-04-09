class Solution {
public:
    int n,ul[100],ux[100],uy[100];
    char mp[100][100];
    vector<vector<string>> ans;
    vector<string>tmp;
    
    void dfs(int x)
    {
        if(x==n)
        {
            tmp.clear();
            for(int i=0;i<n;i++)
            {
                string tb;
                for(int j=0;j<n;j++)
                    tb+=mp[i][j];
                cout<<tb<<endl;
                tmp.push_back(tb);
            }
            ans.push_back(tmp);
            cout<<endl;
            return ;
        }
        for(int j=0;j<n;j++)
        if(ul[j]==0&&ux[j-x+50]==0&&uy[n-x-j+50]==0)
        {
            ul[j]=ux[j-x+50]=uy[n-x-j+50]=1;
            mp[x][j]='Q';
            dfs(x+1);
            mp[x][j]='.';
            ul[j]=ux[j-x+50]=uy[n-x-j+50]=0;
        }
    }
    vector<vector<string>> solveNQueens(int N) {
        n=N;
        memset(ul,0,sizeof ul);
        memset(ux,0,sizeof ux);
        memset(uy,0,sizeof uy);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp[i][j]='.';
        dfs(0);
        return ans;
    }
};