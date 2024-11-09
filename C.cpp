#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_SUM = 90; // Maximum possible sum of digits
bool is_prime[MAX_SUM + 1];
int dp[10][MAX_SUM][MAX_SUM][2];

// Function to precompute prime numbers
void precompute_primes() {
    fill(is_prime, is_prime + MAX_SUM + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_SUM; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_SUM; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Digit DP function
int digit_dp(const string &num, int pos, int even_sum, int odd_sum, bool tight) {
    if (pos == -1) {
        return is_prime[even_sum] && !is_prime[odd_sum];
    }

    if (dp[pos][even_sum][odd_sum][tight] != -1) {
        return dp[pos][even_sum][odd_sum][tight];
    }

    int limit = tight ? (num[num.size() - 1 - pos] - '0') : 9;
    int result = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        if (pos % 2 == 0) {
            result += digit_dp(num, pos - 1, even_sum + digit, odd_sum, tight && (digit == limit));
        } else {
            result += digit_dp(num, pos - 1, even_sum, odd_sum + digit, tight && (digit == limit));
        }
    }

    return dp[pos][even_sum][odd_sum][tight] = result;
}

// Function to calculate very interesting numbers up to a given number
int count_up_to(int n) {
    string num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return digit_dp(num, num.size() - 1, 0, 0, true);
}

// Function to count very interesting numbers in a range [a, b]
int count_very_interesting(int a, int b) {
    return count_up_to(b) - count_up_to(a - 1);
}

int main() {
    precompute_primes();

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << count_very_interesting(a, b) << endl;
    }

    return 0;
}