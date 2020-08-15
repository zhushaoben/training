#include<bits/stdc++.h>
using namespace std;
const int inf=0x1f1f1f1f;
int f[16][16][1<<15],a[16],n,sum[1<<15];
//f[cnt][pos][s] indicate the minimum value of the last element 
//for set s that have cnt numbers and the last number is on position pos
pair<int,int>pre[16][16][1<<15];
void pop(int x){for(int i=x;i<n;i++)a[i]--;} 
void print(int i,int pos,int s){
	if(!s)return;
	int s1=pre[i][pos][s].first,s2=s^s1;
	for(int i=0;i<n;i++)
		if(i!=pos-1&&s2&(1<<i))printf("%d %d\n",a[i],a[pos-1]),pop(i);
	print(i-1,pre[i][pos][s].second,s1);
}
void work(){
	int s;scanf("%d",&n),s=(1<<n);
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)memset(f[i][j],0x1f,sizeof(int)*s);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=1;i<s;i++)sum[i]=a[__builtin_ctz(i)]+sum[i&(i-1)];
	f[0][0][0]=0;
	for(int i=0;i<n;i++)for(int s1=0;s1<s;s1++){
		for(int pos=0;pos<n;pos++){
			if(f[i][pos][s1]==inf)continue;
			int s2=(s-1)^s1,pos1;
			for(int j=s2;j;j=(j-1)&s2){
				if(sum[j]<=f[i][pos][s1]||(j>>pos)==0)continue;
				pos1=pos+__builtin_ctz(j>>pos)+1;
				if(f[i+1][pos1][s1|j]>sum[j]){
					f[i+1][pos1][s1|j]=sum[j];
					pre[i+1][pos1][s1|j]={s1,pos};
				}
			}
		}
	}
	for(int i=0;i<n;i++)a[i]=i+1;
	for(int i=n;i;i--)for(int j=1;j<=n;j++)if(f[i][j][s-1]!=inf){printf("%d\n",n-i),print(i,j,s-1);return;}
	
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
