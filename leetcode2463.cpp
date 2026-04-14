class Solution {
public:

using ll = long long ;
const ll INF = 4e14;

ll solve(int i ,int j , vector<int>& robot, vector<vector<int>>& factory,vector<vector<ll>>& dp){

    int n = robot.size();
    int m = factory.size();

    if(i == n) return 0;
    if(j == m ) return INF;

    if(dp[i][j] != -1) return dp[i][j];

    ll ans = solve(i,j+1,robot,factory,dp);

    ll cost =0 ;
    int pos = factory[j][0];
    int limit = factory[j][1];


    for(int k = 1; k<= limit && i+k-1 <n ; k++){
      cost+= abs((ll)robot[i+k-1]-pos)  ;

     ans = min(ans ,cost+solve(i+k,j+1,robot,factory,dp));
    }
    return dp[i][j] = ans ;


}








    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());


        int n = robot.size();
        int m = factory.size();

        vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));


        return solve(0,0,robot,factory,dp);



        
        
    }
};
