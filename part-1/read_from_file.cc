
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/// Entry point to the read_from_file program
/// \remark Must have 1 argument. The argument is a path to a file. In the
/// simpliest case, it can be the name of a file in the same directory
/// as the program.
int main(int argc, char* argv[]) {
  // TODO: Create a vector of arguments
  // TODO: Check to make sure there are enough arguments. If there are too
  // few, exit and print a warning message.
  // TODO: Declare a string variable named input_file_name
  // TODO: fetch the data from args and assign it to input_file_name. Don't
  // forget to use try and catch.

  // TODO: Declare an input file stream named input_file_stream and initialize
  // it with the variable input_file_name.
  // TODO: Check to ensure that the file was opened successfully. If the file
  // doesn't exist or the program doesn't have permission to read the
  // file then the operation to open the file would have failed.

  // TODO: Using a for loop or a while loop, read the contents of
  // input_file_stream line by line using getline() and print it to the
  // terminal.

  // TODO: Check to make sure the program has successfully reached the end of
  // the file. If it has, print a message celebrating the victory. Else-if,
  // check to see if input_file_stream is bad(). If it is bad, print an error
  // message. Else-if, check to make sure the fail bit is not set. If the fail
  // bit is set, print an error message.

  // TODO: Close the input file stream.

  return 0;
}
