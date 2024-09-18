#include <iostream>

using namespace std;

/*
    - explain queue
    fifo -> first in first out
    lilo -> last in last out
       ___________________
  ->  |    0    1    2    | ->
      |___________________|



*/
template<typename T>
#define size 100
class Queue
{
private:
    T arr[size] ;
    int front , rear ;
public:
    Queue() : front(-1) , rear(0) {}
    bool isfull()
    {
        return rear == size-1 ;
    }
    bool isempty()
    {
        return front == rear ;
    }
    void add(T new_element)
    {
        if(isfull())
        {
            cout << "Queue is full ." << endl ;
        }
        else
        {
            if(front == -1)
            {
                front++ ;
            }
            arr[rear] = new_element ;
            ++rear ;
        }
    }
    void del()
    {
        if(isempty())
        {
            cout << "Queue is empty . " << endl ;
        }
        else
        {
            front++  ;
        }
    }
    void display()
    {
        int carr = front ;
        if(isempty())
        {
            cout << "Queue is empty ."<< endl ;
        }
        while(!isempty() && carr != rear)
        {
            cout << arr[carr] << "  ";
            carr++ ;
        }
        cout << endl ;
    }
};

int main()
{
    Queue<int> q ;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.display();
    q.del();
    q.display();
    q.del();
    q.del();
    q.del();
    q.del();
    q.display();
    return 0;
}
