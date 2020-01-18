#include<bits/stdc++.h>
using namespace std;
#define maxn 5000005
char s[maxn],t[maxn];
int pre[maxn],nex[maxn],NEXT[maxn],co[maxn];
inline void Next(const char a[],int NEXT[],int l){
	for(int i=1,k=0;i<l;i++){
		while(k>0&&a[i]!=a[k]){
			k=NEXT[k-1];
		}
		if(a[i]==a[k])k++;
		NEXT[i]=k;
	}
}
int del(int x,int k){
	int now=x;
	for(int i=0;i<k;i++)now=pre[now];
	pre[x+1]=now,nex[now]=nex[x];
	return now?co[now-1]:0;
}
inline void kmp(const char a[],const char b[],int NEXT[],int l1,int l2){
	for(int i=0,q=0;i<l1;i++){
		while(q>0&&b[q]!=a[i])q=NEXT[q-1];
		if(b[q]==a[i])q++;
		co[i]=q;
		if(q==l2){
			q=del(i+1,l2);
		}
	}
}
void work(){
	int l1=strlen(s),l2=strlen(t);
	for(int i=0;i<l2;i++){nex[i]=i+1,pre[i+1]=i;}nex[l2]=0;
	Next(s,NEXT,l1);
	kmp(t,s,NEXT,l2,l1);
	for(int i=nex[0];i;i=nex[i])putchar(t[i-1]);
	puts("");
}
int main(){
	while(~scanf("%s%s",s,t))work();
	return 0;
}
