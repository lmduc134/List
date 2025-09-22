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
    
    return 0;
}