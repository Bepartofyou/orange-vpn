#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <net/route.h>
#include <sys/types.h>
#include <sys/ioctl.h>

int main(char** args) {

#if !defined(_GATEWAY)
  int sockfd;
  struct rtentry route;
  struct sockaddr_in *addr;
  int err = 0;
  
  // create the socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1)  {
    perror("Socket failed");
    return -1;
  }
  // set route struct to zero
  memset(&route, 0, sizeof(route));
  // assign the default gateway
  //addr = (struct sockaddr_in*) &route.rt_gateway;
  //addr->sin_family = AF_INET;
  //addr->sin_addr.s_addr = inet_addr("0.0.0.0");
  // assign the destination
  addr = (struct sockaddr_in*) &route.rt_dst;
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = inet_addr("10.35.7.0");
  // assign the destination mask
  addr = (struct sockaddr_in*) &route.rt_genmask;
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = inet_addr("255.255.255.0");
  // set the flags NET/UP
  route.rt_dev = "eth2";
  route.rt_flags = RTF_UP ;
  //route.rt_flags = RTF_UP | RTF_GATEWAY;
  // make the ioctl
  if ((err = ioctl(sockfd, SIOCADDRT, &route)) != 0) {
    perror("SIOCADDRT failed");
    return -1;
  }

#else

  int sockfd;
  struct rtentry route;
  struct sockaddr_in *addr;
  int err = 0;

  // create the socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1)  {
	  perror("Socket failed");
	  return -1;
  }
  // set route struct to zero
  memset(&route, 0, sizeof(route));
  // assign the default gateway
  addr = (struct sockaddr_in*) &route.rt_gateway;
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = inet_addr("192.168.36.1");
  // assign the destination
  addr = (struct sockaddr_in*) &route.rt_dst;
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = inet_addr("10.35.7.0");
  // assign the destination mask
  addr = (struct sockaddr_in*) &route.rt_genmask;
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = inet_addr("255.255.255.0");
  // set the flags NET/UP
  route.rt_dev = "eth2";
  route.rt_flags = RTF_UP | RTF_GATEWAY;
  // make the ioctl
  if ((err = ioctl(sockfd, SIOCADDRT, &route)) != 0) {
	  perror("SIOCADDRT failed");
	  return -1;
  }

#endif
}
