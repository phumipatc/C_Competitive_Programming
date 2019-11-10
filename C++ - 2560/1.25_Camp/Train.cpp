/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
list<string> w;
list<string>::iterator it,it2;
string str;
int main(){
	int n;
	char cmd;
	str="123";
            w.push_front(str);
            it = w.begin();
	scanf("%d",&n);
	while(n--){
                        scanf(" %c",&cmd);
                        if(cmd=='i'){
			cin >> str;
			it2 = it;
			it2++;
			if(it2==w.end()){
                                                w.push_back(str);
                                                it++;
			}else{
                                                it++;
                                                w.insert(it,str);
                                                it--;
			}
                        }else if(cmd=='l'){
                                    if(it!=w.begin()){
                                                it--;
			}
		}else if(cmd=='r'){
			it2 = it;
			it2++;
                                    if(it2!=w.end()){
                                                it++;
                                    }
		}else if(cmd=='b'){
                                    if(it!=w.begin()){
				it = w.erase(it);
				it--;
                                    }
		}else if(cmd=='d'){
                                    it2=it;
                                    it2++;
                                    if(it2!=w.end()){
                                                it++;
                                                it = w.erase(it);
                                                it--;
                                    }
		}
	}
	it = w.begin();
            for(it++;it!=w.end();it++){
                        cout << *it << " ";
            }
}
