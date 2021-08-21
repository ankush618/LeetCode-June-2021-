class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int c=1;
        if(nums.size()==0) return 0;
        int lar=1; // for storing largest sequence
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) // if both are equal continue further
            continue;
            if(nums[i] == nums[i+1] - 1){ c=c+1;}
            else c=1;
            
            lar=max(lar,c);
        }
        return lar;
        
    }
};
