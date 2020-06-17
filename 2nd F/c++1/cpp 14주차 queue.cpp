#include <iostream>
using namespace std;
#define SIZE 7

template<typename T>
class Queue
{
private:
    T* queue;
    T Size;
    T head, tail;

public:
    Queue() {}
    void InitQueue(T size)
    {
        Size = size;
        queue = new T[Size];
        head = tail = 0;
    }

    bool Enqueue(T data)
    {
        if ((tail + 1) % Size == head)
        {
            return false;
        }
        queue[tail] = data;
        tail = (tail + 1) % Size;
        return true;
    }

    T Dequeue()
    {
        T data;
        if (head == tail)
        {
            return -1;
        }
        data = queue[head];
        head = (head + 1) % Size;
        return data;
    }
};

int main()
{
    Queue<int> qu;
    int i;
    int num;
    qu.InitQueue(SIZE);
    
    cout << "Queue »ðÀÔ µ¥ÀÌÅÍ : ";
    for (i = 1; i < SIZE; i++) {
        cin >> num;
        qu.Enqueue(num);
    }

    for (i = 1; i < SIZE; i++){
        cout << "q.dequeue<> : " << qu.Dequeue() << endl;
    }

    return 0;
}