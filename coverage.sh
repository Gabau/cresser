#!/bin/bash

# use to generate coverage report

# mkdir -p build
# cd build
# cmake -G Ninja build ../
# ninja
# ninja cresser_coverage
# xdg-open cresser_coverage/index.html

# Used to generate codecov report

lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info '/usr/*' "${HOME}"'/.cache/*' --output-file coverage.info
lcov --list coverage.info
# Upload to codecov
bash <(curl -s https://codecov.io/bash) -f coverage.info || echo "Codecov did not collect coverage reports"