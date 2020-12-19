/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:19:02 by hyunkim           #+#    #+#             */
/*   Updated: 2020/12/09 15:19:02 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*read_flag(const char *form, t_info *info)
{
	while (*form == '-' || *form == '0')
	{
		if (*form == '-')
			info->flag = 1;
		else if (*form == '0')
			if (info->flag != 1)
				info->flag = 2;
		form++;
	}
	return (form);
}

const char	*read_width(const char *form, t_info *info, va_list ap)
{
	if (*form == '*' && form++)
		info->width = va_arg(ap, int);
	else
		while (ft_isnum(*form) == 1)
			info->width = info->width * 10 + (*form++ - '0');
	if (info->width < 0)
	{
		info->width *= -1;
		info->flag = 1;
	}
	return (form);
}

const char	*read_prec(const char *form, t_info *info, va_list ap)
{
	form++;
	while (*form == '0')
		form++;
	if (*form == '*' && form++)
		info->prec = va_arg(ap, int);
	if (ft_isnum(*form) == 1)
		while (ft_isnum(*form) == 1)
			info->prec = info->prec * 10 + (*form++ - '0');
	if (info->prec == 0 && info->flag == 2 && *form != '%')
		info->flag = 0;
	if (info->prec == 0)
		info->point_zero = 1;
	return (form);
}

const char	*print_form_spec(const char *form, t_info *info, va_list ap)
{
	if (*form == 'c' || *form == '%')
		print_c(info, ap, form);
	else if (*form == 's')
		print_s(info, ap);
	else if (*form == 'p')
		print_p(info, ap);
	else if (*form == 'd' || *form == 'i' \
				|| *form == 'u' || *form == 'x' || *form == 'X')
		print_diux(info, ap, form);
	else
		return (NULL);
	return (form);
}
