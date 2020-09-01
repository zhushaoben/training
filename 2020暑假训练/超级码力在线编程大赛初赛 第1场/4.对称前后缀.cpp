#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param s: a string.
     * @return: return the values of all the intervals.
     */
    long long suffixQuery(string &s) {
    	int l=s.length()-1;
    	long long ans=0;
    	for(int i=0;i<=l;i++){
    		bool fl=1;int w=0;
    		for(int j=0;j<=i&&i+j<=l;j++){
    			if(s[i-j]!=s[i+j])fl=0,w=0;
    			else{
    				w++;
    				ans+=(fl?w*2-1:w);
				}
			}
		}
		for(int i=0;i<=l;i++){
			bool fl=1;int w=0;
			for(int j=0;j<=i&&i+j+1<=l;j++){
				if(s[i-j]!=s[i+j+1])fl=0,w=0;
				else{
					w++;
					ans+=(fl?w*2:w);
				}
			}
		}
		return ans;
        // write your code here
    }
}A;
int main(){
	string x="aabbaa";
	printf("%lld\n",A.suffixQuery(x));
	return 0;
}
