//  Median of Two Sorted Arrays

/* Solution 1 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        int p1 = 0, p2 = 0;
        int prev, cur = 0, i = 0;
        while (p1<n1 && p2<n2) {
            prev = cur;
            if (nums1[p1] < nums2[p2])
                cur = nums1[p1 ++];
            else 
                cur = nums2[p2 ++];
            if (i++ == n/2) 
                return (n%2==0) ? (prev+cur)/2.0 : (double)cur;
        }
        while (p1 < n1) {
            prev = cur;
            cur = nums1[p1 ++];
            if (i++ == n/2)
                return (n%2==0) ? (prev+cur)/2.0 : (double)cur;
        }
        while (p2 < n2) {
            prev = cur;
            cur = nums2[p2 ++];
            if (i++ == n/2)
                return (n%2==0) ? (prev+cur)/2.0 : (double)cur;
        }
        return 0;
    }
};

/* Solution 2 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 1)
            return findKth(nums1, 0, nums2, 0, n/2+1);
        else
            return (findKth(nums1, 0, nums2, 0, n/2) + findKth(nums1, 0, nums2, 0, n/2+1)) / 2.0;
    }
    
    int findKth(vector<int> &nums1, int p1, vector<int> &nums2, int p2, int k) {
        if (nums1.size()-p1 > nums2.size()-p2)
            return findKth(nums2, p2, nums1, p1, k);
        if (nums1.size() == p1)
            return nums2[p2+k-1];
        if (k == 1)
            return min(nums1[p1], nums2[p2]);
        int pos1 = min(p1 + k/2, (int)nums1.size());
        int pos2 = p2 + k - pos1 + p1;
        if (nums1[pos1-1] < nums2[pos2-1])
            return findKth(nums1, pos1, nums2, p2, k-pos1+p1);
        else if (nums1[pos1-1] > nums2[pos2-1])
            return findKth(nums1, p1, nums2, pos2, k-pos2+p2);
        else
            return nums1[pos1-1];
    }
};
