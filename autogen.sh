#!/bin/bash

DIE=0

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
    echo
    echo "You must have autoconf installed to compile cli-standard."
    echo "Download the appropriate package for your distribution,"
    echo "or see http://www.gnu.org/software/autoconf"
    DIE=1
}

(automake --version) < /dev/null > /dev/null 2>&1 || {
    echo
    echo "You must have automake installed to compile cli-standard."
    echo "Download the appropriate package for your distribution,"
    echo "or see http://www.gnu.org/software/automake"
    DIE=1
}

if [ "$DIE" -eq 1 ]; then
    exit 1
fi

# Replaced by autoreconf below
autoreconf -if

# if [ $? -eq 0 ]; then
#     echo "Now run ./configure <options> to configure application"
# else
#     echo failed
# fi
