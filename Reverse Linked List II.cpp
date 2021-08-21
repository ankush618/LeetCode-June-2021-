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
    ListNode* reverseBetween(ListNode* head, int start, int end) {if(!head || start == end) return head;
        
        ListNode dummyHead(INT_MIN);
        dummyHead.next = head;
        
        auto* nodeBeforeReversedSublist = &dummyHead;
        int pos = 1;
        while(pos < start) {
            nodeBeforeReversedSublist = nodeBeforeReversedSublist->next;
            pos++;
        }
        
        auto* sublistWorkingPtr = nodeBeforeReversedSublist->next;
        while(start < end) {
            // cut the new node out
            auto* nodeComingToSublistFront = sublistWorkingPtr->next;
            sublistWorkingPtr->next = nodeComingToSublistFront->next;
            
            // pasting it at the front
            nodeComingToSublistFront->next = nodeBeforeReversedSublist->next;
            nodeBeforeReversedSublist->next = nodeComingToSublistFront;
            start++;
        }
        return dummyHead.next;
        
    }
};
