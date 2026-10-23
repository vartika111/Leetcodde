class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        int maxf=0;
        int maxl=0;
        unordered_map<char,int>st;
        while(r<s.size())
        {
            st[s[r]]++;
            maxf=max(maxf,st[s[r]]);

            int changes=(r-l+1)-maxf;           
            if(changes<=k)
            maxl=max(maxl,r-l+1);
            if(changes>k)
            {  st[s[l]]--;
                if(st[s[l]]==0)
                st.erase(st[s[l]]);
                 l++;
            }
            r++;
        }

        return maxl;
        
    }
};