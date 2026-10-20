class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        //stop when more than two distinct elemens
        int r=0;
        int l=0;
        int maxlen =0;
       unordered_map<int,int>st;
        while(r<fruits.size())
        {    st[fruits[r]]++;

            if(st.size()>2) //having count for 2 distinct 
            {
                if(st.size()>2)
                {
                    st[fruits[l]]--;
                    if(st[fruits[l]]==0)
                    st.erase(fruits[l
                    ]);
                    l++;

                }

            }
           
            if(st.size()<=2)
            {
                
                 maxlen=max(maxlen,r-l+1);
            }
           
            r++;




        }
        return maxlen;
        
    }
};