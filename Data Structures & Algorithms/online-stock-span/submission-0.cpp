class StockSpanner {

private:
    std::stack<int> stck;
    std::stack<int> temp;


public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stck.push(price);
        int span = 0;
        while (!stck.empty() && stck.top() <= price){
            temp.push(stck.top());
            stck.pop();
            span ++;
        }

        while (!temp.empty()){
            stck.push(temp.top());
            temp.pop();
        }

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */