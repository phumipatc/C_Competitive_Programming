/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,len,num;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
stack<A> s;
A a[100100];
int l[100100],r[100100];
int main()
{
    A temp,temp2;
    char dir;
    int n,i,pos,maxx=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].pos,&a[i].len);
        a[i].num=1;
    }
    sort(a,a+n);
    for(i=0;i<100000;i++)
        l[i]=r[i]=1;
    temp.pos=a[0].pos,temp.len=a[0].len,temp.num=a[0].num;
    s.push(temp);
    for(i=1;i<n;i++){
        temp=a[i];
        while(!s.empty()){
            temp2=s.top();
            if(temp.pos-temp.len<temp2.pos){
                s.pop();
                temp.num+=temp2.num;
                l[i]+=temp2.num;
            }else
                break;
        }
        s.push(temp);
    }
    while(!s.empty())
        s.pop();
    temp.pos=a[n-1].pos,temp.len=a[n-1].len,temp.num=a[n-1].num;
    s.push(temp);
    for(i=n-2;i>=0;i--){
        temp=a[i];
        while(!s.empty()){
            temp2=s.top();
            if(temp.pos+temp.len>temp2.pos){
                s.pop();
                temp.num+=temp2.num;
                r[i]+=temp2.num;
            }else
                break;
        }
        s.push(temp);
    }
    for(i=0;i<n;i++){
//        printf("%d %d\n",l[i],r[i]);
        if(maxx<l[i]){
            maxx=l[i];
            pos=i;
            dir='L';
        }
        if(maxx<r[i]){
            maxx=r[i];
            pos=i;
            dir='R';
        }
    }
    printf("%d %c\n",pos+1,dir);
    return 0;
}
