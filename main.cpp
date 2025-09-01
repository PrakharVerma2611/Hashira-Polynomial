#include <bits/stdc++.h>
using namespace std;

// Function to convert a string number of given base into decimal
long long convertToDecimal(const string &value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c))
            digit = c - '0';
        else if (isalpha(c))
            digit = tolower(c) - 'a' + 10; // handles bases > 10
        else
            continue;
        result = result * base + digit;
    }
    return result;
}

// Function to multiply polynomials by (x - root)
vector<long long> multiplyPoly(vector<long long> &poly, long long root) {
    int n = poly.size();
    vector<long long> newPoly(n + 1, 0);

    for (int i = 0; i < n; i++) {
        newPoly[i] += poly[i];              // coefficient for x^i
        newPoly[i + 1] += -root * poly[i];  // multiply with (x - root)
    }
    return newPoly;
}

int main() {
    // -------------------------------
    // You can switch between testcases here
    // -------------------------------

    // ---- Testcase 1 ----
    /*
    int n = 4, k = 3;
    vector<pair<int, string>> inputRoots = {
        {10, "4"},
        {2, "111"},
        {10, "12"},
        {4, "213"}
    };
    */

    // ---- Testcase 2 ----
    int n = 10, k = 7;
    vector<pair<int, string>> inputRoots = {
        {6, "13444211440455345511"},
        {15, "aed7015a346d635"},
        {15, "6aeeb69631c227c"},
        {16, "e1b5e05623d881f"},
        {8, "316034514573652620673"},
        {3, "2122212201122002221120200210011020220200"},
        {3, "20120221122211000100210021102001201112121"},
        {6, "20220554335330240002224253"},
        {12, "45153788322a1255483"},
        {7, "1101613130313526312514143"}
    };

    // ---- STEP 1: Convert first k roots to decimal ----
    vector<long long> roots;
    for (int i = 0; i < k; i++) {
        roots.push_back(convertToDecimal(inputRoots[i].second, inputRoots[i].first));
    }

    // ---- STEP 2: Construct polynomial ----
    vector<long long> poly = {1}; // start with P(x) = 1

    for (long long root : roots) {
        poly = multiplyPoly(poly, root);
    }

    // ---- STEP 3: Print coefficients ----
    cout << "Polynomial coefficients (descending powers of x):\n";
    reverse(poly.begin(), poly.end());
    for (long long coeff : poly) {
        cout << coeff << " ";
    }
    cout << endl;

    return 0;
}
