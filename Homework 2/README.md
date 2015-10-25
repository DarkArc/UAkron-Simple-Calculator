# Simple Calculator

## Building

To setup the build, you will need CMake 3.1 or higher, and a C++11 compatible compiler. Create a subdirectory "build", and then from inside the created subdirectory use the commands:

````
cmake ..
make
````

## Executing

There is one executable included in this program which accept input:

| Executable  | Function                                      |
|-------------|-----------------------------------------------|
| CalcEval    | Evaluate input for the correct value          |

All compiled input shall be read in after program initialization.
The only valid command line argument is multiline which can be used
with a file in the following form:
````
./CalcEval multiline < file_name.txt
````

### Expression Termination
All expressions are terminated via new lines. Thus the following:
````
2
+2
````

Will evaluate to:
````
2
2
````

Instead of:
````
4
````

### Multi Eval script

A bash script is provided which allows expressions to be declared in a text file, and then evaluated in one go. The syntax for the script is -- providing you followed the build instructions:

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

This project includes a test script "default_test.sh" which runs a test comparing the input lines in default.txt to the output lines in default.expect.txt. Any discrepancies will be reported in the diff program's respective format.
