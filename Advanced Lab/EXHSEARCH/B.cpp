#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int weight;
    int value;
}item;
item arr[100];
int n,b;
bool item_cmp(item x,item y)
{
    if(x.weight<y.weight)
        return true;
    return false;
}
int Try(int n,int b)
{
    if(n==0||b==0)
        return 0;
    else if(arr[n].weight>b)
        return Try(n-1,b);
    else
    {
        int tmp1=Try(n-1,b);
        int tmp2=arr[n].value+Try(n-1,b-arr[n].weight);
        return max(tmp1,tmp2);
    }


}
int main()
{

    cin>>n>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].weight>>arr[i].value;
        cin.ignore();

    }
    sort(arr,arr+n,item_cmp);
    cout<<Try(n,b)<<endl;


}

