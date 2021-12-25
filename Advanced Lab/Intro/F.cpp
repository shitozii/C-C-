#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
   int num;
   cin>>num;
   cin.ignore();
   string s[num];
   string tmp;
   for(int i=0;i<num;i++)
   {
       getline(cin,s[i]);
   }
   for(int i=0;i<num;i++)
   {
       long long len= (long long) (s[i].length());
       if (len<=10)
        continue;
       else
       {

        tmp=s[i][0]+to_string(len-2)+s[i][len-1];
        s[i]=tmp;

       }
   }
   for(int i=0;i<num;i++)
   {
       cout<<s[i]<<endl;
   }





}
