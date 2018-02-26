//求所有左叶子的节点值的和
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;//递归终止条件
        if(root->left!=NULL && root->left->left == NULL && root->left->right == NULL)//找到左叶子
        {
            return root->left->val + sumOfLeftLeaves(root->right);
        }

        //没找到左叶子
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    }
};   递归 accepted*/

//非递归 BFS队列实现
typedef struct TreeNode node;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue <node *> que;
        int sum = 0;
        if(root == NULL) return 0;
        while(que.empty() == false)
        {
            que.pop();
        }
        que.push(root);
        while(que.empty() == false)
        {
            node * current = que.front();
            que.pop();
            if(current -> left != NULL)
            {
                if(current -> left -> left == NULL && current -> left -> right == NULL)
                {
                    sum += current -> left ->val;
                }
                else
                {
                    que.push(current -> left);
                }
            }
            if(current -> right != NULL)
            {
                que.push(current -> right);
            }
        }
     return sum;
    }
};
