class Solution {
public:
	static const int N=5e4;
    int n, m, num[N+5], mx[N+5], mn[N+5];
    int lowbit(int x) {
    	return x & (-x);
	}
    void upd(int x) {
    	for(int i=x; i<=N; i+=lowbit(i)) {
    		mx[i] = num[i]; mn[i] = num[i];
    		for(int j=1; j<lowbit(i); j<<=1) {
    			mx[i] = max(mx[i], mx[i-j]);
    			mn[i] = min(mn[i], mn[i-j]);
			}
		}
	}
	int qry(int l1, int r1, int l2, int r2) {
		int ans = 0, s = 0;
		while(l1 <= r1) {
			s = max(s, num[r1]);
			r1--;
			for(; r1-lowbit(r1) >= l1; r1-=lowbit(r1)) {
				s = max(s, mx[r1]);
			}
		}
		ans += s; s = 1e9;
		while(l2 <= r2) {
			s = min(s, num[r2]);
			r2--;
			for(; r2-lowbit(r2) >= l2; r2-=lowbit(r2)) {
				s = min(s, mn[r2]);
			}
		}
		ans += s;
		return ans;
	}
    int Intervalxor(vector<int> &b, vector<vector<int>> &ask) {
    	n = b.size(); m = ask.size();
    	for(int i=0; i<=N; i++) {
    		mx[i] = 0; mn[i] = 1e9;
		}
		for(int i=0; i<n; i++) {
			num[i+1] = b[i];
		}
    	for(int i=0; i<n; i++) {
    		upd(i + 1);
		}
		int ans = 0;
		for(int i=0; i<m; i++) {
			int l1 = ask[i][0], r1 = ask[i][1], l2 = ask[i][2], r2 = ask[i][3];
			ans ^= qry(l1, r1, l2, r2);
		}
		return ans;
    }
};
