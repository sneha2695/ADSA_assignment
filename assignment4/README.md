# ADSA_assignment4

Djiskstra 

Compilation command:  g++ -std=c++11 djikstra.cpp -o djiksta
Run command: ./djiksta


Input : Using Matrix as input 

 int graph[V][V] = { { 0, 1, 0, 0, 4, 8, 0, 0},
                        { 0, 0, 2, 0, 0, 6, 6, 0},
                        { 0, 0, 0, 1, 0, 0, 2, 0},
                        { 0, 0, 0, 0, 0, 0, 1, 4 },
                        { 0, 0, 0, 0, 0, 5, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 1, 0, 1 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 } };
						
Output:
Vertex   Distance from Source
0               0
1               1
2               3
3               4
4               4
5               6
6               5
7               6

Bellford 

Compilation command:  g++ -std=c++11 bellford.cpp -o bellford
Run command:  ./bellford

Input: Adajency List 
Enter the number of the vertices 5
Enter the number of the edges 8
Enter the source 0
Enter the dest 1
Enter the weight -1
Enter the source 0
Enter the dest 2
Enter the weight 4
Enter the source 1
Enter the dest 2
Enter the weight 3
Enter the source 1
Enter the dest 3
Enter the weight 2
Enter the source 1
Enter the dest 4
Enter the weight 2
Enter the source 3
Enter the dest 2
Enter the weight 5
Enter the source 3
Enter the dest 1
Enter the weight 1
Enter the source 4
Enter the dest 3
Enter the weight -3

Output:

Vertex   Distance from Source
0                0
1                -1
2                2
3                -2
4                1
