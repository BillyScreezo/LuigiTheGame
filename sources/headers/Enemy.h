#pragma once

#include <vector>

#include "Prototype.h"
#include "Ground.h"
#include "Player.h"

// ���������� ������������� ��������
// ���������� �������� �� ������ level
static int sID{ 0 };

class Player;

// ��� ��������
enum class EnemyType {
	// ������� �����
	// ����
	GOOMBA,
	// ��������
	KOOPA,
	// �������� ��������
	FLYKOOPA,
	// ��������
	PLANT,

	// ����� �����
	// ����������� �����
	SFIRE,
	// ����� �� �����
	BFIRE,
	// ����� �� ������
	PFIRE,

	// ��������(��� ������)
	// ������(������������)
	STAR,
	// ����(���������� �������)
	MUSHROOM,
	// ����(+1 �����)
	LIVEMUSHROOM,
	// ������(����������� ��������)
	FLOWER,
	// ������
	COIN,
	// ����
	DEADBODY,

	BOSS
};

// ��� �������������� ���
enum class Interaction {
	ONX,
	ONY,
	ONYD,
	NOT
};

class Enemy final : public Prototype {
private:
	EnemyType m_type;      // ��� ��������
	bool m_move;           // ����������� ��������, true - right/up, f - left/down
	bool isFriend{ true }; // �������� ������������(��� ������ ���������) ��� ���
	bool canFall;          // ����� �� �������� ������ � ���������� ��� �� Ground
	bool throwFire{ true };
	bool isSee{ false };
	float yU;              // ������� �������� ��� �������� PLANT && FLYKOOPA
	float yD;              // ������� ��� ��� �������� PLANT && FLYKOOPA
	int ID;                // ���������� �������������
	int lastGroundNum;     // ����� ���������� Ground � ������, �� ������� ��������� Enemy
	int position;          // ������� ��������� ��� SFIRE(� ����� ������� ��������� � ������ ������)

	// ��������� ���� ���������
	bool operator==(Enemy&);

	void inVision();

public:

	// �������� �� ��������
	bool status();
	bool inVis();
	// ������� ���������
	// ������������ �� ��������
	bool isFriendF();

	Enemy(float, float, EnemyType, Map&, std::vector<Ground*>&, bool canFall = true, bool move = false);
	Enemy(float, float, Map&);

	// MapC fun
	void setCoord(float, float);
	size_t getType();

	void setType(EnemyType);

	virtual void die(bool type = true) override;

	// ����������� �������� ��� �������� ������
	void moveR(float);

	// ������ �� ��������
	virtual bool isDead() override;

	void throwFireB(std::vector<Enemy*>&);

	void reset();

	// ������� ���������
	inline float getX() { return x; }
	inline float getY() { return y; }

	// �������� �������� � ��������
	void move();

	// �������������� ��������� ���� � ������
	void enemyInteraction(std::vector<Enemy*>&, Player&);

	// ����������� ���� �������������� ������ � ��������
	Interaction interaction(Player&);

	// ��������� �������������� ������ � ��������
	void processInteraction(Player&, Interaction, std::vector<Ground*>&);

	virtual void putOnMap() override;

	void physic(std::vector<Ground*>&, Player&);
};

enum class WorkType {
	ENABLEALL,
	PUTONMAP,
	MOVEL,
	MOVER,
	PTHROW,
	PHYSIC,
	INTERACTION,
	MAX
};

// �������� ���� ������
// ���� ���� ��� - ������� ���
void enemyCheckAndClear(std::vector<Enemy*>&);

void enemyModule(std::vector<Enemy*>&, Player&, std::vector<Ground*>&, Map&, WorkType);