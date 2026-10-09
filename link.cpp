#include <iostream>
using namespace std;
const int MAXSIZE = 100;
struct SqList {
    int data[MAXSIZE];
    int length;
};
//初始化顺序表
void initList(SqList &L) {
    L.length = 0;
}
//追加元素
void pushBack(SqList &L,int value){
    if(L.length >=MAXSIZE){
        cout<<"顺序表已满，不能插入"<<endl;
        return;

    }
    L.data[L.length] = value;
    L.length++;
}
//在指定位置插入
void insert(SqList &L,int pos,int value){
    if(pos < 0 || pos > L.length){
        cout<<"插入位置不合法"<<endl;
        return;
    }
    if(L.length >= MAXSIZE){
        cout<<"顺序表已满，不能插入"<<endl;
        return;
    }
    for(int i = L.length; i > pos; i--){
        L.data[i] = L.data[i-1];
    }
    L.data[pos] = value;
    L.length++;
}
// 删除指定位置元素
void erase(SqList &L, int pos) {
    if (pos < 0 || pos >= L.length) {
        cout << "删除位置非法" << endl;
        return;
    }

    // 前面的元素整体前移
    for (int i = pos; i < L.length - 1; i++) {
        L.data[i] = L.data[i + 1];
    }

    L.length--;
}

// 查找元素
int find(SqList &L, int value) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == value) {
            return i;  // 返回下标
        }
    }
    return -1;  // 没找到
}

// 输出顺序表
void printList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList L;
    initList(L);

    pushBack(L, 10);
    pushBack(L, 20);
    pushBack(L, 30);

    cout << "插入前：";
    printList(L);  // 10 20 30

    insert(L, 1, 15);

    cout << "插入后：";
    printList(L);  // 10 15 20 30

    cout << "20的下标是：" << find(L, 20) << endl;  // 2

    erase(L, 2);

    cout << "删除后：";
    printList(L);  // 10 15 30

    return 0;
}