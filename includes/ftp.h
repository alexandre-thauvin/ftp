//
// Created by thauvi_a on 5/10/17.
//

#ifndef CPP_PLAZZA_FTP_H
#define CPP_PLAZZA_FTP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
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
  char 			*path;
}			t_client;

typedef struct 		s_data
{
  bool			isLogin;
  bool			isConnect;
  char 			*pseudo;
  char 			*path;
}			t_data;

typedef struct 		s_cmd
{
  unsigned int 		nb_w;
  char 			**cmd;
  char 			*buf_tmp;
  char 			**tab;
  t_data		*data;
  t_client		*client;
}			t_cmd;

void		choice(t_cmd *);
int		nb_line(char **tab);
void		default_buff(t_cmd *, char *);
void		fill_buff(char*, t_cmd *);
char 		**ma2d(int, int);
bool		check_end(char *);
unsigned int 	nb_word(char *);
char 		**cmd_to_tab(char*, char **, int);
void 		user(t_cmd *);
void 		pass(t_cmd *);
void 		cwd(t_cmd *);
void 		cdup(t_cmd *);
void 		quit(t_cmd *);
void 		dele(t_cmd *);
void 		pwd(t_cmd *);
void 		pasv(t_cmd *);
void 		port(t_cmd *);
void 		help(t_cmd *);
void 		noop(t_cmd *);

#endif //CPP_PLAZZA_FTP_H
