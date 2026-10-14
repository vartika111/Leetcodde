class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //we just need array here but storing value will be last seen index
        vector<int>st(256,-1);
        int maxlen=0;
        int r=0;
        int l=0;
        int len=0;
        while(r<s.size())
        {
            //alreday seen and boundary check
            if(st[s[r]] != -1 && st[s[r]] >= l) {
                l = st[s[r]] + 1; // Shift left pointer past the previous occurrence
            }


                // Update the last seen index of the current character
                st[s[r]] = r;

                len=r-l+1;
                maxlen=max(len,maxlen);
            
          
            r++;

        }

        return maxlen;

        
    }
};