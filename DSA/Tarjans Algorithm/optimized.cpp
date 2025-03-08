#include <bits/stdc++.h>

using namespace std;

void dfs(int current_node, int parent_node, int &timer, vector<vector<int>> &ans, vector<int> &time, vector<int> &low, vector<bool> &visited, vector<set<int>> &adj_list)
{
    visited[current_node] = true;

    time[current_node] = low[current_node] = timer;

    timer++;

    for (auto next_node : adj_list[current_node])
    {
        if (next_node == parent_node)
            continue;

        if (visited[next_node] == false)
        {
            dfs(next_node, current_node, timer, ans, time, low, visited, adj_list);
            low[current_node] = min(low[current_node], low[next_node]);

            if (low[next_node] > time[current_node])
            {
                ans.push_back({min(current_node, next_node), max(current_node, next_node)});
            }
        }
        else
        {
            low[current_node] = min(low[current_node], low[next_node]);
        }
    }
}

vector<vector<int>> find_bridge_nodes(int n, vector<vector<int>> connections)
{
    // create a adjList for travelling the nodes effeciently
    vector<set<int>> adj_list(n);

    // creating the time, low and visited matrix according to the algorithm
    vector<int> time(n);
    vector<int> low(n);
    vector<bool> visited(n, false);

    // creating a answer vector
    vector<vector<int>> ans;

    // initially set the timer to 1
    int timer = 1;

    for (auto connection : connections)
    {
        adj_list[connection[0]].insert(connection[1]);
        adj_list[connection[1]].insert(connection[0]);
    }

    dfs(0, -1, timer, ans, time, low, visited, adj_list);

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