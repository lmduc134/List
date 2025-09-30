#include <iostream>
using namespace std;
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
class LinkedList // tạo linkedlist
{
private:
    Node *head; // tạo head

public:
    LinkedList() // khởi tạo linkedlist
    {
        head = nullptr;
    }
    int get(int pos) // truy cập O(N)
    {
        if (pos <= 0) return -1;
        Node *temp = head;
        int index = 1;
        while (temp != nullptr && index < pos)
        {
            temp = temp->next;
            index++;
        }
        if (temp == nullptr){
              return -1;
        }
            return temp->data;
        // Nếu không tìm thấy vị trí, trả về giá trị mặc định (ví dụ -1)
      
    }
    void add_front(int value) // thêm phần tử đầu O(1)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void add_back(int value) // thêm phần tử cuối (O(N))
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void Insert(int value, int pos) // thêm vào vị trí bất kì (O(N))
    {
        Node *newNode = new Node(value);
    if (pos <= 0 || head == nullptr){
        newNode->next = head;
        head = newNode;
        return;
    }
        Node *temp = head;
        for (int i = 1; i < pos && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void del_front() // xóa phần tử đầu (O(1))
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void del_back() // xóa phần tử cuối (O(N))
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    void del_pos(int pos) // xóa phần tử ở vị trí bất kì (O(N))
    {
        if (head == nullptr)
            return;
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (temp->next == nullptr)
                return; // Vị trí không hợp lệ
            temp = temp->next;
        }
        if (temp->next == nullptr)
            return; // Vị trí không hợp lệ
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    void traverse_forward() // duyệt xuôi (O(N))
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void traverse_backward(Node *temp)//Duyệt ngược; O(N)
    {
        if (temp == nullptr) return;
        traverse_backward(temp->next);
        cout << temp->data << " ";
    }
    void print_reverse() {
        traverse_backward(head);
        cout << endl;
    }
};

class QueueLinkedList // tạo queuelist
{
private:
    LinkedList list; // sử dụng linkedlist để lưu trữ phần tử
    int count; // đếm số phần tử trong queue
public:
    QueueLinkedList() // khởi tạo queuelist
    {
        count = 0;
    }
    bool isEmpty() { // kiểm tra queue rỗng
        return list.get(1) == -1;
    }
    void enqueue(int value) // thêm phần tử vào cuối queue (O(1))
    {
        list.add_back(value);
        count++;
    }
    int dequeue() { // xóa phần tử đầu khỏi queue và trả về phần tử đó (O(1))
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; 
        }
        int value = list.get(1);
        list.del_front();
        count--;
        return value;
    }
    int peek() { // trả về giá trị phần tử đầu trong queue
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; 
        }
        return list.get(1);
    }
    int size() { // trả về kích thước queue
        return count;
    }
    void print() { // in queue
        cout << "Queue elements: ";
        list.traverse_forward();
    }
};
int main()
{
    LinkedList List;
    List.add_front(10);
    List.add_front(5);
    List.add_back(20);
    List.add_back(30);
    List.Insert(15, 1);
    cout << "duyet xuoi: ";
    List.traverse_forward();
    cout << "duyet nguoc: ";
    List.print_reverse();
    List.del_front();
    cout << "phan tu sau khi xoa phan tu dau la: ";
    List.traverse_forward();
    List.del_back();
    cout << "phan tu sau khi xoa phan tu cuoi la: ";
    List.traverse_forward();

     
    cout << "phan tu o vi tri thu 1 la: " << List.get(1) << endl;
    

    QueueLinkedList queue;
    queue.enqueue(10);
    queue.enqueue(20); 
    queue.enqueue(30);
    queue.print();
    cout << "Queue peek: " << queue.peek() << endl;
    cout << "Queue size: " << queue.size() << endl;
    cout << "Queue dequeue: " << queue.dequeue() << endl;
    queue.print();
    return 0;
}
