#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode l3 = ListNode(-1), *pNode = &l3;
        ListNode *pTmpNode1 = l1, *pTmpNode2 = l2; 

        if (l1 == NULL || l2 == NULL) 
        {
            return l1 != NULL ? l1 : l2;
        }

        while (pTmpNode1 && pTmpNode2)
        {
            if (pTmpNode1->val <= pTmpNode2->val)
            {
                pNode->next = pTmpNode1;
                pTmpNode1 = pTmpNode1->next;
            }
            else
            {
                pNode->next = pTmpNode2;
                pTmpNode2 = pTmpNode2->next;
            }
            pNode = pNode->next;
        }

        pNode->next = (pTmpNode1 == NULL) ? pTmpNode2 : pTmpNode1;

        return l3.next;
    }
};

int main()
{
    vector<int> ivec1 = {1, 2, 4}, ivec2 = {1, 3, 4};
    ListNode *l1 = new ListNode(-1), *l2 = new ListNode(-1);
    ListNode *prev = NULL, *pNode = NULL;
    l1->val = 1; l2->val = 2;

    ListNode *l3 = Solution().mergeTwoLists(l1, l2);
    cout << l3->val << endl;

    prev = l1; 
    delete prev;
    
    return 0;
}