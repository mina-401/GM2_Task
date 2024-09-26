// TextRpg000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

int PlayerAttMin = 0;
int PlayerAtt = 0;
int PlayerHp = 0;
int PlayerSpeed = 10;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
int MonsterSpeed = 10;
char MonsterName[NAMELEN] = "NONE";


// 아주 중요한
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C스타일 글자 개수 세어주는 함수
    int Size = strlen(_Name);
    _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}


// 행동
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    // char[100] = 300번지
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
    PlayerSpeed = _Speed;
}

void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
    MonsterSpeed = _Speed;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s Status", _Name);
    int nameLineCount = LINECOUNT - strlen(_Name) - strlen(" Status");
    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

// 편의를 위해서 랩핑했다고 한다.
void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

void DamageRender(const char* const _AttName, const char* const _DefName, int _Att)
{
    // 랜더링
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}

void ApplyDamage(int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}

void SpeedCheckRender(const char* const _Name)
{
    printf_s("%s 의 선공입니다\n", _Name);
}
int main()
{
    srand(time(0));
    // 선공과 후공을 만드세요.
    CreatePlayer("1", 10, 100, 20);
    CreateMonster("Orc", 10, 100, 10);


    // 플레이어와 몬스터는 각자 난수로 자신의 현재 스피드 능력
    // 시작하기 전에 몬스터와 플레이어는 서로 현재 속력을 뽑아낸다.
    // 더 높은 쪽이 먼저 공격한다.

    while (true)
    {
        // 화면 전체를 지워라.
        // 콘솔창에 다른 프로그램를 실행해주는 프로그램
        system("cls");

        char Input = ' ';

        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();

        system("cls");

        int CurMonsterSpeed = rand() % MonsterSpeed;
        int CurPlayerSpeed = rand() % PlayerSpeed;
        if (CurPlayerSpeed > CurMonsterSpeed)
            ApplyDamage(PlayerHp, MonsterAtt);
        else
            ApplyDamage(MonsterHp, PlayerAtt);

        PlayerStatusRender();
        MonsterStatusRender();

        if (CurPlayerSpeed > CurMonsterSpeed) {
            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
        }
        else {
            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
        }

        Input = _getch();

        system("cls");

        if (CurPlayerSpeed > CurMonsterSpeed)
            ApplyDamage(PlayerHp, MonsterAtt);
        else
            ApplyDamage(MonsterHp, PlayerAtt);

        PlayerStatusRender();
        MonsterStatusRender();


        if (CurPlayerSpeed > CurMonsterSpeed) {
            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
        }
        else {
            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
        }
        Input = _getch();
    }

}
