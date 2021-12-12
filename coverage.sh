#!/bin/bash

# use to generate coverage report

mkdir -p build
cd build
cmake -G Ninja build ../
ninja
ninja cresser_coverage


