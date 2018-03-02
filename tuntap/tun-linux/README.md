## Test

* ./build.sh

        ifconfig

        eth2    Link encap:Ethernet  HWaddr   00:0C:29:51:3D:BC  
                inet addr:192.168.36.128  Bcast:192.168.36.255  Mask:255.255.255.0
                inet6 addr: fe80::20c:29ff:fe51:3dbc/64 Scope:Link
                UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
                RX packets:30759 errors:0 dropped:0 overruns:0 frame:0
                TX packets:29724 errors:0 dropped:0 overruns:0 carrier:0
                collisions:0 txqueuelen:1000 
                RX bytes:10396865 (9.9 MiB)  TX bytes:5282674 (5.0 MiB)

        lo      Link encap:Local Loopback  
                inet addr:127.0.0.1  Mask:255.0.0.0
                inet6 addr: ::1/128 Scope:Host
                UP LOOPBACK RUNNING  MTU:65536  Metric:1
                RX packets:4 errors:0 dropped:0 overruns:0 frame:0
                TX packets:4 errors:0 dropped:0 overruns:0 carrier:0
                collisions:0 txqueuelen:0 
                RX bytes:240 (240.0 b)  TX bytes:240 (240.0 b)

    * sudo ./build/add_tun_linux 

          ifconfig
        
          eth2  Link encap:Ethernet  HWaddr 00:0C:29:51:3D:BC  
                inet addr:192.168.36.128  Bcast:192.168.36.255  Mask:255.255.255.0
                inet6 addr: fe80::20c:29ff:fe51:3dbc/64 Scope:Link
                UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
                RX packets:30816 errors:0 dropped:0 overruns:0 frame:0
                TX packets:29768 errors:0 dropped:0 overruns:0 carrier:0
                collisions:0 txqueuelen:1000 
                RX bytes:10403536 (9.9 MiB)  TX bytes:5290460 (5.0 MiB)

          lo    Link encap:Local Loopback  
                inet addr:127.0.0.1  Mask:255.0.0.0
                inet6 addr: ::1/128 Scope:Host
                UP LOOPBACK RUNNING  MTU:65536  Metric:1
                RX packets:4 errors:0 dropped:0 overruns:0 frame:0
                TX packets:4 errors:0 dropped:0 overruns:0 carrier:0
                collisions:0 txqueuelen:0 
                RX bytes:240 (240.0 b)  TX bytes:240 (240.0 b)

          tun0  Link encap:UNSPEC  HWaddr 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  
                inet addr:10.168.1.11  P-t-P:10.168.1.11  Mask:255.255.255.255
                UP POINTOPOINT RUNNING NOARP MULTICAST  MTU:65535  Metric:1
                RX packets:0 errors:0 dropped:0 overruns:0 frame:0
                TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
                collisions:0 txqueuelen:500 
                RX bytes:0 (0.0 b)  TX bytes:0 (0.0 b)