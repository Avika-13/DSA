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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;

        vector<ListNode*>store;
        while(curr){
            store.push_back(curr);
            curr= curr->next;
        }
        if(store.size()>0&& k>0)
        {

            k = k%store.size();
            reverse(store.begin(),store.end());
            reverse(store.begin(),store.begin()+k);
            reverse(store.begin()+k,store.end());
            for(int i=1;i<store.size();i++){
                store[i-1]->next= store[i];
            }
            store[store.size()-1]->next= NULL;
        }
        if(head){
            
            return store[0];
        }
        else{
            return NULL;
        }
        
    }
};