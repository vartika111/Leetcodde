class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>rank;
        vector<string>ans(score.size());
        for(int i=0;i<score.size();i++)
        {
            rank.push_back({score[i],i});
        }

        //now sort pair in desecending order
        sort(rank.begin(),rank.end(),greater<pair<int,int>>());

for(int i = 0; i < rank.size(); i++)
 {
            int originalIndex = rank[i].second;

            if(i == 0)
                ans[originalIndex] = "Gold Medal";
            else if(i == 1)
                ans[originalIndex] = "Silver Medal";
            else if(i == 2)
                ans[originalIndex] = "Bronze Medal";
            else
                ans[originalIndex] = to_string(i + 1);
        }

return ans;
        
    }
};