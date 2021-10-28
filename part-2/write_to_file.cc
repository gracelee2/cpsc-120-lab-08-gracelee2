// Grace Lee
// CPSC 120-01
// 2021-10-28
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab 08-02
//
// This lab writes in a file
//

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
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 2) {
    cout << "Please provide a path to a file.\n";
    try {
      cout << args.at(0) << " output_file.txt\n";
    } catch (out_of_range const& problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }
  int status = 0;
  string output_file_name;
  // TODO: declare and initialize an int variabl named status
  // TODO: declare and initialize a string variable named output_flie_name
  // TODO: fetch the data from args and assign it to output_file_name. Don't
  // forget to use try and catch.
  try {
      output_file_name = args.at(1);
    } catch (exception const& problem) {
      cout << problem.what() << "\n";
      return 1;
    }
  // TODO: Declare an output file stream named output_file_stream and initialize
  // it with the variable output_file_name.
  ofstream output_file_stream(output_file_name);
  // TODO: Check to ensure that the file was opened successfully. If the file
  // doesn't exist or the program doesn't have permission to write the
  if (!output_file_stream.is_open()) {
    cout << "File not open";
    return 1;
  }
  // file then the operation to open the file would have failed. Print an error
  // message and exit if the file didn't open.

  // TODO: Declare and initialize a string variable named secret_message
string secret_message;
  // TODO: Prompt the user with instructions. See the Example Output in the
  // README.
cout << "What's a secret message that you'd like to write into a file?\n";
cout << "Type your message out and when you're done press return or enter.\n";
  // TODO: Use getline() to read the secret message from cin and store it into
  // secret_message.
getline(cin, secret_message);
output_file_stream << secret_message << "\n";
cout << "Your secret message was saved into output_file.txt.\n";
  // TODO: Write the secret message to output_file_stream

  // TODO: Check to make sure the output_file_stream isn't bad or that it hasn't
  // failed. If there was an error, set the variable status to 1.
  if (output_file_stream.bad()) {
      cout << "I/O error while reading\n";
      return 1;
    } else if (output_file_stream.fail()) {
      cout << "Encountered something crazy! Long line?\n";
      return 1;
    }
    output_file_stream.close();
    return status;
  // TODO: Print a message saying the secret message was successfully written to
  // the filename stored in output_file_name.

  // TODO: Close the output file stream

  // TODO: return the variable status.
  return 0;
}
