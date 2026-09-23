class Solution {
public:
// Next Smaller Element (strictly smaller), n if none
vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

// Previous Smaller or Equal Element, -1 if none
vector<int> findPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        vector<int> nse(n, n), pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nse[st.top()] = i;   // next strictly smaller
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();  // previous smaller or equal
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + left * right % mod * arr[i]) % mod;
        }
        return total;
    }
};