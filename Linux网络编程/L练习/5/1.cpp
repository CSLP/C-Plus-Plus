#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
int main(int argc,char*argv[])
{
    int i;
    struct hostent *host;
    // host=gethostbyname(argv[1]);
    // printf("official name:%s\n",host->h_name);
    // for(i =0;host->h_aliases[i];i++)
    //     printf("Aliases %d:%s\n",i+1,host->h_aliases[i]);
    // printf("Address type:%s\n",(host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");
    // for(i=0;host->h_addr_list[i];i++)
    //     printf("IP addr %d:%s\n",i+i,inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_addr.s_addr=inet_addr(argv[1]);
    host=gethostbyaddr((char*)&addr.sin_addr,4,AF_INET); 
    printf("%s\n",host->h_name);
    for(i =0;host->h_aliases[i];i++)
        printf("Aliases %d:%s\n",i+1,host->h_aliases[i]);
    printf("Address type:%s\n",(host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");
    for(i=0;host->h_addr_list[i];i++)
        printf("IP addr %d:%s\n",i+i,inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
    return 0;
}