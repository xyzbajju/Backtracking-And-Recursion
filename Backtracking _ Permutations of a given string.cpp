// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


// here we are keeping the l part fix and then swapping the right portion and then backtrack again

void util(int l, int r, string &s, set<string> &ans) {
    if (l == r) {
        ans.insert(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            util(l + 1, r, s, ans);    
            swap(s[l], s[i]); // backtrack
        }
    }
}

vector<string> find_permutation(string s) {
    int n = s.length();
    set<string> ans_set; // Use a set to store unique permutations
    util(0, n - 1, s, ans_set);
    vector<string> ans(ans_set.begin(), ans_set.end()); // Convert set to vector
    return ans;
}

int main() {
    string s;
    cin >> s;
    vector<string> permutations = find_permutation(s);
    for (const string &perm : permutations) {
        cout << perm << endl;
    }
}




                If we do not pass by reference
//////////////////////////////////////////////////////////////////



#include <bits/stdc++.h>
using namespace std;

void util(int l, int r, string s, set<string> &ans) {
    if (l == r) {
        ans.insert(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            util(l + 1, r, s, ans);
            // No need to swap back since s is passed by value
        }
    }
}

vector<string> find_permutation(string s) {
    int n = s.length();
    set<string> ans_set; // Use a set to store unique permutations
    util(0, n - 1, s, ans_set);
    vector<string> ans(ans_set.begin(), ans_set.end()); // Convert set to vector
    return ans;
}

int main() {
    string s;
    cin >> s;
    vector<string> permutations = find_permutation(s);
    for (const string &perm : permutations) {
        cout << perm << endl;
    }
}
