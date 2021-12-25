#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    long num;
    int tmp;
    cin>>num;
    cin.ignore();
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>tmp;
        arr[i]=tmp;
    }
    sort(arr,arr+num);
    for(int i=0;i<num;i++)
    {
        cout <<arr[i]<< " " ;
    }




}
