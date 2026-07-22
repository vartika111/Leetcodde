class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int e=r*c-1;
        int st=0;
        //linear mid index
       
        while(st<=e)
        {   int mid=st+(e-st)/2;
            int ele= matrix[mid/c][mid%c];
            if(ele==target)
            return 1;
            if(ele>target)
            e=mid-1;

            if(ele<target)
            st=mid+1;

        }
        return 0;

        
    }
};