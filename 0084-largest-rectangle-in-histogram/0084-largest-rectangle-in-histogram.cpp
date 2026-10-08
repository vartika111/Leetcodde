class Solution {
public:

    int largestRectangleArea(vector<int>& arr) {
    stack<int> st;
    int maxArea = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // While stack is not nerdy and the element at stack top is greater than current arr[i]
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int element = st.top();
            st.pop();
            
            int nse = i; // Next Smaller Element index
            int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element index
            
            maxArea = max(maxArea, arr[element] * (nse - pse - 1));
        }
        st.push(i);
    }

    // Process remaining elements in the stack
    while (!st.empty()) {
        int nse = n;
        int element = st.top(); 
        st.pop();
        
        int pse = st.empty() ? -1 : st.top();
        
        maxArea = max(maxArea, (nse - pse - 1) * arr[element]);
    }

    return maxArea;
}
};