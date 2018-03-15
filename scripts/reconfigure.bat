
cd ../build

cmake ^
    ^
    -D CMAKE_CXX_FLAGS_RELEASE="/EHsc /MP4 /MT" ^
    -D CMAKE_CXX_FLAGS_DEBUG="/EHsc /MP4 /MT" ^
    ^
    -D GTEST_ROOT="C:/Program Files (x86)/googletest-distribution" ^
    ^
    ..

cd ../scripts