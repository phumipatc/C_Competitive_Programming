#include <stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *l,*r;
};
typedef struct node *ptr;
ptr root;
int numm;

void find(ptr nod){
	while(1){
		while(nod->num < numm && nod->r!=NULL){
			nod=nod->r;
			printf("R");
		}
		while(nod->num > numm && nod->l!=NULL){
			nod=nod->l;
			printf("L");
		}
		if(nod->num < numm && nod->r == NULL){
			ptr temp;
			temp=(ptr)malloc(sizeof(struct node));
			temp->num=numm;
			temp->r=NULL;
			temp->l=NULL;
			nod->r=temp;
			printf("R");
			break;
		}
		if(nod->num > numm && nod->l == NULL){
			ptr temp;
			temp=(ptr)malloc(sizeof(struct node));
			temp->num=numm;
			temp->r=NULL;
			temp->l=NULL;
			nod->l=temp;
			printf("L");
			break;
		}
	}
}

int main(void){
	root=(ptr)malloc(sizeof(struct node));
	root->r=NULL;
	root->l=NULL;
	int n;
	scanf("%d %d",&n,&numm);
	root->num=numm;
	printf("*\n");
	while(--n){
		scanf("%d",&numm);
		find(root);
		printf("*\n");
	}
	return 0;
}
