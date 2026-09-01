<<<<<<< HEAD
#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
=======
#include<iostream>
using namespace std;
void merge(int arr[], int lb, int mid, int ub) {
    int temp[100];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while(i <= mid && j <= ub) {
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int i=lb;i<=ub;i++){
        arr[i]=temp[i];
    }
}

void mergesort(int arr[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main(){
    int arr[100],lb,ub;
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
    mergesort(arr, lb, ub-1);
    cout<<"\n after sorting \n";
    for(int i=lb;i<ub;i++){
        cout<<arr[i]<<" ";
    }
}
>>>>>>> 8287f9c624a076fc35c895b5724af9ab6ff9213c
