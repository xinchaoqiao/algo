_Pragma("once")
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
//结构
//----------------------------------------------------
//树
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace Utils {
    //---------------------------------------------------
    //链表


    //生成测试链表
    ListNode* generateList() {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(1);
        return head;
    }
    //打印链表
    void printList(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            cout << cur->val;
            cur = cur->next;
        }
        cout << endl;
    }






    // ---------------------------------------------------
    //数组
    template <class T>
    void printArray(T arr[]) {
        int length = (int)(sizeof(arr) / sizeof(arr[0]));
        for (size_t i = 0;i < length;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    //打印字符串 
    void printString(string& s) {
        for (auto ch : s) {
            cout << ch;
        }
        cout << endl;
    }
    /*容器
    比较函数 sort可以使用
    less  从小到大
    more 从大到小 */

    bool less(double num1, double num2) {
        return num1 < num2;
    }
    bool more(double num1, double num2) {
        return num2 < num1;
    }

    //vector
    //打印vector容器
    template <class T>
    void printVector(vector<T> v) {
        for (auto it = v.begin(); it != v.end();it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}
