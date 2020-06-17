#include <iostream>
using namespace std;

template <typename T>
class queue
{
private:
    T* Queue;
    T QSize;
    T head, tail;
public:
    void InitQueue(T size)
    {
        QSize = size;
        Queue = new T[QSize];
        head = tail = 0;
    }
    void FreeQueue()
    {
        free(Queue);
    }
    bool Insert(T data)
    {
        if ((tail + 1) % QSize == head)
        {
            return false;
        }
        Queue[tail] = data;
        tail = (tail + 1) % QSize;
        return true;
    }
    T dequeue()
    {
        T data;
        if (head == tail)
        {
            return -1;
        }
        data = Queue[head];
        head = (head + 1) % QSize;
        return data;
    }
};
int main()
{
    int x, y;
    queue<int> q;
    cout << "큐 크기를 입력하시오 : ";
    cin >> x;
    q.InitQueue(x + 1);

    for (int i = 0; i < x; i++) {
        cout << "Queue 삽입 데이터 : ";
        cin >> y;
        q.Insert(y);
    }

    for (int i = 0; i < x; i++) {
        cout << "q.dequeue() : " << q.dequeue() << endl;
    }
    q.FreeQueue();
}