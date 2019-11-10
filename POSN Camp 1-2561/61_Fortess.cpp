/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long q = 20,n,m;
    while(q--){
        scanf("%lld %lld",&m,&n);
        if(m-(2*n)<0 || m>(4*n))    printf("0\n");
        else                        printf("%lld\n",((4*n)-m)/2+1);
    }
    return 0;
}
/*
40 15
30 12
60 40
50 18
66 26
36 11
36 16
36 18
56 20
56 22
44 18
32 14
42 20
36 16
38 14
38 16
34 20
36 16
44 14
34 14
*/