# Learn Modern C++

## Build

```
apt install binutils-dev    # for backward-cpp

cmake --preset=default -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Run

```
build/main
```

## Test

```
ctest --test-dir build

# or
cd build && ctest

# or
build/test1
build/test2
```
