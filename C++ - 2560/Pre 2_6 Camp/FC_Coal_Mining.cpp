/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int block[1100],a[1000005];
int main(){
    int ans,n,k,pos,num,sq,i,j;
    scanf("%d %d",&n,&k);
    sq = (int)sqrt(n);
    while(k--){
        ans = n;
        scanf("%d %d",&pos,&num);
        pos--;
        a[pos] = num;
        block[pos/sq] = -1e9;
        for(i=(pos/sq)*sq;i<((pos/sq)*sq)+sq;i++)
            block[pos/sq] = max(block[pos/sq],a[i]);
        for(i=pos;i>=0;){
            if(i%sq == sq-1 && i-sq>=0){
                if(block[i/sq]>num){
                    for(j=i;j>i-sq;j--)
                        if(a[j]>num)
                            break;
                    ans = min(ans,pos-j);
                    break;
                }
                i-=sq;
            }else{
                if(a[i]>num){
                    ans = min(ans,pos-i);
                    break;
                }
                i--;
            }
        }
        for(i=pos;i<n;){
            if(i%sq == 0 && i+sq<n){
                if(block[i/sq]>num){
                    for(j=i;j<i+sq;j++)
                        if(a[j]>num)
                            break;
                    ans = min(ans,j-pos);
                    break;
                }
                i+=sq;
            }else{
                if(a[i]>num){
                    ans = min(ans,i-pos);
                    break;
                }
                i++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
