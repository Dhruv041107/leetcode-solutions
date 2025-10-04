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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // for(int i=0;i<nums.size();i++){
        //     int key=nums[i];
        //     ListNode*temp=head;
        //     ListNode*prev=NULL;
        //     while(temp!=NULL){
        //         if(temp->val==key){
        //             if(temp==head){
        //                 head=temp->next;
        //             }
        //             if(prev)    prev->next=temp->next;
        //             temp=temp->next;

        //         }
        //         else{
        //             prev=temp;
        //             temp=temp->next;
        //         }
        //     }
        // }
        // return head;

        unordered_set<int>s(nums.begin(),nums.end());

        ListNode dummy(0,head);
        ListNode*prev=&dummy;
        ListNode*temp=head;

        while(temp!=NULL){
            if(s.count(temp->val)){
                if(prev)    prev->next=temp->next;
            }
            else{
                prev=temp;
            }
            temp=temp->next;
        }
        return dummy.next;
    }
};