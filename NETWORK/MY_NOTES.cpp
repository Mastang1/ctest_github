/**
 * @file MY_NOTES.cpp
 * @author some notes
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


/* 1 */
/* Extension from POSIX.1:2001.  */
struct addrinfo
{
  int                   ai_flags;			/* Input flags.  */
  int                   ai_family;		    /* Protocol family for socket.  */
  int                   ai_socktype;		/* Socket type.  */
  int                   ai_protocol;		/* Protocol for socket.  */
  socklen_t             ai_addrlen;		    /* Length of socket address.  */
  struct sockaddr       *ai_addr;	        /* Socket address for socket.  */
  char                  *ai_canonname;		/* Canonical name for service location.  */
  
  struct addrinfo       *ai_next;	        /* Pointer to next in list.  */
};