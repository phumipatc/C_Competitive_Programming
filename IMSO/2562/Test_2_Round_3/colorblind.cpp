#include "colorblind.h"
using namespace std;
string investivate_colors(int N) {
	// your code here
	string ans;
	int res,res2;
	if(N == 2){
		res = use_device(1,2);
		if(res == 4){
			return "RBRB";
		}else{
			res = use_device(0,1);
			if(res == 4)	return "RRBB";
			else			return "RBBR";
		}
	}else{
		// for(int i=1;i<=N;i++)
		// 	ans.push_back('R');
		// for(int i=1;i<=N;i++)
		// 	ans.push_back('B');
		ans.clear();
		ans+="RB";
		for(int i=1;i<2*N-1;i+=2){
			res = use_device(i,i+1);
			if(ans.back() == 'B'){
				res2 = use_device(ans.size()-1,ans.size()-2);
				if(res != res2)	ans+="RB";
				else			ans+="BR";
			}else{
				if(res != res2)	ans+="BR";
				else			ans+="RB";
			}
		}
	}
	return ans;
}