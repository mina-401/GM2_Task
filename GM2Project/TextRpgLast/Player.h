#pragma once
#include "Actor.h"

// UObject �̸�
// UStatusUnit�� ���ؼ� �ɷ�ġ
// UFightUnit�� ���ؼ� ����
class UPlayer : public AActor
{
	// �Ϻη� ����


public:
	UPlayer();

	inline int GetEquipAtt() const
	{
		return EquipAtt;
	}

	inline void SetEquipAtt(int _Value)
	{
		EquipAtt = _Value;
	}

	void StatusTextRender() override;

private:
	int EquipAtt = 0;
};

