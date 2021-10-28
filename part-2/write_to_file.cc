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
  try {
    output_file_name = args.at(1);
  } catch (exception const& problem) {
    cout << problem.what() << "\n";
    return 1;
  }

  ofstream output_file_stream(output_file_name);
  if (!output_file_stream.is_open()) {
    cout << "File not open";
    return 1;
  }
  string secret_message;
  cout << "What's a secret message that you'd like to write into a file?\n";
  cout << "Type your message out and when you're done press return or enter.\n";
  getline(cin, secret_message);
  output_file_stream << secret_message << "\n";
  cout << "Your secret message was saved into output_file.txt.\n";

  if (output_file_stream.bad()) {
    cout << "I/O error while reading\n";
    return 1;
  } else if (output_file_stream.fail()) {
    cout << "Encountered something crazy! Long line?\n";
    return 1;
  }
  output_file_stream.close();
  return status;

  return 0;
}
