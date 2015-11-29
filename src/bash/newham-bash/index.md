# Learning the bash Shell

- p. ix - Since changing shells is as easy as changing hats, ...
- Bourne Again shell (bash), Korn shell (ksh), tektronix C shell (tcsh)
- `echo $BASH_VERSION`
- p. 1 - Ultrix, AIX, Xenix, SunOS, Linux
- character-based user interfaces, graphical user interfaces (GUI)
- p. 3 - Stephen R. Bourne
- p. 5 - `echo $SHELL`
- p. 6 - Ctrl+D
- p. 7 - there are different types of files
    - regular files, executable files, directories
- p. 8 - full pathname = absolute pathname
- p. 9 - working directory = current directory
- full pathname /= relative pathname
- home directory = login directory
- cd, pwd
- p. 11 - MS-DOS and VAX/VMS users should note that there is *nothing special* about the dot (.) in UNIX filenames (aside from the leading dot, which "hides" the file); it's just another character. For example, `ls *` lists all files in the current directory; you don't need `*.*` as you do on other systems. Indeed, `ls *.*` won't list all the files---only those that have at least one dot in the middle of the name.
- p. 13 - However, it's important to be aware that the commands that you run only see the results of wildcard expansion.
- p. 14 - `echo b{ed,olt,ar}s`
- standard input, standard output, standard error (output)
- p. 15 - a pipeline, in which the standard output of one program feeds directly into the standard input of another;
- cat, grep, sort, cut, sed, tr
- p. 16 - I/O redirection
- p. 18 - background jobs
- p. 19 - `jobs`
- p. 25 - Ctrl+M = Return
- stty --all
- Ctrl+? = Erase last character
- p. 26 - Ctrl+H = Backspace
- Ctrl+U = Erase characters before the caret
- tty driver

## 2. Command-Line Editing

- p. 29 - two most popular UNIX editors,*vi* and *emacs*.
- p. 58 - Ctrl+A = beginning of line
- Ctrl+E = end of line
- Ctrl+F = next character
- Ctrl+B = previous character
- Ctrl+P = previous history
- Ctrl+N = next history
- Tab = file name completion

