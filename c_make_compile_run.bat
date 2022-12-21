cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\studentai10000.txt Debug\studentai10000.txt
copy src\studentai10000.txt Debug\studentai100000.txt
copy src\studentai10000.txt Debug\studentai1000000.txt
Debug\v1.2.exe