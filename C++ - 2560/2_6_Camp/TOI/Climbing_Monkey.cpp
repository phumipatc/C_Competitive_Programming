/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pillar,height;
    bool operator < (const A&o) const{
        if(height!=o.height)  return height<o.height;
        else                  return pillar<o.pillar;
    }
};
A a[1000100];
int value[200100],idx[200100],way[200100],temp[200100];
char str[5];
int main(){
    int m,n,k,i,st,maxx;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&value[i]),idx[i] = way[i] = i;
    for(i=1;i<=k;i++)
        scanf("%d %d",&a[i].pillar,&a[i].height);
    scanf("%d",&st);
    sort(a+1,a+k+1);
    for(i=1;i<=k;i++){
        swap(idx[way[a[i].pillar]],idx[way[a[i].pillar+1]]);
        swap(way[a[i].pillar],way[a[i].pillar+1]);
    }
    for(i=1;i<=n;i++)   temp[i] = idx[i];
    maxx = value[temp[way[idx[st]]]];
    strcpy(str,"NO");
    for(i=1;i<=n;i++)   way[i] = idx[i] = i;
    for(i=1;i<=k;i++){
        swap(idx[way[a[i].pillar]],idx[way[a[i].pillar+1]]);
        swap(way[a[i].pillar],way[a[i].pillar+1]);
        if(a[i].height == a[i+1].height)  continue;
        if(value[temp[way[idx[st]+1]]]>maxx){
            maxx = value[temp[way[idx[st]+1]]];
            strcpy(str,"USE");
        }
        if(value[temp[way[idx[st]-1]]]>maxx){
            maxx = value[temp[way[idx[st]-1]]];
            strcpy(str,"USE");
        }
    }
    printf("%d\n%s\n",maxx,str);
    return 0;
}
