// StringCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(const char* const _str) {

    int Count = 0;
    while (_str[Count]) {
        Count = Count + 1; //문자열 끝인 0이 나올때 까지 카운트를 늘린다.
    }

    return Count;
}
int main()
{
    int Count = StringCount("한글자");
    int a = 0;

}
