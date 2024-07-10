// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


//             | Approach 1 |
/////////////////////////////////////////////////////////////////


void util(int ind , string s , int n , string &f){
	//we passed f by reference so we need to backtrack it as well
	if(ind == n){cout<<f<<endl;return;}
	f  = f + s[ind];   // adding the string to f
    util(ind+1 , s , n , f);  
	f.pop_back(); //backtracking 
    util(ind+1 , s , n, f);  // and then exploring again
}

int main() {
	string s;
	cin>>s;
	int n= s.length();
	string f= "";
	util(0 ,s , n , f);

}


//             | Approach 2 |
/////////////////////////////////////////////////////////////////

void util(int ind, string s, int n, string f) {
    if (ind == n) {
        cout << f << endl;
        return;
    }
    // we have passed f by value not by reference
    util(ind + 1, s, n, f + s[ind]); // include the current character
    util(ind + 1, s, n, f); // exclude the current character
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    string f = "";
    util(0, s, n, f);
}

