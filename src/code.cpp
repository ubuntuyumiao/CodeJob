
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
/*     ListNode head(9),node1(5),node2(3),node3(7),node4(0);
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
   ListNode * head1 = sln.insertionSortList(&head);
   while (head1!=nullptr)
   {
       cout << head1->val <<" ";
       head1 = head1->next ;
   } */
   
    int a[10]={2,5,7,1,8,2,5,10,4,6};
    sln.quick_sort(a,0,9);
    for(int i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}