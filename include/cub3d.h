/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:50:21 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 15:45:29 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_paths
{
	char			**path_no;
	char			**path_we;
	char			**path_so;
	char			**path_ea;
}					t_paths;

typedef struct s_colors
{
	char			**f;
	char			**c;
}					t_colors;

typedef struct s_cp_param
{
	int				no;
	int				we;
	int				so;
	int				ea;
	int				c;
	int				f;
}					t_cp_param;

typedef struct s_map
{
	t_cp_param		conter_param;
	t_paths			tex_paths;
	t_colors		colors;
	int				map_width;
	char			**map;
	char			**map_bin;
	char			**map_param;
	char			**final_map;
	char			p_symbole;
	size_t			rows;
	size_t			cols;
}					t_map;

typedef struct s_img
{
	void			*image;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	char			*buffer;
}					t_img;

typedef struct s_player
{
	double			x;
	double			y;
	double			radius;
	int				turndirection;
	int				walkdirection;
	double			rotationangle;
	float			movespeed;
	double			rotationspeed;
	double			col_angle;
	int				color;
	int				sign;
	int				left;
	int				right;
}					t_player;

typedef struct s_cord
{
	int				x;
	int				y;
	int				color;
	int				pixels;
	char			c;
}					t_cord;

typedef struct s_rays
{
	double			fovangle;
	double			angle;
	double			angle_c;
	double			angle_s;
	double			angle_b;
	int				wallstrip;
	int				numrays;
	double			xintercept;
	double			yintercept;
	double			xintercept_v;
	double			yintercept_v;
	double			xstep;
	double			ystep;
	double			xstep_v;
	double			ystep_v;
	int				isup;
	int				isdown;
	int				isright;
	int				isleft;
	double			x_h;
	double			y_h;
	double			x_v;
	double			y_v;
	int				i;
}					t_rays;

typedef struct s_xpm
{
	void			*img_no;
	void			*img_so;
	void			*img_we;
	void			*img_ea;
	t_img			no_img;
	t_img			so_img;
	t_img			we_img;
	t_img			ea_img;
	unsigned int	*tab_no;
	unsigned int	*tab_so;
	unsigned int	*tab_we;
	unsigned int	*tab_ea;

}					t_xpm;

typedef struct s_textures
{
	void			*img;
	unsigned int	*tab;
	int				width;
	int				hieght;
	t_img			stract_img;

}					t_textures;

typedef struct s_mlx
{
	int				bpp;
	int				size_line;
	int				fd;
	int				endian;
	void			*mlx;
	void			*win_ptr;
	int				size_x;
	int				size_y;
	char			*title;
	int				flag;
	t_textures		*textures;
	t_img			img;
	t_cord			cord;
	t_map			*map;
	t_player		player;
	t_rays			rays;
	t_xpm			xpm;
	int				colc;
	int				colf;
	int				a;
	double			tmp_ray;
	int				b;
	int				k;
	char			*temp;
	double			offsetx;
	double			offsety;
	unsigned int	*tab_img;
	int				height_text;

}					t_mlx;

