class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){return 1.0;}
        if(x==0){return 0;}
        if(x==1){return 1.0;}
        if(x==-1&&n%2==0){return 1.0; }
        if(x==-1&&n%2!=0){return -1.0;}

        long binary=n;

        if(n<0){
            x=1/x;
            binary=-binary;
        }

        double ans=1;

        while(binary>0){
            if(binary%2==1){
                ans*=x;
            }
            x*=x;
            binary/=2;}

        
        return ans;
        
    }
};
