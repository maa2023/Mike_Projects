#!/bin/bash
make -f Makefile || exit
echo config2.txt | ./a.out