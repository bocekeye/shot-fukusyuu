#include "DxLib.h"
#include "game.h"
#include "enemy.h"


namespace
{
	// X�����AY�����̍ő呬�x
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;
}

Enemy::Enemy()
{
	m_handle = -1;
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
}

void Enemy::update()
{
	
	m_pos += m_vec;
}

void Enemy::draw()
{
//	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

float Enemy::getColWidth() //����̍��W�̎擾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}
float Enemy::getColHeight() //�E���̍��W�̎擾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempY;
}