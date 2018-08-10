//  Design HashSet

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (!contains(key)) {
            int pos = search_insert_position(key);
            hash_set.insert(hash_set.begin()+pos, key);
        }
    }
    
    void remove(int key) {
        if (contains(key)) {
            int pos = search_insert_position(key);
            hash_set.erase(hash_set.begin() + pos);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = search_insert_position(key);
        return (pos!=hash_set.size() && hash_set[pos]==key) ? true : false;   
    }
    
    int search_insert_position(int key) {
        int l = 0, r = hash_set.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (hash_set[mid] < key)    l = mid + 1;
            else    r = mid;
        }
        return l;
    }
    
private:
    vector<int> hash_set;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
