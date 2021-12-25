#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(unsigned long long arr[], int n)
{
    int i, j;
    unsigned long long key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    short n1;
    short n2;
    short i=0;
    short num;
    cin>>n1;
    num=n1;
    cin.ignore();
    unsigned long long arr1[n1];
    while(num--)
    {
        cin>>arr1[i];
        i++;
    }
    cin.ignore();
    cin>>n2;
    cin.ignore();
    i=0;
    unsigned long long arr2[n2];
    num=n2;
    while(num--)
    {
        cin>>arr2[i];
        i++;
    }
    insertionSort(arr1,n1);
    insertionSort(arr2,n2);
    short k1=0,k2=0;
    bool check=true;
    while(k1<n1&&k2<n2)
    {
        if(arr2[k2]>arr1[k1])
            k1++;
        else if(arr2[k2]==arr1[k1])
        {
            k1++;
            k2++;
        }
        else
        {
            check=false;
            break;
        }

    }
    if (k2>=n2)
        cout<< 1<<endl;
    else
        cout<< 0<<endl;







}
