#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
char s[N];
int main(){
	scanf("%s",s);
    int n=strlen(s),x,w=0,q;scanf("%d",&q);
    char op[20];
    while(q--){
        scanf("%s%d",op,&x);
        if(op[0]=='A'){
        	printf("%c\n",s[(x+w-1)%n]);
		}
		else w=(w+x+n)%n;
    }
    return 0; 
}
