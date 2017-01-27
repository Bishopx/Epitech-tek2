/*
** server.h for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/include
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Wed May	11 12:51:13 2016 Christophe Ploujoux
** Last update	Wed May	11 12:51:13 2016 Christophe Ploujoux
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

# define BIND_ERROR "Error with bind\n"
# define CONNECT_ERROR "Error with connect\n"
# define LISTEN_ERROR "Error with listen\n"
# define GETPROTO_ERROR "Error with getprotobyname\n"
# define SOCKET_ERROR "Error with socket\n"
# define CLOSE_ERROR "Error with close\n"
# define ACCEPT_ERROR "Error with accept\n"
# define SERVER_FAILED "Server failed to load\n"
# define PROTO_ERROR "Prototype name failed\n"
# define USAGE_ERROR "Usage: ./server port path_to_folder\n"
# define CRLF "\r\n"

typedef struct	s_transfert
{
  int		socket;
  int		port;
  char		*ip;
}		t_transfert;

typedef struct	s_server
{
  int		sock;
  t_transfert	transfert;
  char		**cmd_list;
  int		status;
  char		*server_ip;
  char		*response;
  char		**cmd;
  char    *path;
}		t_server;

void	xbind(int fd, const struct sockaddr *s, size_t size);
void	xlisten(int fd, int backlog);
int	xsocket(int domain, int type, int protocol);
int	xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void	xconnect(int sockfd, struct sockaddr *addr, size_t size);

void	my_putstr(int fd, char *str);
char	*get_next_line(int fd);
char	**split_cmd(char *str);
int	read_code(char *str);
void	change_path(t_server *server);
char	*my_strcat(char *dest, char *src);

void	handle_server(t_server *server);
void	execute(t_server *server);

void	cmd_pwd(t_server *server);
void	cmd_cd(t_server *server);
void	cmd_quit(t_server *server);
void	cmd_ls(t_server *server);
void  cmd_get(t_server *server);
void	cmd_mget(t_server *server);
void  cmd_put(t_server *server);
void	cmd_mput(t_server *server);
void	cmd_user(t_server *server);
void	cmd_password(t_server *server);
void	cmd_delete(t_server *server);
void	cmd_lls(t_server *server);
void	cmd_lpwd(t_server *server);
void	cmd_lcd(t_server *server);

int	check_arg(int ac, char **av);
int	check_cmd(t_server *server);
void	fill_list(t_server *server);

void	init_transfert(t_server *server);

void	connect_data(t_server *server);

#endif /* !CLIENT_H_ */
