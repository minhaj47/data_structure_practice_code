#include <iostream>
using namespace std;

class Array
{
private:
    int  *a;
    int Size;
    int length;
public:
    Array()
    {
        Size = 10;
        length = 0;
        a = new int[Size];
    }
    Array(int sz)
    {
         Size = sz;
        length = 0;
        a = new int[Size];
    }
    ~Array()
    {
        delete []a;
    }
    void display();
    void Insert (int index, int x);
    int Delete(int index);
};

void Array:: display()
{
    for(int i; i<length; i++)
        cout << a[i]<< " ";
    cout << endl;
}
void Array :: Insert(int index, int x)
{
    if(index>=0 && index<=length){
        for(int i = length-1; i>=index; i--)
            a[i+1]=a[i];
        a[index]= x;
    }
}

int  Array :: Delete(int index)
{
    int  x =0;
    if(index>=0 && index<length){
        x = a[index];
        for(int i=index; i<length; i++)
            a[i]=a[i+1];
        length--;
    }
    return x;
}

int main()
{
    Array arr(10);
    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,7);
    arr.Insert(3,8);
    arr.display();
    arr.Delete(2);
    arr.display();
}
