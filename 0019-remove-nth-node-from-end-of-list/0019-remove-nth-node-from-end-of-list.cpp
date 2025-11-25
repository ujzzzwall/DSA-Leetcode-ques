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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp =head;
        // if(head== NULL || head->next==NULL)return NULL;
        // int l =0;
        // while(temp!=NULL){
        //     l++;
        //     temp =temp->next;
        // }
        // if(n==l){
        //     head=head->next;
        //     return head;
        // }
        // int idx=(l-n);
        // ListNode * wantpre=head;
        // for(int i=1;i<idx;i++){
        //     wantpre=wantpre->next;
        // }
        // wantpre->next=wantpre->next->next;
        // return head;

        
        ListNode* slow =head;
        ListNode* fast =head;
        for(int i = 0;i<n+1;i++){
            if(fast==NULL)return head->next;
            fast=fast->next;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};