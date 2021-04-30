/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Treap
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct node{
	int key,prior,num;
	node *l,*r;
	node(int key):key(key),l(NULL),r(NULL){
		prior = rand(),num = 1;
	}
};
typedef node* pnode;
pnode root = NULL;
int sz(pnode t){
	return t?t->num:0;
}
void upd(pnode t){
	if(!t)	return ;
	t->num = 1 + sz(t->l) + sz(t->r);
}
void split(pnode t,pnode &l,pnode &r,int key,int temp=0){
	if(!t){
		l = r = NULL;
		return ;
	}
	int idx = temp + 1 + sz(t->l);
	if(idx<=key)	split(t->r,t->r,r,key,idx),l = t;
	else			split(t->l,l,t->l,key,temp),r = t;
	upd(t);
}
void merge(pnode &t,pnode l,pnode r){
	if(!l || !r){
		t = (l?l:r);
		return ;
	}
	if(l->prior>r->prior)	t = l,merge(l->r,l->r,r);
	else					t = r,merge(r->l,l,r->l);
	upd(t);
}
pnode find(pnode t,int idx,int temp=0){
	if(!t)	return NULL;
	int now = temp + 1 + sz(t->l);
	if(now == idx)	return t;
	if(idx<now)		find(t->l,idx,temp);
	else			find(t->r,idx,now);
}
void solve(){
	int opr,a,l,b;
	cin >> opr;
	if(opr == 1){
		cin >> a >> l >> b;
		if(b>=a+l)	b-=l;
		pnode p1,p2,p3;	//p1 = before, p2 = in range, p3 = after
		split(root,p1,p3,a+l-1);	//split to 1 -> a+l-1 and a+l -> n
		split(p1,p1,p2,a-1);		//split to 1 -> a-1 and a -> a+l-1
		merge(root,p1,p3);			//merge 1 -> a-1 and a+l -> n
		split(root,p1,p3,b-1);		//split to 1 -> b-1 and b to n
		merge(root,p1,p2);			//merge 1 -> b-1 and a -> a+l-1
		merge(root,root,p3);		//merge 1 -> a+l-1 and b -> n
	}else{
		cin >> a;
		cout << find(root,a)->key << '\n';
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,q = 1,v;
	cin >> n >> q;
	rep(i,0,n){
		cin >> v;
		pnode newnode = new node(v);
		merge(root,root,newnode);
	}
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}