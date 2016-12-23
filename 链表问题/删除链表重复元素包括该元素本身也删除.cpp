//
// Created by sooglejay on 16/12/23.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here


        //第一次while循环 ，找出第一个 不重复的 节点，作为整个链表的头
        while (head != nullptr && head->next != nullptr) {
            int ta = head->val;
            ListNode *tem = head->next;
            int i = 1;
            while (tem != nullptr && tem->val == ta) {
                tem = tem->next;
                i++;
            }
            if (i > 1)
                head = tem;
            else {
                break;
            }
            if (head != nullptr && head->next != nullptr) {
                if (head->val == head->next->val) {
                    continue;
                } else {
                    break;
                }
            }
        }
        //作为头部的next元素
        ListNode *temNodeToRes = nullptr;
        ListNode *res = head;
        //赋值 头部的next 元素
        if (head != nullptr && head->next != nullptr) {
            temNodeToRes = head->next;
        }
        while (temNodeToRes != nullptr && temNodeToRes->next != nullptr) {
            int ta = temNodeToRes->val;
            ListNode *tem = temNodeToRes->next;
            int i = 1;
            while (tem != nullptr && tem->val == ta) {
                tem = tem->next;
                i++;
            }
            if (i == 1) {
                //说明这个是符合要求的节点，添加到链表中去
                head->next = temNodeToRes;
                head = head->next;
            }
            temNodeToRes = tem;
        }
        //最后一次也要更新一下链表，因为需要处理重复元素结尾的情况
        if (head != nullptr)
            head->next = temNodeToRes;
        return res;
    }
};

int main() {
    Solution ss = Solution();
    ListNode nod1 = ListNode(14);
    ListNode nod2 = ListNode(13);
    ListNode nod3 = ListNode(12);
    ListNode nod4 = ListNode(12);
    ListNode nod5 = ListNode(11);
    ListNode nod6 = ListNode(11);
    ListNode nod7 = ListNode(11);
    ListNode nod8 = ListNode(11);
    ListNode nod9 = ListNode(11);
    ListNode nod10 = ListNode(10);
    ListNode nod11 = ListNode(10);
    nod1.next = &nod2;
    nod2.next = &nod3;
    nod3.next = &nod4;
    nod4.next = &nod5;
    nod5.next = &nod6;
    nod6.next = &nod7;
    nod7.next = &nod8;
    nod8.next = &nod9;
    nod9.next = &nod10;
    nod10.next = &nod11;

    ListNode *h = ss.removeElements(&nod1, 3);

    while (h) {
        cout << h->val << ' ';
        h = h->next;
    }


}