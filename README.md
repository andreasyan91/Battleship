
This is the README file of "Battleship" game developed by
Anna Andreasyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. DIRECTORY STRUCTURE
        5. USAGE
        6. DOCUMENTATION

1. AUTHOR
Anna Andreasyan
E-mail: andreasyan.an@gmail.com
Tel: +374-55-500105

2. INTRODUCTION
This project is a game called Battliship which is written in C++ and 
is intended to be used only for entertainment purposes. 

The game does not have Graphical user interface  and only uses command line 
interface.

3. PREREQUISITES
The following third party tools should be installed before the
compilation.

Tools:
g++
doxygen

1) Build the project
	make

2) Run the game
	make run

3) Test the project
	make test

4. DIRECTORY STRUCTURE

src/            - the source files of the project
docs/            - the documentation of the project.
                  Please refer to "DOCUMENTATION" section for more details
tests/          - the tests of the project
test_result/	- the result of the tests of the project 
makefile        - top level makefile to build / run the project
Doxyfile        - doxygen configuration for the documentation of the project

5. USAGE
Please refer to "Getting Started Battleship" documents in docs/.

6. DOCUMENTATION
"make doxygen" command generates doxygen documentation.

The source code of the documentation is located in the directory docs/.

Doxygen also generates documentation from C/C++ code comments.

"make html" command to see the generated documentation.

