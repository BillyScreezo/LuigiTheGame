#pragma once

#include <vector>

#include "Prototype.h"
#include "Ground.h"
#include "Player.h"

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
	inline bool operator==(const Enemy& other) { return this->ID == other.ID; }
	void inVision();

public:

	// ���������� ������������� ��������
	// ���������� �������� �� ������ level
	static int sID;

	Enemy(float, float, EnemyType, Map&, std::vector<Ground*>&, bool canFall = true, bool move = false);
	Enemy(float, float, Map&);

	// ��������� ������� ��������(�������/���������)
	inline bool status() { return isStand; }
	inline bool inVis() { return isSee; }
	// ��������� ������� ��������(������������/���������)
	inline bool isFriendF() { return isFriend; }
	// �������� �������� ��� �������� ������ Right
	inline void moveR(float wspeed) { x -= wspeed; }
	// ������������� ��������(���./����. ������)
	inline void move() { isStand = !isStand; }
	// ������� ���������
	inline float getX() { return x; }
	inline float getY() { return y; }

	// MapC fun
	void setCoord(float, float);
	void setType(EnemyType);
	void throwFireB(std::vector<Enemy*>&);
	void reset();
	void physic(std::vector<Ground*>&, Player&);
	// �������������� ��������� ���� � ������
	void enemyInteraction(std::vector<Enemy*>&, Player&);
	// ��������� �������������� ������ � ��������
	void processInteraction(Player&, Interaction, std::vector<Ground*>&);

	// ����������� ���� �������������� ������ � ��������
	Interaction interaction(Player&);
	size_t getType();

	// ������ �� ��������
	virtual bool isDead() override;
	virtual void die(bool type = true) override;
	virtual void putOnMap() override;
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