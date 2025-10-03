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
    ListNode* merge(ListNode* left, ListNode* right) {
        if(!left)   return right;
        if(!right)  return left;

        auto ans=new ListNode(-1);
        auto mtpr=ans;

        while(left && right){
            if(left->val <= right->val){
                mtpr->next=left;
                mtpr=left;
                left=left->next;
            }
            else{
                mtpr->next=right;
                mtpr=right;
                right=right->next;
            }
        }

        while(left){
            mtpr->next=left;
            mtpr=left;
            left=left->next;
        }
        while(right){
            mtpr->next=right;
            mtpr=right;
            right=right->next;
        }

        return ans->next;
    }
    ListNode*getMid(ListNode*head){
        auto slow=head;
        auto fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next==0) return head;


        auto mid=getMid(head);
        auto left=head;
        auto right=mid->next;
        mid->next=nullptr;

        left=sortList(left);
        right=sortList(right);
        auto merged=merge(left,right);


        return merged;
    }
};