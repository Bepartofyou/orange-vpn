#!/bin/sh

if [ ! -d "./build" ];then
	mkdir build
fi

sed -i 's/add_definitions/#add_definitions/g'  ./CMakeLists.txt

cd build && cmake ../ && make
