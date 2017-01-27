/*
** server.h for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/include
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 10:32:51 2016 Christophe Ploujoux
** Last update  Tue May 17 10:32:51 2016 Christophe Ploujoux
*/

#ifndef SERVER_H_
# define SERVER_H_

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
# define USAGE_ERROR "Usage: ./server port\n"

# define  ERR_NEEDMOREPARAMS "461 Not enough parameters"

# define MAX_NICK 9
# define MAX_USER 255
# define MAX_CHAN 255

typedef enum e_status
{
  NOTHING = 0,
  NICK,
  REGISTERED
}            t_status;

typedef struct  s_user
{
  t_channel     channel;
  char          **cmd;
  char          *ip;
  int           fd;
  char          *nick;
  char          *name;
  t_status      status;
}               t_user;

typedef struct	s_server
{
  int     sock;
  t_channel channel;
  int     port;
  int     max_fd;
  char		*server_ip;
  t_user  users[MAX_USER];
  fd_set  fd_read;
  char		**cmd_list;
}		t_server;

void	xbind(int fd, const struct sockaddr *s, size_t size);
void	xlisten(int fd, int backlog);
int	  xsocket(int domain, int type, int protocol);
int   xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void	xconnect(int sockfd, struct sockaddr *addr, size_t size);

void	my_putstr(int fd, char *str);
char	*get_next_line(int fd);
char	**split_cmd(char *str, const char *sep);
void  my_cmd(char **cmd);
char	*my_strcat(char *dest, char *src);
void	init_cmd_connected(void (*fct[9])(t_user *, t_server *));

void  handle_clients(t_user *user, t_server *server);
void  execute_command(t_user *user, t_server *server);
void add_client(t_server *server);

void add_server(t_server *server);
void server_read(t_server *server);
void handle_server(t_server *server);
void names_channel(t_user *user, t_server *server, char *channel, int type);
void write_end(t_user *user, char *channel);
int  count_user(t_server *server, char *chan);
void  msg_to_all(t_server *server, char *chan, char *str);

void  msg_nick(t_user *user, t_server *server);
void  msg_channel(t_user *user, t_server *server);

void	cmd_user(t_user *user, t_server *server);
void	cmd_pass(t_user *user, t_server *server);
void  cmd_quit(t_user *user, t_server *server);
void  cmd_join(t_user *user, t_server *server);
void  cmd_nick(t_user *user, t_server *server);
void  cmd_part(t_user *user, t_server *server);
void  cmd_list(t_user *user, t_server *server);
void  cmd_names(t_user *user, t_server *server);
void	cmd_priv_msg(t_user *user, t_server *server);

int	check_arg(int ac, char **av);
char	**fill_list();

#endif /* !SERVER_H_ */
