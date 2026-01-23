//TOWER OF HANOI USING RECURSION
#include<iostream>
using namespace std;
void towerOfhanoi(int n,char F,char T, char U){
    if(n==1){
    cout<<"move disc 1 : "<< F<<" to "<< T<<endl;
return;
}
    towerOfhanoi(n-1,F,T,U);
    cout<<"move disc :"<<F<<" to "<<U<<endl;
    towerOfhanoi(n-1,F,T,U);


}
int main(){
    int n;
    cout<<"enter number of disc";
    cin>>n;
    towerOfhanoi(n,'F','T','U');
    return 0;

}
