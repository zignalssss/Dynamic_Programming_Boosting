#include<iostream>
using namespace std;
int dp[MAXN];
int solve_recursive(int n){
	if (n  < 0)
		return 0;
	if (n == 0)
		return 1;
	return solve(n-1) + solve(n-3) + solve(n-4);
}

int solve_memoization(int n){
	if (n  < 0)
		return 0;
	if (n == 0)
		return 1;
	if(dp[n] != 0)
		return dp[n];
		
	return dp[n] = solve(n-1) + solve(n-3) + solve(n-4);
}
int solve_tabulation(int n){
	d[0] = 1;
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;
	d[4] = 3;
	for(int i = 5; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-3] + dp[i-5];
	}
	return dp[n];
}
int main(){
	int n;
	cin >> n;
	return 0;
}
