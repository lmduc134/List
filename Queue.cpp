#include <iostream>
using namespace std;

const int MAX = 100;
class QueueList{
    private:
    int data[MAX];
    int frontInd, rearInd;

    public:
    QueueList(){
        frontInd = 0;
        rearInd = -1;
    }
    bool isEmpty(){
        return frontInd > rearInd;
    }
    bool isFull(){
        return rearInd == MAX - 1;
    }
    void enqueue(int item) {
    if (isFull()) {
        cout << "Queue full" << endl;
        return;
    }
    data[++rearInd] = item;
}
    int dequeue() {
    if (isEmpty()) {
        cout << "Queue empty" << endl;
        return -1; 
    }
    return data[frontInd++];
}
    int peek() {
    if (isEmpty()) {
        cout << "Queue empty" << endl;
        return -1; 
    }
    return data[frontInd];
}
    int size() {
    return rearInd - frontInd + 1;
}
    void print() {
    cout << "Queue elements: ";
    for (int i = frontInd; i <= rearInd; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
};

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

class QueueLinkedList{
    private:
    Node *front;
    Node *rear;

    public:
    QueueLinkedList(){
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rear != nullptr) {
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr) {
            front = newNode;
        }
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return -1; 
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; 
        }
        delete temp;
        return value;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return -1; 
        }
        return front->data;
    }
    void print() {
        cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    QueueList ql;
    ql.enqueue(10);
    ql.enqueue(20);
    ql.enqueue(30);
    ql.print();
    cout << "Dequeue: " << ql.dequeue() << endl;
    ql.print();
    cout << "Front element: " << ql.peek() << endl;
    cout << "Queue size: " << ql.size() << endl;

    QueueLinkedList qll;
    qll.enqueue(10);
    qll.enqueue(20);
    qll.enqueue(30);
    qll.print();
    cout << "Dequeue: " << qll.dequeue() << endl;
    qll.print();
    cout << "Front element: " << qll.peek() << endl;

    return 0;
}