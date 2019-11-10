/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],cluster[1100];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int len=(int)sqrt(n);
    while(k--){
        int pos,pow,ans=n,i,j;
        scanf("%d %d",&pos,&pow);
        pos--;
        a[pos]=pow;
        for(i=(pos/len)*len;i<min(((pos/len)*len)+len,n);i++)
            cluster[pos/len]=max(cluster[pos/len],a[i]);
        for(i=pos;i<=n;){
            if(i%len==0 && i+len-1<=n){
                if(cluster[i/len]>pow){
//                    printf("R:Cluster:%d\n",i/len);
                    for(j=i;j<i+len;j++)
                        if(pow<a[j])
                            break;
                    ans=j-pos;
                    break;
                }
                i+=len;
            }else{
                if(a[i]>pow){
//                    printf("R:Single:%d\n",i);
                    ans=i-pos;
                    break;
                }
                i++;
            }
        }
        for(i=pos;i>=0;){
            if(i%len==len-1 && i-len+1>=0){
                if(cluster[i/len]>pow){
//                    printf("L:Cluster:%d\n",i/len);
                    for(j=i;j>i-len;j--)
                        if(pow<a[j])
                            break;
                    ans=min(ans,pos-j);
                    break;
                }
                i-=len;
            }else{
                if(a[i]>pow){
//                    printf("L:Single:%d\n",i);
                    ans=min(ans,pos-i);
                    break;
                }
                i--;
            }
        }
//        for(i=0;i<n;i++)
//            printf("%d ",a[i]);
//        printf("\n");
//        for(i=0;i<=len;i++)
//            printf("%d ",cluster[i]);
//        printf("\n");
        printf("%d\n",ans);
    }
    return 0;
}
