class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        
        int count=0;
        int ansIndex=0;
        while(i<chars.size())
        {    int j=i+1;
            while(j<chars.size()&& chars[i]==chars[j])
        {
           j++;
        }
        chars[ansIndex++]=chars[i];
        count=j-i;
        if(count>1)
        {
            string st=to_string(count);
        for(char ch :st)
        chars[ansIndex++]=ch;
        }
        i=j;
        }
        
        

        return ansIndex;



        
    }
};