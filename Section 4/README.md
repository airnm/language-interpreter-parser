## Build Process

To build the `scanner.c` run the following **flex** command.

```sh
flex -o scanner.c scanner.flex
```

The parser is built using **bison**.
Note this command also builds the `token.h`.

```sh
bison --defines=token.h --output=parser.c parser.bison
```

Then build the `main.c`, `parcer.c` and `scanner.c` using **gcc**.
Note that you may get a few warnings that can be ignored.

```sh
gcc main.c scanner.c  parser.c -o parser.out
```

Then execute the test suite using `./parser.out` and pass in the input from your sample program.
For example here is a command for `samples/program.c`

```sh
./parser.out < samples/program.c
```

Note that sorting_algorithm was changed to implement the function inside of main