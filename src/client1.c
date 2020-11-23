#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

	int sd,sd2,n ;
char  buff[1024] ;
struct sockaddr_in  ad; 
ad.sin_family=AF_INET;
ad.sin_port=htons(2323);
inet_aton("127.0.0.1",&ad.sin_addr);

	if((sd=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP))<0){
		printf("erreur socket : %s \n",strerror(errno));
                exit(1);

	}


if(connect(sd,(struct sockaddr *)&ad,sizeof(ad))<0){
        printf("erreur connect :%s\n",strerror(errno));
        exit(2);
}

while(1){
n=recv(sd,buff,sizeof(buff),0);
buff[n]='\0';
printf("server -----> :%s\n",buff);
gets(buff);
send(sd,buff,strlen(buff),0);
memset(buff,'\0',1024);

}

}

