/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <stdio.h>
int connect[10001][2],cnt[10001];
int visited[10001] = {0};
int startNode = -1,center = -1,i,N;
void runToCen(int node,int step){
	if(visited[node] == 1){
		return ;
	}
	visited[node] = 1;
	if(step == N/2){
		center = node;
		return ;
	}
	for(i=0;i<cnt[node];i++)
		runToCen(connect[node][i],step+1);
}
int main(){
	int i,a,b;
	scanf("%d",&N);
	for(i=0;i<N-1;i++){
		scanf("%d %d",&a,&b);
		connect[a][cnt[a]++] = b;
		connect[b][cnt[b]++] = a;
	}
	for(i=0;i<10001;i++){
		if(cnt[i] == 1){
			startNode = i;
		}
	}
	runToCen(startNode,0);
	printf("%d\n",center);
	return 0;
}
