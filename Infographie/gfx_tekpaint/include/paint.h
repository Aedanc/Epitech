/*
** paint.h for  in /home/fortevg/rendu/infographie/gfx_tekpaint
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jan 25 11:17:45 2016 Forteville Gabriel
** Last update Thu Jan 28 15:15:33 2016 baldas
*/

#ifndef _PAINT_H_
# define _PAINT_H_

typedef struct __attribute__((__packed__))      s_headepi
{
  char	magic_num[3];
  char	unused;
  int	width;
  int	height;
}						t_headepi;

typedef struct __attribute__((__packed__))	s_head
{
  char	magic_num[2];
  int	sizefile;
  int	unused;
  int	pix_pos_file;
  int	header_size;
  int	pixwidth;
  int	pixheight;
  char	bit_plan[2];
  char	bmp_form[2];
  int	compression;
  int	pix_size;
  int	res_width;
  int	res_height;
  int	palet_nb;
  int	master_color;
}						t_head;

typedef struct		s_list
{
  t_bunny_position	*pos;
  struct s_list		*next;
}			t_list;

typedef struct		s_buttons
{
  t_bunny_position	pos1;
  t_bunny_position	pos2;
  int			button;
}			t_buttons;

typedef			struct s_line
{
  t_bunny_position	points[2];
  int			i;
}			t_line;

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_position	pos;
  t_bunny_pixelarray	*draw;
  t_color		color;
  double		radius;
  t_buttons		buttons[11];
  t_line		line;
  int			tool;
  char			*name;
}			t_data;

void			stretch(t_bunny_pixelarray *pix,
				t_bunny_pixelarray *ori);

void			init_ratio(t_bunny_pixelarray *pix, t_bunny_pixelarray *ori,
				   double *ratiowidth, double *ratioheight);

void			init_pos(t_bunny_position *pixpos, int *i, int *y);

void			simple_save(t_bunny_pixelarray *pix, t_data *data);

void			save_as(t_bunny_pixelarray *pix);

t_bunny_pixelarray	*user_load(t_data *data);

t_bunny_pixelarray	*load_file(char *name, t_data *data);

void			write_epixarray(int fd, t_bunny_pixelarray *pix,
				t_headepi *head);

void			configure_epi_head(t_bunny_pixelarray *pix,
					   t_headepi *head);

t_bunny_pixelarray	*load_epixelarray(int fd, t_headepi *head,
					  t_bunny_pixelarray *pix);

void			write_pixarray_32_bit(int fd, t_head *head,
					      t_bunny_pixelarray *pix);

void			write_pixarray_24_bit(int fd, t_head *head,
					      t_bunny_pixelarray *pix);

void			create_head_from_old(t_bunny_pixelarray *pix,
					     t_head *head, t_head *oldhead);

void			create_head_from_scratch(t_bunny_pixelarray *pix,
						 t_head *head);

void			configure_head(t_head *hed, int *fd);

t_color			*read_24_bits(int i, t_bunny_pixelarray *pix2,
				      int fd, t_head *hed);

t_color			*read_32_bits(int i, t_bunny_pixelarray *pix2,
				      int fd, t_head *hed);

int			my_strcmp(char *str1, char *str2);

t_bunny_pixelarray	*load_epi(char *filename);

void			save_bitmap(char *filename, t_bunny_pixelarray *pix,
				    char *oldfilename);

void			save_epi(char *filename, t_bunny_pixelarray *pix);

t_bunny_pixelarray      *load_bitmap(char *file);

void			get_buttons(t_data *data);

void			set_color(t_bunny_pixelarray *pix, unsigned int color);

void			tek_bucket(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_data *data);

void			pencil(void *data);

void			set_max_heap_size(size_t);

int			is_button(t_data			*data,
				  const t_bunny_position	*pos,
				  int				i);

void			is_pallette(t_data *my_data, const t_bunny_position *pos);

void			bucket(void *my_data);

char			*get_next_line(int fd);

int			check(void *data);

unsigned int		tekgetpixel(t_bunny_pixelarray	*pix,
				    t_bunny_position	*pos);

int			tek_put_in_end_list(t_list *list,
					    t_bunny_position *pos);

void			get_color(t_data *my_data);

void			draw_line(t_data *my_data);

void			my_putstr(char *str);

int			my_strlen(char *str);

void			file_handling(t_data *my_data);

/*
Macros
*/

#define		DO_DRAW_SML (1)
#define		DO_DRAW_MED (2)
#define		DO_DRAW_BIG (3)
#define		DO_LINE (4)
#define		DO_BUCKET (8)
#define		DO_ERASE (16)
#define		DO_INVERT (32)
#define		DO_PICK_COLOR (64)
#define		DO_OPEN (128)
#define		DO_SAVE (256)
#define		DO_SAVEAS (512)

# endif /* _PAINT_H_ */
