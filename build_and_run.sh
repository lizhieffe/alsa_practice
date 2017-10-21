#!/bin/bash

g++ \
  main.cc \
  print_alsa_info.cc \
  -lasound -ldl -lm && ./a.out
