#include <iostream>
using namespace std;

template <typename T>
class SqList {
private:
    T* data;
    int length;
    int capacity;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    SqList(int initCapacity = 10) {
        data = new T[initCapacity];
        length = 0;
        capacity = initCapacity;
    }

    ~SqList() {
        delete[] data;
    }

    void pushBack(const T& value) {
        if (length >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[length++] = value;
    }

    void insert(int pos, const T& value) {
        if (pos < 0 || pos > length) {
            throw out_of_range("插入位置非法");
        }
        if (length >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (int i = length; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        length++;
    }

    void erase(int pos) {
        if (pos < 0 || pos >= length) {
            throw out_of_range("删除位置非法");
        }
        for (int i = pos; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    int find(const T& value) {
        for (int i = 0; i < length; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SqList<int> L;

    L.pushBack(10);
    L.pushBack(20);
    L.pushBack(30);

    L.insert(1, 15);
    L.print();  // 10 15 20 30

    cout << "20的位置：" << L.find(20) << endl;  // 2

    L.erase(2);
    L.print();  // 10 15 30

    return 0;
}