//
// Created by zhang on 9/8/19.
//


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        size_t k = lists.size();
        std::vector<ListNode*> pList(lists);
        auto ispListValid = [&](){
            for(const auto& i: pList){
                if(i != nullptr) return true;
            }
            return false;
        };
        auto getMinIndex = [&](){
            int index = 0;
            int min = INT32_MAX;
            for(int i=0; i<k; i++){
                if(pList[i]== nullptr) continue;
                if(pList[i]->val < min){
                    min = pList[i]->val;
                    index = i;
                }
            }
            return index;
        };
        ListNode* pSentinel = new ListNode(-1);
        ListNode* pListNode = pSentinel;
        while (ispListValid()){
            int index = getMinIndex();
            pListNode->next = new ListNode(pList[index]->val);
            pListNode = pListNode->next;
            pList[index] = pList[index]->next;
        }
        ListNode* p = pSentinel->next;
        delete pSentinel; pSentinel = nullptr;
        return p;
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
    Solution sol;
    std::vector<int> v0 = {1,4,5};
    std::vector<int> v1 = {1,3,4};
    std::vector<int> v2 = {2,6};

    ListNode* l0 = sol.buildList(v0);
    ListNode* l1 = sol.buildList(v1);
    ListNode* l2 = sol.buildList(v2);

    std::vector<ListNode*> lists = {l0,l1,l2};
    ListNode* lMerged = sol.mergeKLists(lists);

    sol.displayList(l0);
    sol.displayList(l1);
    sol.displayList(l2);
    sol.displayList(lMerged);

    sol.deleteList(l0);
    sol.deleteList(l1);
    sol.deleteList(l2);
    sol.deleteList(lMerged);

}