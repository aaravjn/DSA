int inc_array(int i, vector<int> &days, int pass){
    int j = i;
    while(pass+days[i] > days[j] and j < days.size()){
        j++;
    }
    return j;
}
int solve(vector<int> &cost, vector<int> &days, int i, vector<int> &passes, vector<int> &dp){
    if(i >= days.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int sum = 1e9;
    for(int j = 0;j < 3 and i < days.size();j++){
        int k = inc_array(i, days, passes[j]);
        sum = min(sum, solve(cost, days, k, passes, dp)+cost[j]);
    }
    dp[i] = sum;
    return sum;
}
int solveTab(vector<int> &cost, vector<int> &days, int i, vector<int> &passes){
    int n = days.size();
    vector<int> dp(n+1, -1);
    dp[n] = 0;
    for(int i = n-1;i >= 0;i--){
        int sum = 1e9;
        for(int j = 0;j < 3 and i < days.size();j++){
            int k = inc_array(i, days, passes[j]);
            sum = min(sum, dp[k]+cost[j]);
        }
        dp[i] = sum;
    }
    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost){
    vector<int> passes = {1, 7, 30};
    return solveTab(cost, days, 0, passes);
}