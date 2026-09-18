class Solution {
public:
    int trap(vector<int>& height)
     {
      int  rMax=0,lMax=0,total=0;
      int l=0;
      int n= height.size();
      int r=n-1;
      while(l<r)
      {
        if(height[l]<=height[r])
        {
            if(lMax>height[l])
            total+=lMax-height[l];
            else
            lMax=height[l];
            l+=1;


        }
        else
        {
            if(rMax>height[r])
            total+=rMax-height[r];
            else
            rMax=height[r];
            r-=1;
        }
      }

      return total;  
    }
};