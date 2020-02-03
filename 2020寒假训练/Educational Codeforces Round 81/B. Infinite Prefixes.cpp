#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn];
int num[maxn*2];
void work(){
	int n,k,now=maxn;scanf("%d%d%s",&n,&k,s),k+=maxn;
	for(int i=0;s[i];i++){
		num[now]++;
		if(s[i]=='0')now++;
		else now--;
	}
	long long ans=0;
	if(now==maxn)ans=(k<0||k>=maxn*2)?0:(num[k]?-1:0);
	else if(now>maxn){
		if(k>=maxn*2)k=(k-maxn*2)%(now-maxn)+maxn*2-(now-maxn);
		while(k>=0)ans+=num[k],k-=(now-maxn);
	}
	else{
		if(k<0)k=k%(maxn-now)+(maxn-now);
		while(k<maxn*2)ans+=num[k],k+=(maxn-now);
	}
	now=maxn;for(int i=0;s[i];i++){
		num[now]--;
		if(s[i]=='0')now++;
		else now--;
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
