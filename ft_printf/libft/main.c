/*
#include "libft.h"
#include <stdio.h>
#include <string.h>
*/

//ft_atoi.c
/*int main(void)
{
	printf("%d\n",ft_atoi("    \n   +-+123#$123"));
}*/

//ft_bzero
/*
int main(void)
{
	char str[80] ="abcdefgh";
	printf("%s\n",str);
	ft_bzero(str,strlen(str));
	printf("%s\n",str);
}
*/

//ft_calloc
/*int main(void)
{
	char *str = ft_calloc(10,sizeof(char));
	int index=0;
	while(index < 9)
	{
		str[index] = 'a';
		index++;
	}
	str[index]='\0';
	printf("%s\n",str);
}*/

//ft_isalnum
/*int main(void)
{
	// 9
	printf("%d\n",ft_isalnum('9'));
	// a
	printf("%d\n",ft_isalnum('a'));
	// =
	printf("%d\n",ft_isalnum('='));
}*/

//ft_isalpha.c
/*int main(void)
{
	printf("%d\n",ft_isalpha('A'));
}*/

//ft_isascii
/*int main(void)
{
	printf("%d\n",ft_isascii('A'));
	printf("%d\n",ft_isascii(128));
}*/

//ft_isdigit
/*int main(void)
{
	printf("%d\n",ft_isdigit('0'));
	printf("%d\n",ft_isdigit('A'));
}*/

//ft_isprint.c
/*int main(void)
{
	printf("%d\n",ft_isprint('A'));
	printf("%d\n",ft_isprint('\n'));
}*/

//ft_itoa.c
/*int main(void)
{
	char* res1=ft_itoa(-1234);
	char* res2=ft_itoa(1234);
	printf("%s\n",res1);
	printf("%s\n",res2);
}*/

//ft_lstadd_back
/*int main(void)
{
	t_list *head=malloc(sizeof(t_list));

	t_list *s1=malloc(sizeof(t_list));
	head -> next = s1;
	t_list *s2=malloc(sizeof(t_list));
	s1 -> next = s2;
	t_list *s3=malloc(sizeof(t_list));
	s2 -> next = s3;
	s3 -> next = NULL;
	printf("%p\n",s1);
	printf("%p\n",s2);
	printf("%p\n",s3);
	t_list* curr = head;
	while(1)
	{
		if(curr->next == NULL)
			break;
		curr=curr->next;
	}
	printf("추가 전 마지막 리스트 : %p\n",curr);
	ft_lstadd_back(&head,malloc(sizeof(t_list)));
	while(1)
	{
		if(curr->next == NULL)
			break;
		curr=curr->next;
	}
	printf("추가 후 마지막 리스트 : %p\n",curr);
}*/

//ft_lstadd_front.c
/*int main(void)
{

	t_list *head = malloc(sizeof(t_list));
	t_list *s1 = malloc(sizeof(t_list));
	head -> next = s1;
	s1 -> next = NULL;
	printf("%p\n",head);
	ft_lstadd_front(&head,malloc(sizeof(t_list)));
	printf("%p\n",head);
}*/

//ft_lstclear
/*void ft_delete(void *s)
{
	char *str = s;
	while(*str)
		*str++ = '\0';
}

int main(void)
{
	char str1[80] = "aaaa";
	char str2[80] = "bbbb";
	int a = 10;
	int b = 20;
	t_list *head = malloc(sizeof(t_list));
	t_list *s1 = malloc(sizeof(t_list));
	t_list *s2 = malloc(sizeof(t_list));
	head->next = s1;
	s1->next = s2;
	s2->next = NULL;
	s1->content = str1;
	s2->content = str2;
	s1->content = &a;
	s2->content = &b;
	printf("%s\n",(char*)s1->content);
	printf("%s\n",(char*)s2->content);
	printf("%d\n",(int*)(s1->content));
	printf("%d\n",(int*)(s2->content));
	ft_lstclear(&head,&ft_delete);
	printf("%s\n",(char*)s1->content);
	printf("%s\n",(char*)s2->content);
}*/

//ft_lstdelone
/*void ft_delete(void *s)
{
	char *str = s;
	while(*str)
		*str++ = '\0';
}

int main(void)
{
	t_list *list = malloc(sizeof(t_list));
	char str[80] = "aaa";
	list -> content = str;
	printf("%s\n",(char*)list->content);
	ft_lstdelone(list, &ft_delete);
	printf("%s\n",(char*)list->content);
}*/

