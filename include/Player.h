#pragma once

#include <SFML/Graphics.hpp>

#include "Input.h"

struct playerHelper
{
	sf::CircleShape* _shape;
	sf::RectangleShape* _line;
	sf::Vector2f _origin;

	sf::Vector2f _shapePos;
	sf::Vector2f _linePos;

	float _angle = 0.0f;
};

class Player
{
public:
	Player();
	~Player();

	void helperInit(playerHelper* helper);
	void Update();
	void Draw(sf::RenderWindow* window);
	sf::Vector2f GetPosition();

private:
	Input _input;
	playerHelper _helper;

	float _radius = 10.f;
	float _rayLength = 25.f;
	float _thickness = 2.f;
	float _speed = 0.6f;
	float _rotVelocity = 0.4f;

	void Rotate();

	void ChangePosition();

	void Move();
};

