/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: Implement
	Status	: Finished
*/
#include <bits/stdc++.h>
using namespace std;

int a[210], b[210];

string stra, strb, nn;

int main(){
    int num = 0, lena = 1, lenb = 1, n = 0, r = 5, c = 0, cnt = 0;

    getline(cin, nn);

    for(int i = 0; i < nn.size(); i++){
        n *= 10;
        n += nn[i] - '0';
    }

    getline(cin, stra);
    getline(cin, strb);
    for(int i = 0; i < stra.size(); i++){
        if(stra[i]==' ' || stra[i] == '\0'){
            a[lena++] = num;
            num = 0;
            continue;
        }
        num *= 10;
        num += stra[i] - '0';
    }
    a[lena] = num;

    num = 0;

    for(int i = 0; i < strb.size(); i++){
        if(strb[i]==' ' | strb[i]=='\0'){
            b[lenb++] = num;
            num = 0;
            continue;
        }
        num *= 10;
        num += strb[i] - '0';
    }
    b[lenb] = num;
    if(lena!=n || lenb!=n){
        cout << 0;
        return 0;
    }

    for(int i = 1; i <= lena; i++){
        r = max(r, a[i]);
    }

    for(int j = 1; j <= lenb; j++){
        c += b[j];
        if(b[j]){
        }
        c += 11;
    }
    c -= 11;
    /*
    //cout << c << "\n";
    */

    for(int i = 1; i <= r; i++){
        for(int k = 1; k <= lenb; k++){
            for(int j = 1; j <= b[k]; j++){
                if(r-i >= a[k]){
                    cout << " ";
                    continue;
                }
                cout << "*";
                cnt++;
            }
            if(k==n)
                continue;
            for(int j = 0; j < 2; j++){
                cout << " ";
            }
            if(r-i==4)
                printf("   -   ");
            else if(r-i==3)
                printf("  -o-  ");
            else if(r-i==2)
                printf(" -oxo- ");
            else if(r-i==1)
                printf("-oxoxo-");
            else if(r-i==0)
                printf("   |   ");
            else
                printf("       ");
            for(int j = 0; j < 2; j++){
                cout << " ";
            }
        }
        cout << "\n";
    }
    for(int i = 0; i < c; i++){
        cout << "*";
        cnt++;
    }
    cout << "\n";
    cout << cnt;

    return 0;
}
