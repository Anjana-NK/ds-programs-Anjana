#include<iostream>
using namespace std ;
int main() {
    int arr[100],n,r[3];
    int i,j=0,sum1=0;
    int sum2=0;
    cout<<"enter number of elements";
    cin>>n;
    cout<<"enter elements";
    for (i=0;i<n;i++) {
        cin>>arr[i];
    }
    while (j<n){
        if (arr[j]%2!=0){
            sum1+=arr[j];
        }
        else {
            sum2+=arr[j];
        }
        j++;

    }
    r[0]=sum1;
    r[1]=sum2;
    cin>>r[0];
    cin>>r[1];
}