#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());

        long long wt = 0, t = 0;

        for(int i = 0; i < n; i++) {
            wt += t;
            t += bt[i];
        }

        return wt / n;
    }
};

int main() {
    vector<int> bt = {4, 3, 7, 1, 2};
    Solution obj;
    cout << obj.solve(bt);
    return 0;
}