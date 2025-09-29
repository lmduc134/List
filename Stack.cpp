#include <iostream>
using namespace std;

// STACK DUNG LINKED LIST//

class Node // tạo lớp node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class StackLinkedlist{// tạo stacklist
private:
    Node *head; // tạo head
    int count;

public:
    StackLinkedlist() // khởi tạo stacklist
    {
        head = nullptr;
        count = 0;
    }
    bool isEmpty() { // kiểm tra stacklist rỗng
        return head == nullptr;
    }
    void push(int value) // thêm phần tử vào đỉnh (O(1))
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }
    int pop (){ // xóa phần tử cuối khỏi stack và trả về phần tử đó (O(1))
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        Node* temp = head;
        int value = head->data;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    int top() { // trả về giá trị phần tử cuối trong stack
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return head->data;
    }
    int size() { // trả về kích thước stack
        return count;
    }
    void print() { // in stack
        Node* current = head;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

//STACK DÙNG LIST//

const int SET = 100;
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

int main(){
    StackLinkedlist stack;
    StackList stack1;
    for (int i = 1; i <= 10; i++) {
        stack.push(i);
        stack1.push(i);
    }

    cout << "StackLinkedlist top: " << stack.top() << endl; 
    cout << "StackList top: " << stack1.top() << endl; 

    cout << "StackLinkedlist size: " << stack.size() << endl; 
    cout << "StackList size: " << stack1.size() << endl; 


        cout << "StackLinkedlist pop: " << stack.pop() << endl;
        cout << "StackList pop: " << stack1.pop() << endl;

        stack.print();
        stack1.print();
    return 0;
}

