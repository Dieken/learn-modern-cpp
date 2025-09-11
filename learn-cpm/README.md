# Learn Modern C++

## Build

```
apt install binutils-dev    # for backward-cpp

export CPM_SOURCE_CACHE=$HOME/.cache/CPM
cmake -GNinja -Bbuild -DCMAKE_BUILD_TYPE=Debug
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
