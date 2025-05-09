# Pipex

`pipex` is a program that replicates the behavior of shell pipelines (`|`), allowing the execution of chained commands with input/output redirection.

## Features
- Simulates shell pipelines using `pipe()` and `fork()`.
- Handles input and output redirection.
- Supports multiple commands in bonus mode.
- Includes error handling for invalid commands or files.

## How to Build and Run
1. Clone the repository:
   ```bash
   git clone git@github.com:Zaaii77/pipex.git
   cd pipex
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./pipex <file1> <cmd1> <cmd2> <file2>
   ```

   Example:
   ```bash
   ./pipex infile "ls -l" "wc -l" outfile
   ```

   This will execute `ls -l` with input from `infile`, pipe its output to `wc -l`, and write the result to `outfile`.

4. For bonus mode (multiple commands):
   ```bash
   make bonus
   ./pipex infile "cmd1" "cmd2" ... "cmdN" outfile
   ```

## Parameters
- `<file1>`: Input file.
- `<cmd1>`: First command to execute.
- `<cmd2>`: Second command to execute.
- `<file2>`: Output file.

## Example Output
```bash
$ cat infile
Hello World
42 is amazing

$ ./pipex infile "grep 42" "wc -l" outfile

$ cat outfile
1
```

## Notes
- The project uses `libft` for utility functions.

## License
This project is licensed under the MIT License.
