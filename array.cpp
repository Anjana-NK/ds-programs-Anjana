#include "array.h"
template <class T>
arrayy<T>::arrayy()
{
    int i;
    std::cout<<"enter lower bound: ";
    std::cin>>lb;
    std::cout<<"enter upper bound: ";
    std::cin>>ub;
    std::cout<<"enter elements: ";
    for(i=lb;i<ub;i++)
    {
        std::cin>>a[i];
    }
}
template <class T>
void arrayy<T>::displayarray(){
    int i;
    for(i=lb;i<ub;i++){
        std::cout<<a[i]<<"\n";
    }
}