
cd ../build

cmake ^
    -G "Visual Studio 15 2017 Win64" ^
    ^
    -D CMAKE_CXX_FLAGS=" /EHsc /MP4" ^
    ^
    ..

cd ../scripts