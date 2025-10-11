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
class compare{
    public: 
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        // ListNode* head=NULL;
        // ListNode* tail=NULL;


        // int totalRows=lists.size();

        // for(int i=0;i<totalRows;i++){
        //     ListNode* temp=lists[i];
        //     if(temp){
        //         pq.push(temp);
        //     }
        // }

        // while(!pq.empty()){
        //     ListNode* front=pq.top();pq.pop();

        //     if(head==NULL && tail== NULL){
        //         head=front;
        //         tail=front;
        //     }
        //     else{
        //         tail->next=front;
        //         tail=front;
        //     }
        //     if(tail->next)  pq.push(tail->next);
        // }

        // return head;

        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        
        ListNode* ans=new ListNode(-1);

        for(auto head:lists){
            if(head)    pq.push(head);
        }

        auto it=ans;

        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();

            it->next=front;
            if(front->next) pq.push(front->next);
            it=it->next;
        }
        ListNode* finalans=ans->next;
        delete ans;
        return finalans;
    }
};