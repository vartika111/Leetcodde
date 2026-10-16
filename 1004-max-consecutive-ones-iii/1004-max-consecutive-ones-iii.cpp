class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0;
        //sc=1 , TC= 2n
        int r=0;
        int zeros=0;
        int maxl=0;
        int len =0;
        while(r<nums.size())
        { 
            if(nums[r]==0 )
            zeros++;

            while(zeros>k)
            {
                if(nums[l]==0)
                zeros--;
                l++;

            }
        if(zeros<=k)
        {
            len=r-l+1;
            maxl=max(maxl,len);
        }

            r++;
        }

        return maxl;
        
    }
};