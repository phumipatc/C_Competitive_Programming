#include <stdio.h>
#include <string.h>
char str[1010];
int mic[1010][1010];
//mic[i][j] will be 0 if substring str[i..j] is not palindrome.
//Else mic[i][j] will be 1
int main(){
	int len,maxLength=1,i,start=0,k,j;
	scanf(" %s",str);
	len = strlen(str);
    for(i=0;i<len;i++)
        mic[i][i] = 1;
    for(i=len-1;i>0;i--){
        if(str[i] == str[i-1]){
            mic[i-1][i] = 1;
            start = i-1;
            maxLength = 2;
        }
    }
    for(k=3;k<=len;++k){
        for(i=0;i<len-k+1;++i){
            // Get the ending index of substring from starting index i and length k
            j = i+k-1;
            // checking for sub-string from ith index to jth index iff str[i+1]
            // to str[j-1] is a palindrome
            if(mic[i+1][j-1] && str[i]==str[j]){
                mic[i][j] = 1;
                if(k>maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
	for(i=start;i<=start+maxLength-1;++i)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}
