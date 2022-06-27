#include <iostream>
using namespace std;

//TODO 链表定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

int main() {
    // int values[] = {0, 1, 2, 3, 4, 5};
    // int num = sizeof(values) / sizeof(values[0]);
    // cout << num << endl;
    int value = -1;
    while(cin >> value) {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *cur = new ListNode(value);
        dummyNode->next = cur;
        while(getchar() != '\n') {
            cin >> value;
            ListNode *tmp = new ListNode(value);
            cur->next = tmp;
            cur = tmp;
        }
        cur = dummyNode;
        while(cur->next) {
            cur = cur->next;
            cout << cur->val <<' ';
        }
        cout << endl; //! 换行输出
        while(cur->next) {
            cur = cur->next;
            delete cur;
        }
    }

}
