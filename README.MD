# jcampo37-ahuert30-psalin2-samuild2
Final project for jcampo37-ahuert30-psalin2-samuild2



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

Here's a blank template to get started: To avoid retyping too much info. Do a search and replace with your text editor for the following: `github_username`, `repo_name`, `twitter_handle`, `linkedin_username`, `email`, `email_client`, `project_title`, `project_description`

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* C++


<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [] Feature 1
- [] Feature 2
- [] Feature 3
    - [] Nested Feature

See the [open issues](https://github.com/github_username/repo_name/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

- Juan David Campolargo - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) - jcampo37@illinois.edu
- Alan Huerta - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) - jcampo37@illinois.edu
- Patricia Salinas - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) - jcampo37@illinois.edu
- Samuil Donchev - [Twitter](https://twitter.com/jdcampolargo) - [LinkedIn](https://linkedin.com/in/jdcampolargo) - jcampo37@illinois.edu

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* []()
* []()
* []()

<p align="right">(<a href="#top">back to top</a>)</p>


# First Time
We will refer to the home project directory as `project/`. If this is your first time with the project and you are unfamiliar with the running scripts, then please execute the following in your command line (Note you must type in the stuff after the dollar sign. The stuff before the `$` symbol denotes the current filepath):

`$ cd project/`

`project$ chmod +x run.sh`

`project$ ./run.sh`

This will run the included script that runs the main method with default arguments and also all tests in each subdirectory. This is just a concatenation of running the bake, tests, and main at once.


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

## Tests
I have made a `test.sh` script that runs all the tests in the subdirectories. You can just run it like so:

`project$ ./test.sh`

and you should see the success on all parts.



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
