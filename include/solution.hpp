/* solution.h */
// 二叉树结构体
#include <iostream>
#include <vector>
#include <queue>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
using namespace std;
class Solution {
public:
    Solution();
    ~Solution();

		// 树的最小深度  
		// 层序遍历 利用 queue size 先将某一层轮询
		int run(TreeNode *root){
			if(root==nullptr) return 0;
			if(root->left==nullptr && root->right==nullptr) return 1;
			queue<TreeNode*> array;
			array.push(root);
			int level=0;
			while (!array.empty())
			{
				int len = array.size();
				for(int i=0;i<len;i++){	
					TreeNode* node = array.front();
					array.pop();

					if(root->left==nullptr && root->right==nullptr){
						return level;
					}
					if(node->left!=nullptr)  array.push(node->left);
					else if(node->right!=nullptr)  array.push(node->right);
					
				}
				level ++;
			}
			
			return level;
		}
	// 异或 满足 交换率&结合率  
	// 巧妙应用之 两数交换 不需要另外的空间
	int singleNumber(int A[], int n) {
        for(int i=1;i<n;i++)
			A[i] = A[i] ^ A[i-1];
		return A[n-1];
    }
	vector<vector<int>> zigzagLevelOrder(TreeNode *root){
		

	}
	vector<vector<int>> levelOrder(TreeNode *root){
		
	}
	bool isSymmetric(TreeNode *root) {
		
	}
	bool isSameTree(TreeNode *p, TreeNode *q) {
		
	}
	void recoverTree(TreeNode *root) {
		
	}


    
};