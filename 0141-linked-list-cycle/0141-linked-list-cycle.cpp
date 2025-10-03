/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // unordered_map<ListNode*,bool> map;

        // ListNode*temp=head;
        // while(temp!=NULL){
        //     if(map[temp]==true){
        //         return true;
        //     }
        //     else{
        //         map[temp]=true;
        //     }
        //     temp=temp->next;
        // }
        // return false;

        ListNode*slow=head;
        ListNode*fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
                if(slow==fast){
                    return true;
                }

            }
        }
        return false;

    }
};