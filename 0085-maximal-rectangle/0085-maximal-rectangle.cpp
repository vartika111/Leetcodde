class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int element = st.top();
                st.pop();
                
                int nse = i; 
                int pse = st.empty() ? -1 : st.top(); 
                
                maxArea = max(maxArea, arr[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n;
            int element = st.top(); 
            st.pop();
            
            int pse = st.empty() ? -1 : st.top();
            
            maxArea = max(maxArea, (nse - pse - 1) * arr[element]);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> psum(r, vector<int>(c, 0));
        int maxArea = 0;

        // Build the histogram heights row by row
        for (int j = 0; j < c; j++) {
            int height = 0;
            for (int i = 0; i < r; i++) {
                if (matrix[i][j] == '1') {
                    height += 1;
                } else {
                    height = 0;
                }
                psum[i][j] = height;
            }
        }

        // Apply largest rectangle in histogram for each row
        for (int i = 0; i < r; i++) {
            maxArea = max(maxArea, largestRectangleArea(psum[i]));
        }

        return maxArea;
    }
};