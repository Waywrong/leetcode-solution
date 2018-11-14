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
