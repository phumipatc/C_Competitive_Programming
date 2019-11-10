/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1510],b[1510];
int main(){
    int n,k,i,j,p,q,mid,sum,num;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i] = 1e9;
    for(i=0;i<n;i++){
        sum = a[i];
        b[1] = min(b[1],a[i]);
        for(j=i+1;j<n;j++){
            sum+=a[j];
            b[j-i+1] = min(b[j-i+1],sum);
        }
    }
    b[n+1] = b[n]+10000000;
    while(k--){
        scanf("%d",&num);
        p = 0;
        q = n+1;
        while(p<=q){
            mid=(p+q)/2;
            if(b[mid]<=num && num<b[mid+1]){
                printf("%d\n",mid);
                break;
            }
            else if(num<b[mid]) q = mid-1;
            else                p = mid+1;
        }
    }
    return 0;
}
/*
4 4
17 10 20 30 50 30 29 7
*/
