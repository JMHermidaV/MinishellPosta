
# La variable CC indica el ejecutable para el compilador C (usualmente son gcc o clang)
CC=gcc
# La variable CFLAGS indica las banderas para el compilador C
CFLAGS=-Wall -Wextra -std=gnu99 -ggdb
# La variable LDLIBS indica las banderas para la parte del "loader", usualmente librerías "-lxxxx"
# LDLIBS=

# Este sería el ejecutable, sus dependencias son los .o
minish:   minish.o builtin_cd.o builtin_dir.o builtin_status.o builtin_exit.o linea2argv.o ejecutar.o externo.o builtin_lookup.o builtin_pid.o builtin_uid.o builtin_gid.o builtin_help.o builtin_getenv.o builtin_dir.o builtin_setenv.o builtin_unsetenv.o bubblesort.o

# Acá van los .o, make sabe que cada .o depende del .c correspondiente, acá se agrega la dependencia al .h
minish.o: minish.h
builtin_cd.o: minish.h
linea2argv.o: minish.h
builtin_uid.o: minish.h
builtin_lookup.o: minish.h
ejecutar.o: minish.h
builtin_help.o: minish.h
builtin_getenv.o: minish.h
builtin_dir.o: minish.h
builtin_status.o: minish.h
builtin_setenv.o: minish.h
builtin_unsetenv.o: minish.h
builtin_pid.o: minish.h
builtin_gid.o: minish.h
builtin_dir.o: minish.h
builtin_exit.o: minish.h
bubblesort.: minish.h