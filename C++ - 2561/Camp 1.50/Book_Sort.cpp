/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id;
    char str[30];
    bool operator < (const A&o) const{
        if(strcmp(str,o.str)!=0)    return strcmp(str,o.str)<0;
        else                        return id<o.id;
    }
};
A a[30100];
int tree[30100];
void update(int idx,int v){
    while(idx<=30010){
        tree[idx]+=v;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int ans[30100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %s",a[i].str);
        a[i].id = i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ans[a[i].id] = query(a[i].id-1)+1;
        update(a[i].id,1);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
	return 0;
}
