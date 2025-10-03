/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNo : val(0), next(nullptr) {}de()
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddle(ListNode*&head,ListNode*& middleprev){
        ListNode* slow=head; 
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                middleprev=slow;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode*& curr,ListNode* prev){
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)  return true;
        if(head->next==NULL)    return true;
        ListNode*firsthead=head;
        ListNode*middleprev=NULL;
        ListNode*middle=getMiddle(head,middleprev);
        middleprev->next=NULL;
    

        ListNode*curr=middle;
        ListNode*prev=NULL;
        ListNode*secondhead=reverse(curr,prev);

        ListNode* temphead1=firsthead;
        ListNode* temphead2=secondhead;

        while(temphead1!=NULL){
            if(temphead1 ->val != temphead2 ->val){
                return false;
            }else
            {
                temphead1=temphead1->next;
                temphead2=temphead2->next;
             }
        }
        return true;
    }
};