#ifndef N_2_HOP_LABELS_H
#define N_2_HOP_LABELS_H

#include <iostream>
#include <fstream>

#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <string>

#include <time.h>

using namespace std;

struct Edge {
    int headVex, tailVex;
    Edge *headLink, *tailLink;

    Edge(int headVex, int tailVex) {
        this->headVex = headVex;
        this->tailVex = tailVex;
        this->headLink = this->tailLink = nullptr;
    }
};

struct Node {
    bool tarjan;
    bool bfs;
    bool reverse_bfs;
    int data;
    vector<int> inNodes, outNodes;
    Edge *firIn, *firOut;

    Node(int data) {
        this->data = data;
        this->tarjan = this->bfs = this->reverse_bfs = false;
        this->firIn = this->firOut = nullptr;
    }
};

struct Graph {
    int nodeNum, edgeNum;
    map<string, int> numberMap;
    map<int, string> nameMap;
    map<int, Node*> nodes;
} graph;


void tarjan(Node*, map<int, int>&, map<int, int>&, stack<int>&, vector<vector<int>>&, map<int, bool>&);
void combine_scc_node(vector<vector<int>>&);
bool query(int outNodeNum, int inNodeNum);
void search_out_node(Node*);
void search_in_node(Node*);


inline void insert_edge(Node* node, Edge* edge)
{
    Edge *last_edge = node->firOut;
    node->firOut = edge;
    edge->headLink = last_edge;
}

inline void insert_reverse_edge(Node* node, Edge* edge)
{

    Edge *last_edge = node->firIn;
    node->firIn = edge;
    edge->tailLink = last_edge;
}

inline Node* init_inexistent_node(int nodeNum)
{
    if (graph.nodes[nodeNum] == nullptr) {
        graph.nodes[nodeNum] = new Node(nodeNum);
    }

    return graph.nodes[nodeNum];
}

#endif //N_2_HOP_LABELS_H

