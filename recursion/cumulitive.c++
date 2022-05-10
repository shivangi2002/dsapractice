#include <bits/stdc++.h>

using namespace std;
int cum(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n+cum(n-1);
    }
}
int main(){
    int n;
    cin >> n;
    cout<<cum(n);

}
