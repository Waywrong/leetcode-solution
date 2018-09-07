//  Max Stack

class MaxStack {
public:
    list<int> l;
    multimap<int, list<int>::iterator> map; 
    
    MaxStack() {}
    
    void push(int x) {
        l.push_front(x);
        map.insert({x, l.begin()});
    }
    
    int pop() {
        int x = l.front();
        l.pop_front();
        map.erase(--map.upper_bound(x));
        return x;
    }
    
    int top() {
        return l.front();
    }
    
    int peekMax() {
        return map.rbegin()->first;
    }
    
    int popMax() {
        auto kv = --map.end();
        map.erase(kv);
        l.erase(kv->second);
        return kv->first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */