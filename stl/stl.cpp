#include<bits/stdc++.h>

// priority queue custom comparator
struct Node { int i; };
bool Compare(Node a, Node b) { return a.i < b.i; };

std::priority_queue<Node, std::vector<Node>, decltype(&Compare)> openSet(Compare);

// set custom comparator
auto cmp = [](int a, int b) { return -a < -b; };
std::set<int, decltype(cmp)> s(cmp);

int main() {

}