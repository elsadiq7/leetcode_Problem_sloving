class MinStack {
    
private:
    stack<int>my_stack;
    stack<int>min_stack;
    int min;
    int start=1;
public:
    MinStack() {}
    
    void push(int val) {
        if (min_stack.empty()||val<=min_stack.top())  
        {
            min_stack.push(val);
        }
        
        my_stack.push(val);
    }
    
    void pop() {
        if (my_stack.top()==min_stack.top())
        {
            min_stack.pop();
        }
        
        my_stack.pop();
        
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        
        return min_stack.top();
        
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