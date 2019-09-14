//
// Created by zhang on 9/3/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        typedef ListNode* pL;
        pL p1 = l1;
        pL p2 = l2;
        pL pHead = nullptr;
        pL p = pHead;

        while (p1 or p2) {
            int val1 = p1 ? p1->val : INT32_MAX;
            int val2 = p2 ? p2->val : INT32_MAX;
            bool p1_less_p2 = val1 < val2;
            int less_val = p1_less_p2 ? val1 : val2;
            if (p) {
                p->next = new ListNode(less_val);
                p = p->next;
            } else {
                pHead = new ListNode(less_val);
                p = pHead;
            }
            p1_less_p2 ? p1 = p1->next : p2 = p2->next;
        }
        return pHead;
    }


    ListNode* buildList(const std::vector<int>& v) {
        if (!v.size()) return nullptr;
        ListNode* pFirst = nullptr;
        ListNode* pCur = nullptr;
        for (auto& i: v) {
            if (pCur) {
                pCur->next = new ListNode(i);
                pCur = pCur->next;
            } else {
                pFirst = new ListNode(i);
                pCur = pFirst;
            }
        }
        return pFirst;
    }

    void deleteList(ListNode* l) {
        if (l == nullptr) return;
        ListNode* p = l;
        while (p != nullptr) {
            ListNode* temp = p->next;
            delete p;
            p = temp;
        }
    }

    void displayList(ListNode* l) {
        ListNode* p = l;
        while (p) {
            std::cout << p->val;
            if (p->next) {
                std::cout << "-->";
            } else {
                std::cout << std::endl;
            }
            p = p->next;
        }
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> v1 = {};
    std::vector<int> v2 = {1, 3, 4, -1, 3, 9, 0};
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    ListNode* l1 = sol.buildList(v1);
    ListNode* l2 = sol.buildList(v2);
    sol.displayList(l1);
    sol.displayList(l2);
    ListNode* l = sol.mergeTwoLists(l1, l2);
    sol.displayList(l);

    sol.deleteList(l1);
    sol.deleteList(l2);
    sol.deleteList(l);
}