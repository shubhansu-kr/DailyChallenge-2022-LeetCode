// https://leetcode.com/problems/word-ladder-ii/

// A transformation sequence from word beginWord to word endWord
// using a dictionary wordList is a sequence of words beginWord ->
// s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does
// not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList,
// return all the shortest transformation sequences from beginWord to
// endWord, or an empty list if no such sequence exists. Each sequence
// should be returned as a list of the words [beginWord, s1, s2, ..., sk].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool able(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int c = 0;
        for (int i = 0; i < s.length(); i++)
            c += (s[i] != t[i]);
        return c == 1;
    }
    void bfs(vector<vector<int>> &g, vector<int> parent[], int n, int sr, int ds)
    {
        vector<int> dist(n, 1005);
        queue<int> q;
        q.push(sr);
        parent[sr] = {-1};
        dist[sr] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int u : g[x])
            {
                if (dist[u] > dist[x] + 1)
                {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                    parent[u].clear();
                    parent[u].push_back(x);
                }
                else if (dist[u] == dist[x] + 1)
                    parent[u].push_back(x);
            }
        }
    }
    void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[], int node)
    {
        if (node == -1)
        {
            Paths.push_back(path);
            return;
        }
        for (auto u : parent[node])
        {
            path.push_back(u);
            shortestPaths(Paths, path, parent, u);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size(), sr = -1, ds = -1;
        vector<vector<string>> ANS;
        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == beginWord)
                sr = i;
            if (wordList[i] == endWord)
                ds = i;
        }
        if (ds == -1)
            return ANS;
        if (sr == -1)
        {
            wordList.emplace(wordList.begin(), beginWord);
            sr = 0;
            ds++;
            n++;
        }
        vector<vector<int>> g(n, vector<int>()), Paths;
        vector<int> parent[n], path;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (able(wordList[i], wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        bfs(g, parent, n, sr, ds);
        shortestPaths(Paths, path, parent, ds);
        for (auto u : Paths)
        {
            vector<string> now;
            for (int i = 0; i < u.size() - 1; i++)
                now.push_back(wordList[u[i]]);
            reverse(now.begin(), now.end());
            now.push_back(wordList[ds]);
            ANS.push_back(now);
        }
        return ANS;
    }
};

class Solution
{
    // MLE
public:
    vector<vector<string>> findLadders(const string &beginWord, const string &endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // to check if a word is existed in the wordSet, in O(1)
        wordSet.erase(beginWord);

        unordered_map<string, vector<vector<string>>> level;
        level[beginWord] = {{beginWord}}; // level[word] is all possible sequence paths which start from beginWord and end at `word`.
        while (!level.empty())
        {
            unordered_map<string, vector<vector<string>>> newLevel;
            for (const auto &[word, paths] : level)
            {
                if (word == endWord)
                    return level[word]; // return all shortest sequence paths
                for (const string &nei : neighbors(word, wordSet))
                {
                    for (auto path : paths)
                    {
                        path.push_back(nei); // form new paths with `nei` word at the end
                        newLevel[nei].push_back(path);
                    }
                }
            }
            for (const auto &[word, _] : newLevel)
                wordSet.erase(word); // remove visited words to prevent loops
            level.swap(newLevel);    // move to new level
        }
        return {};
    }
    vector<string> neighbors(const string &word, const unordered_set<string> &wordSet)
    {
        vector<string> ans;
        for (int i = 0; i < word.size(); ++i)
        { // change every possible single letters and check if it's in wordSet
            for (char c = 'a'; c <= 'z'; ++c)
            {
                string newWord = word.substr(0, i) + c + word.substr(i + 1);
                if (!wordSet.count(newWord))
                    continue;
                ans.push_back(newWord);
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}