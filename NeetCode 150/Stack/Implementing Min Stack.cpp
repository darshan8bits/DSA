class MinStack {
public:
    stack<int> mainStack;
    stack<int> minst;
    
    MinStack() {
    
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minst.empty()){
            minst.push(val);
            return;
        }
        minst.push(min(minst.top(), val));
    }
    
    void pop() {
        mainStack.pop();
        minst.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minst.top();
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