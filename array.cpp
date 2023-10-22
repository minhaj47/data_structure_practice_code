#include <iostream>
using namespace std;

class array
{
private:
    int  *a;
    int size;
    int length;
public:
    array()
    {
        size = 10;
        length = 0;
        a = new int[size];
    }
    array(int sz)
    {
        size = sz;
        length = 0;
        a = new int[size];
    }
    ~array()
    {
        delete []a;
    }
    void display();
    void insert (int index, int x);
    int Delete(int index);
};

void array:: display()
{
    for(int i; i<length; i++)
        cout << a[i]<< " ";
    cout << endl;
}
void array :: insert(int index, int x)
{
    if(index>=0 && index<=length){
        for(int i = length-1; i>=index; i--)
            a[i+1]=a[i];
        a[index]= x;
    }
}

void array :: Delete(int index)
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
    array arr(10);
    arr.insert(0,5);
    arr.insert(1,6);
    arr.insert(2,7);
    arr.insert(3,8);
    arr.display();
    arr.Delete(2);
    arr.display();
}