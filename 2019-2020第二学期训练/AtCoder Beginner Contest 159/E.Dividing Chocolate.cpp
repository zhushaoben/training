#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char s[10][N];
int a[10],sum[10],num[10];
int main(){
	int n,m,s1,ans=1e9,K;scanf("%d%d%d",&n,&m,&K),s1=1<<(n-1);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<s1;i++){
		int w=0,w1=0;for(int j=0;j<n;j++){a[j]=w;if(i&(1<<j))w++;}
		bool fl,fl1;memset(sum,0,sizeof(sum));
		for(int k=0;k<m;k++){
			memset(num,0,sizeof(num));
			for(int j=0;j<n;j++)num[a[j]]+=s[j][k]=='1';
			fl=0,fl1=0;
			for(int j=0;j<=w;j++){
				if((sum[j]+=num[j])>K){fl=1;}
				if(num[j]>K){fl1=1;break;}
			}
			if(fl1)break;
			if(fl){w1++;for(int j=0;j<=w;j++)sum[j]=num[j];}
		}
		if(fl1)continue;
		ans=min(ans,w+w1);
	}
	printf("%d",ans);
	return 0;
}
