#include "requeue.cpp"

int main(){
	int n, k;
	scanf("%d%d",&n,&k);
	std::vector<int> Q;
	Q.reserve(n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		Q.push_back(x);
	}
	printf("%d\n", requeue(Q, k));
	return 0;
}
