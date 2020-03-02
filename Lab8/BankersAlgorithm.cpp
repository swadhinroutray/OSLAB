#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
  cout<<"Input number of processes: ";
  int pro;
  cin>>pro;
  int res;
  cout<<"Input number of resources: ";
  cin>>res;
  int alloc[pro][res], Max[pro][res],need[pro][res];

 cout<<"Input Resource Allocation for Process \n";         
  for (int i = 0; i < pro; i++)
  {
      for (int j = 0; j < res; j++)
      {
          cin>>alloc[i][j];
      }
      
  }
   cout<<"Input Max Allocation for Process\n";
         
  for (int i = 0; i < pro; i++)
  {
      for (int j = 0; j < res; j++)
      {
          cin>>Max[i][j];
      }
      
  }
  //Allocation Matrix
  for (int i = 0; i < pro; i++)
  {
      for (int j = 0; j < res; j++)
      {
          cout<<alloc[i][j]<<"\t";
      }
      cout<<endl;
  }
//Max matrix & need matrix
  for (int i = 0; i < pro; i++)
  {
      for (int j = 0; j < res; j++)
      {
        cout<<Max[i][j]<<"\t";
        need[i][j] = Max[i][j] -alloc[i][j];
      }
      cout<<endl;
  }

cout<<"Input available array \n";
int avail[res];
for (int i = 0; i < res; i++)
{
    cin>>avail[i];
}

int work[pro];
bool finish[pro];
  for (int i = 0; i < pro; i++)
  {
    work[i] = avail[i];
    finish[i] = false;
  }
int fin[10];
int x =0;
for (int i = 0; i < pro; i++)
{
    for (int j = 0; j < res;j++)
    {
        if(finish[i]==false){
            int flag =0;
            for (int k = 0; k < pro; i++)
            {
                if(need[i][j]>avail[k])
                {
                    flag=1;
                    break;
                }
                if(flag == 0){
                    fin[x++] = i;
                    for (int l = 0; l < pro; l++)
                    {
                        avail[l] +=alloc[i][j];
                    }
                    finish[i]=true;
                    
                }
            }
            
        }
    }
    
}
cout<<"Safe sequence:\n";
for (int i = 0; i < x-1; i++)
{
    cout<<fin[i]<<"\t";
}
cout<<endl;
return 0;

}