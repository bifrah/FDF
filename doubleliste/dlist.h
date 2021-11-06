#ifndef D_LIST_H
# define D_LIST_H

# include <stdlib.h>

typedef struct		s_dnode
{
	int				data;
	struct s_dnode	*p_next;
	struct s_dnode	*p_prev;
}					t_dnode;

typedef struct		s_dlist
{
	size_t	length;
	t_dnode	*p_head;
	t_dnode	*p_tail;
}					t_dlist;

t_dnode				*ft_dlistaddh(t_dlist **p_list);
t_dnode				*ft_dlistaddt(t_dlist **p_list);
t_dlist				*ft_dlistnew(void);
void				ft_dlistdel(t_dlist **p_list);
#endif
