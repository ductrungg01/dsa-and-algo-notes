#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) 
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) 
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

// KMP search algorithm to find all occurrences of a pattern in a text
// This version uses the prefix function on the concatenated string "pattern#text" to find occurrences of the pattern in the text. It is a straightforward implementation that leverages the properties of the prefix function to efficiently locate matches.
vector<int> kmp_search_1(const string& text, const string& pattern) {
    string combined = pattern + "#" + text;
    vector<int> pi = prefix_function(combined);

    // for (int i = 0; i < (int)pi.size(); i++) 
    // {
    //     cout << pi[i] << " ";
    // }
    // cout << endl;
    
    int pattern_length = (int)pattern.length();

    vector<int> occurrences;

    for (int i = 0; i < (int)pi.size(); i++) 
    {
        if (pi[i] == pattern_length) 
        {
            occurrences.push_back(i - 2 * pattern_length);
        }
    }

    return occurrences;
}

// KMP search algorithm to find all occurrences of a pattern in a text
// This version uses the prefix function directly on the text and pattern without concatenation
// It is more efficient in terms of space and avoids the need for a separator character 
// Incase search multiple patterns in a single text. It is also more efficient in terms of time complexity, as it avoids the overhead of concatenation and the additional loop to find occurrences.
vector<int> kmp_search_2(const string& text, const string& pattern) {
    int n = (int)text.length();
    int m = (int)pattern.length();
    vector<int> pi = prefix_function(pattern);

    // for (int i = 0; i < (int)pi.size(); i++) 
    // {
    //     cout << pi[i] << " ";
    // }
    // cout << endl;

    vector<int> occurrences;
    int j = 0; // index for pattern

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    return occurrences;
}

void compress_a_string(const string& s){
    vector<int> pi = prefix_function(s);
    int n = (int)s.length();
    int k = n - pi[n - 1]; // Length of the smallest repeating unit, detailed explanation: https://cp-algorithms.com/string/prefix-function.html#compressing-a-string

    if (n % k == 0) {
        cout << "The string can be compressed to: " << s.substr(0, k) << endl;
        cout << "Number of repetitions: " << n / k << endl;
    } else {
        cout << "The string cannot be compressed." << endl;
    }
}

void solve(const string& text, const string& pattern) {
    vector<int> occurrences = kmp_search_2(text, pattern);

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Number of occurrences: " << occurrences.size() << endl;
    cout << "Pattern found at indices: ";
    for (int idx : occurrences) {
        cout << idx << " ";
    }
    cout << endl << endl;
}

int main(){
    solve("ABABDABACDABABCABCABCABCABABCABCABCUABABCABCABC", "ABABCABCABC"); // Result should be: 10, 24, 36
    solve("AAAA", "AA");                                                     // Result should be: 0, 1, 2
    compress_a_string("ABABABAB");                                            // Result should be: AB, 4
    return 0;
}