#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <unordered_map>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    int pre = 0, in = 0, flag = INT_MAX;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = buildTreeWithFlag(preorder, inorder, INT_MAX);
        return root;
    }

    TreeNode* buildTreeWithFlag(vector<int>& preorder, vector<int>& inorder, int stop)
    {
        if (pre >= preorder.size()) return nullptr;
        if (inorder[in] == stop)
        {
            in++;
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[pre++]);
        
        root->left = buildTreeWithFlag(preorder, inorder, root->val);
        root->right = buildTreeWithFlag(preorder, inorder, stop);

        return root;
    }
};
*/

/*
class Solution {
public:
    unordered_map<int, int> m_idx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            m_idx[inorder[i]] = i;
        }

        TreeNode *root = buildTreeWithFlag(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }

    TreeNode* buildTreeWithFlag(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight)
    {
        if (preLeft > preRight) return nullptr;

        TreeNode *root = new TreeNode(preorder[preLeft]);
        int inRoot = m_idx[root->val];
        int preLeftTmp = inRoot - inLeft + preLeft;
        
        root->left = buildTreeWithFlag(preorder, inorder, preLeft + 1, preLeftTmp, inLeft, inRoot-1);
        root->right = buildTreeWithFlag(preorder, inorder, preLeftTmp+1, preRight, inRoot+1, inRight);

        return root;
    }
};
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }


        stack<TreeNode*> stTree;
        int inorderIdx = 0;
        
        TreeNode *cur = new TreeNode(preorder[0]);
        stTree.push(cur);
        TreeNode *root = NULL;
        
        
        for (int i = 1; i < preorder.size(); i++)
        {
            root = stTree.top();
            if (inorder[inorderIdx] != root->val)
            {
                root->left = new TreeNode(preorder[i]);
                stTree.push(root->left);
            }
            else
            {
                while (!stTree.empty() && inorderIdx < inorder.size() && inorder[inorderIdx] == stTree.top()->val)
                {
                    root = stTree.top();
                    stTree.pop();   
                    inorderIdx++;
                }

                root->right = new TreeNode(preorder[i]);
                stTree.push(root->right);
            }
        }

        return cur;
    }
};


int main()
{
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};

    Solution().buildTree(preorder, inorder);
    
}