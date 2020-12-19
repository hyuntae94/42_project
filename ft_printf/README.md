출처 https://modoocode.com/35
* printf 형식문자열
%[플래그(flag)][폭(width)][.정밀도]서식 문자(specifier)
* 서식문자
- c : 문자
- s : 문자열
- p : 포인터 주소(32비트 기준 : 0 ~ 4,294,967,295 , unsigned long long : 0 ~ 18,446,744,073,709,551,615)
- d,i : 부호있는 십진법으로 나타낸 정수(-2,147,483,648 ~ 2,147,483,648)
- u : 부호없는 십진법으로 나타낸 정수(unsigned int : 0 ~ 4,294,967,295)
- x : 부호없는 16진법으로 나타낸 정수(소문자사용) ex)7fa
- X : 부호없는 16진법으로 나타낸 정수(대문자사용) ex)7FA
- % : % 다음에 %를 또 붙이면 stdout에 %를 출력한다.

* flag => -, 0

* va_arg
var_type va_arg(va_list ap, var_type);
ap로 지정된 위치에서 지정된 var_type 값을 검색하고 리스트에서 다음 인수를 가리키도록 ap 를 증가 시켜 다음 인수가 시작 되는 위치를 결정한다. 즉, 특정 가변인자를 가리키고 있는 va_list의 포인터를 다음 가변인자로 이동시켜 주는 매크로이다.

* ap: va_list로 만든 포인터가 담긴다.
* var_type: int나 long, double과 같은 타입 이름이 담긴다.

var_type을 설정할 때 char, short 의 경우에는 int로 대신 쓰고, float의 경우에는 double로 대신 쓴 이후 형 변환을 해주어야 한다.
ex) char ch = (char) va_arg(ap, int);

Makefile
$@ => 현재 타겟의 이름
$^ => 타겟이 의존하는 대상들의 전체목록
make -C dir : dir로 이동해서 make 명령어 실행.

i=-1를 사용하면 뒤에 코드에서 "{ i++ }" 코드3줄을 줄일수있기때문이다.
