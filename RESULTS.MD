
# Results and Discoveries
CS225 (jcampo37-ahuert30-psalin2-samuild2) 

## Deliverable
Our final deliverable is an interactive console in which you can load airports and routes data and compute BFS, Dijkstra's, and PageRank algorithms to find the shortest route from any airport, to its closest major airport.

The interactable console guides the user through with quick prompts such as typing “1” to find the shortest distance between two airports, and typing “2” to find the most popular airport nearby. 

## Proof of Accuracy
Our test cases are complete proof that our algorithms function as intended.  
Our smaller test cases individually consider each edge case, isolating any potential issues.  
We also ran tests to confirm that our algorithms can handle the total number of airports of about 15,000 airports and almost 40,000 routes data set. 

One can view these results in the following way:

Enter the project folder by running `cd_Final Project`
Followed by `./main-final_project` to run the program

You will have the following options: 
* Enter 0 to quit
* Enter 1 for finding shortest route
* Enter 2 for shortest path to nearest popular airport

  
## Discoveries
Throughout this project, we made interesting discoveries on both the dataset we chose to work with and on algorithm implementations in general.  

First, we needed to make a graph of our data. For the graph implementation, we decided to use an adjacency matrix to improve the run time of the project. If two nodes are connected, the adjacency matrix would return the distance between the two nodes. For instance, If the weight is 0 then the nodes do not share a connection.​ The AirportToIndexMap allowed us to save all the Airports based on their airport code/ID. Once inputting an airports ID into the map, we would know where the airport appears on the adjacencyMatrix with the index returned.  This allowed us to look at any airport we wanted using just the airports code/ID 

Next, in the BFS we set it up so that we can start at any node given its airport code/ID or in other words our start position. ​With that, we would use our AdjacencyMatrix in conjunction with our airportToIndexMap to get our starting position and look for any possibly connected nodes.​ However, we ran into a small problem where we had nodes that weren’t being visited at all even though we made sure that there were no nodes that had null codes or information. ​ We later found out that some airports do not have any connections as our Routes Data set did not include those airports.  Thus,  Airports with 0 connections were ignored.​

Once we had BFS completed, we implemented the PageRank algorithm because we knew that we wanted to have some way of ranking the popularity of an airport.​ To accomplish this, we used the number of routes as the determining factor in order to achieve a time complexity of O(V + M) where V is the number of nodes and M is the number of edges. Therefore, the more routes connected to the current node, the more popular it was. ​We ran into an issue where the ratios for airport popularity were correct but higher than what PageRank should output. This was a logical error in the calculation that was adjusted for and ultimately, we were able to get a list of the top popular airports.​

For the last algorithm, we implemented Dijkstra's algorithm. Once we knew what to do, we began by having it take the graph of nodes that we have, a starting airport, and a destination airport.​ At first, understanding how to implement this problem in the context of our project took some time. However, this problem was overcome by testing the algorithm on a small custom data set that allowed us to easily see how the algorithm was functioning and adjust it accordingly. ​Dijkstra’s algorithm has a time complexity of  O(V^2) where V is the number of nodes.


## Final Remarks
Given our question of given an OpenFlights large dataset of airplane airports and routes, can we find the shortest route from any airport, to its closest major airport?​
​
We accomplished to answer our leading question because we were able to find the shortest route from any starting airport to the wanted destination. By inputting the code of our starting airport and the code of our destination airport and the graph where all our nodes are stored, we managed to traverse the graph and find the shortest most optimal path to take from our starting point to our destination. Given the list of most popular airports provided by the PageRank algorithm, we were able to identify the closest major airport from the starting airport as well.


​
