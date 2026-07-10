class Solution {
public:
char toLower(char c)
        {
            if(c>='A' && c<='Z')
        {
             char temp=c-'A'+'a';
            return temp;
        }
        else
            return c;
            
        }
    bool isPalindrome(string s) {
        int st=0;
        bool p=true;
        int e=s.size()-1;
        
        while(st<e)
        {   
            while(st<e &&  !isalnum(s[st]))
            st++;

             while(st<e &&  !isalnum(s[e]))
            e--;

            
            if(toLower(s[st])!=toLower(s[e]))
            {
               return false;
            }
            
             st++;
                e--;

          

        }
         return true;

        
    }
};