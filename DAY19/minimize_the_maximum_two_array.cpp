// 2513. Minimize the Maximum of Two Arrays
// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long ans=INT_MAX;
        long long low=1,high=INT_MAX;
        while(low<=high){
            long long mid=(low+high)/2;
            long long c1=mid-mid/divisor1;
            long long c2=mid-mid/divisor2;
            long long temp=mid-mid/(((long long)divisor1*divisor2)/__gcd(divisor1,divisor2));
            if(c1>=(long long)uniqueCnt1 and c2>=(long long)uniqueCnt2 and temp>=uniqueCnt1+uniqueCnt2){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};