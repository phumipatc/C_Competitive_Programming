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
    int m,n,k,i,j,st,maxx;
    scanf("%d %d %d",&m,&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&value[i]),idx[i]=way[i]=i;
    for(i=1;i<=k;i++)
        scanf("%d %d",&a[i].pillar,&a[i].height);
    scanf("%d",&st);
    sort(a+1,a+k+1);
    for(i=1;i<=k;i++){
        j=a[i].pillar;
        swap(idx[way[j]],idx[way[j+1]]);
        swap(way[j],way[j+1]);
    }
    for(i=1;i<=n;i++)
        temp[i]=idx[i];
    maxx=value[temp[way[idx[st]]]];
    str[0]='N',str[1]='O';
    for(i=1;i<=n;i++)
        way[i]=idx[i]=i;
    for(i=1;i<=k;i++){
        j=a[i].pillar;
        swap(idx[way[j]],idx[way[j+1]]);
        swap(way[j],way[j+1]);
        if(a[i].height==a[i+1].height)  continue;
        if(value[temp[way[idx[st]+1]]]>maxx){
            maxx=value[temp[way[idx[st]+1]]];
            str[0]='U',str[1]='S',str[2]='E';
        }
        if(value[temp[way[idx[st]-1]]]>maxx){
            maxx=value[temp[way[idx[st]-1]]];
            str[0]='U',str[1]='S',str[2]='E';
        }
    }
    printf("%d\n%s\n",maxx,str);
    return 0;
}
/*
20 5 6
7 5 3 9 4
1 5
1 6
2 10
1 12
3 6
3 13
1

40 5 4
100 150 115 130 90
1 10
2 15
4 20
3 25
3
*/
