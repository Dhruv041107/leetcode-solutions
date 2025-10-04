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
    int getLength(ListNode*head){
        ListNode*temp=head;
        int len=0;
        while(temp){
            len++;temp=temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return 0;
        int len=getLength(head);

        int actualrotate=(k%len);
        if(actualrotate==0) return head;
        int newLastPos= len-actualrotate-1;
        ListNode*newLastNode=head;

        for(int i=0;i<newLastPos;i++){
            newLastNode=newLastNode->next;
        }
        ListNode*newHead=newLastNode->next;
        newLastNode->next=0;

        ListNode*temp=newHead;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;

        return newHead;

    }
};