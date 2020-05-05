#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int main(){
	int n,sum=0,ans=0,l=-1;scanf("%d%s",&n,s);
	for(int i=0;s[i];i++){
		if(s[i]=='(')sum++;
		else sum--;
		if(sum<0&&l==-1)l=i;
		else if(sum==0&&l!=-1)ans+=i-l+1,l=-1;
	}
	if(sum)return puts("-1"),0;
	printf("%d",ans);
	return 0;
} 
