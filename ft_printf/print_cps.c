/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:41:34 by hyunkim           #+#    #+#             */
/*   Updated: 2020/12/16 16:36:55 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_info *info, va_list ap, const char *form)
//정밀도를 신경써줄필요가없다.
{
	int		i;
	char	data;

	if (*form == 'c')
		data = va_arg(ap, int);//data에 출력할 문자 저장
	else
		data = '%';
	i = -1;//?
	if (info->flag != 1)//'0','-'플래그 존재X
		while (++i < info->width - 1)
			write(1, &" ", 1);
	write(1, &data, 1);
	(info->ret)++;
	i = -1;
	if (info->flag == 1)//'-'플래그 존재할 경우
		while (++i < info->width - 1)//문자 출력하고 폭의 수 -1 만큼 뒤에 공백출력
			write(1, &" ", 1);
	i = -1;
	while (++i < info->width - 1)//출력된 공백수또는0 결과값에 더해주기
		(info->ret)++;
}

void	print_p(t_info *info, va_list ap)
//폭와 '-'플래그, point_zero에 영향을 받는다.
{
	unsigned long long	data;
	int					i;

	data = va_arg(ap, unsigned long long);//unsigned int(32bit)
	i = -1;
	if (info->flag != 1)
		while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
			write(1, &" ", 1);
	write(1, &"0x", 2);
	if (!(data == 0 && info->point_zero))
	//data값이 0이고 정밀도가 0인 경우를 제외하고 모든 경우
		ft_putthex2(data);
	if (info->flag == 1)
		while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
			write(1, &" ", 1);
	info->ret += 2 + hex_leng_2(data, info->point_zero);
	i = -1;
	while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
		(info->ret)++;
}

void	print_s_1(t_info *info, int *size, char *data)
//문자열은 '0'플래그와 같이 사용할 수없다.
{
	if (info->width <= info->prec && info->prec <= ft_strlen(data))
	//"%1.2s","abc" => [ab]
	//폭이 가장 작은경우에는 정밀도가 작은지 문자열이 작은지 경우의 수를 2가지 고려해야한다.
		size[0] = info->prec;
	else if (info->width <= ft_strlen(data) && ft_strlen(data) <= info->prec)
	//"%1.4s","abc" =>[abc]
		size[0] = ft_strlen(data);
	else if (info->prec <= info->width && info->prec <= ft_strlen(data))
	//"%3s","abcd" => [abcd]
	//정밀도가 가장 작은경우에는 폭과 data의 상관관계는 중요하지않다.
	{
		size[0] = info->prec;
		size[1] = info->width - info->prec;//[1]에는 문자출력하고 남은 공간
	}
	else if (ft_strlen(data) <= info->width && ft_strlen(data) <= info->prec)
	//"%4.3s","ab"=>[  ab]
	//data문자열의 길이가 가장 작을 경우 폭과 정밀도의 상관관계는 중요하지않다.
	{
		size[0] = ft_strlen(data);//[0]에는 출력될 문자의 개수
		size[1] = info->width - ft_strlen(data);//전체 출력 개수 - 문자개수
	}
	if (info->point_zero)
	//정밀도가 존재하고 그 값이 0인경우 예외처리코드
	//"%5.0s","abc"=>[     ]
	{
		size[0] = 0;
		size[1] = info->width;
	}
}

void	print_s(t_info *info, va_list ap)
//'0'플래그와는 같이 사용될수없고
//정밀도가 음수이면 문자열 전체출력
//1 -> 1개,2 -> 2개
//만약 문자열이 "abc"이고 정밀도가 4 이상이면 무시된다.
{
	char	*data;
	int		size[2];
	int		i;

	arr_init(size, 2);//int타입의 배열2개 생성
	//[0]-> 출력되는 문자의 개수
	//[1]-> 공백개수
	data = ft_strdup(va_arg(ap, char*));
	if (data == NULL)
		data = ft_strdup("(null)");
	if (info->prec <= 0)
	//정밀도가 존재하고 그 값이 0인 코드는 따로 처리 ,여기서는 다루지않는다.
	//line 77코드
		info->prec = ft_strlen(data);
	print_s_1(info, size, data);
	i = -1;
	if (info->flag != 1)
		while (++i < size[1])
			write(1, &" ", 1);
	write(1, data, size[0]);//문자출력
	if (info->flag == 1)
		while (++i < size[1])
			write(1, &" ", 1);
	info->ret += size[0];
	i = -1;
	while (++i < size[1])
		(info->ret)++;
	free(data);
	data = NULL;
	//data를 NULL초기화 시키않는다면 중요한 정보가 data에 들어갈 경우 임의의 메모리가 들어가기때문에 나중에는 찾을 수 없다.
}
