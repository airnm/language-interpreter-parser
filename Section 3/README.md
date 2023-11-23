# Flex Scanner

Create a scanner for the sample programs.

## Testing the Language Scanner

Write unit test for your sample code.
The sample program uses `utest.h` which is a simple c unit test framework.
The documentation can be found at <https://github.com/sheredom/utest.h>.

The `main.c` has been replaced with unit test code.

## Build Process

To build the `scanner.c` run the following **flex** command.

```sh
flex -o scanner.c scanner.flex
```

Then build the `main.c` and `scanner.c` using **gcc**.

```sh
gcc main_test.c scanner.c -o scanner_test.out
```

Then execute the test suite using `./a.out`.

```sh
./scanner_test.out
```

## Scanner Only


```sh
flex -o scanner.c scanner.flex
gcc main_test.c scanner.c -o scanner.out
./scanner.out
```
