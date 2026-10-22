class Solution {
public:
    int numberOfSubstrings(string s) {
       
      vector<int>Lastseen(3,-1);
        int r=0;
        int count=0;
        while(r<s.length())
        {
        Lastseen[s[r]-'a']=r;

        if(Lastseen[0]!=-1 && Lastseen[1]!=-1 && Lastseen[2]!=-1)
        {
            count+=1+min(
                {Lastseen[0],Lastseen[1],Lastseen[2]});
        }
            r++;
        }

        return count;
        
    }
};