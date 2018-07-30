//  Min Stack

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        main_stack.push(x);
        if (min_stack.empty() || x<=min_stack.top())
            min_stack.push(x);
    }
    
    void pop() {
        if (main_stack.empty()) return;
        int t = main_stack.top();
        main_stack.pop();
        if (min_stack.top() == t)
            min_stack.pop();
    }
    
    int top() {
        if (main_stack.empty()) return INT_MIN;
        return main_stack.top();
    }
    
    int getMin() {
        if (min_stack.empty())  return INT_MIN;
        return min_stack.top();
        
    }
    
private:
    stack<int> main_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */