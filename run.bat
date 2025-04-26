cmake -G "MinGW Makefiles" -D CMAKE_CXX_COMPILER=g++64 -S . -B build
cmake --build build
cd bin
consoleCalculator.exe