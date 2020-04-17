# Simple Shell

The simple shell program is a CLI (Command Line Interface) that was coding in C language and allow the user access through the keyboard to the Linux Operating System. The purpose of this project is put into practice all knowledge got in the first trimester of basic formation in Holberton School. If you want to know more about the Holberton School, please go to: [www.holbertonschool.com](https://www.holbertonschool.com/).

## Installation

Clone the repository from the link below: 

    https://github.com/andresjjn/simple_shell.git

Now, to execute the simple shell program, you can use the `gcc` Linux compiler. If you do not have installed this compiler, please follow the next instructions:

**1.** Update the Linux packages list:

```bash
sudo apt update
```
**2.** Install the build-essential package:

```bash
sudo apt install build-essential
```

**3.** Verify the installation and the compiler version using:

```bash
gcc --version
```

**4.** If it was well installed, you can see the next message:  

```bash
gcc (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4
Copyright (C) 2013 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
**5.** Use all C files and the header file, which contain the libraries and the program functions, to create a new file named simple_shell. Now, you can compilate it typing:

```bash
gcc *.c *.h -o simple_shell
```

**6.** Finally, execute the simple_shell file: 

```bash
./simple_shell
```

## Usage

If you had a successful installation and compilation process, you will see `$`. That means your simple shell program is working and is ready to receive commands:

```bash
$
```

To close the simple shell program, use the key combination  `Crtl + D` or type: 

```bash
$ exit
```
If you want to know how the simple shell program works, please visit the manual page: [Manual simple_shell](https://github.com/andresjjn/simple_shell).

## Examples

Some include functions on the simple shell program are:

**-** Change actual directory
```bash
$ cd (name of directory to move)
```
**-** List all files into the actual directory 
```bash
$ ls
```
**-** List the files in a long format and show the hidden files, using the command options allowed
```bash
$ ls -al
```

## Authors

[Andres Felipe Escobar Cardona](https://github.com/woltfang)
 and [Andrés Felipe Jején Tabares](https://github.com/andresjjn).

## Contributing
Pull requests are welcome. For important changes, please open an issue to discuss the change you would like to improve.

## License
[MIT](https://choosealicense.com/licenses/mit/)