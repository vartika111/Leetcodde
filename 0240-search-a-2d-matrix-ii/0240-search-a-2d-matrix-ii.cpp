class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int r=matrix.size();
    int c= matrix[0].size();
    int strow=0;
    int ecol=c-1;

    while(strow<r && ecol>=0)
    {
        int ele=matrix[strow][ecol];
        if(ele==target)
        return 1;
        if(ele>target)
        ecol--;
        if(ele<target)
        strow++;
    }
    return 0;
    }
};