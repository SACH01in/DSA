class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for(int nu = 1; nu < n; nu++){
            for(int de = nu +1 ; de < n+1; de++){
                if(gcd(nu,de) == 1){
                    res.push_back(to_string(nu) + "/" + to_string(de));
                }
            }
        }
        return res;
    }
};