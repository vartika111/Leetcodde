class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>ans;
        int strow=0;
        int stcol=0;
        int erow=r-1;
        int ecol=c-1;
        int total=r*c;
        int count=0;
        while(count<total)
        {
            //print starting row
            for(int j=stcol;count<total && j<=ecol;j++)
            {
                ans.push_back(matrix[strow][j]);
                count++;
               
            }
             strow++;

            //print end column
            for(int i=strow;count<total && i<=erow;i++)
            {
                ans.push_back(matrix[i][ecol]);
                count++;
              
            }
              ecol--;

            //print end row
             for(int j=ecol;count<total && j>=stcol;j--)
            {
                ans.push_back(matrix[erow][j]);
                count++;
              
            }
              erow--;

            //print starting col
             for(int i=erow;count<total && i>=strow;i--)
            {
                ans.push_back(matrix[i][stcol]);
                count++;
              
            }
              stcol++;

        }

        return ans;

    
        
    }
};