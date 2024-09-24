// 003_PlusString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int StringCount(const char* const _str) {

    int Count = 0;
    while (_str[Count]) {
        Count = Count + 1; //문자열 끝인 0이 나올때 까지 카운트를 늘린다.
    }

    return Count;
}


void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    // NumberToString(Buffer, BufferSize, _Value0);
    int Count = 0;
    int valueSize0 = StringCount(_Value0);
    for (int i = 0; i < valueSize0; i++)
    {
        _Buffer[i] = _Value0[i];
    }
    int valueSize1 = StringCount(_Value1);
    for (int i = 0; i < valueSize1; i++)
    {
        _Buffer[i + valueSize0] = _Value1[i];
    }
    //_Buffer[valueSize0 + valueSize1] = 0;
    int a = 0;
}

int main()
{

    char Buffer[100] = { 0 };
    PlusString(Buffer, 100, "AAA", "BBB");


    int a = 0;
}
