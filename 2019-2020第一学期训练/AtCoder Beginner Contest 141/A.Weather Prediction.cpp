#include<bits/stdc++.h>
using namespace std;
char s[3][10]={"Sunny","Cloudy","Rainy"},s1[10];
int main(){
	scanf("%s",s1);int x;
	for(int i=0;i<3;i++)if(s1[0]==s[i][0])x=i;
	printf("%s",s[(x+1)%3]);
	return 0;
} 
