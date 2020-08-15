#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=5e6+5;
bitset<N>b[10],ans;
char s[M];
int main(){
	int n,d,x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&d);
		for(int j=0;j<d;j++)scanf("%d",&x),b[x].set(i);
	}
	scanf("%s",s);
	for(int i=0;s[i];i++){
		ans=ans<<1;ans.set(0);
		ans=ans&b[s[i]-'0'];
		if(ans[n-1]==1){
			char c=s[i+1];s[i+1]=0;
			puts(s+i-n+1);
			s[i+1]=c;
		}
	}
	return 0;
}
