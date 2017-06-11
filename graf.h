/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:05:40 by gpurci            #+#    #+#             */
/*   Updated: 2017/02/13 15:55:53 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAF_H
# define GRAF_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <mlx.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# define PI 3.14
# define PTR_MOTION (1L << 6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L << 6)
# define KEY_RELEASE_MASK (1L << 1)
# define KEY_PRESS 5
# define KEY_RELEASE 3

/*
 *  *  Summary:
 *   *    Virtual keycodes
 *    *  
 *     *  Discussion:
 *      *    These constants are the virtual keycodes defined originally in
 *       *    Inside Mac Volume V, pg. V-191. They identify physical keys on a
 *        *    keyboard. Those constants with "ANSI" in the name are labeled
 *         *    according to the key position on an ANSI-standard US keyboard.
 *          *    For example, kVK_ANSI_A indicates the virtual keycode for the key
 *           *    with the letter 'A' in the US keyboard layout. Other keyboard
 *            *    layouts may have the 'A' key label on a different physical key;
 *             *    in this case, pressing 'A' will generate a different virtual
 *              *    keycode.
 *               */
typedef enum {
	kVK_ANSI_A                    = 0x00,
	kVK_ANSI_S                    = 0x01,
	kVK_ANSI_D                    = 0x02,
	kVK_ANSI_F                    = 0x03,
	kVK_ANSI_H                    = 0x04,
	kVK_ANSI_G                    = 0x05,
	kVK_ANSI_Z                    = 0x06,
	kVK_ANSI_X                    = 0x07,
	kVK_ANSI_C                    = 0x08,
	kVK_ANSI_V                    = 0x09,
	kVK_ANSI_B                    = 0x0B,
	kVK_ANSI_Q                    = 0x0C,
	kVK_ANSI_W                    = 0x0D,
	kVK_ANSI_E                    = 0x0E,
	kVK_ANSI_R                    = 0x0F,
	kVK_ANSI_Y                    = 0x10,
	kVK_ANSI_T                    = 0x11,
	kVK_ANSI_1                    = 0x12,
	kVK_ANSI_2                    = 0x13,
	kVK_ANSI_3                    = 0x14,
	kVK_ANSI_4                    = 0x15,
	kVK_ANSI_6                    = 0x16,
	kVK_ANSI_5                    = 0x17,
	kVK_ANSI_Equal                = 0x18,
	kVK_ANSI_9                    = 0x19,
	kVK_ANSI_7                    = 0x1A,
	kVK_ANSI_Minus                = 0x1B,
	kVK_ANSI_8                    = 0x1C,
	kVK_ANSI_0                    = 0x1D,
	kVK_ANSI_RightBracket         = 0x1E,
	kVK_ANSI_O                    = 0x1F,
	kVK_ANSI_U                    = 0x20,
	kVK_ANSI_LeftBracket          = 0x21,
	kVK_ANSI_I                    = 0x22,
	kVK_ANSI_P                    = 0x23,
	kVK_ANSI_L                    = 0x25,
	kVK_ANSI_J                    = 0x26,
	kVK_ANSI_Quote                = 0x27,
	kVK_ANSI_K                    = 0x28,
	kVK_ANSI_Semicolon            = 0x29,
	kVK_ANSI_Backslash            = 0x2A,
	kVK_ANSI_Comma                = 0x2B,
	kVK_ANSI_Slash                = 0x2C,
	kVK_ANSI_N                    = 0x2D,
	kVK_ANSI_M                    = 0x2E,
	kVK_ANSI_Period               = 0x2F,
	kVK_ANSI_Grave                = 0x32,
	kVK_ANSI_KeypadDecimal        = 0x41,
	kVK_ANSI_KeypadMultiply       = 0x43,
	kVK_ANSI_KeypadPlus           = 0x45,
	kVK_ANSI_KeypadClear          = 0x47,
	kVK_ANSI_KeypadDivide         = 0x4B,
	kVK_ANSI_KeypadEnter          = 0x24,
	kVK_ANSI_KeypadMinus          = 0x4E,
	kVK_ANSI_KeypadEquals         = 0x51,
	kVK_ANSI_Keypad0              = 0x52,
	kVK_ANSI_Keypad1              = 0x53,
	kVK_ANSI_Keypad2              = 0x54,
	kVK_ANSI_Keypad3              = 0x55,
	kVK_ANSI_Keypad4              = 0x56,
	kVK_ANSI_Keypad5              = 0x57,
	kVK_ANSI_Keypad6              = 0x58,
	kVK_ANSI_Keypad7              = 0x59,
	kVK_ANSI_Keypad8              = 0x5B,
	kVK_ANSI_Keypad9              = 0x5C,
	esc								
} caracter;

