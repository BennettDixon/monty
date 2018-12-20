# :ocean: Monty Interpreter

Welcome to the Monty Bytecode Interpreter. This interpreter was built in the C language and is compliant with `ISO90`, `ISO99`, & `ISO11`. It reads a file of any extension (preferably `.m` although it doesn't matter), and interprets the byte codes contained in the file. Our interpreter can either be run in stack or queue mode, and have its mode switched mid script. See Examples for more information regarding this functionality. You may build stacks or queues with this interpreter and perform operations on them such as mathematical and position related operations.

## :running: Getting Started

* [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/) - Operating system reqd.

* [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/) - Compiler used


## :warning: Prerequisites

* Must have `git` installed

* Must have repository cloned

```
$ sudo apt-get install git
```


## :arrow_down: Installing

Clone the repository into a new directory

```
$ git clone https://github.com/BennettDixon/monty.git
```
Compile with the following:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```


## :clipboard: Examples

Note, Monty Interpreter runs in the default mode of STACK mode. Meaning it uses a stack. To switch to queue mode, see examples below.

Push values onto the stack and print them all, or the top of the stack/front of queue.

```
$ cat push_pall_pint.m
push 1
push 2
push 3
pall
pint
$ ./monty push_pall_pint.m
3
2
1
3
```

Using mathmatical operations to add, multiply, divide, etc. Takes the second from the top and performs the operation on the top: `second_from_top / top`, `second_from_top - top`, `etc`. Then assigns that to the `second_from_top` and pops the top element off the stack.

```
$ cat math.m
push 3
push 2
push 1
pall
mul
pall
$ ./monty math.m
1
2
3
1
6
```

Entering queue mode to perform all operations in FIFO (queue) mode instead of default LIFO (stack) mode. Note: does not change current stack, sets front of queue to top of stack.

```
$ cat queue.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
$ ./monty queue.m
1
2
3
6
5
4
1
2
3
```

## :books: Coding Style Tests

Strictly followed `Betty` style guide. To install

```
$ git clone https://github.com/holbertonschool/Betty.git

$ cd Betty; ./install.sh
```


## :pencil: Version

* 0.1.0



## :blue_book: Authors

* **Brennan Baraban** - [@bdbaraban](https://github.com/bdbaraban)

* **Bennett Dixon** - [@BennettDixon](https://github.com/BennettDixon)



## :mag: License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details



## :mega: Acknowledgments

* Holberton School (providing guidance)
* Stack Overflow (help on various memory errors (not leaks))
