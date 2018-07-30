//  Contains Duplicate III

// Time O(NlogK), Space O(K)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<long> slide;
        for (int i=0; i<nums.size(); i++) {
            if (i > k) {
                vector<long>::iterator it = find(slide.begin(), slide.end(), nums[i-k-1]);
                slide.erase(it);
            }
            int pos = search_insert_position(slide, nums[i]);
            slide.insert(slide.begin()+pos, nums[i]);
            if (pos-1 >= 0 && slide[pos]-slide[pos-1]<=t)
                return true;
            if (pos+1<slide.size() && slide[pos+1]-slide[pos]<=t)
                return true;
        }
        return false;
    }
    
    int search_insert_position(vector<long> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) l = mid + 1;
            else    r = mid;
        }
        return l;
    }
};