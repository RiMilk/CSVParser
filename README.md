# SCVParser
A CSV file (comma-separated values) with a header that lists the column names. The rows are numbered
The columns are numbered with positive integers, not necessarily in ascending order. The cells of a CSV file can either contain integers
numbers or expressions of the form
= ARG1 OP ARG2
where ARG1 and ARG2 are integers or cell addresses in Column_name Row_number format, and OP is an arithmetic operation
from the list: +, -, *, /.

## Compilation for windows
>make

## Compilation for linux
>make
