//  LRU Cache

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        int val = map[key]->second;
        queue.erase(map[key]);
        queue.push_front(make_pair(key, val));
        map[key] = queue.begin();
        return val;
    }
    
    void put(int key, int value) {
        if (map.find(key) == map.end()) {
            if (queue.size() >= capacity) {
                int temp = queue.back().first;
                queue.pop_back();
                map.erase(temp);
            }
        }
        else 
            queue.erase(map[key]);
        queue.push_front(make_pair(key, value));
        map[key] = queue.begin();
    }
    
private:
    int capacity;
    list<pair<int, int>> queue;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */