//  Kth Largest Element in an Array

// Time O(KNlogN), Space O(1)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int size = nums.length;
        for (int i=1; i<=k; i++) {
            buildMaxHeap(nums, size-i+1);
            int t = nums[0]; nums[0] = nums[size-i]; nums[size-i] = t;
        }
        return nums[size-k];
    }
    
    private void buildMaxHeap(int[] nums, int size) {
        for (int step=size/2; step>=0; step--) {
            int i = step, j = 2*step+1;
            while (j < size) {
                int left=j, right=j+1, largest;
                if (nums[left] > nums[i])
                    largest = left;
                else
                    largest = i;
                if (right<size && nums[right]>nums[largest])
                    largest = right;
                if (largest != i) {
                    int t = nums[largest]; nums[largest] = nums[i]; nums[i] = t;
                    i = largest; j = 2*i+1;
                }
                else
                    break;
            }
        }
    }
}