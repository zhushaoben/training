#include<bits/stdc++.h>
const int N=2e5+5;
using namespace std; 
char s[N];
int main(){
	int n,num=0,ans=0;scanf("%d%s",&n,s);
	for(int i=0;s[i];i++)num+=(s[i]=='W');
	for(int i=n-1;~i;i--){
		if(!num)break;
		ans+=(s[i]=='R'),num--;
	}
	printf("%d",ans);
	return 0;
}
