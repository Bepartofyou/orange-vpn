cmake_minimum_required(VERSION 2.8)
project(route)

add_definitions(-D_GATEWAY)

add_executable(add_route_ioctl add_route_ioctl.c)
add_executable(del_route_ioctl del_route_ioctl.c)
