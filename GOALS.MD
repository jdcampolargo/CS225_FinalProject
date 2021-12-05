## How can we find the shortest route from any airport, to its closest major airport?
Given an OpenFlights large dataset of airplane routes and locations, we can find paths from one location to another. Furthermore, naturally, there will be some airports which get more traffic than ours. Can we find the shortest route from any airport, to its closest major airport?

## Dataset
We have chosen to use the OpenFlights dataset to get data such as routes.dat and airports.dat to achieve our goal. 

We downloaded the data from the OpenFlights website (https://openflights.org/data.html) directly and then convert the two files into JSON data. Once we have the two JSON files, we stored the information of each file into two classes that helped retrieve any important information stored within them (Parse data). 

To avoid any data errors or missing entries we first filtered through the data and remove any incorrect information giving us properly mapped data sets. The way, we checked any null values in the data when we split them into classes. 

## Algorithms
We implemented BFS as a way to traverse through our OpenFlights dataset. We also used Dijkstra’s Algorithm to find  the distance between airports as the weight to find the most optimal routes between the two points. The inputs were a weighted graph and two nodes on the graph (airports), where the weight is calculated based on the distance of the two airports. While the output will be the summarized weight of the shortest path from airport A to airport. Additionally, we also implemented the PageRank algorithm in order to determine the most popular airport, where popular means most traffic. The inputs for this algorithm were a graph of the airports, which were used to determine the most popular airport. The output is a dictionary that holds an airport and its popularity value. In the end, the traversal and the two algorithms were compiled and executed under the appropriate runtime constraints that we previously stated in our proposal.


## Final Deliverable 


## Timeline
11/18 - Download and store datasets
11/25 - Write out the strong base to start with for algorithms that will be used. 
12/2 - Implement the algorithms into the data correctly.
12/9 - Test and debug 
12/13 - Revise and polish code if necessary.
