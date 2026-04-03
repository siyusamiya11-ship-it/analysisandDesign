//adjancency matrix to calculate 
#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter number of modes: ";
cin>>n;
int adj[n][n];
cout<<"enter adjacency matrix:\n";
for(int i=0;i<n;i++){
    for(int j=0; j<n; j++){
    cin>>adj[i][j];
}
}
cout<<"number of modes="<<n<<endl;
return 0;
}