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

vector<int> kmp_search(const string& text, const string& pattern) {
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

void solve(const string& text, const string& pattern) {
    vector<int> occurrences = kmp_search(text, pattern);

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
    return 0;
}