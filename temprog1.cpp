#include<iostream>
using namespace std ;
template< class T >
T large(T n1, T n2){
    return (n1>n2)?n1:n1;
}
int main(){
    cout<<large(2,3)<<endl;
    cout<<large('0','1')<<endl;
    return 0;
}