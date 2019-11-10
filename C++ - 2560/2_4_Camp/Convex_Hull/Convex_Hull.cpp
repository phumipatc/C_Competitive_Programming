/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define PI pair<long long,long long>
using namespace std;
PI P[50010],S[50010];
int orientation(PI p1,PI p2,PI p3){
    long long temp=(long long)(p2.first-p1.first)*(p3.second-p2.second)-(p2.second-p1.second)*(p3.first-p2.first);
    if(temp==0) return 0;
    else        return (temp<0) ?1 :2;
}
long long dist(PI A,PI B){
    return (A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second);
}
int comp(const void *a,const void *b){
    PI A=*(PI*)a;
    PI B=*(PI*)b;
    int o=orientation(P[0],A,B);
    if(o==0)
        return dist(P[0],A)>dist(P[0],B);
    return (o!=2);
}
int main(){
    int n,m,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&P[i].first,&P[i].second);
        P[i].second*=-1;
    }
    sort(P,P+n);
    for(int i=0;i<n;i++)
        P[i].second*=-1;
    qsort(&P[1],n-1,sizeof (PI),comp);
    m=1;
    for(int i=1;i<n;i++){
        while(i<n-1 && !orientation(P[0],P[i],P[i+1]))    i++;
        P[m++]=P[i];
    }
    S[0]=P[0];
    S[1]=P[1];
    S[2]=P[2];
    t=3;
    for(int i=3;i<m;i++){
        while(t>2 && orientation(S[t-2],S[t-1],P[i])!=2) t--;
        S[t++]=P[i];
    }
    printf("%d\n",t);
    for(int i=0;i<t;i++)    printf("%lld %lld\n",S[i].first,S[i].second);
    return 0;
}
