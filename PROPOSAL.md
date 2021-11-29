Signatures: [Samuil Donchev, Patricia Salinas, Alan Huerta, Juan David Campolargo]
CS 225 Data Structures 
Project Proposal (jcampo37-ahuert30-psalin2-samuild2) 

Leading Question
Given an OpenFlights large dataset of airplane routes and locations, we can find paths from one location to another. Furthermore, naturally, there will be some airports which get more traffic than ours. Can we find the shortest route from any airport, to its closest major airport?
Dataset Acquisition and Processing
We have chosen to use the OpenFlights dataset to get data such as routes.dat and airports.dat to achieve our goal. 
We’ll download the data from the OpenFlights website (https://openflights.org/data.html) directly and then convert the two files into JSON data. Once we have the two JSON files, we will store the information of each file into two classes that will help retrieve any important information stored within them (Parse data). 
To avoid any data errors or missing entries we will first filter through the data and remove any incorrect information giving us properly mapped data sets. The way we’ll filter is by checking for any null values in the data when we split them into classes. 

Graph Algorithms
By the end of the project, we will have completed Dijkstra’s Algorithm, using the distance between airports as the weight to find the most optimal routes between the two points. The inputs will be a weighted graph and two nodes on the graph (airports), where the weight is calculated based on the distance of the two airports. While the output will be the summarized weight of the shortest path from airport A to airport B. Dijkstra’s algorithm will have a time complexity of  O(V^2) where V is the number of nodes.

We will also implement the PageRank algorithm in order to determine the most popular airport, where popular means most traffic. The inputs for this algorithm will be a graph of the airports, which will be used to determine the most popular airport. The output will be a dictionary that holds an airport and its popularity value. The time complexity of this algorithm should be O(V + M) where V is the number of nodes and M is the number of edges.

We will also be using BFS to traverse the graph.

Timeline
11/18 - Download and store datasets
11/25 - Write out the strong base to start with for algorithms that will be used. 
12/2 - Implement the algorithms into the data correctly.
12/9 - Test and debug 
12/13 - Revise and polish code if necessary. 