//ft_lstiter(함수반복)
/*void ft_f(void* s)
{
	char *str = s;
	while(*str)
		*str++ = 'a';
}

int main(void)
{
	t_list* list1 = malloc(sizeof(t_list));
	t_list* list2 = malloc(sizeof(t_list));
	t_list* list3 = malloc(sizeof(t_list));
	list1->next=list2;
	list2->next=list3;
	list3->next=NULL;
	char str1[80]="bbb";
	char str2[80]="ccc";
	char str3[80]="ddd";
	list1->content=str1;
	list2->content=str2;
	list3->content=str3;
	printf("%s\n",(char*)list1->content);
	printf("%s\n",(char*)list2->content);
	printf("%s\n",(char*)list3->content);
	ft_lstiter(list1,&ft_f);
	printf("%s\n",(char*)list1->content);
	printf("%s\n",(char*)list2->content);
	printf("%s\n",(char*)list3->content);
}*/

//ft_lstlast
/*int main(void)
{
	t_list* list1 = malloc(sizeof(t_list));
	t_list* list2 = malloc(sizeof(t_list));
	t_list* list3 = malloc(sizeof(t_list));
	list1->next=list2;
	list2->next=list3;
	list3->next=NULL;
	char str1[80]="bbb";
	char str2[80]="ccc";
	char str3[80]="ddd";
	list1->content=str1;
	list2->content=str2;
	list3->content=str3;
	printf("%s\n",(char*)list1->content);
	t_list* res = ft_lstlast(list1);
	printf("%s\n",(char*)res->content);
}*/

//ft_lstmap(새로운 리스트 생성 및 반환)
/*void *ft_ch(void* s)
{
	char *str = s;
	while(*str)
		*str++='f';
	return (s);
	//타입만다른게 만들고 다시 원래포인터변수반환
}

void ft_delete(void *s)
{
	char *str = s;
	*str ='\0';
}

int main(void)
{
	t_list* list1 = malloc(sizeof(t_list));
	t_list* list2 = malloc(sizeof(t_list));
	t_list* list3 = malloc(sizeof(t_list));
	list1->next=list2;
	list2->next=list3;
	list3->next='\0';
	char str1[80]="bbb";
	char str2[80]="ccc";
	char str3[80]="ddd";
	list1->content=str1;
	list2->content=str2;
	list3->content=str3;
	t_list *curr = list1;
	while(curr != NULL)
	{
		printf("%s\n",(char*)curr->content);
		curr=curr->next;
	}
	t_list *res = ft_lstmap(list1,&ft_ch,&ft_delete);
	curr  = res;
	while(curr != NULL)
	{
		printf("%s\n",(char*)curr->content);
		curr=curr->next;
	}
}*/

//ft_lstnew
/*int main(void)
{
	char *str ="aaa";
	t_list *res = ft_lstnew(str);
	printf("%s\n",(char*)res->content);
}*/

//ft_lstsize
/*int main(void)
{
	t_list *lst1=ft_lstnew("");
	t_list *lst2=ft_lstnew("");
	t_list *lst3=ft_lstnew("");
	lst1->next=lst2;
	lst2->next=lst3;
	lst3->next=NULL;
	int res = ft_lstsize(lst1);
	printf("%d\n",res);
}*/

//ft_memccpy
/*int main(void)
{
	char dst[80]="asdfasdfasdf";
	char src[80] = "qwerazxcv";
	void *res = ft_memccpy(dst,src,97,10);
	printf("%s\n",(char*)res);
	printf("%s\n",(char*)memccpy(dst,src,97,10));
}*/

//ft_memchr
/*int main(void)
{
	char dst[80]="abcdefghijk";
	void *res = ft_memchr(dst,'e',10);
	printf("%s\n",(char*)res);
	printf("%s\n",(char*)memchr(dst,'e',10));
}*/

//ft_memcmp
/*int main(void)
{
	char *str1="abcdafg";
	char *str2="abcdbwe";
	printf("%d\n", ft_memcmp(str1,str2,10));
	printf("%d\n",memcmp(str1,str2,10));
}*/

//ft_memcpy
/*int main(void)
{
	char str1[80]="asdfasdf";
	char str2[80]="qwerqwer";
	printf("%s\n",(char*)ft_memcpy(str1,str2,10));
	printf("%s\n",(char*)memcpy(str1,str2,10));
}*/

