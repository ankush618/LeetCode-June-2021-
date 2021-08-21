class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int l2r[n];
        int r2l[n];
        for(int i=0;i<n;i++)
            l2r[i]=r2l[i]=1;
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                l2r[i]=l2r[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                r2l[i]=r2l[i+1]+1;
        }
        int res[n];
        for(int i=0;i<n;i++){
            res[i]=max(r2l[i],l2r[i]);
        }
        int ans = accumulate(res,res+n,0);
        return ans;
        
    }
};
//code by shreyashi bansal
