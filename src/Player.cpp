#include "Player.h"

Player::Player()
{
	helperInit(&_helper);	
}

Player::~Player()
{

}

void Player::helperInit(playerHelper* ptrHelper)
{
	ptrHelper->_origin = { 200.f, 200.f };
	ptrHelper->_shape = new sf::CircleShape(_radius);
	ptrHelper->_shape->setPosition(ptrHelper->_origin);
	ptrHelper->_shape->setFillColor(sf::Color::Red);

	ptrHelper->_line = new sf::RectangleShape(sf::Vector2f(_thickness, _rayLength));
	ptrHelper->_line->setPosition(ptrHelper->_shape->getPosition().x + _radius, ptrHelper->_shape->getPosition().y + _radius);
	ptrHelper->_line->setFillColor(sf::Color::White);
}

void Player::Rotate()
{
	if (sf::Mouse::getPosition().x >= sf::VideoMode::getDesktopMode().width - 1)
	{
		sf::Mouse::setPosition(sf::Vector2i(0, sf::Mouse::getPosition().y));
	}
	else if (sf::Mouse::getPosition().x <= 0)
	{
		sf::Mouse::setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width - 0.1f, sf::Mouse::getPosition().y));
	}

	float tempAngle = sf::Mouse::getPosition().x * _rotVelocity;

	_helper._angle = tempAngle;

	DBG_MSG(_helper._angle);

	_helper._line->setRotation(_helper._angle);
}

void Player::ChangePosition()
{
	_helper._shape->setPosition(_helper._shapePos.x, _helper._shapePos.y);
	_helper._line->setPosition(_helper._linePos.x, _helper._linePos.y);
}


void Player::Move()
{
	_helper._shapePos = _helper._shape->getPosition();
	_helper._linePos = _helper._line->getPosition();

	switch (_input.pressedKey())
	{
	case eUP:
		_helper._shapePos.y -= _speed;
		_helper._linePos.y -= _speed;

		Rotate();
		ChangePosition();
		break;

	case eUP_LEFT:
		_helper._shapePos.y -= _speed/1.5;
		_helper._linePos.y -= _speed/1.5;

		_helper._shapePos.x -= _speed/1.5;
		_helper._linePos.x -= _speed/1.5;

		Rotate();
		ChangePosition();
		break;

	case eUP_RIGHT:
		_helper._shapePos.y -= _speed/1.5;
		_helper._linePos.y -= _speed/1.5;

		_helper._shapePos.x += _speed/1.5;
		_helper._linePos.x += _speed/1.5;

		Rotate();
		ChangePosition();
		break;

	case eDOWN:
		_helper._shapePos.y += _speed;
		_helper._linePos.y += _speed;

		Rotate();
		ChangePosition();
		break;

	case eDOWN_LEFT:
		_helper._shapePos.y += _speed/1.5;
		_helper._linePos.y += _speed/1.5;

		_helper._shapePos.x -= _speed/1.5;
		_helper._linePos.x -= _speed/1.5;

		Rotate();
		ChangePosition();
		break;

	case eDOWN_RIGHT:
		_helper._shapePos.y += _speed/1.5;
		_helper._linePos.y += _speed/1.5;

		_helper._shapePos.x += _speed/1.5;
		_helper._linePos.x += _speed/1.5;

		Rotate();
		ChangePosition();
		break;

	case eLEFT:
		_helper._shapePos.x -= _speed;
		_helper._linePos.x -= _speed;

		Rotate();
		ChangePosition();
		break;

	case eRIGHT:
		_helper._shapePos.x += _speed;
		_helper._linePos.x += _speed;

		Rotate();
		ChangePosition();
		break;

	default:
		Rotate();
		break;
	}
}

void Player::Update()
{
	Move();
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(*_helper._shape);
	window->draw(*_helper._line);
}

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(_helper._shape->getPosition().x + _radius, _helper._shape->getPosition().y - _radius);
}