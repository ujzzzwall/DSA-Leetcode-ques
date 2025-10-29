class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int>st;
        vector<int> nge(m);
        nge[m-1] = -1;
        st.push(nums2[m-1]);
        for(int i =m-2 ; i>=0 ; i--){
            while(st.size()!=0 && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.size()!=0) nge[i]=st.top();
            else nge[i]= -1;
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ;j<m ;j++){
                if(nums1[i]==nums2[j]){ans.push_back(nge[j]);
                break;}
            }
        }
        return ans;
    }
};