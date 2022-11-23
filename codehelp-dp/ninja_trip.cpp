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
//     cout<<"Begining of the outer for loop"<<endl;
    int last = n;
    for(int i = n-1;i >= 0;i--){
        int sum = 1e9;
        for(int j = 0;j < 3 and i < days.size();j++){
            int k = inc_array(i, days, passes[j]);
            sum = min(sum, dp[k]+cost[j]);
//             cout<<"sum->"<<sum<<' '<<"k->"<<k<<' '<<"dp[k]->"<<dp[k]<<'+'<<"cost[j]->"<<cost[j]<<endl;
        }
        while(i+30 < last){
            dp.pop_back();
            last--;
        }
//         cout<<"final sum for "<<i<<" is "<<sum<<endl;
        dp[i] = sum;
    }
//     cout<<"final output"<<endl;
//     for(int i = 0;i<n;i++){
//         cout<<dp[i]<<' ';
//     }
//     cout<<endl;
    return dp[0];
}
int solveMem(vector<int> &cost, vector<int> &days, int i, vector<int> &passes){
    int n = days.size();
    queue<pair<int, int>>month;
    queue<pair<int, int>>week;
    int ans = 0;
    for(int day: days){
        while(!month.empty() and month.front().first + 30 <= day){
            month.pop();
        }
        while(!week.empty() and week.front().first + 7 <= day){
            week.pop();
        }
        
        month.push(make_pair(day, ans+cost[2]));
        week.push(make_pair(day, ans+cost[1]));
        ans = min(ans+cost[0], min(month.front().second, week.front().second));
    }
    return ans;
        
}
int minimumCoins(int n, vector<int> days, vector<int> cost){
    vector<int> passes = {1, 7, 30};
    return solveMem(cost, days, 0, passes);
}