size_t				ft_strlen(char const *str);
void				my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int					rows_calcul(char **map);
void				fill_data(t_mlx *mlx);
void				draw_rays(t_mlx *mlx);
int					keypress(int keycode, t_mlx *mlx);
int					keyrelease(int keycode, t_mlx *mlx);
int					player_movements(t_mlx *mlx);
double				normalize_angle(double angle);
char				*get_next_line(int fd);
char				*ft_substr(const char *str, size_t start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *str);
char				*ft_substr_s(char *str, size_t start, size_t len);
char				*ft_strchr(char *str, int c);
char				*ft_strdup(char *s1);
char				**ft_split(char const *s, char c);
int					is_str_print(char *str);
char				*ft_to_string(char c);
void				pars(t_map *all);
int					ft_isprint(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				parse_param(t_map *all);
char				*ft_strtrim(char *s1, char *set);
void				check_caracters(t_map *all);
void				get_values_colors(t_map *all);
void				check_colors_values(t_map *all);
int					ft_atoi(char *str);
void				check_colors_values_h(t_map *all);
void				check_exten(char *str, int ac);
void				ft_err(char *str);
int					ft_count_char(char *str, char c);
int					count_rows(char **tab);
void				check_param_ext(t_map *all);
void				init_images(t_mlx *mlx);
double				normalize_angle(double angle);
void				draw_walls_ayman(t_mlx *mlx, double wallheight,
						int height_textures, unsigned int *tab_img);
int					return_text_pixle_color(int x, int y, unsigned int *tab,
						int height_text);
void				get_colors_values(t_mlx *mlx);
void				free_tab(char **tab);
void				draw_map(t_mlx *mlx);
void				setting_elements(t_mlx *mlx, char c, t_cord *cord);
void				horizontal_intersections(t_mlx *mlx);
void				vertical_intersections(t_mlx *mlx);
double				distance_h(t_mlx *mlx);
double				distance_v(t_mlx *mlx);
void				cast_v(t_mlx *mlx);
int					check_wall(t_mlx *mlx, int xo, int yo);
int					check_wall_v(t_mlx *mlx, int xo, int yo);
void				first_intersection_vertical(t_mlx *mlx);
int					first_intersection_h(t_mlx *mlx, double y);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isprint(int c);
char				*ft_to_string(char c);
void				get_final_map(t_map *all, int i, int j);
int					is_str_print(char *str);
void				draw_rays(t_mlx *mlx);
void				draw_rays(t_mlx *mlx);
void				init_images(t_mlx *mlx);
void				init_images_h(t_mlx *mlx, t_textures *text, char *path);
void				pars_h_1(t_map *all, int *i, int *param);
void				parse_param2(t_map *all, int i);
void				parse_param1(t_map *all, int i);
void				horizontal_intersections_c(t_mlx *mlx);
void				vertical_intersections_c(t_mlx *mlx);
int					other_intersections_h_c(t_mlx *mlx, double x_h, double y_h);
int					other_intersections_v_c(t_mlx *mlx, double x_h, double y_h);
void				first_intersection_vertical_c(t_mlx *mlx);
int					first_intersection_h_c(t_mlx *mlx, double y);
void				vertical_intersections_c(t_mlx *mlx);
void				horizontal_intersections_s(t_mlx *mlx);
void				vertical_intersections_s(t_mlx *mlx);
int					other_intersections_h_s(t_mlx *mlx, double x_h, double y_h);
int					other_intersections_v_s(t_mlx *mlx, double x_h,
						double y_h);
void				first_intersection_vertical_s(t_mlx *mlx);
int					first_intersection_h_s(t_mlx *mlx, double y);
void				vertical_intersections_s(t_mlx *mlx);
void				horizontal_intersections_b(t_mlx *mlx);
void				vertical_intersections_b(t_mlx *mlx);
int					other_intersections_h_b(t_mlx *mlx, double x_h, double y_h);
int					other_intersections_v_b(t_mlx *mlx, double x_h,
						double y_h);
void				first_intersection_vertical_s(t_mlx *mlx);
int					first_intersection_h_s(t_mlx *mlx, double y);
void				vertical_intersections_s(t_mlx *mlx);
int					mouse_hook(t_mlx *ptr);
void				set_values(t_mlx *mlx, t_cord *cord);
void				check_sides(t_mlx *mlx, double tmp_x, double tmp_y);
void				check_collision(t_mlx *mlx, double tmp_x, double tmp_y);
int					collision(t_mlx *mlx, double tmp_x, \
					double tmp_y, double angle);
double				cast_col(t_mlx *mlx);
double				collision_sides(t_mlx *mlx, double angle);
double				cast_col(t_mlx *mlx);
double				collision_sides(t_mlx *mlx, double angle);
void				first_intersection_vertical_b(t_mlx *mlx);

#endif
