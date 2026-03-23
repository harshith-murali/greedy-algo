#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int n = arr.size();
        int cntFives = 0, cntTens = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] == 5) {
                cntFives++;
            }
            else if(arr[i] == 10) {
                if(cntFives > 0) {
                    cntFives--;
                    cntTens++;
                } else return false;
            }
            else { // arr[i] == 20
                if(cntTens > 0 && cntFives > 0) {
                    cntTens--;
                    cntFives--;
                }
                else if(cntFives >= 3) {
                    cntFives -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> arr = {5,5,5,10,20};
    Solution obj;
    cout << obj.canServe(arr); // 1 (true)
    return 0;
}