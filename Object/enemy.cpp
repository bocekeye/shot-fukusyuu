#include "DxLib.h"
#include "game.h"
#include "enemy.h"
#include "SceneMain.h"

namespace
{
	// 
	constexpr float kSpeedMax = 8.0f;
}

Enemy::Enemy():
	m_pMain(nullptr),
	m_handle(-1),
	m_isExist(false),
	m_shotInterval(0),
	m_pos(),
	m_vec()
{
}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{
	m_pos.x = Game::kScreenWidth / 2;
	m_pos.y = Game::kScreenWidth / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_isExist = true;
}

void Enemy::update()
{
	if (!m_isExist) return;
	
	m_pos += m_vec;

	m_shotInterval++;
	if ((m_pMain) && (m_shotInterval >= 60))
	{
		m_pMain->createShot(m_pos,false);
		m_shotInterval = 0;
	}
}

void Enemy::draw()
{
	if (!m_isExist) return;

//	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

float Enemy::getColWidth() //¶ã‚ÌÀ•W‚Ìæ“¾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}
float Enemy::getColHeight() //‰E‰º‚ÌÀ•W‚Ìæ“¾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempY;
}