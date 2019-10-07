/* solution.h */
// 二叉树结构体
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <algorithm>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
using namespace std;
class Solution {
public:
    Solution();
    ~Solution();
		public:
				void push(int node) {
						while (!stack1.empty())
						{
							stack2.push(stack1.top());
							stack1.pop();
						}
						stack1.push(node);
						while (!stack2.empty())
						{
							stack1.push(stack2.top());
							stack2.pop();
						}
				}

				int pop() {
					  int res = stack1.top();
						stack1.pop();
						return res;
				}


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
	// 计算逆波兰式
	  int str2int(string str){
				return atoi(str.c_str()); 
		}
	  int evalRPN(vector<string> &tokens) {
        stack<int>tmp;
				if(tokens.size()<3) return str2int(tokens[0]);
				for(int k=0;k<tokens.size();k++){
					if(tokens[k]!="+"&&tokens[k]!="-"&&tokens[k]!="*"&&tokens[k]!="/"){
						tmp.push(str2int(tokens[k]));
					}
					else if(tokens[k]=="+"){
						int a = tmp.top();
						tmp.pop();
						int b = tmp.top();
						tmp.pop();
						tmp.push(b+a);
					}
					else if(tokens[k]=="-"){
						int a = tmp.top();
						tmp.pop();
						int b = tmp.top();
						tmp.pop();
						tmp.push(b-a);
					}
					else if(tokens[k]=="*"){
						int a = tmp.top();
						tmp.pop();
						int b = tmp.top();
						tmp.pop();
						tmp.push(b*a);
					}
					else if(tokens[k]=="/"){
						int a = tmp.top();
						tmp.pop();
						int b = tmp.top();
						tmp.pop();
						tmp.push(int(b/a));
					}
				}
				return tmp.top();
    }
		//在O(nlogn)的时间内使用常数级空间复杂度对链表进行排序
		ListNode *sortList(ListNode *head) {
        
    }
		// 迭代　求给定的二叉树的后序遍历
		void postorder(TreeNode* root,vector<int>& res){
					if(root==nullptr) return;

					postorder(root->left,res);
					postorder(root->right,res);
					res.push_back(root->val);
		}
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int>res ;
				if(root==nullptr) return res;
				// postorder(root,res);
				// return res;
				stack<TreeNode*> stack_tree;
				TreeNode* pre=root;
				TreeNode* cur;
				stack_tree.push(root);
				while (!stack_tree.empty())
				{
					cur = stack_tree.top();
					if(cur->left&& pre!=cur->left && pre!=cur->right){  // 存在左节点　且　左右节点都没有访问
						stack_tree.push(cur->left);
					}
					else if(cur->right&& pre!=cur->right){              //1不成立　且存在未访问的右节点
						stack_tree.push(cur->right);
					}
					else{																								// 左右节点已经访问　输出该节点　记录　pre指针
						res.push_back(cur->val);
						stack_tree.pop();
						pre=cur;
					}
				}
				return res;

    }
		// 对于给定的n个位于同一二维平面上的点，求最多能有多少个点位于同一直线上
    int maxPoints(vector<Point> &points) {
        
    }
		// 求给定的二叉树的前序遍历
		vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
				if(root==nullptr) return res;
				stack<TreeNode*> stack_tree;

				TreeNode* cur=root;
				while (1)
				{
						while (cur!=nullptr)
						{
								stack_tree.push(cur);
								res.push_back(cur->val);
								cur = cur->left ;
						}
						if(stack_tree.empty()) return res;					
						cur = stack_tree.top();
						stack_tree.pop();
						cur = cur->right;    // 一直往左查询　跳出循环代表左到底　开始以上一节点的右子树　查找
				}
				return res;
    }
		int maxDepth(TreeNode *root) {
		// 递归写法 左右子数的最大高度　＋　１（本身占一层）

    // if(root==nullptr) return 0;
		// return max(maxDepth(root->left)+1,maxDepth(root->right)+1);   

		// 层序遍历　最高能到哪一层
		if(root==nullptr) return 0;
		queue<TreeNode*> queue_tree;
		queue_tree.push(root);
		int level=0;
		TreeNode* curr;
		while (!queue_tree.empty())
		{
			 uint16_t size = queue_tree.size();
			 for(uint16_t i=0;i<size;i++){
				 curr = queue_tree.front();
				 if(curr->left) queue_tree.push(curr->left);
				 if(curr->right) queue_tree.push(curr->right);
				 queue_tree.pop();
			 }
			 level++;
		}
		return level;
    }

		// 动态规划　股票最大收益 任意次买卖　最多持有一股
		int maxProfit(vector<int> &prices) {
				uint16_t n = prices.size();
				if(n<=1) return 0;
        vector<vector<int>> dp(n,vector<int>(2));
				dp[0][0]=0;
				dp[0][1]=0-prices[0];
				
				for(uint16_t i=1;i<n;i++){
					dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
					dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
				}
				return max(dp[n-1][0],dp[n-1][1]);
		}
		// 最多只进行一次交易　　买一次和卖一次
		int maxProfit2(vector<int> &prices) {
				int min_ = prices[0];
				int max_=0;
        for(int i=1;i<prices.size();i++){
						min_ = min(min_,prices[i]);
						max_ = max(max_,prices[i]-min_);
					}
				return max_;
    }
		// 数字反转
		int reverse(int x) {
        string tmp,res;
				tmp = to_string(x);
				for(uint16_t i=tmp.size()-1;i>=1;i--)
					res.push_back(tmp[i]);
				if(tmp[0]=='+'){
					return atoi(res.c_str());
				}
				else if(tmp[0]=='-'){
					return (0-atoi(res.c_str()));
				}
				else{
					res.push_back(tmp[0]);
					return atoi(res.c_str());
				}
				return 0;
    }
		// 判断链表是否有环 快慢指针　快指针没到　nullptr 就可以一直循环　
		bool hasCycle(ListNode *head) {
			if(head==nullptr) return false;
        ListNode *fast=head,*low=head;
				while (fast!=nullptr&&fast->next!=nullptr)
				{
					fast = fast->next->next;
					low = low->next;
					if(low==fast) return true;
				}
				return false;
    }
	//　跳格子　最少几步跳到终点（最后的下标）
		int solution(int a[], int N)
		{
				if(N<=0) return -1;
				int reach=0,last=0,cnt=0;
				for(int i=0;i<N;i++){
					if(i>reach) return -1;
					if(i>last){
						cnt++;
						last = reach;
					}
					if(i+a[i]>reach) reach = i+ a[i];
				}
				return cnt;
		}
		// 将序列分成两份　权值和差值最小
		int solution(int n, int weight[]) {
			int sum=0;
			for(int i=0;i<n;i++) sum+=weight[i];
			vector<vector<int>> dp;
			for(int i=0;i<=n;i++){
				vector<int>tmp;
				for(int j=0;j<=sum/2;++j) tmp.push_back(0);
				dp.push_back(tmp);
			}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=sum/2;++j){
					if(j>=weight[i-1]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+weight[i-1]);
						else dp[i][j]=dp[i-1][j];
				}
			}
			return sum-2*dp[n][sum/2];
		}
		// 判断一个数字是不是回文
	  bool isPalindrome(int x) {
        if(x<0) return false;
				if(x==0) return true;
				
				//求最高位数
				int hi=1;
				while (x/hi>=10)	hi*=10;
				while (x!=0){
					if(x/hi  != x%10) return false;
					x = (x%hi)/10;
					hi = hi/100;
				}
				return true;
    }
		// 判断两颗二叉树　是否相等
		bool isSameTree(TreeNode *p, TreeNode *q) {
				// 递归　方法
				/* if(p==nullptr&&q==nullptr) return true;
				if((p==nullptr||q==nullptr)||(p->val!=q->val)) return false;
				return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)); */

				//　层序遍历　写法
				//  将空的子数写进队列　对空的ｆｒｏｎｔ　节点只进行比较　不读取左右节点（还是空）
    }
		// 方格两顶点间　路径总数
		int uniquePaths(int m, int n) {
			 if(m<=1||n<=1) return 1;
       vector<vector<int>> dp(m,vector<int>(n,1));

			 for(int i=m-2;i>=0;i--)
			 	for(int j=n-2;j>=0;j--){
					 	dp[i][j]=dp[i+1][j]+dp[i][j+1];
				 } 
				return dp[0][0];
    }
		// 有序数组查找　找到返回下表没找到返回插入位置
		int searchInsert(int A[], int n, int target) {
      int left=0,right=n-1;
			while (left<=right)
			{
					int mid=(left+right)/2;
					if(A[mid]==target) return mid;
					else if(A[mid]>target) right=mid-1;
					else left=mid+1;
			}
			return left;
    }
		// 数组中只有一个元素只出现一次，其余元素都出现三次 
		// 线性复杂度　不使用额外空间
		int singleNumber2(int A[], int n) {
        
    }
		// 选择那个加油站出发　可以在环形路上走一圈　
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
    }
		// 对于一个给定的链表，返回环的入口节点，如果没有环，返回null
		
		ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return nullptr;
				ListNode *fast = head,*low=head,*ori=head;
				int fast_step=0;
				int low_step=0;
				while (fast!=nullptr&&fast->next!=nullptr)
				{
					fast = fast->next->next;
					fast_step+=2;
					low = low->next;
					low_step+=1;
					if(fast==low){   
						while(ori != fast){
						ori = ori->next;
						fast = fast->next;
						}
					}
				}
				return nullptr;
    }

		// 使用插入排序对链表进行排序
		ListNode *insertionSortList(ListNode *head) {

			/* if(head==nullptr) return nullptr;
			ListNode* ori=head;
			ListNode* last=head;
			ListNode* cur = head;
			while (cur!=nullptr)
			{
					ListNode * tmp_cur = cur->next;
					ListNode * phead = head;
					ListNode * pre = head;
					while (phead!=cur)
					{
						if(phead->val>cur->val){
							last->next = cur->next;
							cur->next = phead ;
							if(phead==ori){
								head = cur;
								ori = head;
							}
							else	pre->next = cur ;
							break;
						}
						pre = phead ;
						phead = phead->next ;
					}
					last = phead;
					cur = tmp_cur;
			}
			return ori; */




		}
		// 合并两个排序链表
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
				if(l1==nullptr) return l2;
				if(l2==nullptr) return l1;
				ListNode *res=new ListNode(0);
				ListNode *ori = res;
        while (l1!=nullptr && l2!=nullptr)
				{
						if(l1->val<l2->val){
							res->next = l1;
							l1 = l1->next ;
						}
						else{
							res->next = l2;
							l2 = l2->next ;
						}
						res = res->next ;
				}
				if(l1==nullptr) res->next = l2;
				else if(l2==nullptr) res->next = l1;
				return ori->next;
    }

		//	合并ｋ个排序链表  两两合并
		ListNode *mergeKLists(vector<ListNode *> &lists) {
			    if(lists.size()<=0) return nullptr;
        	ListNode *res=lists[0];
					for(int i=1;i<lists.size();i++){
					 res=mergeTwoLists(res,lists[i]);
					}
					return res;
    }

		// 快速排序　
		int get_index(int a[],int low,int high){
					int tmp=a[low];
					while (low<high)
					{
						while (low<high && a[high]>=tmp)
						{
							high--;
						}
						a[low]=a[high];
						while (low<high && a[low]<=tmp)
						{
							low++;
						}
						a[high]=a[low];
					}
					
					a[low]=tmp;
					return low;
		}
		void quick_sort(int a[],int low, int high){
				if(low<high){
					int mid = get_index(a,low,high);

					quick_sort(a,0,mid-1);
					quick_sort(a,mid+1,high);
				}
		}



		private:
    stack<int> stack1;
    stack<int> stack2;
};