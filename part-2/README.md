# Write to a File

Reading from a file opens up new pathways for us to write more sophisticated and insteresting programs. Writing to a file enables us to have our programs communicate with people and with other programs.

Imagine that your instructor wishes to have a mechanisim to remind students about deadlines. Your instructor could write a file with the name of the assignment and the date it's due, one entry per line. Then a program can look at who has turned in their work and who hasn't and generate a file with all the students who forgot to submit their assignment. Another program could use that list to send a message on Canvas. Writing files helps us track and connect pieces of information.

In this exercise, we prompt the computer user to enter a secret message from the keyboard. Our program shall take that message (as a `string`) and write it into a file.

Last time we used [`ifstream`](https://en.cppreference.com/w/cpp/io/basic_ifstream) to create an input file stream. This time we shall use [`ofstream`](https://en.cppreference.com/w/cpp/io/basic_ofstream) to create an output file stream. The `ofstream` object is defined in the same `fstream` header file as `ifstream`.

Where as reading from a file implies that the file must exist first in order for it to be read from, writing to a file does not have this requirement. If the file doesn't exist, then we will create a new file. However, if the file already exists, we have to be careful.

For our purposes, we'll just truncate (delete) the file. This is the path of least resistance yet it is a dangerous path becuase you could accidentally delete an important file. Be careful and remember to use git prudently to track your work.

To declare an `ofstream`, it is just like declaring an `ifstream`. Writing to an `ofstream` is like writing to `cout` (because `cout` is an `ofstream`).

```c++
ofstream output_file_stream("my_output_file.txt");
output_file_stream << "Hello World\n";
output_file_stream.close();
```

The code above will create an `ofstream` variable named `output_file_stream`. The variable `output_file_stream` is intialized to open the file `"my_output_file.txt"`. If the file doesn't exist, it will be created. If it already exists then it will be deleted and recreated (truncated). Using the insertion operator `<<` write the strings `"Hello World\n"` to the `output_file_stream`. Finally, we close the `output_file_stream` because we are done working with it.

The other challenge of this exercise is reading a whole line of text from the keyboard into a variable. If you think about it, so far we've never worked with a whole line. We always limited ourselves to just a word or a number. Reading in a line of text is a little different and we'll use the function (not the method) [`getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline).

The function [`getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline) is part of the `string` header file and it can be used to read a line of text from any input stream.

Let's imagine we want to prompt someone to enter their favorite movie title. Then we would first print a message to the terminal using `cout`, declare a `string` variable to store the movie title, and then use `getline()` to copy the data from the terminal's keyboard to the `string` variable.

```c++
  cout << "What's your favorite movie? ";
  string their_favorite_movie;
  getline(cin, their_favorite_movie);
```

In the last line, `getline()` shall read the values from `cin` up to but not including the `\n` letter and save the input into the `string` variable `their_favorite_movie`.

Because we're only writing one line, we do not need to use a loop. Instead, our program checks the status of the `ofstream` and then exits.

Just like an `ifstream`, once a file has been opened, you can check the status of the file.

```c++
  if (output_file_stream.bad()) {
    cout << "I/O error while reading\n";
    return 1;
  } else if (output_file_stream.fail()) {
    cout << "Encountered something crazy! Long line?\n";
    return 1;
  }
  output_file_stream.close();
```

Remember, you can only check the status of a file while it is open so make sure you check before you close the `ofstream`.

## Inline Documentation

Are you curious what the `Doxyfile` is for? Wonder what the difference is between the regular comments (`//`) and the weird comments (`///`)?

The triple slash comment (`///`) is used to create documentation using a documentation generator named [Doxygen](http://www.doxygen.nl). In the C++ community, Doxygen is a commonly used program to generate HTML and PDF documentation from a program's comments.

To try it out, use `make doc`. This will create a folder in the project's directory named `doc`. Inside of that directory are HTML files which you can view with your web browser.

Try the following commands to generate and view the documentation for this project:

```
$ make doc
(cat Doxyfile; echo "PROJECT_NAME = rectangle_area") | doxygen -
Notice: Output directory 'doc' does not exist. I have created it for you.
Searching for include files...
Searching for example files...
  # Many lines out output removed
Patching output file 1/2
Patching output file 2/2
lookup cache used 2/65536 hits=2 misses=2
finished...
$ gio open doc/html/index.html 
```

The last command `gio open doc/html/index.html` will open the main HTML file in your web browser.

Another benefit of documenting your code is that when you use an editor like Visual Studio Code, it can show you the documentation when you point your mouse's cursor at a function name.

## Requirements

Using `ofstream`, write a message to a file that is specified on the command line. Read the message the computer user wishes to save by line using the `getline()` function.

If there are any errors, print an error message and exit.


The program takes one command line arguments other than the program's name. The first argument is the path to the output file.

Do not use the method (member function) `getline()`. Use the function [`getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline) which is part of the `string` header.

Close any file streams that you open and report any errors encountered.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.
* unittest: run unit tests to verify parts of your program performs according to the instructor supplied unit tests.
* doc: generate the project's documentation from the source files and store it in the directory named `doc`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 write_to_file.cc \
| sed 's/\(write_to_file\)\.o[ :]*/\1.o write_to_file.d : /g' > write_to_file.d; \
[ -s write_to_file.d ] || rm -f write_to_file.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c write_to_file.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o write_to_file write_to_file.o 
$ ./write_to_file 
Please provide a path to a file.
$ ./write_to_file output_file.txt
What's a secret message that you'd like to write into a file?
Type your message out and when you're done press return or enter.
I like apricots.
Your secret message was saved into output_file.txt.
$ cat output_file.txt 
I like apricots.
$ make test
2021-10-25 23:39:12,783 - INFO - Start Grading Tuffy Titan tuffy.titan@csu.fullerton.edu tuffytitan
2021-10-25 23:39:12,783 - INFO - All files: ./write_to_file.cc
2021-10-25 23:39:12,783 - DEBUG - Skipping base file comparison.
2021-10-25 23:39:12,821 - INFO - Formatting passed on ./write_to_file.cc
2021-10-25 23:39:12,832 - INFO - Using compile command clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64
2021-10-25 23:39:12,834 - DEBUG - Writing compile_commands.json
2021-10-25 23:39:14,070 - INFO - Linting passed in ./write_to_file.cc
2021-10-25 23:39:14,070 - DEBUG - make -C . spotless
2021-10-25 23:39:14,082 - INFO - stderr: rm: cannot remove 'unittest': No such file or directory
make[1]: [Makefile:133: cleanunittest] Error 1 (ignored)
2021-10-25 23:39:14,083 - DEBUG - make -C . all
2021-10-25 23:39:14,768 - INFO - Build passed
2021-10-25 23:39:14,768 - INFO - Test 1 - ('test01.txt', 'In seeking the unattainable, simplicity only gets in the way.')
2021-10-25 23:39:14,924 - INFO - ++++ Pass ++++
2021-10-25 23:39:14,925 - INFO - Test 2 - ('test02.txt', 'Your motives for doing whatever good deed you may have in mind will be misinterpreted by somebody.')
2021-10-25 23:39:15,081 - INFO - ++++ Pass ++++
2021-10-25 23:39:15,082 - INFO - Test 3 - ('test03.txt', 'Never trust an operating system.')
2021-10-25 23:39:15,238 - INFO - ++++ Pass ++++
2021-10-25 23:39:15,239 - INFO - Test 4 - ('test04.txt', 'He that is giddy thinks the world turns round.')
2021-10-25 23:39:15,395 - INFO - ++++ Pass ++++
2021-10-25 23:39:15,395 - INFO - Run passed
2021-10-25 23:39:15,396 - INFO - End Grading Tuffy Titan tuffy.titan@csu.fullerton.edu tuffytitan
```

