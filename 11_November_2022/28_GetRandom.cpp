// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    RandomizedSet(){}

    bool insert(int val)
    {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> m;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}