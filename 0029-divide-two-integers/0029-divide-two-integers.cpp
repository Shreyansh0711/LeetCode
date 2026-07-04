class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if (dividend < 0 && divisor > 0)
            sign = false;
        if (dividend >= 0 && divisor < 0)
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        
        long qo = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1)) && (d << (cnt + 1)) >= d)
                cnt++;
            qo += (1LL << cnt);
            n -= (d << cnt);
        }
        if (qo == (1LL << 31) && sign)
            return INT_MAX;
        if (qo == (1LL<< 31) && !sign)
            return INT_MIN;

        return sign ? qo : -qo;
    }
};