//ft_memcpy
//num만큼 src주소값부터 복사해 dst주소부터 붙여넣기
/*int main(void)
{
	char s1[80]="0123456789";
	ft_memmove(s1+1,s1+3,3);
	printf("%s\n",s1);
	char s2[80]="0123456789";
	ft_memmove(s2+3,s2+1,3);
	printf("%s\n",s2);
}
*/

//ft_memset
//메모리 초기화
/*int main(void)
{
	char str[80]="aaaaaaaaa";
	printf("%s\n",(char*)ft_memset(str,'b',10));
}*/

//ft_putchar_fd
/*int main(void)
{
	ft_putchar_fd('a',1);
}
*/

//ft_putendl_fd
/*int main(void)
{
	char *str="aaaaaaa";
	ft_putendl_fd(str,1);
}*/

//ft_putnbr_fd
/*int main(void)
{
	ft_putnbr_fd(-2147483648,1);
	printf("\n");
	ft_putnbr_fd(2147483647,1);
	printf("\n");
	ft_putnbr_fd(1234,1);
	printf("\n");
	ft_putnbr_fd(-1234,1);
	printf("\n");
}*/

//ft_putstr_fd.c
/*int main(void)
{
	char *str = "aaaaa";
	ft_putstr_fd(str,1);
}
*/

//ft_split
/*int main(void)
{
	char *str="a!sdf@ds$jf@Jkf@fj!ks@";
	char **res = ft_split(str,'@');
	while(*res)
	{
		printf("%s\n",*res);
		res++;
	}
}*/

//ft_strchr
//문자열에서 특정문자가 가장먼저나타는곳의 위치를 반환
//마지막 NULL문자도 문자열의 일부로 간주
/*int main(void)
{
	char *str = "abcdefgh";
	printf("%s\n",ft_strchr(str,'d'));
	printf("%s\n",strchr(str,'d'));
}*/

//ft_strdup
/*int main(void)
{
	char *res;
	char *s ="aaaaaa";
	res = ft_strdup(s);
	printf("%s\n",res);
}*/

//ft_strjoin
/*int main(void)
{
	char *s1="aaaa";
	char *s2="bbbb";
	char *res = ft_strjoin(s1,s2);
	printf("%s\n",res);
}*/

//ft_strlcat
/*int main(void)
{
	char dest[80] ="12345";
	char src[80] = "6789";
	size_t res = ft_strlcat(dest,src,10);
	printf("%ld\n",res);
	printf("%s\n",dest);
	char dest1[80] ="12345";
	char src1[80] = "6789";
	size_t res1 = ft_strlcat(dest1,src1,6);
	printf("%ld\n",res1);
	printf("%s\n",dest1);
}*/

//ft_strlcpy
/*int main(void)
{
	char dest[80]="";
	char src[80]="123456789";
	size_t res = ft_strlcpy(dest,src,5);
	printf("%ld\n",res);
	printf("%s\n",dest);
}*/

//ft_strmapi
/*char ft_newString(unsigned int index, char ch)
{
	if (index % 2 == 0)
		ch -= 32;
	return (ch);
}

int main(void)
{
	char str[80]="abcdefghi";
	char *res = ft_strmapi(str,&ft_newString);
	printf("%s\n",res);
}*/

//ft_strncmp
/*int main(void)
{
	char s1[80]="aaaaa";
	char s2[80]="aabaa";
	printf("%d\n",ft_strncmp(s1,s2,5));
}*/

//ft_strnstr
/*int main(void)
{
	char s1[80]="123456789";
	char s2[80]="456";
	char *res =ft_strnstr(s1,s2,10);
	printf("%s\n",res);
}*/

//ft_strrchr
//배열 뒤에서부터 같은문자를 찾아서 그 해당 포인터반환
/*int main(void)
{
	char str[80]="123456789";
	char *res = ft_strrchr(str,'5');
	printf("%s\n",res);
}*/

//ft_strtrim
//앞뒤구분자 자르난 후 문자열 반환
/*int main(void)
{
	char s[80]="! !!!!jgdksaldsfjkdsf@@ @@";
	char *res = ft_strtrim(s," !@");
	printf("%s\n",res);
}*/

//ft_substr
//start지점부터 len만큼 새로운 문자열 만들어서 반환
/*int main(void)
{
	char s[80]="0123456789";
	char *res = ft_substr(s,4,3);
	printf("%s\n",res);
}
*/

