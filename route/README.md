## Test

* ./build.sh

            route -n

            Kernel IP routing table
            Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
            192.168.36.0    0.0.0.0         255.255.255.0   U     1      0        0 eth2
            0.0.0.0         192.168.36.2    0.0.0.0         UG    0      0        0 eth2

    * sudo ./build/add_route_ioctl 
    * 
            route -n

            Kernel IP routing table
            Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
            192.168.36.0    0.0.0.0         255.255.255.0   U     1      0        0 eth2
            10.35.7.0       0.0.0.0         255.255.255.0   U     0      0        0 eth2
            0.0.0.0         192.168.36.2    0.0.0.0         UG    0      0        0 eth2

    * sudo ./build/del_route_ioctl 

            route -n

            Kernel IP routing table
            Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
            192.168.36.0    0.0.0.0         255.255.255.0   U     1      0        0 eth2
            0.0.0.0         192.168.36.2    0.0.0.0         UG    0      0        0 eth2

* ./build_gateway.sh

            route -n

            Kernel IP routing table
            Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
            192.168.36.0    0.0.0.0         255.255.255.0   U     1      0        0 eth2
            0.0.0.0         192.168.36.2    0.0.0.0         UG    0      0        0 eth2

    * sudo ./build/add_route_ioctl 

            route -n

            Kernel IP routing table
            Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
            192.168.36.0    0.0.0.0         255.255.255.0   U     1      0        0 eth2
            10.35.7.0       192.168.36.1    255.255.255.0   UG    0      0        0 eth2
            0.0.0.0         192.168.36.2    0.0.0.0         UG    0      0        0 eth2

    * sudo ./build/del_route_ioctl 

            route -n

            Kernel IP routing table
            Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
            192.168.36.0    0.0.0.0         255.255.255.0   U     1      0        0 eth2
            0.0.0.0         192.168.36.2    0.0.0.0         UG    0      0        0 eth2