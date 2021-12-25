#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,f,piece,test;
	int tmp;
	double S[10001];
	double low,high,mid;
	double pii = acos(-1.0);
	cin>>test;
	cin.ignore();
	while(test--)
	{
		cin>>n>>f;
		cin.ignore();
		f+=1;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			S[i]=tmp*tmp;
		}
		low = 0; high = 1e8;
		while(high-low>1e-7)
		{
			mid = (low+high)/2;
			piece = 0;
			for(int i=0; i<n ;i++)
			{
            piece+=(int)floor(S[i]/mid);
			}
			if(piece < f)
				high=mid;
			else
				low=mid;
		}
		low *= pii;
		printf("%.6lf\n",low);
	}
}