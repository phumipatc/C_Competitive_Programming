/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<double ,double > a[500100];
int main(){
    double n,m,t1,t2;
    scanf("%lf %lf",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].first,&a[i].second);
        if(i == 1 || (a[i].first-a[i-1].first)*a[i-1].second>=m){
            printf("0\n");
            continue;
        }
        t1 = (m-((a[i].first-a[i-1].first)*a[i-1].second))/a[i-1].second;
        t2 = m/a[i].second;
        if(t2<t1){
            printf("%.0lf\n",a[i].second-floor((m*a[i-1].second)/(m-((a[i].first-a[i-1].first)*a[i-1].second))));
            a[i].second = floor((m*a[i-1].second)/(m-((a[i].first-a[i-1].first)*a[i-1].second)));
        }else{
            printf("0\n");
        }
    }
    return 0;
}
