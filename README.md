# :ocean: Monty Interpreter

TODO: UPDATE THIS DESCRIPTION
cshell is an implementation of the original UNIX shell in C. It uses the POSIX API to implement a lot of the same functionality of Ken Thompson's first shell. The API calls predominantly used are <code>read</code>, <code>write</code>, <code>fork</code>, <code>exec</code>, and <code>wait</code> to name a few.


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

Using `$PATH` to find custom commands (executables)

```
> echo dog
dog
> /bin/echo dog
dog
```

Using `&&` or `||` logic to run commands based on success

```
> ls -l /asdfasdf && echo this won't print!
ls: cannot access /asdfasdf: No such file or directory 
> ls -l /asdfasdf || echo this will  print!
ls: cannot access /asdfasdf: No such file or directory
this will print!
```

Using `;` to seperate commands and run regardless of success

```
> ls -l /asdfasdf ; echo printme! ; wc -l main.c
ls: cannot access /asdfasdf: No such file or directory
printme!
 21 316 main.c
```

Using `exit [status]` to exit the process with status number

```
> exit 102
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo $?
102
```

Using `env` to print the environmental variables

```
> env
XDG_SESSION_ID=30
TERM=ansi
SHELL=/home/vagrant/simple_shell/seashell
...
...
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

* Bennett Dixon (for being a wizard)
* Holberton School (providing guidance)
* Stack Overflow (help on various memory errors (not leaks))
