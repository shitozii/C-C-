#include <iostream>
#include <vector>
#include <algorithm>
#include<utility>
using namespace std;
 int main()
 {
     int num;
     cin>>num;
     cin.ignore();
     vector<int> max_age,index;
     int arr[num];
     int res[num];
     for(int i=0;i<num;i++)
     {
         cin>>arr[i];
     }
     for(int i=num-1;i>=0;i--)
     {
         if(max_age.size()==0||max_age.back()>= arr[i])
         {
             max_age.push_back(arr[i]);
             index.push_back(i);
             res[i]=-1;

         }
         else
        {
            int tmp=distance(max_age.rbegin(),lower_bound(max_age.rbegin(),max_age.rend(),arr[i]));
            int pos=(int)(max_age.size())-tmp;
            //cout<<"pos is"<<pos<<endl;
            res[i]=index[pos]-i-1;
        }
     }
     for(int i=0;i<num;i++)
     {
         cout<<res[i]<<" ";
     }
     cout<<endl;

 }
