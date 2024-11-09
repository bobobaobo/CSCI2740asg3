#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Function to perform fast modular exponentiation
long long mod_exp(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate the count of interesting numbers of length n
long long interesting_numbers_count(long long n) {
    long long half_len = n / 2;
    if (n % 2 == 0) {
        return (mod_exp(4, half_len, MOD) * mod_exp(6, half_len, MOD)) % MOD;
    } else {
        return (mod_exp(4, half_len, MOD) * mod_exp(6, half_len + 1, MOD)) % MOD;
    }
}

int main() {
    int q;
    cin >> q;
    vector<long long> results(q);
    for (int i = 0; i < q; ++i) {
        long long n;
        cin >> n;
        results[i] = interesting_numbers_count(n);
    }
    
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}