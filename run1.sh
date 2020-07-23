#!/bin/bash
make -f Makefile || exit
echo config1.txt | ./a.out