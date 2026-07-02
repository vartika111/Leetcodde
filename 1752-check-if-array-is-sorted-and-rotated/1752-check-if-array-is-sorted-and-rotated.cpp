class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        vector<int> temp(n);
        bool dup=false;
        vector<int> asc;
        asc=nums;
        sort(asc.begin(),asc.end());
       
        for(int i=0;i<n;i++)
        {
            int k=0;
           while(k<n)
           {
            temp[(k+i)%n]=nums[k];
            k++;
           }

           if(temp==asc)
           dup=true;
        }

        if(dup)
        return true;
        else
        return false;
        
    }
};