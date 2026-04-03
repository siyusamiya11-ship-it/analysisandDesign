#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int bt[100], at[100], wt[100], tat[100];
    int completed[100] = {0};

  
    for(int i=0;i<n;i++){
        cout<<"Enter Arrival Time for P"<<i+1<<": ";
        cin>>at[i];
        cout<<"Enter Burst Time for P"<<i+1<<": ";
        cin>>bt[i];
    }

    int time = 0, count = 0;

    while(count < n){
        int min_index = -1;
        int min_bt = 9999;


        for(int i=0;i<n;i++){
            if(at[i] <= time && completed[i]==0){
                if(bt[i] < min_bt){
                    min_bt = bt[i];
                    min_index = i;
                }
            }
        }

        if(min_index == -1){
            time++; 
        }
        else{
        
            wt[min_index] = time - at[min_index];
            tat[min_index] = wt[min_index] + bt[min_index];

            time += bt[min_index];

            completed[min_index] = 1;
            count++;
        }
    }


    cout<<"\nProcess\tAT\tBT\tWT\tTAT\n";

    float total_wt=0, total_tat=0;

    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout<<"\nAverage WT: "<<total_wt/n;
    cout<<"\nAverage TAT: "<<total_tat/n;

    return 0;
}