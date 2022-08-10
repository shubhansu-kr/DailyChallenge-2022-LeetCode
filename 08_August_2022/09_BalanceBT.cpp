// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (end <= start)return NULL;
        int midIdx = (end + start) / 2;
        TreeNode *root = new TreeNode(nums[midIdx]);
        root->left = sortedArrayToBST(nums, start, midIdx);
        root->right = sortedArrayToBST(nums, midIdx + 1, end);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};
class Solution
{
    // Wrong Solution
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return createTree(nums, n / 2);
    }

    TreeNode *createTree(vector<int> &nums, int i)
    {
        if (i == -1 || i == nums.size())
            return nullptr;

        TreeNode *p = new TreeNode(nums[i]);
        if (i <= nums.size() / 2)
        {
            p->left = createTree(nums, i - 1);
        }
        if (i >= nums.size() / 2)
        {
            p->right = createTree(nums, i + 1);
        }

        return p;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}