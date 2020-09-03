#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
char s[N];
int main(){
	int num=0;scanf("%s",s);
	for(int i=0;s[i];i++)(num+=s[i]-'0')%=9;
	if(num)puts("No");
	else puts("Yes");
	return 0;
}
