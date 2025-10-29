class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int m =nums.size();
        stack<int> st;
        vector<int> nge(m,-1);
        for (int i = 2*m-1; i >= 0; i--) {
            int curr = nums[i % m];
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            } 
            if (i<m && !st.empty()) nge[i] = st.top();
            st.push(curr);
        }
        return nge;
    }
};