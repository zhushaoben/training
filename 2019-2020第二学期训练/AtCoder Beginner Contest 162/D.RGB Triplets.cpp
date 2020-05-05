#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5;
char s[N];
int main(){
	int n,a=0,b=0,c=0;scanf("%d%s",&n,s);
	for(int i=0;s[i];i++){
		if(s[i]=='R')a++;
		else if(s[i]=='G')b++;
		else c++;
	}
	long long ans=1ll*a*b*c;
	for(int i=n/2;i;i--){
		for(int j=0;j+i*2<n;j++){
			if(s[j]!=s[j+i]&&s[j+i]!=s[j+2*i]&&s[j]!=s[j+2*i])ans--;
		}
	}
	printf("%lld",ans);
	return 0;
}
