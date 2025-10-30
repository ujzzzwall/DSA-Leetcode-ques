/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * temp =head;
        vector<int>nge;
        vector<int>arr;
        stack<int>st;
        if(head==NULL || head->next==NULL){
            nge.push_back(0);
            return nge;
        }
        while(temp){
            arr.push_back(temp->val);
            temp =temp->next;
        }
        int n =arr.size();
        vector<int>ngee(n,0);
        for(int i=n-1 ; i>=0 ; i--){
            while(st.size()!=0 && st.top()<=arr[i]){
                st.pop();
            }
            if(st.size()==0)ngee[i]=0;
            else ngee[i]=st.top();
            st.push(arr[i]);
        }
        return ngee;
    }

};