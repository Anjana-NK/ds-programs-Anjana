#include<iostream>
using namespace std;
int main(){
    int arr[100],lb,ub,pos,val;
    cout<<"enter value of lower bound"<<endl;
    cin>>lb; 
    cout<<"enter value of upper bound"<<endl;
    cin>>ub;
    cout<<"enter elements"<<endl;
    for(int i=lb;i<ub;i++){
        cin>>arr[i];
    }
    cout<<"displaying array"<<endl;
    for(int i=lb;i<ub;i++){
        cout<<arr[i]<<" ";
    }

    for(int i=lb;i<ub;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
    cout<<"\n after sorting \n";
    for(int i=lb;i<ub;i++){
        cout<<arr[i]<<" ";
    }
}