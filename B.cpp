#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to count very interesting numbers in a range
int count_very_interesting(int a, int b) {
    int count = 0;
    for (int num = a; num <= b; ++num) {
        string s = to_string(num);
        int even_sum = 0, odd_sum = 0;
        int len = s.length();

        // Calculate sums of digits at even and odd positions
        for (int i = 0; i < len; ++i) {
            int digit = s[i] - '0';
            int position = len - 1 - i;
            if (position % 2 == 0) {
                even_sum += digit;
            } else {
                odd_sum += digit;
            }
        }

        // Check if the number is very interesting
        if (is_prime(even_sum) && !is_prime(odd_sum)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << count_very_interesting(a, b) << endl;
    }
    return 0;
}