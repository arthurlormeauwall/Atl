# ATL

* C++ 17
* Premake 5 

This repo contains a usage example of ATL. You can find the code of the library per se inside 
Atl_lib_core directory.

- [Overview] : overview of Atl archicture and how you can use the library in your project.
- [Building the example] : how to use premake to build the example
- [How to use Atl] : how to create and run your tests


## Overview


---

<p align="center">
  <img src="./resources/architectureOverview.jpg" width="1000" title="hover text">
</p>


You can consider ATL as consisting of 4 parts

* **Your production code**
* **Your tests** : *module, test classes, unit tests*
* **Atl app** : *console application that output test results in the console*
* **Atl core** : *the library per se ; you don't have to touch anything in that* 
 
Note that your tests need to have access to your production code. 

So you can either have all your tests with
your application and use main method of your application to run Atl. 

Or you can separate tests from your code. It requires that the code under test is link to tests as a library.

In this repo Atl app and modules are kept in their own project. 
This method give you the most flexibility. 

## Building the example
Example use premake 5 as build system. https://premake.github.io/

Premake5 uses Lua as script langage and lets you generate solution and projects files, 
for visual studio, xcode etc. 


If you're on **Windows**, you can directly use **premake5.exe** at the root of the repo.

``` console
> .\premake5.exe <version of visual studio> 
``` 

For **mac** and **linux**, please refer to the website (premake documentation is really great :))


## How to use ATL 



