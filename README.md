# Broken-Clock
Solution to the Broken Clock problem in Comp 349 Applied Algorithms

# Statement of the problem
Steve has a problem with his bed-side alarm clock. Some of the LED components work only intermittently. He would like
for you to write a program that, given which LED components are not working, outputs which digits may be confused with
others.

The clock components are numbered as:

1: Top led

2: Top left led

3: Top right led

4: Center led

5: Bottom left led

6: Bottom right led

7: Bottom led

# Input-file (led.in)

The input file contains several test cases. The input for each test case consists of 1 or more single digit integers separated by
a single space all on one line. The end of each line is marked with a single ‘0’. Each non-zero digit represents a LED
component that isn’t working. After all of the test cases, the last line contains a single zero ‘0’. 

# Output-file (led.out)

For each test case there should be one line of output. The first text on each line should be the string: “Case: '<_list>'”,
where list is a comma-delimited list of the broken component(s). There is 1 space between the letter ‘e’ and the left
angle bracket ‘<’. A comma should be not displayed before the first component nor after the last component in the list.
If there are clock digits that will be confused due to the broken component(s), display a single space after the colon followed
by the set (or sets) of confused digits. If more than one set of clock digits will be confused, the sets should be separated by a
single space. The format of each set should appear as “{set}” where set is a comma-delimited list of the clock digits that
would be confused.
No line of output should begin or end with a space character. There should never be 2 consecutive spaces in the output file

# Example input

1 0

2 0

3 0

1 3 0

1 2 3 4 5 6 0

0

# Example output

Case <1>: {1,7} {4,9}

Case <2>:

Case <3>: {6,8}

Case <1,3>: {1,7} {4,9} {6,8}

Case <1,2,3,4,5,6>: {0,2,3,5,6,8} {1,4,7,9}

