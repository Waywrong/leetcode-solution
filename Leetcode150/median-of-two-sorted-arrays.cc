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
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
            return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
        }
    }
    double findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j) return findKth(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int pa = min(i + k / 2, int(nums1.size())), pb = j + k - pa + i;
        if (nums1[pa - 1] < nums2[pb - 1]) 
            return findKth(nums1, pa, nums2, j, k - pa + i);
        else if (nums1[pa - 1] > nums2[pb - 1]) 
            return findKth(nums1, i, nums2, pb, k - pb + j);
        else 
            return nums1[pa - 1];
    }
};