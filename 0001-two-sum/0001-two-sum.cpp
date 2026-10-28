class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>st;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            st.push_back({nums[i],i});
        }
        
        //sorting the values
        sort(st.begin(),st.end());

        //Two pinter
        int i=0;
        int j=nums.size()-1;

        while(i<j)
        {
            int sum=st[i].first+st[j].first;

            if(sum==target)
            return {st[i].second,st[j].second};
            else if(sum>target)
            j--;
            else
            i++;

        }

     return{};
    }
};