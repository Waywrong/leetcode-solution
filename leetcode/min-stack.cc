//  Min Stack

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        main_stack.push(x);
        if (mini_stack.empty() || x <= mini_stack.top())
            mini_stack.push(x);
    }
    
    void pop() {
        int tmp = main_stack.top();
        main_stack.pop();
        if (tmp == mini_stack.top())
            mini_stack.pop();
    }
    
    int top() {
        int res = main_stack.top();
        return res;
    }
    
    int getMin() {
        int res = mini_stack.top();
        return res;
    }
    
private:
    stack<int> main_stack;
    stack<int> mini_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */