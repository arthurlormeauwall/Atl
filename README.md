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
* **Your tests** : *modules, test classes, unit tests*
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

### Main.cpp 
``` cpp 
int main(int argc, char* argv[]) {
	auto testRunner = AtlController(argv);;
	testRunner.runAllTests(std::make_shared<MyTests>());
}
``` 

### AllTest
``` cpp 
class MyTests  : public AllTestBuilder {
public:
	MyTests() {}
	void addModules() override {
		createModule<MyModule>("My Module");
		createModule<AnotherModule>("Another Module");
	}
};
``` 

### Module
``` cpp 
class MyModule: public ModuleBuilder {
public:

	MyModule(TestData td) : ModuleBuilder(td) {}
	virtual void addTestClasses() override {
		createTestClass<TestClass>("Test of a class");
	}
};
``` 

### Test class

``` cpp 
class TestClass: public TestClassBuilder {
public:
	TestClass(TestData td) : TestClassBuilder(td) {}
	virtual void addUnitTests() {
		createUnitTest(<a unit test>);
	}
};
``` 

### Unit test
``` cpp
	createUnitTest("Should something",
		[]()->vector<Result>
		{ 
			vector<Result> assertions;
			assertions.push_back(<your assertion>);
			return assertions;
		}
	);
```
####  Is Equal to 

```cpp
	createUnitTest("A test that should succeed",
		[]()->vector<Result> {
			vector<Result> assertions;
			assertions.push_back(IsEqualTo<float>(3,3).getResult());
			return assertions;
		}
	);
```

#### Is Equal to with custom to_string 
``` cpp
struct Item {
	string name;
	int value;
	bool operator==(Item& rhs) {
		return name == rhs.name && value == rhs.value;
	}
	string(*toString)(Item it) =
		[](Item it)->string { return string("Name : ")
		.append(it.name)
		.append(" and value : ")
		.append(std::to_string(it.value));
	};
	Item(string n, int v) :name(n), value(v) {}
};

void TestClass::addUnitTests() {
	createUnitTest("Should be equal",
		[]()->vector<Result>
		{
			vector<Result> assertions;
			Item item1("item_1", 4);
			Item item2("item_1", 4);

			assertions.push_back(IsEqualTo<Item>(item1, item2)
				.getResultWithCustomToString(item1.toString));

			return assertions;
		} 
```

##### Custom assertion 

``` cpp
void TestClass::addUnitTests() {
	createUnitTest("Should fail",
		[]()->std::vector<Result>
		{
			vector<Result> assertions;
			assertions.push_back(Result(false,
				vector<string>({ "This is a custom assert","this test do not pass" })));
			return assertions;
		}
	);
}
```

