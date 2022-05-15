# ADSA_assignment1

PRIMS algo :

Compilation command : g++ -std=c++11 Prims.cpp -o prims
Run Command : ./prims

Input : Adajency matrix as below with 6 vertices

    int graph[V][V] = { { 0, 3, 0, 0, 6, 5 },
                        { 3, 0, 1, 0, 0, 4 },
                        { 0, 1, 0, 6, 0, 4 },
                        { 0, 0, 6, 0, 8, 5 },
                        { 6, 0, 0, 8, 0, 2 },
                        { 5, 4, 4, 5, 2, 0 } };

Output:
Edge    Weight
0 - 1   3
1 - 2   1
5 - 3   5
5 - 4   2
1 - 5   4

Krushkals :

Compilation command :  g++ -std=c++11 Krushkal.cpp -o Krushkal
Run Command :  ./Krushkal

Input : Adjacency list is taken as input 

Following are the edges in the Input Graph
0 -- 1 == 10
0 -- 2 == 6
0 -- 3 == 5
1 -- 3 == 15
2 -- 3 == 4

Output :

Following are the edges in the constructed MST
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10