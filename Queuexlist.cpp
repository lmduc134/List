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

    return 0;
}