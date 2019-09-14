//
// Created by zhang on 9/13/19.
//

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* pList = head;
        while (pList){
            while (pList->next and pList->next->val == pList->val){
                deleteNext(pList);
            }
            pList = pList->next;
        }
        return head;
    }

    bool deleteNext(ListNode* pList){
        if(pList==nullptr or pList->next==nullptr) return false;
        ListNode* temp = pList->next;
        pList->next = pList->next->next;
        delete temp;
        temp = nullptr;
        return true;
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

int main(int argc, char** argv){
    Solution solution;
    auto List  = solution.buildList({1,1,1});
    solution.displayList(List);
    solution.deleteDuplicates(List);
    solution.displayList(List);
    solution.deleteList(List);
}
