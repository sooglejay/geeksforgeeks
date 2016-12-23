//
// Created by sooglejay on 16/12/23.
//

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
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        if(head==nullptr){
            return nullptr;
        }
        ListNode *re = nullptr;
        while (head!=nullptr && head->val == val) {
            head = head->next;
        }
        re = head;
        while (head!=nullptr&&head->next!=nullptr) {
            if (head->next->val == val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return re;

    }

};