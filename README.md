This is a README for Assignment 6.

The executable can be found in the build directory.

To recompile,

	cd build
	make
	cd ../

To run the program,

	cd build
	./bst
	cd ../

The executable is titled bst.

The only functions fully implemented are the ones required for the test program, e.g. add and its helpers, getHeight and its helpers, and the three traversals. The other functions like remove and getNumberOfNodes are just stubs.

One flaw in the program is the build process. I was having issues with CMake, so I had to include all three source files in my main. This does not affect the integrity or function of the program, just bad programming practice.

---
##### Credits
Code based on examples and pseudocode found in Data Abstraction and Problem Solving with C++: Walls and Mirrors (6th edition).
