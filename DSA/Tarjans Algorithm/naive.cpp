#include <bits/stdc++.h>

using namespace std;

void dfs(int node, map<int, bool> &visited, vector<set<int>> &adjList)
{
    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (visited[i] == false)
        {
            dfs(i, visited, adjList);
        }
    }
}

vector<vector<int>> find_bridge_nodes(int n, vector<vector<int>> connections)
{
    // first we will make a adjList
    vector<set<int>> adjList(n);
    for (auto i : connections)
    {
        adjList[i[0]].insert(i[1]);
        adjList[i[1]].insert(i[0]);
    }

    vector<vector<int>> ans;

    // now we will start removing nodes one by one and check weather there are
    // nodes in graph which are still not visited and all

    for (auto i : connections)
    {
        map<int, bool> visited;

        adjList[i[0]].erase(i[1]);
        adjList[i[1]].erase(i[0]);

        dfs(0, visited, adjList);

        for (int node = 0; node < n; node++)
        {
            if (visited[node] == false)
            {
                ans.push_back({min(i[0], i[1]), max(i[0], i[1])});
                break;
            }
        }

        adjList[i[0]].insert(i[1]);
        adjList[i[1]].insert(i[0]);
    }

    return ans;
}

void testcase_1()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> ans = {{1, 3}};

    vector<vector<int>> recived_ans = find_bridge_nodes(n, connections);

    bool testcase_pass = true;

    for (auto i : ans)
    {
        if (find(recived_ans.begin(), recived_ans.end(), i) == recived_ans.end())
        {
            testcase_pass = false;
        }
    }

    cout << "TESTCASE 1 PASS -> " << (testcase_pass == true ? "YES" : "NO") << "\n";
}

void testcase_2()
{
    int n = 12;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {5, 8}, {6, 7}, {7, 8}, {9, 11}, {9, 10}, {7, 9}};
    vector<vector<int>> ans = {{3, 4}, {4, 5}, {7, 9}};

    vector<vector<int>> recived_ans = find_bridge_nodes(n, connections);

    bool testcase_pass = true;

    for (auto i : ans)
    {
        if (find(recived_ans.begin(), recived_ans.end(), i) == recived_ans.end())
        {
            testcase_pass = false;
        }
    }

    cout << "TESTCASE PASS -> " << (testcase_pass == true ? "YES" : "NO") << "\n";
}

int main()
{

    testcase_1();
    testcase_2();

    return 0;
}