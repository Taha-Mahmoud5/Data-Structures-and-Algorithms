#include <iostream>

using namespace std;
/*

    -Data Structure
        -primitive
            - int , char , float
        -non primitive
            -list
                -linear
                    -stack
                    -queue
                - non linear
                    -tree
                    -graphs
            -array
            -files
*/

void pointer()
{
    int x =10;
    float c=10.5;
    cout << sizeof(x) << endl ;
    cout << &x << endl ;
    cout << *&x << endl ;
     // identification pointer
     // int * pointer's-name = &value(address)  ;
     int *ptr = &x ;
     cout << *ptr << endl ;
     cout << ptr << endl ;
     // new and delete
        // take a size in run time

}

void array_()
{
    // identification array
    // data-type  name  number's-value  values
    int arr [10] = {1,2,3,4,5,6} ;
    // address of array = address the first element in array
    cout << "The address of array = " << &arr << endl ;
    cout << "The address of the first element in array = " << &arr[0] << endl ;
    // but *&arr = Random value
    cout << *&arr << endl ;

    cout << *(arr+1) << endl ; // second element in array

    // how use pointer in array ?  // take size in run time
    int sizeofarray ;
    cout << "Enter size of array : " ;
    cin>> sizeofarray ;
    cout << endl ;
    int *ar ;
    ar = new int[sizeofarray] ;
    for (size_t i=0 ; i<sizeofarray ; i++)
    {
        cout << "Enter the element : " ;
        cin >> ar[i] ;
        cout << endl ;
    }
    for(size_t j=0 ; j<sizeofarray ; j++)
    {
        cout << ar[j] << endl ;
    }

    delete ar ;
}

void structur()
{
    struct student
    {
       int age ;
       int degree ;
       string name ;

    };
    student one , two={14 , 85 , "malik" };
    one.age = 19 ;
    one.degree = 90 ;
    one.name= "taha";

    cout << "student name is : " << one.name << endl ;
    cout << "student age is : " << one.age << endl ;
    cout << "student degree is : " << one.degree << endl ;
    cout << "--------------------------------------------"<< endl ;
    cout << "student name is : " << two.name << endl ;
    cout << "student age is : " << two.age << endl ;
    cout << "student degree is : " << two.degree << endl ;

    // array from struct
    student students[5] ;
    for(size_t i=0 ; i<5 ; i++)
    {
        cout << "Enter student "<< i+1 << " name : " ;
        cin >> students[i].name ;
        cout << "\n Enter student " << i+1 << " age : " ;
        cin >> students[i].age ;
        cout << "\n Enter student " << i+1 << " degree : " ;
        cin >> students[i].degree ;
        cout << endl ;
    }
    for(student d : students)
    {
        cout << "student name " << d.name << endl ;
        cout << "student age " << d.age << endl ;
        cout << "student degree : " << d.degree << endl ;
        cout << "-------------------------------"<< endl ;
    }

}


int main()
{
    // pointer() ;
    // array_();
    structur();

    system("pause") ;
    return 0;
}
