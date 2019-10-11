#include<bits/stdc++.h>
using namespace std;
#define maxn 200
char s[maxn];
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='L'&&i%2==0){puts("No");return 0;}
		else if(s[i]=='R'&&i%2==1){puts("No");return 0;}
	}
	puts("Yes");
	return 0;
}
