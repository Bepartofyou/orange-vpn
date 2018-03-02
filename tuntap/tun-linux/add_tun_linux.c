#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <errno.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <net/route.h>
#include <linux/if.h>
#include <linux/if_tun.h>

char interface_name[IFNAMSIZ] = "tun0";

int main(int argc, char** argv){

	int  fd;
	struct ifreq ifr;
	int err;

	if ((fd = open("/dev/net/tun", O_RDWR)) < 0)
	{
		printf("Error open :%d :%s\n", errno, strerror(errno));
		return -1;
	}

	memset(&ifr, 0, sizeof(ifr));
	ifr.ifr_flags |= IFF_TUN | IFF_NO_PI;

	if (*interface_name != '\0')
		strncpy(ifr.ifr_name, interface_name, IFNAMSIZ);

	if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0)
	{
		printf("Error TUNSETIFF :%d :%s\n", errno, strerror(errno));
		return -1;
	}

	strcpy(interface_name, ifr.ifr_name);

	//interface up
	int s;
	if((s = socket(PF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("Error create socket :%d :%sn", errno, strerror(errno));
		return -1;
	}

	struct ifreq ifr_i;
	strcpy(ifr_i.ifr_name, interface_name);

	short flag;
	flag = IFF_UP;
	if(ioctl(s, SIOCGIFFLAGS, &ifr_i) < 0)
	{
		printf("Error up SIOCGIFFLAGS %s :%d :%s\n",interface_name, errno, strerror(errno));
		return -1;
	}

	ifr_i.ifr_ifru.ifru_flags |= flag;
	if(ioctl(s, SIOCSIFFLAGS, &ifr_i) < 0)
	{
		printf("Error up SIOCSIFFLAGS %s :%d :%s\n",interface_name, errno, strerror(errno));
		return -1;
	}

	ifr_i.ifr_ifru.ifru_mtu = 65535; //max
	if(ioctl(s, SIOCSIFMTU, &ifr_i) < 0)
	{
		printf("Error mtu SIOCSIFMTU %s :%d :%s\n",interface_name, errno, strerror(errno));
		return -1;
	}

	//add ip
	struct ifreq ifr_ip;
	strcpy(ifr_ip.ifr_name, interface_name);

	struct sockaddr_in addr;
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = PF_INET;
	inet_aton("10.168.1.11", &addr.sin_addr);

	memcpy(&ifr_ip.ifr_ifru.ifru_addr, &addr, sizeof(struct sockaddr_in));

	if(ioctl(s, SIOCSIFADDR, &ifr_ip) < 0)
	{
		printf("Error set SIOCSIFADDR %s ip :%d :%s\n",interface_name, errno, strerror(errno));
		return -1;
	}

	pause();
	return 0;
}
