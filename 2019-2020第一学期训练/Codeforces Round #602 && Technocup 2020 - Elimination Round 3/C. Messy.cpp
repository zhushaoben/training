#include<bits/stdc++.h>
using namespace std;
#define maxn 2000
char s[maxn+5],s1[maxn+5];
int a[maxn+5],b[maxn+5],ans;
void rev(int i,int j){while(i<j)swap(s[i],s[j]),i++,j--;}
void work(){
	int n,k;ans=0;scanf("%d%d%s",&n,&k,s);
	for(int i=0;i<k-1;i++)s1[i<<1]='(',s1[i<<1|1]=')';
	for(int i=(k-1)<<1;i<n/2+k-1;i++)s1[i]='(';
	for(int i=n/2+k-1;i<n;i++)s1[i]=')';
	for(int i=0,j;i<n;i++){
		if(s1[i]!=s[i]){
			for(j=i+1;j<n;j++)if(s[j]==s1[i]){break;}
			a[ans]=i+1,b[ans++]=j+1,rev(i,j);
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)printf("%d %d\n",a[i],b[i]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
