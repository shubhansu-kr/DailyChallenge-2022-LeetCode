// https://leetcode.com/problems/the-skyline-problem/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        multiset<int> st;
        map<int, vector<int> > mp;
        for(auto &b: buildings){mp[b[0]].push_back(b[2]);mp[b[1]].push_back(-b[2]);}
        vector<vector<int> > ans;
        for(auto& [c,vec] : mp){
            for(auto &x: vec){if(x > 0){st.insert(x);}else{st.erase(st.lower_bound(-x));}}            
            int val = st.empty() ? 0 : *st.rbegin();
            if(ans.empty() || (ans.size() && ans.back()[1] != val)){ans.push_back({c, val});}
        }
        return ans;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int> coords;
		for (const vector<int> & building : buildings) {
			coords.emplace(building[0], building[2]);
			coords.emplace(building[1], -building[2]);
		}

		multiset<int> heights = { 0 };
		vector<pair<int, int>> corners;
		int x = -1;
		int y = 0;
		for (const pair<int, int> & p : coords) {
			if ((x >= 0) && (p.first != x) && (corners.empty() || (corners.rbegin()->second != y))) {
				corners.emplace_back(x, y);
			}

			if (p.second >= 0) {
				heights.insert(p.second);
			}
			else {
				heights.erase(heights.find(-p.second));
			}

			x = p.first;
			y = *heights.rbegin();
		}
		
		if (!corners.empty()) {
			corners.emplace_back(x, 0);
		}
		
		return corners;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}