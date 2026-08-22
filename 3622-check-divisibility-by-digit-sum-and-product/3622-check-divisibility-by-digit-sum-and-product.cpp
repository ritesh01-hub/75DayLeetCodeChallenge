class Solution {
public:

    int sumof(int n){
        int  sum = 0;
        while(n>0){
            int lst = n%10;
            sum += lst;
            n /= 10;
        }

        return sum;
    }

    int pro(int n){
        int prod = 1;

        while(n > 0){
            int lst = n%10;
            prod *= lst;
            n /= 10;
        }

        return prod;
    }
    bool checkDivisibility(int n) {
       int  sumofN = sumof(n);
        int prodofN = pro(n);

        return n%(sumofN + prodofN) ==0;
        // return (n % sumofN == 0 && n % prodofN == 0);
    }
};