/* keycodes for keys that are independent of keyboard layout*/
enum optional {
	kVK_Reinit	                    = 0x4C,
	kVK_Tab                       = 0x30,
	kVK_Space                     = 0x31,
	kVK_Backspace                 = 0x33,
	kVK_Escape                    = 0x35,
	kVK_Command                   = 0x37,
	kVK_Shift                     = 0x38,
	kVK_CapsLock                  = 0x39,
	kVK_Option                    = 0x3A,
	kVK_Control                   = 0x3B,
	kVK_RightShift                = 0x3C,
	kVK_RightOption               = 0x3D,
	kVK_RightControl              = 0x3E,
	kVK_Function                  = 0x3F,
	kVK_F17                       = 0x40,
	kVK_VolumeUp                  = 0x48,
	kVK_VolumeDown                = 0x49,
	kVK_Mute                      = 0x4A,
	kVK_F18                       = 0x4F,
	kVK_F19                       = 0x50,
	kVK_F20                       = 0x5A,
	kVK_F5                        = 0x60,
	kVK_F6                        = 0x61,
	kVK_F7                        = 0x62,
	kVK_F3                        = 0x63,
	kVK_F8                        = 0x64,
	kVK_F9                        = 0x65,
	kVK_F11                       = 0x67,
	kVK_F13                       = 0x69,
	kVK_F16                       = 0x6A,
	kVK_F14                       = 0x6B,
	kVK_F10                       = 0x6D,
	kVK_F12                       = 0x6F,
	kVK_F15                       = 0x71,
	kVK_Help                      = 0x72,
	kVK_Home                      = 0x73,
	kVK_PageUp                    = 0x74,
	kVK_ForwardDelete             = 0x75,
	kVK_F4                        = 0x76,
	kVK_End                       = 0x77,
	kVK_F2                        = 0x78,
	kVK_PageDown                  = 0x79,
	kVK_F1                        = 0x7A,
	kVK_LeftArrow                 = 0x7B,
	kVK_RightArrow                = 0x7C,
	kVK_DownArrow                 = 0x7D,
	kVK_UpArrow                   = 0x7E
};
typedef struct	s_graf_u
{
	char		k;
	struct s_graf_u	*next;
}					graf_u;

typedef struct	s_graf_d
{
	char		c;
	struct s_graf_d	*dr;
	graf_u			*jos;	
}					graf_d;

typedef struct	gr_nod
{
	char			nume;
	char			stare;
	char			x[2];
	char			y[2];
	void			*much;
}					nod;

typedef struct			gr_muchie
{
 	struct gr_muchie	*dr;
	nod					*nd;
	char				st_much;
}						muchie;
typedef struct			s_table
{
	muchie				*nucleu;
	nod					*nd;
	nod					*lst_nd;	
}						table;

typedef struct			graf_coord
{
	int					x;
	int					y;
}						coordonate;

typedef struct			graf_dublu_coord
{
	coordonate			init;
	coordonate			final;
}						dublu_coord;

typedef	struct	v_mlx
{
	char		pres;
	char		nume;
	char		key;
	char		but;
	void		*mlx;
	void		*win;
	table		nuc;
}				mlx_win;
typedef struct		d_graf
{
	int				ID;
	nod				*nd;
	int				x;
	int				y;
	int				IDsursa;
	unsigned int	len;
	char			stare;
}					Djekstra;

void					cre_graf(muchie **lst_much, int ac, char **av);
void					af_graf(muchie *nucleu);
int						coord_x_y(char *c);
void					del_graf(muchie **nucleu);
void					del_nod(muchie **nucleu, char nume);
void					add_much(muchie **lst_much, nod *nd);
nod						*cre_nod(char nume, char *i);
void					conv_int_char_coord(int x, int y, char *i);
void					cre_graf_mouse(muchie **much, int x, int y, char c);
void					grafic_graf(mlx_win *mlx);
void					reinit_coord(dublu_coord *leg, int color, mlx_win *mlw, muchie *much);
void					line(int xo, int yo, int xu, int yu, int color, int scara, mlx_win *m_w);
void					circle(int xo, int yo, int r, int arc, int color, mlx_win *mlx);
int						my_key_fun(int keycode, void *param);
int						my_mouse_fun(int button, int x, int y, void *param);
int						mouse_motion(int x, int y, void *q);
int						my_loop_hook_fun(void *par);
int						mouse_pres(int k, int x, int y, void *q);
char					cre_mouse_much(mlx_win *mlw, int xp, int yp);
void					help(mlx_win *mlw);
int						get_next_line(int const fd, char **line);
void					reinit_frame_graf(mlx_win *mlw);
void					*del_one_muchie(void **much, char nume);
void					del_one_much(mlx_win *mlw, char nume);
void					reinit_name(mlx_win *mlw, char nume);
void					reinit_flag(mlx_win *mlw);
void					reinit_coord_graf(mlx_win *mlw, int x, int y);
void					del_one_nod(muchie **nucleu);
int						distanta_graf(int xo, int yo, int xu, int yu);
muchie					*cautare_nod(void *much, muchie **find, char nume);
void					delete_array_graf(int **array, int k);
int						num_muchii(muchie *much);
void					coincidenta_nume(int *array, muchie *nucleu, muchie *much);
int						**conv_graf_lst_array(muchie *nucleu, int i, char nume);
void					dist_min_nod(mlx_win *mlw, Djekstra *dist, int dest);
int						ver_stare(Djekstra *dist, int len_graf);
void					alg_djekstra(Djekstra *dist, int *array, int i);
void					djeckstra(mlx_win *mlw);
void					delete_djekstra(Djekstra *dist, int len);
void					af_array_graf(int **array);
void					conv_char_int(coordonate *init, char *c);


char					ascii(char	c);
#endif
