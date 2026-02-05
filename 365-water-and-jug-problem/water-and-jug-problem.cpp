class Solution {
public:
    int GCD(int a, int b){
        while (b>0){
            int c = a%b;
            a = b;
            b=c;
        }
        return a;
    }

    bool canMeasureWater(int x, int y, int target) {
        if(target > (x+y)){
            return false;
        }

        if(x == target || y == target || target == (x+y) || target % GCD(x,y) == 0){
            return true;
        } else {
            return false;
        }
    }
};