# ATL

* C++ 17
* Premake 5 

This repo contains a usage example of ATL. You can find the code of the library per se inside 
Atl_lib_core directory.

- [Overview] : overview of Atl archicture and how you can use it in your project.
- [Building the example] : how to use premake to build the example
- [How to use Atl] : how to create and run your tests


## Overview


---

<p align="center">
  <img src="./resources/architectureOverview.jpg" width="1000" title="hover text">
</p>


You can consider ATL as consisting in 4 parts ; 2

* **Your production code**
* **Your tests** : *module, test classes, unit tests*
* **Atl app** : *console application that output test results in the console*
* **Atl core** : *the library per se ; you don't have to touch anything in that* 
 
Note that your tests need to have access to your production code. 
So you can either have all your tests with
your production application and use main method of your application to run Atl. 

Or you can separate tests from your code. It requires that the code under test is link to tests as a library.

In this repo you'll find a usage example of Atl lib, with 
## Building the example
## How to use ATL 



