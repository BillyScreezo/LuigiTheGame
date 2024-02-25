#pragma once
#include "Prototype.h"
#include "Ground.h"
#include "Player.h"
#include <vector>
#include "Const.h"
// ���������� ������������� ��������
// ���������� �������� �� ������ level
static int sID{ 0 };

class Player;

// ��� ��������
enum class EnemyType
{
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
enum class Interaction
{
	ONX,
	ONY,
	ONYD,
	NOT
};

using namespace std;
class Enemy : public Prototype
{
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

	Enemy(float, float, EnemyType, Map&, vector<Ground*>&, bool canFall = true, bool move = false);
	Enemy(float, float, Map&);

	// MapC fun
	void setCoord(float x, float y);
	size_t getType();

	void setType(EnemyType);

	virtual void die(bool type = true) override;

	// ����������� �������� ��� �������� ������
	void moveR(float wspeed);



	// ������ �� ��������
	virtual bool isDead() override;

	void throwFireB(vector<Enemy*>& ENEMY);

	void reset();


	// ������� ���������
	float getX() { return x; }
	float getY() { return y; }



	// �������� �������� � ��������
	void move();


	// �������������� ��������� ���� � ������
	void enemyInteraction(vector<Enemy*>&, Player&);

	// ����������� ���� �������������� ������ � ��������
	Interaction interaction(Player& player);

	// ��������� �������������� ������ � ��������
	void processInteraction(Player&, Interaction, vector<Ground*>&);



	virtual void putOnMap() override;




	void physic(vector<Ground*>& space, Player& player);


};


enum class WorkType
{
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
void enemyCheckAndClear(vector<Enemy*>&);

void enemyModule(vector<Enemy*>&, Player&, vector<Ground*>&, Map& map, WorkType);