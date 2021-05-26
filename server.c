// server program for udp connection
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
int main(int argc,char**argv)
{
int sockfd,n;
socklen_t len;
struct sockaddr_in serv_addr,cli_addr;
double tempinc,tempinf,tempink,lengthinkm,lengthinm,lengthincm,lengthinfoot,lengthininch;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(5035);
printf("\n\n Binded");
bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
printf("\n\nListening...");
printf("\n");
len=sizeof(cli_addr);
recvfrom(sockfd,&tempinc,sizeof(tempinc),0,(struct sockaddr*)&cli_addr,&len);
printf("\nClient message for temprature:%lf\n",tempinc);
tempinf=(tempinc*9)/5+32;
tempink=tempinc+273;
sendto(sockfd,&tempinf,sizeof(tempinf),0,(struct sockaddr*)&cli_addr,len);
sendto(sockfd,&tempink,sizeof(tempink),0,(struct sockaddr*)&cli_addr,len);
recvfrom(sockfd,&lengthinkm,sizeof(lengthinkm),0,(struct sockaddr*)&cli_addr,&len);
printf("\nClient message for length:%lf\n",lengthinkm);
lengthinm=lengthinkm*1000;
lengthincm=lengthinkm*100000;
lengthinfoot=lengthinkm*3280.8;
lengthininch=lengthinkm*3280.8*12;
sendto(sockfd,&lengthinm,sizeof(lengthinm),0,(struct sockaddr*)&cli_addr,len);
sendto(sockfd,&lengthincm,sizeof(lengthincm),0,(struct sockaddr*)&cli_addr,len);
sendto(sockfd,&lengthinfoot,sizeof(lengthinfoot),0,(struct sockaddr*)&cli_addr,len);
sendto(sockfd,&lengthininch,sizeof(lengthininch),0,(struct sockaddr*)&cli_addr,len);
return 0;
}