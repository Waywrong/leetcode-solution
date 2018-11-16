//  Find Peak Element

//  Solution 1, O(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size()-1);
    }
    
    int findPeakElement(vector<int>& nums, int start, int end){
        if(start > end)
            return -1;
        int mid = (end-start)/2 + start;
        if((mid==0 ||nums[mid-1] < nums[mid]) && (mid==nums.size()-1 || nums[mid+1] < nums[mid]))
            return mid;
        int index1,index2;
        index1 = findPeakElement(nums, start, mid-1);
        index2 = findPeakElement(nums, mid+1, end);
        if(index1 != -1)
            return index1;
        return index2;
    }
};

//  Solution 2, O(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((mid == 0 || nums[mid-1] < nums[mid]) && (mid == nums.size()-1 || nums[mid+1] < nums[mid]))
                return mid;
            if (mid != 0 && nums[mid-1] > nums[mid])
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return l;
    }
};
