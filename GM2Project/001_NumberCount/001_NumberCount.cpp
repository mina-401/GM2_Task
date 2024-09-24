// 001_NumberCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int NumberCount(int _Value)
{
    int Result = 0;
    while (_Value)
    {
        Result = Result + 1; // 카운트
        _Value = _Value / 10;

    }
    return Result;
}


//숫자 -> 문자열 
void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    int i = NumberCount(_Value); //4
    Buffer[i] = 0;

    while (_Value)
    {
        i = i - 1;
        Buffer[i] = (_Value % 10) + '0';
        _Value = _Value / 10;
    }

    return;
}
int main()
{
    int Result0 = NumberCount(12358);//5
    int Result1 = NumberCount(5258);//4
    int Result2 = NumberCount(5258111);//7

    char Buffer[100] = { 0 };
    NumberToString(Buffer, 100, 1234);
    // std::cout << Buffer << std::endl;
    int a = 0;
    //음수,0 못넣는다.
}
