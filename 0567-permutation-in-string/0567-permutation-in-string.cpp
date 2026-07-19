class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.length();
        int m=s2.length();
        if(k>m)
        return false;

        vector<int>f1(26,0);
        vector<int>f2(26,0);

        //frequency of s1
        for(char ch:s1)
        f1[ch-'a']++;

        //frequency of window sixe k
        for(int i=0;i<k;i++)
        f2[s2[i]-'a']++;

        if(f1==f2)
        return true;

        //next window
        for(int i=k;i<m;i++)
        {
            f2[s2[i]-'a']++;//add new character
            f2[s2[i-k]-'a']--;//remove oldcharacter
            if (f1 == f2)
                return true;
        }

        return false;

        
        
    }
};