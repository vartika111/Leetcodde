class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> temp(n);
      
        int i=0;
        while(i<n)
        {  
            temp[(i+k)%n]=nums[i];
            i++;
        }
        
        for(int j=0;j<n;j++)
        nums[j]=temp[j];
    }
};