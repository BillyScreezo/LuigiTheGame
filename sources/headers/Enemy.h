#pragma once

#include <vector>

#include "Prototype.h"
#include "Ground.h"
#include "Player.h"

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
	inline bool operator==(const Enemy& other) { return this->ID == other.ID; }
	void inVision();

public:

	// Уникальный идентификатор сущности
	// Необходимо обнулять на каждом level
	static int sID;

	Enemy(float, float, EnemyType, Map&, std::vector<Ground*>&, bool canFall = true, bool move = false);
	Enemy(float, float, Map&);

	// Получение статуса сущности(активна/неактивна)
	inline bool status() { return isStand; }
	inline bool inVis() { return isSee; }
	// Получение статуса сущности(дружественна/враждебна)
	inline bool isFriendF() { return isFriend; }
	// Смещение сущности при движении игрока Right
	inline void moveR(float wspeed) { x -= wspeed; }
	// Переактивация сущности(вкл./выкл. физики)
	inline void move() { isStand = !isStand; }
	// Геттеры координат
	inline float getX() { return x; }
	inline float getY() { return y; }

	// MapC fun
	void setCoord(float, float);
	void setType(EnemyType);
	void throwFireB(std::vector<Enemy*>&);
	void reset();
	void physic(std::vector<Ground*>&, Player&);
	// Взаимодействие сущностей друг с другом
	void enemyInteraction(std::vector<Enemy*>&, Player&);
	// Обработка взаимодействия игрока и сущности
	void processInteraction(Player&, Interaction, std::vector<Ground*>&);

	// Определение типа взаимодействия игрока и сущности
	Interaction interaction(Player&);
	size_t getType();

	// Мертва ли сущность
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

// Проверка всех врагов
// Если враг мёрт - удалить его
void enemyCheckAndClear(std::vector<Enemy*>&);

void enemyModule(std::vector<Enemy*>&, Player&, std::vector<Ground*>&, Map&, WorkType);