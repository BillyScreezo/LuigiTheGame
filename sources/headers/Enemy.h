#pragma once

#include <vector>

#include "Prototype.h"
#include "Ground.h"
#include "Player.h"

// Уникальный идентификатор сущности
// Необходимо обнулять на каждом level
static int sID{ 0 };

class Player;

// Тип сущности
enum class EnemyType {
	// Обычные враги
	// Гриб
	GOOMBA,
	// Черепаха
	KOOPA,
	// Летающая черепаха
	FLYKOOPA,
	// Растение
	PLANT,

	// Особы враги
	// Статический огонь
	SFIRE,
	// Огонь от босса
	BFIRE,
	// Огонь от игрока
	PFIRE,

	// Предметы(для игрока)
	// Звезда(неуязвимость)
	STAR,
	// Гриб(увеличение размера)
	MUSHROOM,
	// Гриб(+1 жизнь)
	LIVEMUSHROOM,
	// Цветок(возможность стрелять)
	FLOWER,
	// Монета
	COIN,
	// Труп
	DEADBODY,

	BOSS
};

// Вид взаимодействия сущ
enum class Interaction {
	ONX,
	ONY,
	ONYD,
	NOT
};

class Enemy final : public Prototype {
private:
	EnemyType m_type;      // Тип сущности
	bool m_move;           // Направление движения, true - right/up, f - left/down
	bool isFriend{ true }; // Сущность дружественна(для других сущностей) или нет
	bool canFall;          // Может ли сущность падать с начального для неё Ground
	bool throwFire{ true };
	bool isSee{ false };
	float yU;              // Уровень верхушки при движении PLANT && FLYKOOPA
	float yD;              // Уровень дна при движении PLANT && FLYKOOPA
	int ID;                // Уникальный идентификатор
	int lastGroundNum;     // Номер последнего Ground в списке, на котором находился Enemy
	int position;          // Текущее состояние для SFIRE(в какой позиции находится в данный момент)

	// Сравнение двух сущностей
	bool operator==(Enemy&);

	void inVision();

public:

	// Активена ли сущность
	bool status();
	bool inVis();
	// Функции состояния
	// Дружественна ли сущность
	bool isFriendF();

	Enemy(float, float, EnemyType, Map&, std::vector<Ground*>&, bool canFall = true, bool move = false);
	Enemy(float, float, Map&);

	// MapC fun
	void setCoord(float, float);
	size_t getType();

	void setType(EnemyType);

	virtual void die(bool type = true) override;

	// Перемещение сущности при движении игрока
	void moveR(float);

	// Мертва ли сущность
	virtual bool isDead() override;

	void throwFireB(std::vector<Enemy*>&);

	void reset();

	// Геттеры координат
	inline float getX() { return x; }
	inline float getY() { return y; }

	// Привести сущность в движение
	void move();

	// Взаимодействие сущностей друг с другом
	void enemyInteraction(std::vector<Enemy*>&, Player&);

	// Определение типа взаимодействия игрока и сущности
	Interaction interaction(Player&);

	// Обработка взаимодействия игрока и сущности
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

// Проверка всех врагов
// Если враг мёрт - удалить его
void enemyCheckAndClear(std::vector<Enemy*>&);

void enemyModule(std::vector<Enemy*>&, Player&, std::vector<Ground*>&, Map&, WorkType);