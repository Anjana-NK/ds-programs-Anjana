#include<iostream>
using namespace std;
int main(){
    int arr[100],lb,ub,pos,val;
    cout<<"enter value of lower bound"<<endl;
    cin>>lb;
    cout<<"enter value of upper bound"<<endl;
    cin>>ub;
    cout<<"enter elements"<<endl;
    for(int i=lb;i<=ub;i++){
        cin>>arr[i];
    }
    cout<<"displaying array"<<endl;
    for(int i=lb;i<=ub;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n enter position to be inserted \n";
    cin>>pos;
    cout<<"enter value to be inserted";
    cin>>val;

    for(int i=ub;i>= pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=val;
    ub+=1;
    cout<<"after inserting the element";
    for(int i=lb;i<=ub;i++){
        cout<<arr[i]<<" ";
    }
}