// 2327. Number of People Aware of a Secret
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/


#define ll long long
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
     vector<ll> v(n+1,0);//v[i] will store how many person knows the secret on ith day
        
        
        
        v[0] = 1; //only 1 person knows the secret on day 1
        int mod = 1000000007;
        for(int i =0 ;i < n;i ++)// for each day (i) the persons who knows the secret on that day will start spreading it from (i+delay)th day
        {
            if(v[i] == 0)//no one knows a secret
                continue;
            for(int j = i + delay;j < n && (j-i)  < forget;j++) // it start spreading the secret on  (i+delay)th day til it forgets after (i+forget)th day
            {
                v[j] += v[i];
                v[j] = v[j]%mod;
            }
        }
        
        ll ans = 0;
     
        for(int i = n-1;i >= n-forget;i--)// taking last (forget-1) persons becaause the persons before that would have forgotten till nth day
        {
            ans += v[i];
            ans = ans%mod;
        }
        
        return ans; 
    }
};