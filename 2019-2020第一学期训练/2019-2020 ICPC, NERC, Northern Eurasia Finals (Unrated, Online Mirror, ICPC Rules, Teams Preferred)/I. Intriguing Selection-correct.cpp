#include<bits/stdc++.h>
using namespace std;
#define maxn 205
char res[20];
int a[maxn],b[maxn];
bool cmp(int a,int b){
	printf("? %d %d\n",a,b),fflush(stdout);
	scanf("%s",res);
	return res[0]=='>';
}
void insert(int x,int a[],int &si){
	for(int i=0;i<si-1;i++){
		if(!cmp(a[i],x)){
			for(int j=si-1;j>i;j--)a[j]=a[j-1];
			a[i]=x;return;
		}
	}
	a[si-1]=x;
}
void work(){
	int n,as=0,bs=0;scanf("%d",&n);
	for(int i=1;i<=(n+1)/2;i++)a[as++]=i;
	for(int i=(n+1)/2+1;i<=n+1;i++)b[bs++]=i;
	sort(a,a+as,cmp);sort(b,b+bs,cmp);
	for(int i=n+2;i<=2*n;i++){
		if(!cmp(a[as-1],b[bs-1]))insert(i,a,as);
		else insert(i,b,bs);
	}
	cmp(a[as-1],b[bs-1]);
	printf("!\n"),fflush(stdout);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
