## CMake
The tests for this project is run using CMake together with the Catch unit-test framework.

Instructions of how to run the tests:
```
> cd $test_path
> mkdir build
> cd build
> cmake 
> cmake --build .
> ctest 
```

I currently use this config while running the ctest command:
```
> ctest -C Debug -V -R
```