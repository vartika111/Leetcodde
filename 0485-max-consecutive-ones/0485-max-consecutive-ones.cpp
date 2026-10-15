class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int maxlen=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==1)
            maxlen =max(maxlen,r-l+1);
            else
            {
                //shift l becuse new 1is string started
                l=r+1;
            }
        }
        return maxlen;
        
    }
};