
#include "../include/solution.hpp"      // 剑指offer 保存
# include "../include/interview.hpp"    // 真题练习 

int main (int argc, char *argv[]) {
    Solution sln;

/*     TreeNode root(1);
    TreeNode node(2);
    root.right=&node;
    cout << sln.run(&root) << endl; */
    
    
/*     int *a = new int(5);
    a[0]=a[1]=2;
    a[2]=a[3]=3;
    a[4]=7;
    cout << sln.singleNumber(a,5) << endl; */

    vector<string> test = {"wuxu","xianli","qianqian","yumiao"};
    cout << sln.evalRPN(test);
    return 0;
}