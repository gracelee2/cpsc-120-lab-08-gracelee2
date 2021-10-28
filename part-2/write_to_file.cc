
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
  // TODO: declare and initialize an int variabl named status
  // TODO: declare and initialize a string variable named output_flie_name
  // TODO: fetch the data from args and assign it to output_file_name. Don't
  // forget to use try and catch.

  // TODO: Declare an output file stream named output_file_stream and initialize
  // it with the variable output_file_name.
  // TODO: Check to ensure that the file was opened successfully. If the file
  // doesn't exist or the program doesn't have permission to write the
  // file then the operation to open the file would have failed. Print an error
  // message and exit if the file didn't open.

  // TODO: Declare and initialize a string variable named secret_message

  // TODO: Prompt the user with instructions. See the Example Output in the
  // README.

  // TODO: Use getline() to read the secret message from cin and store it into
  // secret_message.

  // TODO: Write the secret message to output_file_stream

  // TODO: Check to make sure the output_file_stream isn't bad or that it hasn't
  // failed. If there was an error, set the variable status to 1.

  // TODO: Print a message saying the secret message was successfully written to
  // the filename stored in output_file_name.

  // TODO: Close the output file stream

  // TODO: return the variable status.
  return 0;
}
