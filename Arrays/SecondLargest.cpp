//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int largest, second;
        if(arr[0]>arr[1]) {
            largest = arr[0];
            second = arr[1];
        } else {
            largest = arr[1];
            second = arr[0];
        }
        for(int i=2;i<arr.size();i++) {
            if(arr[i]>second && arr[i]<largest) {
                second=arr[i];
            } else {
                if(arr[i]>largest) {
                    second = largest;
                    largest=arr[i];
                } else {
                    continue;
                }
            }
        }
        if(largest == second) {
            return -1;
        }
        return second;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends