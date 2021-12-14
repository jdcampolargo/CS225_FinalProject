# CS 225: Open Flights Final Project
Final project for jcampo37-ahuert30-psalin2-samuild2


<!-- ABOUT THE PROJECT -->
## About The Project


Here's a blank template to get started: To avoid retyping too much info. Do a search and replace with your text editor for the following: `github_username`, `repo_name`, `twitter_handle`, `linkedin_username`, `email`, `email_client`, `project_title`, `project_description`

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* C++


<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

- Juan David Campolargo - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo)
- Alan Huerta - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) 
- Patricia Salinas - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) 
- Samuil Donchev - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) 

<p align="right">(<a href="#top">back to top</a>)</p>





<p align="right">(<a href="#top">back to top</a>)</p>

# Project Structure
The project structure is created to maximize modularity, increase compartmentalization, and make use of tools through CMake. Each sub-project of the overall project has its own folder, wherein each contains its own test, main methods, CMake files, and header files, thus increasing modularity of the overall project. Thus, each sub-project can actually stand alone on its own, and we add them here together much like applications rather than a hard-stuck part of the project. An example project structure is shown below for better visualization of the structure:
```
project/
> parsing/
    > include/
        - ...header files
    > src/
        - ...src files
    - main.cpp
    - CMakeLists.txt
> bfs/
    |-- ...
```

This is a very similar structure as all other large open-source code bases like OpenCV as it allows maximum modularity and stand-alone applications.


# First Time
We will refer to the home project directory as `project/`. If this is your first time with the project and you are unfamiliar with the running scripts, then please execute the following in your command line (Note you must type in the stuff after the dollar sign. The stuff before the `$` symbol denotes the current filepath):

`$ cd project/`

`project$ chmod +x run.sh`

`project$ ./run.sh`

This will run the included script that runs the main method with default arguments and also all tests in each subdirectory. This is just a concatenation of running the bake, tests, and main at once.

<p align="right">(<a href="#top">back to top</a>)</p>


# Building Files
We decided to use CMake in this project due to its usefulness in helping us create Makefiles through a list of well-defined macros. The following command will bake the project (Build & Make). Run these in your local terminal. Note, please consider doing all of this on EWS as we assume tools on EWS (like CMake3 etc.).

`project$ ./bake.sh`

# Running Main, Tests
## Main
To run main or tests, you can just execute the main script like so:

`project$ ./main.sh`
<!-- 
The main method also includes some additional input if you would like to play around with the inputs. You can run `./main -h` or `./main --help` for more information on the usage type. The result should print something like:

`Usage: ./main [nodes file] [edges file]`

For example, we provided a fake dataset so you could run the following:

`./main ../data/nodes.csv ../data/edges.csv` -->

Note that everything will be relative to the `src/` directory even though the script is in the `project/` directory.

<p align="right">(<a href="#top">back to top</a>)</p>


## Tests
I have made a `test.sh` script that runs all the tests in the subdirectories. You can just run it like so:

`project$ ./test.sh`

Our tests cover the functionality of
* constructing the node, edge, and airport classes 
* constructing a graph
* the BFS traversal
* the Pagerank algorithm
* Djikstra's algorithm

<p align="right">(<a href="#top">back to top</a>)</p>
