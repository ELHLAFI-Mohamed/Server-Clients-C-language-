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
if(bind(sd,(struct sockaddr *)&ad,sizeof(ad))<0){
printf("erreur bind :%s \n",strerror(errno));
exit(2);
}
listen(sd,100);
int taille =sizeof(ad);

while(1){
if((sd2=accept(sd,(struct sockaddr *)&ad,&taille))<0){
printf("erreur bind :%s \n",strerror(errno));
exit(2);
                }

printf("connexion d'un client:%s\n ",inet_ntoa(ad.sin_addr));


if(fork()==0){
close(sd);
while(1){   
gets(buff);
send(sd2,buff,strlen(buff),0);
n=recv(sd2,buff,sizeof(buff),0);
buff[n]='\0';
printf("client ------>  :%s\n",buff);

}
}
close(sd2);


}

}

