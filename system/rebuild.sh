#!/bin/sh -x
if [ "x$1" = "xcc" ]; then
    rm -r *.out
else
    gcc -o pthread_sample_of_man.out pthread_sample_of_man.c -pthread
    gcc -o pthread-mutex-test.out pthread-mutex-test.c -pthread
    g++ -D _GNU_SOURCE -D _XOPEN_SOURCE -D _POSIX_C_SOURCE -o gnu-source-test.out gnu-source-test.c
fi
set +x
