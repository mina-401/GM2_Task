#include <iostream>

class Player
{
public: // <= 곧 알려드리겠습니다.
    int Hp;
    int Att;
};

int Test(int _Value)
{
    return _Value + 4;
}

// 맴버변수 항목들의 바이트 크기에 따라서 차이가 생기기 시작합니다.
class ClassTest
{
public:
    // 바이트 패딩 규칙
    // 1. 내부에서 가장 바이트 크기가 큰 녀석을 찾습니다.
    //    => 현재는 4바이트
    // 2. 첫번째 변수부터 메모리적 위치를 잡는다.
    //    2-1. 이 변수는 현재 가장큰 메모리 크기보다 큰가 작은가 같은가?
    //    2-2. 같으면 그냥 그대로 위치
    //    2-3. 작다면 앞쪽에 위치시키고 나머지를 패딩바이트로 채웁니다.
    //    2-4. 가장 큰 바이트안에 쪼개서 밀어 넣을수 있다면
    //         8~4~2~1 단위로 밀어 넣습니다.
    //         어떤자료형이 4바이트인데.
    //         s0
    //         s1
    //         [b0][pb][s0][s0][s1][s1][pb][pb]

    // [i0][i0][i0][i0][b0][b1][C0][pb][i1][i1][i1][i1][c0][pb][pb][pb]
    int int0; // 4
    bool bool0; // 4

    long long long0;
};


int main()
{
    // short 2바이트 정수형
    //       int의 2바이트 버전

    Test(4);

    {
        Player NewPlayer = Player();

        // 맴버변수 쓰는 기초적인 방법
        // 객체기반이기 때문에 
        // 객체'.' .을 통해서 객체가 내부의 맴버를 사용할수 있습니다.

        int Value = 0;
        int& ValueRef = Value;
        &ValueRef;


        // 첫번째 맴버변수의 주소값과 동일하다.
        Player& PlayerRef = NewPlayer;
        __int64 Addthis = reinterpret_cast<__int64>(&PlayerRef);

        int& HPRef = NewPlayer.Hp;
        __int64 Add0 = reinterpret_cast<__int64>(&HPRef);

        int& AttRef = NewPlayer.Att;
        __int64 Add1 = reinterpret_cast<__int64>(&AttRef);
    }

    {
        int Value = sizeof(short);
        int a = 0;
    }

    {
        ClassTest NewTest;

        int Value = sizeof(ClassTest);
        __int64 Addthis = reinterpret_cast<__int64>(&NewTest);
        long longValue= sizeof(NewTest.long0);

        int a = 0;

        //int& Add0Ref = NewTest.intValue;
        //__int64 Add0 = reinterpret_cast<__int64>(&Add0Ref);

        //bool& Add1Ref = NewTest.boolValue;
        //__int64 Add1 = reinterpret_cast<__int64>(&Add1Ref);
        //int a = 0;
    }
}
