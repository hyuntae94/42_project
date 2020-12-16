/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_diux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:42:24 by hyunkim           #+#    #+#             */
/*   Updated: 2020/12/16 21:16:48 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_diux_1(t_info *info, int *size, long long data, const char *form)
{
	if (info->flag == 2)
	//'0'플래그가 살아있는 경우는
	//정밀도가 존재하지않을 때,
	//정밀도가 길이보다 클때
	//정밀도가 음수일때
	{
		if (info->prec <= leng(data, form) && leng(data, form) <= info->width)
		//폭이 가장 큰경우 case1
		//"[%04d]",100 =>[0100], "[%04.*d]",-6,100 =>[0100]
			size[1] = info->width - leng(data, form);//'0'추가할 갯수
		else if (leng(data, form) <= info->prec && info->prec <= info->width)
		//폭이 가장 큰경우 case2
		//[%06.5d]\n",100 => [ 00100]
		{
			size[0] = info->width - info->prec;//공백갯수
			size[1] = info->prec - leng(data, form);//'0'갯수
		}
		else if (info->width <= info->prec && leng(data, form) <= info->prec)
		//정밀도가 가장 큰 경우에는 폭과 데이터의 크기순서는 중요하지않다.
		//[%2.5d]\n",100 => [00100]//폭이 정밀도 보다 작으면 폭은 무시된다.
			size[1] = info->prec - leng(data, form);//'0'의 갯수
		if (data < 0 && info->prec < leng(data, form))
		//정밀도가 길이보다 크다면 '-'부호는 '0'개수에 영향을 주지않고 사용된다.
		//"[%04d]",-100 =>[-100]
			size[1]--;//'-'부호를 넣기위해서 '0'하나빼준다.
	}
	else
	{
		size[1] = info->prec - leng(data, form);
		if (size[1] < 0)//정밀도가 작다면 정밀도는 필요없다.
			size[1] = 0;//'0'은 없다
		size[0] = info->width - size[1] - leng(data, form); // 공백의 갯수구하기
		if (data == 0 && info->point_zero)
			size[0]++;//data값이 이고 정밀도가 0이면 0은 출력X => 공백추가
	}
	if (data < 0)
		size[0]--;//'-'부호추가
}

void	print_diux_2(t_info *info, int *size, long long data, const char *form)
{
	int i;

	i = -1;
	while (info->flag != 1 && ++i < size[0])
		write(1, &" ", 1);
	if (data < 0 && ++(info->ret))
		write(1, &"-", 1);
	i = -1;
	while (++i < size[1])
	{
		write(1, &"0", 1);
		(info->ret)++;
	}
	if (!(info->point_zero == 1 && data == 0))
	{
		ft_put_data(data, form);
		info->ret += leng(data, form);
	}
	i = -1;
	while (info->flag == 1 && ++i < size[0])
		write(1, &" ", 1);
	i = -1;
	while (++i < size[0])
		(info->ret)++;
}

void	print_diux(t_info *info, va_list ap, const char *form)
{
	long long	data;
	//unsigned int 와 int를 받기위해서 longlong선언
	int			size[2];

	data = 0;
	if (*form == 'u' || *form == 'x' || *form == 'X')
		data = va_arg(ap, unsigned int);
	else if (*form == 'd' || *form == 'i')
		data = va_arg(ap, int);
	arr_init(size, 2);
	if (info->prec <= leng(data, form))//정밀도 보다 출력하는 개수가 더 크고
	{
		if (info->prec > 0 && info->flag == 2)//정밀도가 0보다 크고 플래그 '0'이 존재한다면
			info->flag = 0;
	}
	print_diux_1(info, size, data, form);
	print_diux_2(info, size, data, form);
}
