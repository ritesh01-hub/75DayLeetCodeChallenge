class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long tt = t;
        int e2=0,e3=0,e5=0,e7=0;
        while(tt%2==0){tt/=2;e2++;}
        while(tt%3==0){tt/=3;e3++;}
        while(tt%5==0){tt/=5;e5++;}
        while(tt%7==0){tt/=7;e7++;}
        if(tt!=1) return "-1";

        // dp[i][j] = min extra digits (from {2,3,4,6,8,9}) to reach 2-exp>=i and 3-exp>=j
        vector<vector<int>> dp(e2+1, vector<int>(e3+1, 0));
        static const int opts[6][2] = {{1,0},{0,1},{2,0},{1,1},{3,0},{0,2}};
        for(int i=0;i<=e2;i++){
            for(int j=0;j<=e3;j++){
                if(i==0&&j==0){ dp[i][j]=0; continue; }
                int best=INT_MAX;
                for(auto &o:opts){
                    int ni=max(0,i-o[0]), nj=max(0,j-o[1]);
                    if(ni==i && nj==j) continue;
                    if(dp[ni][nj]==INT_MAX) continue;
                    best=min(best, dp[ni][nj]+1);
                }
                dp[i][j]=best;
            }
        }

        auto digitExp = [&](int d, int &dx2,int &dx3,int &dx5,int &dx7){
            dx2=dx3=dx5=dx7=0;
            switch(d){
                case 2: dx2=1;break;
                case 3: dx3=1;break;
                case 4: dx2=2;break;
                case 5: dx5=1;break;
                case 6: dx2=1;dx3=1;break;
                case 7: dx7=1;break;
                case 8: dx2=3;break;
                case 9: dx3=2;break;
                default: break;
            }
        };

        auto feasible = [&](long long m, int r2,int r3,int r5,int r7)->bool{
            if(r5<0) r5=0;
            if(r7<0) r7=0;
            long long forced = (long long)r5 + r7;
            if(forced> m) return false;
            long long rem = m - forced;
            if(r2<0) r2=0;
            if(r3<0) r3=0;
            if(r2>e2 || r3>e3) return false;
            int need = dp[r2][r3];
            if(need==INT_MAX) return false;
            return (long long)need <= rem;
        };

        auto fillSuffix = [&](long long m, int r2,int r3,int r5,int r7)->string{
            string res; res.resize(m);
            for(long long pos=0; pos<m; pos++){
                long long remPos = m-pos-1;
                for(int d=1; d<=9; d++){
                    int dx2,dx3,dx5,dx7;
                    digitExp(d,dx2,dx3,dx5,dx7);
                    int nr2=max(0,r2-dx2), nr3=max(0,r3-dx3);
                    int nr5=max(0,r5-dx5), nr7=max(0,r7-dx7);
                    if(feasible(remPos, nr2,nr3,nr5,nr7)){
                        res[pos]='0'+d;
                        r2=nr2;r3=nr3;r5=nr5;r7=nr7;
                        break;
                    }
                }
            }
            return res;
        };

        int n = num.size();
        vector<int> pref2(n+1,0), pref3(n+1,0), pref5(n+1,0), pref7(n+1,0);
        for(int i=0;i<n;i++){
            int d=num[i]-'0';
            int dx2,dx3,dx5,dx7;
            digitExp(d,dx2,dx3,dx5,dx7);
            pref2[i+1]=pref2[i]+dx2;
            pref3[i+1]=pref3[i]+dx3;
            pref5[i+1]=pref5[i]+dx5;
            pref7[i+1]=pref7[i]+dx7;
        }

        int z = n;
        for(int i=0;i<n;i++) if(num[i]=='0'){ z=i; break; }

        if(z==n){
            int r2=e2-pref2[n], r3=e3-pref3[n], r5=e5-pref5[n], r7=e7-pref7[n];
            if(r2<=0 && r3<=0 && r5<=0 && r7<=0) return num;
        }

        int imax = (z<n)? z : n-1;
        for(int i=imax; i>=0; i--){
            int pe2=pref2[i], pe3=pref3[i], pe5=pref5[i], pe7=pref7[i];
            int r2=max(0,e2-pe2), r3=max(0,e3-pe3), r5=max(0,e5-pe5), r7=max(0,e7-pe7);
            int digit0 = num[i]-'0';
            for(int d=digit0+1; d<=9; d++){
                int dx2,dx3,dx5,dx7;
                digitExp(d,dx2,dx3,dx5,dx7);
                int nr2=max(0,r2-dx2), nr3=max(0,r3-dx3);
                int nr5=max(0,r5-dx5), nr7=max(0,r7-dx7);
                long long m = n-i-1;
                if(feasible(m, nr2,nr3,nr5,nr7)){
                    string res = num.substr(0,i);
                    res.push_back('0'+d);
                    res += fillSuffix(m, nr2,nr3,nr5,nr7);
                    return res;
                }
            }
        }

        long long Lmin = (long long)e5 + e7 + dp[e2][e3];
        long long L = max((long long)n+1, Lmin);
        return fillSuffix(L, e2, e3, e5, e7);
    }
};