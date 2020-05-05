#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char s[maxn];
void work(){
	scanf("%s",s);
	int ans=0,l=strlen(s);
	for(int i=0;s[i];i++)if(s[i]=='0')ans++;
	for(int i=0;s[i];i++){
		if(s[i]=='1')break;
		ans--;
	}
	for(int i=l-1;~i;i--){
		if(s[i]=='1')break;
		ans--;
	}
	printf("%d\n",max(ans,0));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
