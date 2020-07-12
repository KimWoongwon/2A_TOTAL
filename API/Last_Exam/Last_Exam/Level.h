#pragma once
#include "Global.h"
#include "Enemy.h"
#include "Bullet.h"
struct Level	// 레벨의 구현을 위해 구조체 정의 했습니다.
{
	Enemy*	EnemyList[MAX_ENEMY];			//Enemy List
	Bullet*	BulletList[MAX_EYBULLET];		//Enemy Bullet Lsit
	int		GenCount = 0;					//해당레벨에 얼만큼의 몬스터가 젠되었는지 체크하기위한 변수입니다.
	int		ShotCount = 0;					//해당 레벨의 현재 총알이 몇발 나갔는지 체크합니다.

	// 초기화를 위한 부분입니다.
	void Initialize(Player* player, HBITMAP Enemybitmap[], HBITMAP EnemyBulletBitmap, POINT Offset, EnemyType Type01, EnemyType Type02)
	{
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			if (i % 2 == 1)
				EnemyList[i] = new Enemy(player->GetPos(), Enemybitmap[0], Type01);
			if (i % 2 == 0)
				EnemyList[i] = new Enemy(player->GetPos(), Enemybitmap[1], Type02);
		}
		for (int i = 0; i < MAX_EYBULLET; i++)
		{
			BulletList[i] = new Bullet(player->GetPos(), EnemyBulletBitmap, Offset);
		}
	}
};