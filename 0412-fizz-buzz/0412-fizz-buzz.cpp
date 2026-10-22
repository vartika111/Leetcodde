class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>st;
        st.reserve(n);

        for(int i=1;i<=n;i++)
        {    
            string current="";
            
            if(i%3==0)
            current+="Fizz";
            if(i%5==0)
            current+="Buzz";
           if(current.empty())
           current+=to_string(i);

           st.push_back(current);


           
        }

        return st;
        
    }
};