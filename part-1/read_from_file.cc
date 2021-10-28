// Grace Lee
// CPSC 120-01
// 2021-10-28
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab 08-01
//
// This lab reads files
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
    input_file_name = args.at(1);
  } catch (exception const& problem) {
    cout << problem.what() << "\n";
    return 1;
  }

  ifstream input_file_stream(input_file_name);
  if (!input_file_stream.is_open()) {
    cout << "File not open";
    return 1;
  }

  for (string line_buffer; getline(input_file_stream, line_buffer);) {
    cout << line_buffer << "\n";
  }

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
