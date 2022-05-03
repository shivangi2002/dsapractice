#include <bits/stdc++.h>
using namespace std;
void towerofhanoi(int n, char fromrod,char torod,char aux){
    if(n==0){
        return;
    }
    towerofhanoi(n-1,fromrod,aux,torod);
    cout <<"move disk "<<n << " from rod " << fromrod <<" to rod "<<torod<<endl;
    towerofhanoi(n-1,aux,torod,fromrod);
}
int main(){
    int n = 4;
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}