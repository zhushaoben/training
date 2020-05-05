#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
char s[maxn];
void work(){
	int now=1,pre=0;
	for(int i=0;s[i];i++){
		if(s[i]<='Z'&&s[i]>='A'){
			s[i]=((s[i]-'A')+now)%26+'A';
			swap(pre,now),now=now+pre%26;
		}
	}
	puts(s);
}
int main(){
	while(gets(s)!=NULL)work();
	return 0;
} 
