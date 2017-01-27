/*
** server.h for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/include
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 10:32:51 2016 Christophe Ploujoux
** Last update  Tue May 17 10:32:51 2016 Christophe Ploujoux
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "channel.h"

# define BIND_ERROR "Error with bind\n"
# define LISTEN_ERROR "Error with listen\n"
# define GETPROTO_ERROR "Error with getprotobyname\n"
# define SOCKET_ERROR "Error with socket\n"
# define CLOSE_ERROR "Error with close\n"
# define ACCEPT_ERROR "Error with accept\n"
# define SERVER_FAILED "Server failed to load\n"
# define CONNECT_ERROR "Server failed to connect\n"
# define PROTO_ERROR "Prototype name failed\n"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KBLU  "\x1B[34m"

typedef struct  t_server
{
  char          **cmd;
  char          **cmd_server;
  char          **cmd_list;
  t_channel 	channel;
  int           port;
  char          *ip;
  int           sock;
  int           status;
  fd_set        fd_read;
}               t_server;

void	xbind(int fd, const struct sockaddr *s, size_t size);
void	xlisten(int fd, int backlog);
int	  xsocket(int domain, int type, int protocol);
int   xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void	xconnect(int sockfd, struct sockaddr *addr, size_t size);

void	my_putstr(int fd, char *str);
char	*get_next_line(int fd);
char	**split_cmd(char *str, const char *sep);
void 	my_cmd(char **cmd);
char	*my_strcat(char *dest, char *src);
void	init_cmd(void (*fct[9])(t_server *));

void  cmd_server(t_server *server);
void  cmd_nick(t_server *server);
void  cmd_list(t_server *server);
void  cmd_join(t_server *server);
void  cmd_part(t_server *server);
void  cmd_users(t_server *server);
void  cmd_msg(t_server *server);
void  cmd_quit(t_server *server);
void  cmd_names(t_server *server);
void  cmd_send_file(t_server *server);
void  cmd_accept_file(t_server *server);

void  handle_server(t_server *server);

int	check_arg(int ac, char **av);
void fill_list(t_server *server);

#endif /* !CLIENT_H_ */
