//
// Created by thauvi_a on 5/10/17.
//

#ifndef CPP_PLAZZA_FTP_H
#define CPP_PLAZZA_FTP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>

typedef struct 		s_client
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  socklen_t 		s_in_size;
  int 			fd;
  int 			port;
  int 			client_fd;
  char 			*client_ip;
}			t_client;

typedef struct 		s_data
{
  bool 			isLogin;
  bool			isConnect;
}			t_data;

typedef struct 		s_cmd
{
  int 			nb_w;
  char 			**cmd;
  char 			*buf_tmp;
  char 			**tab;
}			t_cmd;

void		choice(t_cmd *, void (*[])());
void		default_buff(t_cmd *, char *);
void		fill_buff(char*, t_cmd *, void (*[])());
char 		**ma2d(int, int);
bool		check_end(char *);
int 		nb_word(char *);
char 		**cmd_to_tab(char*, char **);
void 		user();
void 		pass();
void 		cwd();
void 		cdup();
void 		quit();
void 		dele();
void 		pwd();
void 		pasv();
void 		port();
void 		help();
void 		noop();



#endif //CPP_PLAZZA_FTP_H
