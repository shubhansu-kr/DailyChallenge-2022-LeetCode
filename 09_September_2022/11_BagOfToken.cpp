// https://leetcode.com/problems/bag-of-tokens/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, points = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                res = max(res, ++points);
            } else if (points > 0) {
                points--;
                power += tokens[j--];
            } else {
                break;
            }
        }
        return res;
    }
};

class Solution {
    // BruteForce: Recursion 
    // WA: We can play token in any order
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = INT_MIN, score = 0; 
        solve(tokens, ans, score, power);
        return ans;
    }
    void solve(vector<int> &tokens, int &ans, int score, int power, int i=0) {
        if (i == tokens.size()) {
            ans = max(ans, score);
            return;
        }

        // Play Up: +1 score 
        if (power >= tokens[i]) solve(tokens, ans, score+1, power-tokens[i], i+1);
        // Play Down: -1 score
        if (score > 0) solve(tokens, ans, score-1, power+tokens[i], i+1);
        // NoPlay: 0
        solve(tokens, ans, score, power, i+1);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}