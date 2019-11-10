/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int no,i,num[100000010];
int gcd(int a,int b)
{
    int rem;
    if(b==0)
    return a;
    if(a==0)
    return b;
    if(b>a)
    {
           a=a+b;
           b=a-b;
           a=a-b;
           }
           rem=a%b;
    while(rem>0)
    {
              a=b;
              b=rem;
              rem=a%b;
              }
              if(rem==0)
              return b;
              else
              return rem;
              }
int main()
{
/*LCM(a,b) = a*b/GCD(a,b)*/
cin>>no;
for(i=1;i<=no;i++)
{
             cin>>num[i];
             }
int lcm;
lcm=num[1]*num[2]/gcd(num[1],num[2]);
for(i=3;i<=no;i++)
                  lcm=lcm*num[i]/gcd(lcm,num[i]);

cout<<lcm;


                                  return 0;
                                  }
