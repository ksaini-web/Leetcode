class Solution {
public:
static const long long MOD=1000000007;
long long helpereven(long long even){
    if(even==0){
        return 1;
    }
    return 5*helpereven( even-1)%MOD;
}
public:
long long helperodd(long long odd){
    if(odd==0){
        return 1;
    }
    return 4*helperodd( odd-1)%MOD;
}
    long long countGoodNumbers(long long n) {
long long even=(n+1)/2;
long long odd=n/2;

return helpereven(even)*helperodd(odd)%MOD;
        
    }
};
