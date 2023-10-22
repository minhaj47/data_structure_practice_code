#include <iostream>
using namespace std;

template <class typ>
class arithmetic
{
    private:
    typ a, b
    public:
    arithmetic(typ a, typ b);
    typ add();
    typ sub();
    
};

template <class typ>
arithmetic<typ>::arithmetic(typ a, typ b)
    {
        this->a = a;
        this->b = b;
    }
    template <class typ>
    typ arithmetic<typ>::add()
    {
        return a+b;
    }
    template <class typ>
    typ arithmetic<typ>::sub()
    {
        return a-b;
    }

int main()
{
    arithmetic<float> ar(10.0,5.78);

    cout << "add " << ar.add() << endl;
    cout << "substruct " << ar.sub() << endl;

}

