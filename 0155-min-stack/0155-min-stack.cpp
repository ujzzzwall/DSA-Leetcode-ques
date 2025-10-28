class MinStack {
public:
    stack<long long>st;
    long long mn;
    // stack<int>container;
    MinStack() {
        mn = LLONG_MAX;
    }
    
    void push(int val) {
        // st.push(val);  //1. method


        //2. method

        // if(st.size()==0 && container.size()==0){   
        //     st.push(val);
        //     container.push(val);
        // }
        // else if(st.size()>0){
        //     st.push(val);
        //     if(container.top()>=val){
        //         container.push(val);
        //     }
        // }   

        // 3. method
        long long x =(long long)val;
        if(st.size()==0){
            st.push(x);
            mn = x;
        }
        else if(x>=mn)st.push(x);
        else{
            st.push(2*x-mn);
            mn=x;
        }
    }
    
    void pop() {
        // st.pop();   //1

        //2.method

        // if(st.top()==container.top()){   
        //     container.pop();
        // }
        // st.pop();
        
        // 3. method
        if(st.top()<mn){
            mn = 2*mn-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mn)return (int)mn;
        else return (int)st.top();
    }
    
    int getMin() {

        //1 method gives TLE

        // int mn =INT_MAX;
        // while(st.size()>0){
        //     container.push(st.top());
        //     if(st.top()<mn) mn = st.top();           
        //     st.pop();
        // }
        // while(container.size()>0){
        //     st.push(container.top());
        //     container.pop();
        // }
        // return mn;

         // 2. this runs on TC o(1) & SC o(n) 

        // return container.top();        

        //3.Method
        return (int)mn;  
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