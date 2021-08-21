class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxconsecutiveone=0;
        int start=0;
        int zerocount=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==0)
                zerocount++;
            while(zerocount>k){
                if(nums[start]==0)
                    zerocount--;
                start++;
            }
            maxconsecutiveone=max(maxconsecutiveone,end-start+1);
        }
        return maxconsecutiveone;
    }
};
