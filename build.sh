#!/bin/bash
if [ -d build ]
then
  cd ./build
  # rm -rf ./build
else
  mkdir build
  cd ./build
  cmake -G "Unix Makefiles" ..
fi

cmake --build .
