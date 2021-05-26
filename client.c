// udp client driver program
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(int argc,char*argv[])
{
int sockfd,n,n1,n2,n3;
socklen_t len;
struct sockaddr_in serv_addr;
double tempinc,tempinf,tempink=0,lengthinkm,lengthinm=0,lengthincm=0,lengthinfoot=0,lengthininch=0;
printf("\n Enter temperature in centigrade:");
scanf("%lf",&tempinc);
sockfd=socket(AF_INET,SOCK_DGRAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_addr.sin_port=htons(5035);
len =sizeof(serv_addr);
sendto(sockfd,&tempinc,sizeof(tempinc),0,(struct sockaddr*)&serv_addr,len);
recvfrom(sockfd,&tempinf,sizeof(tempinf),0,NULL,NULL);
recvfrom(sockfd,&tempink,sizeof(tempink),0,NULL,NULL);
printf("\n Enter length in km:");
scanf("%lf",&lengthinkm);
sendto(sockfd,&lengthinkm,sizeof(lengthinkm),0,(struct sockaddr*)&serv_addr,len);
recvfrom(sockfd,&lengthinm,sizeof(lengthinm),0,NULL,NULL);
recvfrom(sockfd,&lengthincm,sizeof(lengthincm),0,NULL,NULL);
recvfrom(sockfd,&lengthinfoot,sizeof(lengthinfoot),0,NULL,NULL);
recvfrom(sockfd,&lengthininch,sizeof(lengthininch),0,NULL,NULL);
printf("\n Server's conversion: tempreture in farheniet-%lf , in kelvin-%lf\n\n",tempinf,tempink);
printf("\n Server's conversion: length in meter-%lf , in centimeter-%lf, in foot-%lf, in inch-%lf\n\n",lengthinm,lengthincm,lengthinfoot,lengthininch);
return 0;
}
