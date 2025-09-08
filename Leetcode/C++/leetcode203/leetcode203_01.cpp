#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  // 内部构造函数
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);  // 生成一个哑点， 这样做就可以检查head是否满足情况
    dummy->next = head;
    ListNode* cur = dummy;
    while(cur->next != nullptr){
        if(cur->next->val == val){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;  // 直接指向下下个节点，放弃符合条件的
            delete tmp;  // 释放内存
        }else{
            cur = cur->next;
        }
    }
    ListNode* newHead = dummy->next;  // 生成新的头节点
    delete dummy; // 释放内存
    return newHead;
}


int main(){

    return 0;
}
