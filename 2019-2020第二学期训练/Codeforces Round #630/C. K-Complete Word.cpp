#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int num[N][26];
void work(){
	int n,k;scanf("%d%d%s",&n,&k,s);
	memset(num,0,sizeof(int)*(k+5)*26);
	for(int i=0;s[i];i++)num[i%k][s[i]-'a']++;
	int ans=0;n/=k;
	for(int i=0;i<(k+1)/2;i++){
		if(i*2==k-1){
			int w=0;
			for(int j=0;j<26;j++)w=max(w,num[i][j]);
			ans+=n-w;
		}
		else{
			int w=0;
			for(int j=0;j<26;j++)w=max(w,num[i][j]+num[k-i-1][j]);
			ans+=2*n-w;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
