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

## 4. Basic Shell Programming

- p. 82 - スクリプトファイルを実行するには、組み込み命令である source を用いるか、ファイル名を直接指定する。ファイル名を直接指定する場合、もし環境変数によってパスが通っていないならば、./example.sh などとしてディレクトリを明示する必要がある。
- なお、source を用いた場合には同じプロセスで実行され、用いない場合にはサブプロセス（サブシェル）で実行される。subprocess、subshell。
- 一般に、コマンドの末尾に & を添えた場合、サブプロセスで実行される。ただし、& においては、親プロセスを非同期に操作できる。（対して、単にサブプロセスを実行した場合には、同期的に、すなわち親プロセスはサブプロセスの終了を待機する。）
- p. 86 - SNOBOL

