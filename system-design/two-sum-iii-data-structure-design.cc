//  Two Sum III - Data Structure Design

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < number) l = mid + 1;
            else    r = mid;
        }
        nums.insert(nums.begin()+l, number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum > value)    r --;
            else if (sum < value)   l ++;
            else    return true;
        }
        return false;
    }
    
private:
    vector<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */