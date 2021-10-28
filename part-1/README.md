# Read From a File

Working with data in the computer's memory is a good starting point. We've done that with a variety of different types (int, float, string). The next challenge for us to over come is how to read and write from [files](https://en.wikipedia.org/wiki/Computer_file).

Reading from files is a great leap forward. Writing programs that can read from a file means that you are no longer limited to what a human can enter at the computer's console. Reading from a file means that you can make use of much more interesting (and larger!) data sources. The smallest and most portable computer can store Gigabytes of data. That is a lot of space to store files (and database)!

How big of a file can your fit on your computer? Is there a limit to how large or how many files you can have on your computer? How big is the smallest file?

A file is just an abstraction of some information that is stored in your computer's [file system](https://en.wikipedia.org/wiki/File_system). It's an address of sorts to help you, the programmer, locate a resource that has been stored in your computer's file system.

You can think of a path to a file kind of like a [URL](https://en.wikipedia.org/wiki/URL) to a website. If you have the right path, your computer can open up the file and read it. (And if you think about it a little bit you may ask yourself if you can read from a file, then how hard can it be to read from a website?).

The first thing we need is an abstraction of what a file is. For the programmer, a file is a stream. A stream not in the sense of a flowing body of water but a sequence that streams by. More like a train which has a beginning, middle, and end. Given a stream in C++, we want to have operations to read from it and move forward and backwards.

For starters, let's focus on opening up a file and reading it line by line. (Remember a line is terminated by the "\n" letter.)

C++ has a special type called [`ifstream`](https://en.cppreference.com/w/cpp/io/basic_ifstream) which is defined in the `fstream` header file. If we have the name of a file such as `"words_that_start_with_m.txt"`, then we can open and minupulate the file with the following code:

```c++
string filename = "words_that_start_with_m.txt"
ifstream input_file_stream(filename);
```

The variable `input_file_stream` is of type `ifstream` or input file stream. It is a C++ object which is allocated and initialized with the file path `"words_that_start_with_m.txt"`. From here, we can perform operations such as checking to see if the file was succssefully opened or read a line of text from the file.

To read from a input file stream line by line, we need to think of it as copying the line from the file on disk to a temporary buffer in RAM. In other words, we will use the function `getline()` to read a single line (a `string`) from the input file stream and then assign that line to a `string` variable. Once we have it as a `string` variable we can print it to the terminal.

We can extract a line of text from a file stream using the [`getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline) function. Our strategy is to first declare a `string` variable and then use `getline()` to copy the line from the file stream into the variable. Let's assume the variable `input_file_stream` successfully opened `"words_that_start_with_m.txt"` and the first line of the contains the line "muffins and mittens".

```c++
string filename = "words_that_start_with_m.txt"
ifstream input_file_stream(filename);
string line_buffer;
getline(input_file_stream, line_buffer);
cout << line_buffer << "\n";
input_file_stream.close();
```

On the last line, `input_file_stream` is closed because we are no longer using it. If you open something, like a file, you must close it.

We only read one line of text in the given example. What if we want to read the contents of an entire file?

To read the contents of an entire file, all one needs to do is to use `getline()` in a loop.

For example, to read all the lines in a file using a while loop:
```c++
string filename = "words_that_start_with_m.txt"
ifstream input_file_stream(filename);
while (input_file_stream) {
	string line_buffer;
	getline(input_file_stream, line_buffer);
	cout << line_buffer << "\n";
}
input_file_stream.close();
```

To read all the lines in a file using a for loop:
```c++
for (string line_buffer; getline(input_file_stream, line_buffer); /* empty */) {
	cout << line_buffer << "\n";
}
```
Notice that the for loop looks a little different from what we may have experienced previously. There are only two statements within the for loops parantheses. The first statement declares and initializes line_buffer. The second statement reads from `input_file_stream` and returns a boolean value to tell the for loop if it has reached the end of the file. There isn't a third statement to update the counter like we have done previously.

Finally, if we want to know if we have been successful in reading to the end of the file, we can ask the `ifstream` what's happened. You can only check the status of an `ifstream` while it is open. You cannot check its status after you have closed it. The following if-eslse-if block can be used right before the `ifstream` is closed to print it's status to the terminal.

```c++
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
```

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

Using `ifstream`, read the contents of a file that is specified on the command line and print the contents to the terminal. Read the contents of the file line by line using the `getline()` function. Do not use the `getline()` member function from the `ifstream` class.

If there are any errors, print an error message and exit.

Use the files 01_words.txt, 02_words.txt, 03_words.txt, 04_words.txt to help you validate that your program works as expected. Sample output is provided below.

The program takes one command line arguments other than the program's name. The first argument is the path to the input file

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
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 read_from_file.cc \
| sed 's/\(read_from_file\)\.o[ :]*/\1.o read_from_file.d : /g' > read_from_file.d; \
[ -s read_from_file.d ] || rm -f read_from_file.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c read_from_file.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o read_from_file read_from_file.o 
$ ./read_from_file 
Please provide a path to a file.
$ ./read_from_file 01_words.txt 
wittering
postdiastolic
pipkinet
candleball
unwax
unquiescent
wavingly
megadyne
shirtlike
whank
escopette
neuropathy
envassal
prosector
clotter
proctological
Moorish
superheterodyne
unvillaged
equiarticulate

End of file reached successfully!
$ make test
2021-10-25 23:28:49,317 - INFO - Start Grading Tuffy Titan tuffy.titan@csu.fullerton.edu tuffytitan
2021-10-25 23:28:49,317 - INFO - All files: ./read_from_file.cc
2021-10-25 23:28:49,318 - DEBUG - Skipping base file comparison.
2021-10-25 23:28:49,359 - INFO - Formatting passed on ./read_from_file.cc
2021-10-25 23:28:49,369 - INFO - Using compile command clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64
2021-10-25 23:28:49,372 - DEBUG - Writing compile_commands.json
2021-10-25 23:28:50,596 - INFO - Linting passed in ./read_from_file.cc
2021-10-25 23:28:50,596 - DEBUG - make -C . spotless
2021-10-25 23:28:50,607 - INFO - stderr: rm: cannot remove 'unittest': No such file or directory
make[1]: [Makefile:133: cleanunittest] Error 1 (ignored)
2021-10-25 23:28:50,607 - DEBUG - make -C . all
2021-10-25 23:28:51,283 - INFO - Build passed
2021-10-25 23:28:51,283 - INFO - Test 1 - ('01_words.txt', '\\s*wittering\\s+postdiastolic\\s+pipkinet\\s+candleball\\s+unwax\\s+unquiescent\\s+wavingly\\s+megadyne\\s+shirtlike\\s+whank\\s+escopette\\s+neuropathy\\s+envassal\\s+prosector\\s+clotter\\s+proctological\\s+Moorish\\s+superheterodyne\\s+unvillaged\\s+equiarticulate\\s+End\\s+of\\s+file\\s+reached\\s+successfully!\\s*')
2021-10-25 23:28:51,287 - INFO - ++++ Pass ++++
2021-10-25 23:28:51,287 - INFO - 
2021-10-25 23:28:51,387 - INFO - Test 2 - ('02_words.txt', '\\s*sprew\\s+periligamentous\\s+overhover\\s+maltolte\\s+Phyllis\\s+arboral\\s+coaxial\\s+Kiangan\\s+Nereidiformia\\s+defraudation\\s+stereostatic\\s+unshakeably\\s+tardigradous\\s+chocard\\s+pensy\\s+intersectional\\s+phymatosis\\s+stereometer\\s+sherifa\\s+cooter\\s+End\\s+of\\s+file\\s+reached\\s+successfully!\\s*')
2021-10-25 23:28:51,393 - INFO - ++++ Pass ++++
2021-10-25 23:28:51,394 - INFO - 
2021-10-25 23:28:51,494 - INFO - Test 3 - ('03_words.txt', '\\s*unnatural\\s+nonchargeable\\s+gallic\\s+taenioid\\s+subbrachyskelic\\s+fallway\\s+soldierlike\\s+notopteroid\\s+forelive\\s+paraphrase\\s+touser\\s+pennywort\\s+webwork\\s+galactopoiesis\\s+ferineness\\s+earhole\\s+pseudoantique\\s+site\\s+horme\\s+wheyeyness\\s+End\\s+of\\s+file\\s+reached\\s+successfully!\\s*')
2021-10-25 23:28:51,500 - INFO - ++++ Pass ++++
2021-10-25 23:28:51,500 - INFO - 
2021-10-25 23:28:51,601 - INFO - Run passed
2021-10-25 23:28:51,601 - INFO - End Grading Tuffy Titan tuffy.titan@csu.fullerton.edu tuffytitan
```

