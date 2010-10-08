Current directory is ~/Development/REGIS/CS372/MergeSort/
GNU gdb (GDB) 7.1-ubuntu
Copyright (C) 2010 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /home/trentonknight/Development/REGIS/CS372/MergeSort/out...done.
(gdb) break merge
Breakpoint 1 at 0x400a5e: file main.cpp, line 41.
(gdb) run
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Breakpoint 1, merge (list=0x7fffffffe1d0, lo=0, m=0, hi=1) at main.cpp:41
(gdb) display *list
1: *list = 1
(gdb) display *tempL
2: *tempL = 1667391840
(gdb) n
2: *tempL = 0
1: *list = 1
(gdb) n
2: *tempL = 0
1: *list = 1
(gdb) n
2: *tempL = 0
1: *list = 1
(gdb) n
2: *tempL = 0
1: *list = 1
(gdb) n
2: *tempL = 0
1: *list = 1
(gdb) n
2: *tempL = 0
1: *list = 1
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
1: *list = 0
(gdb) n
mergesort (list=0x7fffffffe1d0, lo=0, hi=1) at main.cpp:36
(gdb) n
mergesort (list=0x7fffffffe1d0, lo=0, hi=2) at main.cpp:33
(gdb) n
(gdb) n

Breakpoint 1, merge (list=0x7fffffffe1d0, lo=0, m=1, hi=2) at main.cpp:41
2: *tempL = -7936
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
2: *tempL = 0
1: *list = 0
(gdb) n
1: *list = 0
(gdb) d
Delete all breakpoints? (y or n) y
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
`/home/trentonknight/Development/REGIS/CS372/MergeSort/out' has changed; re-reading symbols.
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8
  <tool-bar> <stop>

Program received signal SIGINT, Interrupt.
0x0000000000400aa3 in merge (list=0x7fffffffe1d0, lo=0, m=0, hi=1) at main.cpp:45
(gdb) break merge
Breakpoint 2 at 0x400a5e: file main.cpp, line 42.
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Breakpoint 2, merge (list=0x7fffffffe1d0, lo=0, m=0, hi=1) at main.cpp:42
(gdb) n
(gdb) n
(gdb) display *list
3: *list = 1
(gdb) display *temp
4: *temp = 0
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) c
Continuing.

  <tool-bar> <stop>
Program received signal SIGINT, Interrupt.
0x0000000000400a91 in merge (list=0x7fffffffe1d0, lo=0, m=0, hi=1) at main.cpp:45
4: *temp = 1
3: *list = 1n
Continuing.
3: *list = 1n
n
n
  <tool-bar> <stop>run
Program received signal SIGINT, Interrupt.
0x0000000000400ac3 in merge (list=0x7fffffffe1d0, lo=0, m=0, hi=1) at main.cpp:44
4: *temp = 1
3: *list = 1
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Breakpoint 2, merge (list=0x7fffffffe1d0, lo=0, m=0, hi=1) at main.cpp:42
4: *temp = 1667391840
3: *list = 1
(gdb) n
4: *temp = 0
3: *list = 1
(gdb) n
4: *temp = 0
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) n
4: *temp = 1
3: *list = 1
(gdb) 
4: *temp = 1
3: *list = 1

(gdb) 4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) 
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) s
4: *temp = 1
3: *list = 1
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
`/home/trentonknight/Development/REGIS/CS372/MergeSort/out' has changed; re-reading symbols.
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Program received signal SIGSEGV, Segmentation fault.
0x00000000004009e1 in mergesort (list=Cannot access memory at address 0x7fffff5aeff8
) at main.cpp:28
(gdb) quit
A debugging session is active.

	Inferior 1 [process 7996] will be killed.

Quit anyway? (y or n) y

Debugger finished
Current directory is ~/Development/REGIS/CS372/MergeSort/
GNU gdb (GDB) 7.1-ubuntu
Copyright (C) 2010 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /home/trentonknight/Development/REGIS/CS372/MergeSort/out...done.
(gdb) run
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Program received signal SIGSEGV, Segmentation fault.
0x00000000004009e1 in mergesort (list=Cannot access memory at address 0x7fffff5aeff8
) at main.cpp:28
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
`/home/trentonknight/Development/REGIS/CS372/MergeSort/out' has changed; re-reading symbols.
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8
after: -7808
after: -7728
after: 32767
after: 32767
after: 4196941
after: 0
after: 10
after: 6
after: 6299744
after: 0

Program exited normally.
(gdb) run
`/home/trentonknight/Development/REGIS/CS372/MergeSort/out' has changed; re-reading symbols.
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Program received signal SIGSEGV, Segmentation fault.
0x00007fffffffe1d0 in ?? ()
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
`/home/trentonknight/Development/REGIS/CS372/MergeSort/out' has changed; re-reading symbols.
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Program received signal SIGSEGV, Segmentation fault.
0x00007fffffffe1d0 in ?? ()
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8

Program received signal SIGSEGV, Segmentation fault.
0x00007fffffffe1d0 in ?? ()
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
`/home/trentonknight/Development/REGIS/CS372/MergeSort/out' has changed; re-reading symbols.
Starting program: /home/trentonknight/Development/REGIS/CS372/MergeSort/out 
before: 1
before: 19
before: 2
before: 10
before: 6
before: 5
before: 4
before: 7
before: 9
before: 8
after: -7808
after: -7728
after: 32767
after: 32767
after: 4196941
after: 0
after: 10
after: 6
after: 6299744
after: 0

Program exited normally.
(gdb) break merge
Breakpoint 1 at 0x400a65: file main.cpp, line 43.
(gdb) display *list
(gdb) display *tempArray