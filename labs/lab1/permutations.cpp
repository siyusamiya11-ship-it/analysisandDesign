#include<iostream>
using namespace std;

void permute(string str, int l, int r){
    if(l==r){
        cout<<str<<endl;
        return;
    }
    for(int i=1;i<=r;i++){
        swap(str[l],str[i]);
        permute(str,l+1,r);
        swap(str[l],str[i]);

    }
}
int main(){
    string str;
    cout<<"enter a string";
    cin>>str;
    permute(str,0,str.length()-1);
    return 0;
}