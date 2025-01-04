//1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dijkstra(int start, int n,
                         vector<vector<pair<int, int>>>& graph) {
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node])
                continue;

            // Explore neighbors
            for (auto it : graph[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Build the graph as an adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].emplace_back(to, weight);
            graph[to].emplace_back(from, weight);
        }

        int minReachable = INT_MAX;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            // Get the shortest paths from city `i` using Dijkstra's algorithm
            vector<int> dist = dijkstra(i, n, graph);

            // Count cities reachable within distanceThreshold
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }

            // Update result based on reachableCount and city index
            if (reachableCount < minReachable ||
                (reachableCount == minReachable && i > resultCity)) {
                minReachable = reachableCount;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
