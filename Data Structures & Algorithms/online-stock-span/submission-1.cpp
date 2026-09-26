class StockSpanner {

private:

    std::stack<std::pair<int, int>> values;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 1;
        while (!values.empty() && values.top().first <= price){
            span += values.top().second;
            values.pop();
        }

        values.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */