# OS_Multithreading_5
Write a C / C++ program that reads signed integer data from a file, makes decisions upon each integer in the file, and then writes each integer to one or more files. The goal of the assignment is to implement this program using multithreading and mutex locks or semaphores to ensure that the various threads don’t interfere with one another.
At minimum, your solution must be divided across two threads:
1. A reader thread that reads data from the file and puts it into a buffer.
2. A processor thread that reads data from the buffer, determines which files to write the data to, then writes the integer to those files.

Input File Specification
The input file will adhere to the following specifications:
1. The file will be a plain text file.
2. Each line of the file will contain a single signed 32-bit integer in decimal format.
3. The integer will be represented as a sequence of digits optionally preceded by a negative sign (-).
4. The integer will not be separated by any whitespace or special characters.
5. The file will not contain any headers, footers, or metadata.
6. The file will be encoded using the ASCII standard character encoding.
Output File Specification
Your output files must adhere to the following specifications:
1. The file should be a plain text file.
2. Each line of the file should contain a single signed 32-bit integer in decimal format.
3. The integer should be represented as a sequence of digits optionally preceded by a negative sign (-).
4. The integer should not be separated by any whitespace or special characters.
5. The file should not contain any headers, footers, or metadata.
6. The file should be encoded using the ASCII standard character encoding.
7. 
