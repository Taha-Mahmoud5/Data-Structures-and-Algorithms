#include <iostream>
using namespace std;



#define size 100
template <typename T>

class Stack
{
private:
    T arr[size];
    int top ;
public:
    Stack() : top(-1){}

    bool isempty()
    {
        return top == -1 ;
    }
    bool isfull()
    {
        return top == size-1 ;
    }
    void push(T new_element)
    {
        if(isfull())
        {
            cout << "Stack was full ." << endl ;
        }
        else {
            ++top ;
            arr[top] = new_element ;
        }
    }

    void pop()
    {
        if(isempty())
        {
            cout << "Stack was empty . "<< endl ;
        }
        else
            --top ;
    }
    void print_to_delet()
    {
        while(!isempty())
        {
            cout << arr[top] << endl ;
            --top ;
        }
    }

    void desplay()
    {
        int carr = top ;
        while(!isempty() && carr >-1 )
        {
            cout << arr[carr] << endl ;
            --carr ;
        }
    }
};


int main()
{
    Stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.desplay();
    cout << "------------------"<< endl;
    s.pop();
    s.push(5);
    s.print_to_delet();

    return 0;
}
