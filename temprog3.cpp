#include<iostream>
using namespace std;
template <class T>
class array_op{
    private : T a[100]; int n;
    public : 
    void readdata();
    T findarraysum(T a);
    void display();
};
template <typename T> void array_op<T>::readdata()
{
    cout<<"enter size";
    cin>>n;
    cout<<"enter elements";
    for (int i =0;i<n;i++){
        cin>>a[i];
    }
}
template <typename T> void array_op<T>::display()
{
    cout<<"elements are "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
template <typename T> T array_op<T>::findarraysum(T key)
{
    int s=0;
    for(int i=0;i<n;i++){
        s=a[i]+key;
    }
    return s;
}
int main(){
    array_op<int> obj1;
    obj1.readdata();
    obj1.display();
    cout<<"\n array sum"<<obj1.findarraysum(3)<<endl;
    return 0;
}