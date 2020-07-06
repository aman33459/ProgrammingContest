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
    void deleteNode(ListNode* node) {
        while(node->next!=NULL){
            //cout << node->val << " " << node->next->val <<  "\n";
            node->val = node->next->val;
            auto tmp = node->next ;
            //node->next = node->next->next;
            if(node->next->next == NULL) node->next = NULL;
            node  = tmp;
        }
       // delete(node);
    }
};
