#include<iostream>
using namespace std;
template <class T>
class calculator
{
    private: T num1, num2;
    public:
    calculator(T n1, T n2)
    {
        num1=n1;
        num2=n2;

    }
    T add(){
        return num1+num2;
    }
};
int main(){
    calculator<int> obj1(20,22);
    calculator<double> obj2(2.1,2.2);
    calculator<string> obj3("hello","world");
    cout<<obj1.add()<<endl;
    cout<<obj2.add()<<endl;
    cout<<obj3.add()<<endl;
    return 0;
}