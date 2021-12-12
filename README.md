[![CMake CI](https://github.com/Gabau/cresser-private/actions/workflows/cmake.yml/badge.svg)](https://github.com/Gabau/cresser-private/blob/master/.github/workflows/cmake.yml)


# Cresser

LZ77 Compression ultility project. Cresser is an encoding application that is capable
of reducing the size of relatively large files through the lz77 algorithm. 
Cresser can be used through the following command format,

```
cresser [input_file] -o [output_file]
```
to encode the file in the output of the algorithm. Cresser can also be used to 
decode files encoded by cresser through the addition of an extra flag.

```
cresser [input_file] -o [output_file] -d
```
which would allow cresser to decode the input file.

## Installation



## Acknowledgements

 * [Cmake code coverage script](https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake)
 * [Cmake](https://cmake.org/)
 * [Resources for lz77](https://en.wikipedia.org/wiki/LZ77_and_LZ78)



