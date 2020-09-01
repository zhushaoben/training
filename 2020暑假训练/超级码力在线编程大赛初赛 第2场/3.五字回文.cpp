#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	/**
	 * @param s: The given string
	 * @return: return the number of Five-character palindrome
	 */
	int Fivecharacterpalindrome(string &s) {
		// write your code here
		int n=s.size(),r=0;
		for(int i=0;i<n;i++){
			if(i+4>=n) break;
			if(s[i]==s[i+1]||s[i+1]==s[i+2]||s[i]==s[i+2]) continue;
			if(s[i]==s[i+4]&&s[i+1]==s[i+3]) r++;
		}
		return r;
	}
}x;
string a="abcba";
int main(){
	printf("%d",x.Fivecharacterpalindrome(a));
	return 0;
}
