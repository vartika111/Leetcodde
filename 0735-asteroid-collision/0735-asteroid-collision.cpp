class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int>st;
        int n=asteroids.size();
       for(int i=0;i<n;i++)
       {
        if(asteroids[i]>=0)
        {
            st.push(asteroids[i]);
        }
        
        else
        {
           //current ele is negative 
           bool destroy=false;
           while(!st.empty() && st.top()>0)
           { //if exist value is smaller tha n pop
            if(st.top()<abs(asteroids[i]))
            st.pop();
            else if(st.top()==abs(asteroids[i]))
            {
                st.pop(); //destroy existing and upcmoig value cant be added to stack
                destroy=true;
                break;

            }
            else
            {
                //incoming asteroid is smaller than existing asteroid
                destroy=true;
                break;
            }

           }

           if(!destroy)// destroy have to be false to insert
           st.push(asteroids[i]);


        }
      
     
        
       }
      vector<int> result(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};