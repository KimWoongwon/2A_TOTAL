#pragma once
#include "Global.h"
#include "Enemy.h"
#include "Bullet.h"
struct Level	// ������ ������ ���� ����ü ���� �߽��ϴ�.
{
	Enemy*	EnemyList[MAX_ENEMY];			//Enemy List
	Bullet*	BulletList[MAX_EYBULLET];		//Enemy Bullet Lsit
	int		GenCount = 0;					//�ش緹���� ��ŭ�� ���Ͱ� ���Ǿ����� üũ�ϱ����� �����Դϴ�.
	int		ShotCount = 0;					//�ش� ������ ���� �Ѿ��� ��� �������� üũ�մϴ�.

	// �ʱ�ȭ�� ���� �κ��Դϴ�.
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