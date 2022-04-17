class MinStack {
public:
    stack<int> ogStack;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        ogStack.push(val);
        if(minStack.size() > 0)
            val = min(val, minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        ogStack.pop();
        minStack.pop();
    }
    
    int top() {
        return ogStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */