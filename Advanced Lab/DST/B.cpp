#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef struct{
    long long pos;
    long long num;
}add;
bool my_cmp( add x,add y)
{
    if(x.pos<y.pos)
    return true;
    return false;

}
int main(){
    long long n,k;
    cin >> n >> k;
    cin.ignore();
    add pos[n+10];
    add neg[n+10];
    long long np=0;
    long long nn=0;
    long long po=0,num=0;
    long long total=0;
    long long remain=0;
    long long tmp=0;
    for(long long i=0;i<n;i++)
    {
        cin>>po>>num;
        if(po>0)
        {
            pos[np].pos=po;
            pos[np].num=num;
            np++;
        }
        else
        {
            neg[nn].pos=-po;
            neg[nn].num=num;
            nn++;
        }
        cin.ignore();
    }

    if(np>0)
    sort(pos,pos+np,my_cmp);
    if(nn>0)
    sort(neg,neg+nn,my_cmp);

    long long i=np-1;

    while(i>=0)
    {
         if(pos[0].num==0)
            break;
        pos[i].num-=remain;
        if(pos[i].num<0)
        {
            remain=-pos[i].num;
            pos[i].num=0;
        }

        else{
        remain= pos[i].num%k;
        if(remain!=0)
            remain=k-remain;
        tmp=pos[i].num/k;
        if(remain>0)
            {
                total+=2ll*(tmp+1)*pos[i].pos;



            }
            else
                total+=2*tmp*pos[i].pos;


        }
        i--;




    }
    i=nn-1;
    remain=0;

    while(i>=0)
    {
         if(neg[0].num==0)
            break;
        neg[i].num-=remain;
        if(neg[i].num<0)
        {
            remain=-neg[i].num;
            neg[i].num=0;
        }

        else{
        remain=neg[i].num%k;
        if(remain!=0)
            remain=k-remain;
        tmp=neg[i].num/k;
        if(remain>0)
            {
                total+=2ll*(tmp+1)*neg[i].pos;



            }
            else
                total+=2*tmp*neg[i].pos;


        }
        i--;




    }
    cout<<total<<endl;




}
