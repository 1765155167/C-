#include "Player.h"

Player::Player(std::string name, int score):
	name(name),score(score)
{
}

void Player::setScore(int score)
{
	this->score = score;
}

int Player::getScore()
{
	return this->score;
}

void Player::show()
{
	std::cout << "������" << this->name
		<< " �÷֣�" << this->score << std::endl;
}

Player::~Player()
{
}
