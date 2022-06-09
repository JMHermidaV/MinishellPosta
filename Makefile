
# La variable CC indica el ejecutable para el compilador C (usualmente son gcc o clang)
CC=gcc
# La variable CFLAGS indica las banderas para el compilador C
CFLAGS=-Wall -Wextra -std=gnu99 -ggdb
# La variable LDLIBS indica las banderas para la parte del "loader", usualmente librerías "-lxxxx"
# LDLIBS=

# Este sería el ejecutable, sus dependencias son los .o
minish:   minish.o builtin_cd.o linea2argv.o ejecutar.o externo.o builtin_lookup.o builtin_uid.o

# Acá van los .o, make sabe que cada .o depende del .c correspondiente, acá se agrega la dependencia al .h
minish.o: minish.h
builtin_cd.o: minish.h
linea2argv.o: minish.h
builtin_uid.o: minish.h
builtin_lookup.o: minish.h
ejecutar.o: minish.h