#include<iostream>
#include<algorithm>
using namespace std;
long long cmin=1000000;
long long c[21][21];
bool visited[21];
long long x[30];
int n,m;
long long f;
long long f_min=9999999999;
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(visited[v] == false){
            x[k] = v;
            if(c[x[k-1]][x[k]]==-1)
                continue;
            f = f + c[x[k-1]][x[k]];
            visited[v] = true;
            if(k == n)
                {
                    if(c[x[n]][x[1]]!=-1)
                f_min=min(f + c[x[n]][x[1]],f_min);
                }
        else{

            if(f + cmin*(n-k+1) < f_min)
            Try(k+1);
            }
        visited[v] = false;
        f = f - c[x[k-1]][x[k]];
        }

    }

}

int main()
{

    cin>>n>>m;
    cin.ignore();
    int i,j;
    long long fee;
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<21;j++)
            c[i][j]=-1;
    }
    for(int i=0;i<21;i++)
        visited[i]=false;
    for(int k=0;k<m;k++)
    {
        cin>>i>>j>>fee;
        cin.ignore();
        c[i][j]=fee;
        cmin=min(c[i][j],cmin);
    }
    x[1]=1;
    visited[1]=true;
    f=0;
    Try(2);
    cout<<f_min<<endl;
}
