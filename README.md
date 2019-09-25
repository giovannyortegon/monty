# Monty bytecode interpreter

This is an interpreter for Monty 0.98 scripting language. 


## Environment
-   Ubuntu 14.04 LTS
-   Vagrant
-   VirtualBox

## Output
Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

````
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$
````

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

````
```
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$
```
````
## Some examples
Note: Please see [File Descriptions](https://github.com/bchen528/monty#file-descriptions) <- need correction for all the opcode definitions.
```
$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ./monty bytecodes/07.m 
3
2
1
2
1
1
```
```
$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m 
1
2
3
```
```
$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
$ ./monty bytecodes/09.m 
3
2
1
2
3
1
```
## Setup

```
git clone https://github.com/Skillhh/monty.git
```

## Compilation

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Export a file

You can export the current file by clicking **Export to disk** in the menu. You can choose to export the file as plain Markdown, as HTML using a Handlebars template or as a PDF.


## Description of File Structure

-   [monty.c](https://github.com/Skillhh/monty/blob/master/monty.c)  - contains main function
    -   `main`  - takes filename(s) as an argument
-   [parse.c](https://github.com/bchen528/monty/blob/master/parse.c)  - contains parse function
    -   `parse`  - parses commandline input into tokens
-   [eval.c](https://github.com/bchen528/monty/blob/master/eval.c)  - contains eval function
    -   `eval`  - evaluate operation given commandline input, stack/queue mode, and line number of file
