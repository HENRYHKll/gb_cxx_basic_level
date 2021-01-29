# Основы C++ Geekbrains

```sh
$ git clone git@github.com:HENRYHKll/gamedev.git
$ #home work
$ g++ -E main.cxx -o main.ii
$ g++ -S main.ii -o main.s
$  10 .LC0:
$  11	.string	"Hello Wolrd!" //- make edit "Bye bye Wolrd!"
$ as main.s -o main.o
$ g++ main.o -o main
$ ./main
$ #Bye bey Wolrd!
$
$ #build Project
$ mkdir build
$ cd build
$ cmake -G Ninja .. 
$ cmake --build .
```