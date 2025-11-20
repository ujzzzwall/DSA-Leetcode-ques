class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       int m =nums.size();
       vector<int>a1;
       for(int i=0;i<n ; i++){
        a1.push_back(nums[i]);
       }
       vector<int>a2;
       for(int i=n;i<2*n ; i++){
        a2.push_back(nums[i]);
       }
       vector<int>ans;

       for(int i=0 ;i<n ;i++){
            ans.push_back(a1[i]);
            ans.push_back(a2[i]);
       }
       return ans;
    }
};