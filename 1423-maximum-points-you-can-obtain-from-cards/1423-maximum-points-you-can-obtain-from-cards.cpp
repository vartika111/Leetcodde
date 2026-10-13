class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //k element sum from left side
        int lsum=0;
        int rsum=0;
       
        for(int i=0;i<k;i++)
        lsum+=cardPoints[i];

        //intial maxsum
         int maxsum=lsum;

        //now we have to reduce one element in each loop
        int j=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=cardPoints[i];
            rsum+=cardPoints[j];
            j--;
            maxsum=max(maxsum,lsum+rsum);
        }

        return maxsum;

        
    }
};