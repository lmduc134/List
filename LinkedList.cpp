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
    int get(int pos) // truy cập
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
    void add_front(int value) // thêm phần tử đầu
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void add_back(int value) // thêm phần tử cuối
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
    void Insert(int value, int pos) // thêm vào vị trí bất kì
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
    void del_front() // xóa phần tử đầu
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void del_back() // xóa phần tử cuối
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
    void del_pos(int pos) // xóa phần tử ở vị trí bất kì
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
    void traverse_forward() // duyệt xuôi
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void traverse_backward(Node *temp)//Duyệt ngược;
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
    return 0;
}

