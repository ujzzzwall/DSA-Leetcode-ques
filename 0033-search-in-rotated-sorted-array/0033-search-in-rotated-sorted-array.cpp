class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int pivot = -1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                pivot = mid;
                break;
            }
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
                pivot = mid + 1;
                break;
            }
            if (nums[mid] >= nums[lo] && nums[mid] > nums[hi]) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }
        if(pivot==-1){
            lo = 0;
            hi = nums.size() - 1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target)return mid;
                else if(nums[mid]<target)lo=mid+1;
                else hi=mid-1;
            }
            return -1;
        }
        if(target>=nums[0] && target<=nums[pivot-1]){
            lo=0;
            hi=pivot-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target)return mid;
                else if(nums[mid]<target)lo=mid+1;
                else hi=mid-1;
            }
        }
        else{
            lo=pivot;
            hi=nums.size()-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target)return mid;
                else if(nums[mid]<target)lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};