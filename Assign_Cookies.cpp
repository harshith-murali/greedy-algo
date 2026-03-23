#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        int n = greed.size();
        int m = cookie.size();

        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());

        int i = 0, j = 0;
        int count = 0;

        while(i < n && j < m) {
            if(cookie[j] >= greed[i]) {
                count++;
                i++;
                j++;
            } else {
                j++; // try bigger cookie
            }
        }

        return count;
    }
};

int main() {
    vector<int> greed = {1, 2, 3};
    vector<int> cookie = {1, 1};

    Solution obj;
    cout << obj.maxChildren(greed, cookie);

    return 0;
}