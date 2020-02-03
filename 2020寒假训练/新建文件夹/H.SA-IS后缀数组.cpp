#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
char s[maxn];
void work(){
	int n,now=0;scanf("%d%s",&n,s);
	for(int i=0;s[i];i++){
		if(s[i]<s[i+1]){
			while(now<=i&&now<n-1)now++,putchar('<');
		}
		if(s[i]>s[i+1]){
			while(now<=i&&now<n-1)now++,putchar('>');
		}
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
