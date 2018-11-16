//  Kth Largest Element in an Array

//  Method I, Heap Sort, O(KlogN)
class Solution {
public:
    void maxHeapify(vector<int> &nums, int low, int high) {
        int i = low, j = 2 * i + 1, k = 0;
        while (j <= high) {
            k = nums[i] > nums[j] ? i : j;
            if (j<high && nums[j+1]>nums[k])
                k = j + 1;
            if (k != i) {
                swap(nums[k], nums[i]);
                i = k;
                j = 2 * i + 1;
            }
            else
                break;
        }
    }
    
    void buildMaxHeap(vector<int> &nums) {
        int n = nums.size();
        for (int i = n / 2; i >= 0; -- i)
            maxHeapify(nums, i, n-1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        int n = nums.size();
        for (int i = 1; i < k; ++ i) {
            swap(nums[0], nums[n - i]);
            maxHeapify(nums, 0, n - i - 1);
        }
        return nums[0];
    }
};

//  Method 2, Quick Sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
    
private:
    int partition(vector<int> &nums, int low, int high) {
        int t = nums[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && nums[j] < t)
                -- j;
            if (i < j)
                nums[i ++] = nums[j];
            while (i < j && nums[i] > t) 
                ++ i;
            if (i < j)
                nums[j --] = nums[i];
        }
        nums[i] = t;
        return i;
    }
    
    int findKthLargest(vector<int> &nums, int low, int high, int k) {
        if (low == high)
            return nums[low];
        int pos = partition(nums, low, high);
        if (pos == low + k - 1)
            return nums[pos];
        else if (pos > low + k - 1)
            return findKthLargest(nums, low, pos - 1, k);
        else
            return findKthLargest(nums, pos + 1, high, k - pos + low - 1);
    }
};
