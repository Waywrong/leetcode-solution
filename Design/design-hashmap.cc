//  Design HashMap

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = containsKey(key);
        if (pos != -1)
            hash_map[pos] = make_pair(key, value);
        else {
            int k = searchInsertPosition(key);
            hash_map.insert(hash_map.begin()+k, make_pair(key, value));
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = containsKey(key);
        if (pos != -1)
            return hash_map[pos].second;
        else
            return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = containsKey(key);
        if (pos != -1)
            hash_map.erase(hash_map.begin() + pos);  
    }
    
    int containsKey(int key) {
        int l = 0, r = hash_map.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (hash_map[mid].first < key)  
                l = mid + 1;
            else    r = mid;
        }
        return (l!=hash_map.size() && hash_map[l].first==key) ? l : -1;
    }
    
    int searchInsertPosition(int key) {
        int l = 0, r = hash_map.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (hash_map[mid].first < key)  
                l = mid + 1;
            else    r = mid;
        }
        return l;
    }
private:
    vector<pair<int, int>> hash_map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
