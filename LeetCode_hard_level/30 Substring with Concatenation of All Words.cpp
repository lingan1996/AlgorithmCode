class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int cnt[10000],ns[10000],n=s.length(),m=words[0].length(),vn=words.size();
        string tmp=words[0];
        map<string,int>hs;
        set<int>st;
        for(int i=0;i<words.size();i++)
        {
            if(hs[words[i]])
                ns[hs[words[i]]]++;
            else
                hs[words[i]]=i+1,ns[i+1]=1;
        }
        for(int i=0;i<m;i++)
        {
            vector<int>num;
            memset(cnt,0,sizeof cnt);
            for(int j=i;j<n&&j+m<=n;j+=m)
            {
                for(int k=0;k<m;k++)
                    tmp[k]=s[j+k];
                if(hs.find(tmp)!=hs.end())
                    num.push_back(hs[tmp]);
                else
                    num.push_back(0);
            }
            for(int p=0,q=0,k=0;p+vn<=num.size();p++)
            {
                while(q<p+vn)
                {
                    if(num[q]&&(cnt[num[q]]<ns[num[q]]))
                        k++,cnt[num[q]]++;
                    else if(num[q])
                        cnt[num[q]]++;
                    q++;
                }
                if(k==vn)
                    st.insert(p*m+i);
                if(num[p]&&cnt[num[p]]<=ns[num[p]])
                    k--,cnt[num[p]]--;
                else if(num[p])
                    cnt[num[p]]--;
            }
        }
        vector<int>ans;
        for(auto it:st)
            ans.push_back(it);
        return ans;
            
    }
};