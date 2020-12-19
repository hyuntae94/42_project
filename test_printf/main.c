#include "ft_printf.h"
#include "stdio.h"
#include "stdlib.h"

int main(void)
{
      /*print_cps 26~28코드추가
      First line of code: {return test("%05%")}
      expected output : "0000%"
      your output     : "    %"
      expected (nonprintable as hex) : "0000%"
      actual   (nonprintable as hex) : "    %"
      */
      /*print_cps 26번째 코드추가
       First line of code: {return test("%05%");}
      expected return value : 5
      your return value     : 5
      expected output : "0000%"
      your output     : "%"
      expected (nonprintable as hex) : "0000%"
      actual   (nonprintable as hex) : "%"
	*/
      /*
	print_cps.c 55번째 코드 추가
First line of code: {return test("%.0p", 0);}
      expected return value : 2
      your return value     : 2
      expected output : "0x"
      your output     : "0x0"
      expected (nonprintable as hex) : "0x"
      actual   (nonprintable as hex) : "0x0"
Test 431 (p_void_width_nofit) : FAILED.
First line of code: {return test("%2.p", NULL);}
      expected return value : 2
      your return value     : 2
      expected output : "0x"
      your output     : "0x0"
      expected (nonprintable as hex) : "0x"
      actual   (nonprintable as hex) : "0x0"*/
	/*
	print_cps 117코드 < 0 대신 <= 0을 사용한 이유
	Test 728 (new2019_star_3) : FAILED.
    First line of code: {return test("%*s", 3, "hello");} 폭3 정밀도 X, 데이터5
      expected return value : 5
      your return value     : 3
      expected output : "hello"
      your output     : "   "
      expected (nonprintable as hex) : "hello"
      actual   (nonprintable as hex) : "   "*/

/*
print_diux 90~96 코드
Test 246 (d_prec_width_nf_pos_zp) : FAILED.
    First line of code: {return test("%08.3d", 8375);}
      expected output : "    8375"
      your output     : "00008375"
      expected (nonprintable as hex) : "    8375"
      actual   (nonprintable as hex) : "00008375"

Test 247 (d_prec_width_nf_neg_zp) : FAILED.
    First line of code: {return test("%08.3d", -8473);}
      expected output : "   -8473"
      your output     : "-0008473"
      expected (nonprintable as hex) : "   -8473"
      actual   (nonprintable as hex) : "-0008473"

Test 323 (i_prec_width_nf_pos_zp) : FAILED.
    First line of code: {return test("%08.3i", 8375);}
      expected output : "    8375"
      your output     : "00008375"
      expected (nonprintable as hex) : "    8375"
      actual   (nonprintable as hex) : "00008375"

Test 324 (i_prec_width_nf_neg_zp) : FAILED.
    First line of code: {return test("%08.3i", -8473);}
      expected output : "   -8473"
      your output     : "-0008473"
      expected (nonprintable as hex) : "   -8473"
      actual   (nonprintable as hex) : "-0008473"

Test 375 (u_prec_width_nf_pos_zp) : FAILED.
    First line of code: {return test("%08.3u", 8375);}
      expected output : "    8375"
      your output     : "00008375"
      expected (nonprintable as hex) : "    8375"
      actual   (nonprintable as hex) : "00008375"

Test 420 (x_prec_width_nf_pos_zp) : FAILED.
    First line of code: {return test("%08.3x", 8375);}
      expected output : "    20b7"
      your output     : "000020b7"
      expected (nonprintable as hex) : "    20b7"
      actual   (nonprintable as hex) : "000020b7"
Test 465 (X_prec_width_nf_pos_zp) : FAILED.
    First line of code: {return test("%08.3X", 8375);}
      expected output : "    20B7"
      your output     : "000020B7"
      expected (nonprintable as hex) : "    20B7"
      actual   (nonprintable as hex) : "000020B7"
      Test 634 (moul_prec_5) : FAILED.
    First line of code: {return test("%%04.2i 42 == |%04.2i|", 42);}
      expected output : "%04.2i 42 == |  42|"
      your output     : "%04.2i 42 == |0042|"
      expected (nonprintable as hex) : "%04.2i 42 == |  42|\x0a"
      actual   (nonprintable as hex) : "%04.2i 42 == |0042|\x0a"
*/
/*
      ft_printf("%d\n",ft_printf("[%05%]\t"));
      ft_printf("%d\n",ft_printf("[%5.c]\t",'a'));
      ft_printf("%d\n",ft_printf("[%5.3c]\t",'a'));
      ft_printf("%d\n",ft_printf("[%5.*c]\t",-3,'a'));
      ft_printf("%d\n",ft_printf("[%5.*c]\t",3,'a'));
	ft_printf("%d\n",ft_printf("[%5c]\t",'a'));
	ft_printf("%d\n",ft_printf("[%05c]\t",'a'));
	ft_printf("%d\n",ft_printf("[%-05c]\t",'a'));
*/
/*
      int *pa = 0;
	int b = 10;
	int *pb = &b;
	ft_printf("%d\n",ft_printf("[%p]\t",pa));
	ft_printf("%d\n",ft_printf("[%.p]\t",pa));
	ft_printf("%d\n",ft_printf("[%.*p]\t",3,pa));
	ft_printf("%d\n",ft_printf("[%p]\t",pb));
	ft_printf("%d\n",ft_printf("[%20p]\t",pb));
	ft_printf("%d\n",ft_printf("[%-20p]\t",pb));
	ft_printf("%d\n",ft_printf("[%-020p]\t",pb));
*/
/*
      ft_printf("%d\n",ft_printf("[%s]\t","abc")-3);
      ft_printf("%d\n",ft_printf("[%.s]\t","abc")-3);
      ft_printf("%d\n",ft_printf("[%.4s]\t","abc")-3);
      ft_printf("%d\n",ft_printf("[%.*s]\t",-1,"abc")-3);
      ft_printf("%d\n",ft_printf("[%05s]\t","abc")-3);
      ft_printf("%d\n",ft_printf("[%05.s]\t","abc")-3);
      ft_printf("%d\n",ft_printf("[%05.4s]\t","abc")-3);
      ft_printf("%d\n",ft_printf("[%-05s]\t","abc")-3);
*/
/*
      ft_printf("%d\n",ft_printf("[%8d]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%-08d]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08d]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.6d]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.*d]\t",-5, 8375)-3);
      ft_printf("%d\n",ft_printf("[%8.*d]\t",-5, 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3d]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3d]\t", -8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3i]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3i]\t", -8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3u]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3x]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%08.3X]\t", 8375)-3);
      ft_printf("%d\n",ft_printf("[%04.2i]\t",42)-3);
*/
}

