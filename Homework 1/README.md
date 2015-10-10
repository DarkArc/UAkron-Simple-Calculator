# Simple Calculator

## Building

To setup the build, you will need CMake 3.1 or higher, and a C++11 compatible compiler. Create a subdirectory "build", and then from inside the created subdirectory use the commands:

````
cmake ..
make
````

## Executing

There are three executables included in this program which accept input:

| Executable  | Function                                      |
|-------------|-----------------------------------------------|
| CalcEval    | Evaluate input for the correct value          |
| CalcSExpr   | Reformat the input text into an S-Expr        |
| CalcPostfix | Reformat the input text into postfix notation |

All input shall be read in after program initialization, any command line arguments shall be ignored.

### Multi Eval script

Additionally, a bash script is provided which allows expressions to be declared in a text file, and then evaluated in one go. The syntax for the script is -- providing you followed the build instructions:

````
./multi_eval.sh ./build/<executable> <test expressions file>
````

#### Example

Given the input of some file "test.txt" with the following contents:
````
2 + 2
3 + 52 + 2
3 + 5
````

You shall receive the following output in you shell:
````
4
57
8
````

Given the following command:
````
./multi_eval ./build/CalcEval test.txt
````

## Testing

This project includes a test executable CalcTest. When executed, the test will proceed to run several test. Any test failures will be reported in lines which do not start with two pound symbols.
