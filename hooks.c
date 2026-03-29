#include "image.h"
#include "aicu.h"

int close_win(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
    (void) keycode;
    (void) vars;
	ft_putnbr(keycode);
	return (0);
}