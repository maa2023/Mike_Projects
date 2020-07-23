#!/bin/bash
make -f Makefile || exit
echo config3.txt | ./a.out