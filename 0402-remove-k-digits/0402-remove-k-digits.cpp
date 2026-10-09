class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        //only k times pop operation 
        int c=0;
        stack<char>st;
        int n= num.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && (num[i]<st.top() && c<k))
            {
                 st.pop();
                 c++;
            }

            st.push(num[i]);
           
        }

        // 3. If k deletions haven't been met yet (e.g., "123", k=2)
        while(c < k && !st.empty()) 
        {
            st.pop();
            c++;
        }


        string str="";
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());


        //remove ) index at beginig
        int zeroIdx=0;
        while(zeroIdx<str.length() && str[zeroIdx]=='0')
        zeroIdx++;
        string result=str.substr(zeroIdx);
        return result.empty()?"0":result; 
    }
};