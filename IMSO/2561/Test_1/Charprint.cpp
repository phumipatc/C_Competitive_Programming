/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[300100],str2[100100];
vector<int> v[30];
long long tree[300100];
void update(long long idx,long long v){
    while(idx<=300010){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long len,idx,opr,ans = 0;
    scanf("%lld %s",&opr,str+1);
    len = strlen(str+1);
    for(long long i=len;i>=1;i--)
        v[str[i]-'a'].push_back(i);
    scanf(" %s",&str2);
    len = strlen(str2);
    if(opr == 0){
        for(long long i=0;i<len;i++){

            if(v[str2[i]-'a'].size() == 0){
                printf("-1\n");
                return 0;
            }
            idx = v[str2[i]-'a'][v[str2[i]-'a'].size()-1];
            ans+=idx;
//            printf("%c : %lld %lld\n",str2[i],idx,ans);
            v[str2[i]-'a'].pop_back();
        }
    }else{
        for(long long i=0;i<len;i++){
            if(v[str2[i]-'a'].size() == 0){
                printf("-1\n");
                return 0;
            }
            idx = v[str2[i]-'a'][v[str2[i]-'a'].size()-1];
            ans+=idx-query(idx-1);
            update(idx,1);
//            printf("%c : %lld %lld\n",str2[i],idx,ans);
            v[str2[i]-'a'].pop_back();
        }
    }
    printf("%lld\n",ans);
	return 0;
}
