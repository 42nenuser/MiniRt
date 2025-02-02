/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:25:11 by fhihi             #+#    #+#             */
/*   Updated: 2023/09/13 04:18:04 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//these variables for the quadratic equation
typedef struct s_var1
{
	float	a;
	float	b;
	float	c;
	float	r;
	float	t;
	float	t0;
	float	t1;
}		t_var1;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_vec3
{
	float	r;
	float	g;
	float	b;
}			t_vec3;

typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
}			t_ray;

typedef struct s_vec2
{
	float	x;
	float	y;
}			t_vec2;

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_vec4;

typedef struct s_mat3
{
	float	m[3][3];
}			t_mat3;

typedef struct s_camera 
{
	t_vec3	position;
	t_vec3	direction;
	float	zoom;
}			t_camera;

typedef struct s_sphere
{
	t_vec3			color;
	t_vec3			position;
	float			radius;
	struct s_sphere	*next;
}					t_sphere;

typedef struct s_Light
{
	t_vec3	direction;
	t_vec3	color;
	float	brightness;
}			t_light;

typedef struct s_ambientlight
{
	float	ratio;
	t_vec3	color;
}			t_ambientlight;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_vec3			color;
	struct s_plane	*next;
}					t_plane;

typedef struct s_cylinder
{
	t_vec3				color;
	t_vec3				position;
	t_vec3				axis;
	float				diameter;
	float				height;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_cyvar
{
	t_vec3	position;
	t_vec3	nor;
	t_vec3	axis;
	float	diameter;
	float	height;
	t_vec3	color;
}			t_cyvar;

typedef struct s_objects
{
	t_cylinder	*cy;
	t_sphere	*sp;
	t_plane		*pl;
}				t_objects;

typedef struct s_lights
{
	t_ambientlight	al;
	t_light			l;
}					t_lights;

typedef struct s_units
{
	t_camera	cam;
	t_objects	obj;
	t_lights	lght;
}				t_units;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_units	*un;
	int		mouse_x;
	int		mouse_y;
}			t_vars;

//intersect cylinder
typedef struct s_incy
{
	t_mat3		lrotmat;
	t_cylinder	cylinder;
	t_vec3		lrayorig;
	t_vec3		lraydir;
}				t_incy;

// erdring struct
typedef struct s_rend
{
	t_vec2	fragcoord;
	t_vec2	iresolution;
	t_vec3	iraydir;
	t_vec3	col;
}			t_rend;

typedef struct s_temp
{
	t_vec3	v1;	
	t_vec3	v2;	
	t_vec3	v3;	
	t_vec3	v4;	
	t_vec3	v5;
	float	f1;	
	float	f2;	
	float	f3;	
	float	f4;	
	float	f5;	
}			t_temp;

#endif