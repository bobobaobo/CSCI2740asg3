#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> d(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r; 
        
        vector<int> remaining;
        
        // Collect DSIs of subjects not in the range [l, r]
        for (int i = 0; i < n; ++i) {
            if (i < l || i > r) {
                remaining.push_back(d[i]);
            }
        }
        
        int count = 0;
        
        // Count pairs with DSI difference <= t
        for (size_t i = 0; i < remaining.size(); ++i) {
            for (size_t j = i + 1; j < remaining.size(); ++j) {
                if (abs(remaining[i] - remaining[j]) <= t) {
                    ++count;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}