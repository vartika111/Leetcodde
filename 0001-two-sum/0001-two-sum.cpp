class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++)
        arr.push_back({nums[i],i});
      
        sort(arr.begin(), arr.end());

      
        int s=0;
        int e= arr.size()-1;

        while(s<e)
        {
            int sum=arr[s].first + arr[e].first;
            if(sum==target)
            {
                int i1=arr[s].second;
                int i2=arr[e].second;

                if(i1<i2)
                return {i1,i2};
                else
                return {i2,i1};

            }
           

            else if(sum<target)
            s++;

            else
            e--;
        }

        return{};
        
    }
};