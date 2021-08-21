class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int arr[n];
        for(int i=0;i<n;i++) arr[i]=cost[i];
        for(int i=2;i<n;i++){
            arr[i]+=min(arr[i-1],arr[i-2]);
        }
        return min(arr[n-1],arr[n-2]);
        
    }
};
