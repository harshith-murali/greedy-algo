#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return 0;
        if(arr[0] == 0) return -1;

        int jumps = 0;
        int l = 0, r = 0;

        while(r < n - 1){
            int farthest = 0;

            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + arr[i]);
            }

            // 🚨 can't move forward
            if(farthest <= r) return -1;

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2,3,1,1,4};
    cout << obj.minJumps(arr);
}