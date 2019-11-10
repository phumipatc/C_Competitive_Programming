/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],cluster[1010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int len=(int)sqrt(n);
    while(k--){
        int pos,v,ans=n,i,j;
        scanf("%d %d",&pos,&v);
        pos--;
        a[pos] = v;
        for(i=(pos/len)*len;i<min(((pos/len)*len)+len,n);i++)
            cluster[pos/len] = max(cluster[pos/len],a[i]);
        for(i=pos;i<=n;){
            if(i%len == 0 && i+len-1<=n){
                if(cluster[i/len]>v){
                    for(j=i;j<i+len;j++)
                        if(v<a[j])
                            break;
                    ans = j-pos;
                    break;
                }
                i+=len;
            }else{
                if(a[i]>v){
                    ans = i-pos;
                    break;
                }
                i++;
            }
        }
        for(i=pos;i>=0;){
            if(i%len == len-1 && i-len+1>=0){
                if(cluster[i/len]>v){
                    for(j=i;j>i-len;j--)
                        if(v<a[j])
                            break;
                    ans = min(ans,pos-j);
                    break;
                }
                i-=len;
            }else{
                if(a[i]>v){
                    ans = min(ans,pos-i);
                    break;
                }
                i--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
