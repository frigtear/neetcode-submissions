class MinStack {

private:
    std::vector<int> minStack;
    std::vector<int> mainStack;
    

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStack.empty() || (!minStack.empty() && minStack.back() >= val)){
            minStack.push_back(val);
        }  
        mainStack.push_back(val);
    }
    
    void pop() {
        if (!minStack.empty() && minStack.back() == mainStack.back()){
            minStack.pop_back();
        }
        
       
        mainStack.pop_back();
        
    }
    
    int top() {
        return mainStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
