class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    
     int r=matrix.size();
     int c=matrix[0].size();
      vector<vector<int>>matrix2(r, vector<int>(c));
     int s=c-1;
     for(int i=0;i<r;i++)
     { 
        for(int j=0;j<c;j++)
        {
            matrix2[j][s]=matrix[i][j];
        }
        s--;
     }

     matrix=matrix2;


        
    }
};