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
        ListNode *l3 = l1, *pNode = l1;
        ListNode *pTmpNode1 = l1, *pTmpNode2 = l2; 

        l3 = pNode;
        if (l1 == NULL || l2 == NULL) 
        {
            return l1 != NULL ? l1 : l2;
        }

        while (pTmpNode1 &&pTmpNode2)
        {
            if (pTmpNode1->val <= pTmpNode2->val)
            {
                pNode = pTmpNode1;
                pTmpNode1 = pTmpNode1->next;
                continue;
            }
            
            pNode->next = pTmpNode2;
            pNode = pNode->next;
            pTmpNode2 = pTmpNode2->next;
            while(pTmpNode2 && pTmpNode1)
            {
                if (pTmpNode2->val <= pTmpNode1->val)
                {
                    pNode = pTmpNode2;
                    pTmpNode2 = pTmpNode2->next;
                    continue;
                }

                break;
            }

            pNode->next = pTmpNode1;
            if (pTmpNode2 == NULL)
            {
                break;
            }
            pNode = pNode->next;
            pTmpNode1 = pTmpNode1->next;
        }

        return l3;
    }
};

int main()
{
    vector<int> ivec1 = {1, 2, 4}, ivec2 = {1, 3, 4};
    ListNode *l1 = new ListNode(-1), *l2 = new ListNode(-1);
    ListNode *prev = NULL, *pNode = NULL;

    prev = l1;
    for (int i = 0; i < ivec1.size(); i++)
    {
        pNode = new ListNode(ivec1[i]);
        prev->next = pNode;
        prev = prev->next;
    }

    prev = l2;
    for (int i = 0; i < ivec2.size(); i++)
    {
        pNode = new ListNode(ivec2[i]);
        prev->next = pNode;
        prev = prev->next;
    }

    prev = l1->next;
    for (; prev != NULL; prev = prev->next)
    {
        cout << prev->val << " ";
    }
    cout << endl;

    prev = l2->next;
    for (; prev != NULL; prev = prev->next)
    {
        cout << prev->val << " ";
    }
    cout << endl;

    ListNode *l3 = Solution().mergeTwoLists(l1->next, l2->next);
    
    prev = l3;
    for (; prev != NULL; prev = prev->next)
    {
        cout << prev->val << " ";
    }
    cout << endl;

    while (l1)
    {
        pNode = l1; 
        l1 = l1->next;
        delete pNode;
    }

    while (l2)
    {
        pNode = l2; 
        l2 = l2->next;
        delete pNode;
    }

    return 0;
}