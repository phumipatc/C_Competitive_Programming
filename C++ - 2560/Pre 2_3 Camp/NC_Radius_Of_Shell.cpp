/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100],l[300100],r[300100];
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),a[i+n]=a[i+(2*n)]=a[i];
        for(int i=1;i<=(3*n);i++){
            l[i]=i-1;
            while(l[i]>0 && a[i]>=a[l[i]])
                l[i]=l[l[i]];
        }
        for(int i=3*n;i>0;i--){
            r[i]=i+1;
            while(r[i]<=(3*n) && a[i]>=a[r[i]])
                r[i]=r[r[i]];
        }
        for(int i=1;i<=(3*n);i++)
            l[i]=i-l[i]-1;
        for(int i=3*n;i>0;i--)
            r[i]=r[i]-i-1;
        for(int i=n+1;i<=2*n;i++){
            if(min(l[i],r[i])>=(n-1)/2)
                printf("%d ",(n-1)/2);
            else
                printf("%d ",min(l[i],r[i]));
        }
    }
    return 0;
}
