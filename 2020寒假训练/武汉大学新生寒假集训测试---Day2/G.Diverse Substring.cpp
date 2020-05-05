#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char s[maxn];
int main(){
	int n;scanf("%d%s",&n,s+1);
	s[0]=s[1];
	for(int i=1;s[i];i++){
		if(s[i]!=s[i-1]){
			puts("YES");
			printf("%c%c\n",s[i-1],s[i]);return 0;
		}
	}
	puts("NO");
	return 0;
}
