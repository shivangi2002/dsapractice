#include <bits/stdc++.h>
using namespace std;
int prod(int arr[],int n){
    if(n==0 ){
        return 0;
    }
    else if(n==1){
        return arr[0];
    }
    else{
        return arr[n-1]*prod(arr,n-1);
    }
}
int main(){
    int n;
    cout <<"enter no of elements"<<endl;
    cin >> n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }
    cout << prod(arr,n);
}