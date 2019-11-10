/*
TASK: Next Permutation
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int q,n,a[1010],i,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        ch=1;
        for(i=0;i<n;i++){
            if(a[i]!=n-i)
                ch=0;
        }
        if(ch)  printf("No next permutation\n");
        else{
            next_permutation(a,a+n);
            for(i=0;i<n;i++)
                printf("%d ",a[i]);
            printf("\n");
        }
    }
    return 0;
}
