#include <iostream>
using namespace std;

const int SET = 100;

class List
{
public:
    int data[SET];
    int size;
    List()
    {
        size = 0;
    }

    // truy cập O(1)    
    int get(int pos) 
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Out of position" << endl;
            return -1;
        }
        return data[pos];
    }

    // chèn vào đầu O(N)
    void add_first(int value)
    {
        if (size == SET)
            return;
        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }

    // chèn vào cuối O(1)
    void add_last(int value)
    {
        if (size == SET)
            return;
        data[size] = value;
        size++;
    }

    //chèn vào vị trí i (O(N))
    void InsertPos(int value, int pos)
    {
        if (size == SET)
            return;
        for (int i = size; i >= pos; i--)
        {
            data[i] = data[i - 1];
        }
        data[pos - 1] = value;
        size++;
    }

    // xóa vị trí đầu (O(N))
    void del_first()
    {
        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    // xóa vị trí cuối (O(1))
    void del_last()
    {
        size--;
    }
    
    // xóa khỏi vị trí i (O(N))
    void del_pos(int pos)
    {
        for (int i = pos - 1; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    // duyệt xuôi (O(N))
    void rev_forward()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
    }

    //duyệt ngược (O(N))
    void rev_backward()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
    }
};
    class StackList{
private:
    int data[SET];
    int topInd;

public:
    StackList(){
        topInd = -1;
    }
    bool isEmpty(){
        return topInd == -1;
    }
    void push(int item) {
        if (topInd == SET - 1) {
            cout << "Stack full" << endl;
            return;
        }
        data[++topInd] = item;
    }
    int pop() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return -1; 
        }
        return data[topInd--];
    }
    int top() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return -1; 
        }
        return data[topInd];
    }
    int size() {
        return topInd + 1;
    }
    void print() {
        cout << "Stack elements: ";
        for (int i = topInd; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    List myList;
    myList.add_first(22);
    myList.add_last(20);
    myList.add_last(30);
    myList.add_first(6);
    myList.InsertPos(15, 2);

    cout << "phan tu o vi tri thu 1 la: " << myList.get(1) << endl;
    
    cout << "duyet xuoi: ";
    myList.rev_forward();
    cout << endl;

    cout << "duyet nguoc: ";
    myList.rev_backward();
    cout << endl;

    myList.del_first();
    cout << "phan tu sau khi xoa phan tu dau la: ";
    myList.rev_forward();
    cout << endl;
    
    myList.del_last();
    cout << "phan tu sau khi xoa phan tu cuoi la: ";
    myList.rev_forward();
    
    StackList stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.print();

    cout << "StackList top: " << stack1.top() << endl;
    cout << "StackList size: " << stack1.size() << endl;
    cout << "StackList pop: " << stack1.pop() << endl;
    stack1.print();
    
    return 0;
}