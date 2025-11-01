
class MyCircularDeque {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode (int x): val(x) , next(nullptr) , prev (nullptr){}   
    };
public:
    int s;
    int c;
    ListNode * head;
    ListNode * tail;
    MyCircularDeque(int k) {
        s=0;
        c=k;
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next=tail;
        tail->prev = head;
    }
    
    bool insertFront(int val) {
        if(s==c)return false;
        ListNode *nextnode = new ListNode(val);
        nextnode->next = head->next;
        head->next->prev = nextnode;
        head->next = nextnode;
        nextnode->prev =head;

        s++;
        return true;
    }
    
    bool insertLast(int val) {
        if(s==c)return false;
        ListNode *nextnode = new ListNode(val);
        nextnode->next = tail;
        tail->prev->next = nextnode;
        nextnode->prev =tail->prev;
        tail->prev = nextnode;
        s++;
        return true;
    }
    
    bool deleteFront() {
        if(s==0)return false;
        head->next=head->next->next;
        head->next->prev =head;
        s--;
        return true;
    }
    
    bool deleteLast() {
        if(s==0)return false;
        tail->prev=tail->prev->prev;
        tail->prev->next =tail;
        s--;
        return true;
    }
    
    int getFront() {
        if(s==0)return -1;
        return head->next->val;
    }
    
    int getRear() {
        if(s==0)return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        if(s==0)return true;
        return false;
    }
    
    bool isFull() {
        if(s==c)return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */