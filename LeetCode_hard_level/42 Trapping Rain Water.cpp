class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size()==0)
            return 0;
        int n=h.size(),ans=0,pre[100000];
        pre[0]=h[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+h[i];
        for(int i=0;i<n-1;i++)
        if(h[i])
        {
            int d=-1,dh,ff=0;
            for(int j=i+1;j<n;j++)
            if(h[j]>=h[i])
            {
                ans+=min(h[i],h[j])*(j-i-1)-(pre[j-1]-pre[i]);
                i=j-1,ff=1;
                break;
            }
            else if(d<0||h[j]>dh)
                d=j,dh=h[j];
            if(d>0&&!ff)
                ans+=dh*(d-i-1)-(pre[d-1]-pre[i]),i=d-1;
        }
        return ans;
    }
};