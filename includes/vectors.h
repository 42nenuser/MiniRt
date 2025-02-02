/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:40:47 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/16 20:53:07 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "structs.h"

# define WIDTH 1080
# define HEIGHT 720
# define MAX_CYLINDERS 10 
# define EPSILON 1e-6
# define A 1
# define C 2
# define L 3
# define PL 4
# define SP 5
# define CY 6

// vec2 utilitis
t_vec2		vec2_create(float x, float y);
t_vec2		vec2_divide_vec(t_vec2 a, t_vec2 b);
t_vec2		vec2_subtract_scalar(t_vec2 a, float scalar);

//vec3 utilitis
t_vec3		vec3_create(float r, float g, float b);
t_vec3		mat3_multiply_vec3(t_mat3 m, t_vec3 v);
t_vec3		vec3_multiply_scalar(t_vec3 v, float scalar);
t_vec3		cross_vec3(t_vec3 x, t_vec3 y);
t_vec3		mat3_mul_vec3(t_mat3 m, t_vec3 v);
t_vec3		vec3_negate(t_vec3 v);
t_vec3		vec3_divide_scalar(t_vec3 v, float scalar);
t_vec3		vec3_subtract(t_vec3 a, t_vec3 b);
t_vec3		vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3		normalize_vec3(t_vec3 x);
t_vec3		vec3_multiply_float(t_vec3 v, float scalar);
float		dot_vec3(t_vec3 v1, t_vec3 v2);
float		vec3_length(t_vec3 v);

//mat3 utilitis
t_mat3		mat3_create(t_vec3 t, t_vec3 b, t_vec3 n);
t_mat3		mat3_add(t_mat3 m1, t_mat3 m2);
t_mat3		mat3_transpose(t_mat3 m);
t_mat3		mat3_multiply_scalar(t_mat3 m, float scalar);
t_mat3		mat3_multiply(t_mat3 m1, t_mat3 m2);
t_mat3		rotationtoy(t_vec3 dir);

//other utilitis
t_vec4		vec4_create(float x, float y, float z, float w);
int			vec4_to_color(t_vec4 color);
float		clamp(float x, float min, float max);

// objects and intersections and some math functions
int			intersect(t_vec3 rayorig, t_vec3 raydir, t_vec3 *sf, \
t_cylinder cylinder);
int			intersect_plane(t_units *un, t_vec3 dir, t_vec3 *hit);
int			solvequadratic(t_var1 *v);
t_vec3		raytrace(t_vec3 direction, t_units *un);
int			isinshadow(t_units *un, t_vec3 point, t_vec3 tolight);
int			intersect_sphere(t_sphere sphere, t_ray r, t_vec3 *sf, float *thit);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		radians(double degrees);

// parsing functions 
double		ft_atof(char *str);
void		check_cordinats(char **s, t_units *un);
t_vec3		set_point(char *s, t_units *un);
t_vec3		set_color(char *s, t_units *un);
t_vec3		set_vec(char *s, t_units *un);
void		set_light(char **s, int len, t_units *un);
void		set_camera(char **s, int len, t_units *un);
void		set_sphere(char **s, int len, t_units *un);
void		set_plane(char **s, int len, t_units *un);
void		set_cylinder(char **s, int len, t_units *un);
void		free_arr(char **arr);
int			check_open(char *file, t_units *un);
int			check_id(char *s);
void		set_ambiant(char **s, int len, t_units *un);
void		ft_set(char **s, int len, t_units **un);
void		ft_error(t_units *un);
void		check_str(char *s, t_units **un);
void		init_units(t_units **un);
t_units		*parse_file(char *file);
t_sphere	*new_sphere(float r, t_vec3 center, t_vec3 color);
t_sphere	*last_sphere(t_sphere *lst);
void		add_sphere(t_sphere **list, t_sphere *new);
t_plane		*new_plane(t_vec3 point, t_vec3 nor, t_vec3 color);
t_plane		*last_plane(t_plane *lst);
void		add_plane(t_plane **list, t_plane *new);
t_cylinder	*new_cylinder(t_cyvar var);
t_cylinder	*last_cylinder(t_cylinder *lst);
void		add_cylinder(t_cylinder **list, t_cylinder *new);
int			closingesc(void *data);
int			closing(int keycode, void *data);
//free
void		free_un(t_units *un);

#endif