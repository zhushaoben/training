#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param triangle: Coordinates of three points
     * @param point: Xiaoqi's coordinates
     * @return: Judge whether you can cast magic
     */
     long long calc(int x1,int y1,int x2,int y2,int x,int y){
     	return 1ll*(x2-x1)*(y-y1)-1ll*(y2-y1)*(x-x1);
	 }
    string castMagic(vector<vector<int>> &triangle, vector<int> &point) {
        // write your code here
        int d=0,e=0;long long x;
		if(1){
			int w,w1;w=(point[0]>triangle[0][0])+(point[0]>triangle[1][0])+(point[0]>triangle[2][0]),w1=(point[0]<triangle[0][0])+(point[0]<triangle[1][0])+(point[0]<triangle[2][0]);
			if(w==3||w1==3)return "No";
			w=(point[1]>triangle[0][1])+(point[1]>triangle[1][1])+(point[1]>triangle[2][1]),w1=(point[1]<triangle[0][1])+(point[1]<triangle[1][1])+(point[1]<triangle[2][1]);
			if(w==3||w1==3)return "No";
		}
		x=calc(triangle[0][0],triangle[0][1],triangle[1][0],triangle[1][1],point[0],point[1]);
		d+=(x>0),e+=(x<0);
		x=calc(triangle[1][0],triangle[1][1],triangle[2][0],triangle[2][1],point[0],point[1]);
		d+=(x>0),e+=(x<0);
		x=calc(triangle[2][0],triangle[2][1],triangle[0][0],triangle[0][1],point[0],point[1]);
		d+=(x>0),e+=(x<0);
		if(d&&e)return "No";
		else return "Yes";
    }
};
int main(){
	return 0;
}
