# Практическое задание номер 1
[![Build Status](https://travis-ci.com/HENRYHKll/gb_cxx_basic_level.svg?branch=main)](https://travis-ci.com/HENRYHKll/gb_cxx_basic_level)

* Скачайте и настройте на компьютере среду программирования. Не важно, какой именно инструментарий Вы выберете, главное, чтобы Вы понимали как с использованием выбранного Вами инструментария выполнять компиляцию и запуск исходного кода, а также осуществлять управление компиляцией. Результат выполнения задания:
  
  - Архив с файлами исходного кода приложения “Привет, мир”

  - Приложите в архив скриншот с результатом выполнения программы с использованием Вашего инструментария.

* Приложите в архив промежуточные файлы компиляции
  
* Скомпилируйте исходный код со строкой “Привет, мир”, а скомпилированный файл ассемблируйте и скомпонуйте со строкой “Привет, Geekbrains”. Приложите файл программы с изменённым приветствием.


```sh
$ git clone https://github.com/HENRYHKll/gb_cxx_basic_level.git
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
