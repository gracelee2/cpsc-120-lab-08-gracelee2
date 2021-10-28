// Grace Lee
// CPSC-120-01
// 2021-10-28
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab-08-01
//
// reading file line by line
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
  vector<string> args = vector<string>(argv, argv+ argc);
  if (args.size() < 1) {
    cout << "Please provide a path to a file.\n";
    try {
      cout << args.at(0) << " 01_words.txt\n";
    } catch (out_of_range const& problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }
  string input_file_name;
  try {
    input_file_name = stoi(args.at(1));
  } catch (exception const& problem) {
    cout << problem.what() << "\n";
    return 1;
  }

  // TODO: fetch the data from args and assign it to input_file_name. Don't
  // forget to use try and catch.
 ifstream input_file_stream(input_file_name);
 string line_buffer;
 getline(input_file_stream, line_buffer);
 cout << line_buffer <<"\n";
 input_file_stream.close();
  // TODO: Check to ensure that the file was opened successfully. If the file
  // doesn't exist or the program doesn't have permission to read the
  // file then the operation to open the file would have failed.

  // TODO: Using a for loop or a while loop, read the contents of
  // input_file_stream line by line using getline() and print it to the
  // terminal.
  for (string line_buffer; getline(input_file_stream, line_buffer);) {
          cout << line_buffer << "\n";
  }
  // TODO: Check to make sure the program has successfully reached the end of
  // the file. If it has, print a message celebrating the victory. Else-if,
  // check to see if input_file_stream is bad(). If it is bad, print an error
  // message. Else-if, check to make sure the fail bit is not set. If the fail
  // bit is set, print an error message.
  if (input_file_stream.eof()) {
    cout << "End of file reached successfully!\n";
  } else if (input_file_stream.bad()) {
    cout << "I/O error while reading.\n";
    return 1;
  } else if (input_file_stream.fail()) {
    cout << "Failure: Long line.\n";
    return 1;
  }
  input_file_stream.close();

  return 0;
}
