class StockSpanner {
public:
    stack<int> st;
    stack<int> container;
    StockSpanner() {
        
    }
    
    int next(int p) {
        
        int span=1;
        if(st.size()==0) {
            st.push(p);
            container.push(span);
            return span;
        }
        while(st.size()>0 && p>=st.top()){
            st.pop();
            span += container.top();
            container.pop();
        }
        st.push(p);
        container.push(span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */