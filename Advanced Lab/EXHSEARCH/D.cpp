#include<iostream>
using namespace std;
int n,max_num;
int x[250];
int cur;
bool visited[250];
int c[250][250];
int cmin=11;
int f,f_min=999999999;
bool candidate(int v,int k)
{
    if(visited[v]==true)
        return false;
    if(v<=n)
    {
        if(cur>=max_num)
            return false;

    }
    else
    {
        if(!visited[v-n])
            return false;
    }
    return true;
}
void Try(int k)
{
    for(int v = 1; v <=2*n; v++){
    if(candidate(v,k))
        {
            x[k] = v;
            f += c[x[k-1]][x[k]];
            if(v <= n)
                cur += 1;
            else cur -= 1;

            visited[v] = true;
            if(k == 2*n)
            {
                f_min=min(f_min,f + c[x[2*n]][0]);
            }
            else{
                if(f + (2*n+1-k)*cmin < f_min)
                Try(k+1);

                }
            if(v <= n) cur -= 1;
            else cur +=1;
            visited[v] = false;
            f -= c[x[k-1]][x[k]];
}
}
}

int main()
{
    cin>>n>>max_num;
    cin.ignore();
    for(int i=0;i<=2*n;i++)
        for(int j=0;j<=2*n;j++)
    {
        cin>>c[i][j];
        if(j==2*n)
            cin.ignore();
        if(i!=j)
            cmin=min(cmin,c[i][j]);
    }
    for(int i=0;i<250;i++)
        visited[i]=false;
    x[0]=0;
    cur=0;
    f=0;
    Try(1);
    cout<<f_min<<endl;

}