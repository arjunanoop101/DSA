// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            return 1/f(x,-N);
        }
        else{
            return f(x,N);
        }
    }

    double f(double x, int N){
        if(N==0){
            return 1;
        }
        double res = f(x,N/2);
        if(N%2 ==0){
            return res * res;
        }
        else{
            return x * res * res;
        }
    }
};