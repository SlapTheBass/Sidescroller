#include "Input.h"

Input::Input()
{
	_keyHandler = eNONE;
}

Input::~Input()
{

}

E_keys Input::pressedKey()
{
	if (_keyboard.isKeyPressed(sf::Keyboard::W))
	{
		if (_keyboard.isKeyPressed(sf::Keyboard::A))
		{
			_keyHandler = eUP_LEFT;
		}
		else if (_keyboard.isKeyPressed(sf::Keyboard::D))
		{
			_keyHandler = eUP_RIGHT;
		}
		else
		{
			_keyHandler = eUP;
		}
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::S))
	{
		if (_keyboard.isKeyPressed(sf::Keyboard::A))
		{
			_keyHandler = eDOWN_LEFT;
		}
		else if (_keyboard.isKeyPressed(sf::Keyboard::D))
		{
			_keyHandler = eDOWN_RIGHT;
		}
		else
		{
			_keyHandler = eDOWN;
		}
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::A))
	{
		_keyHandler = eLEFT;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::D))
	{
		_keyHandler = eRIGHT;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::LShift) || _keyboard.isKeyPressed(sf::Keyboard::RShift))
	{
		_keyHandler = eSHIFT;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::LControl) || _keyboard.isKeyPressed(sf::Keyboard::RControl))
	{
		_keyHandler = eCTRL;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::Space))
	{
		_keyHandler = eSPACE;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::Escape))
	{
		_keyHandler = eESC;
	}
	else
	{
		_keyHandler = eNONE;
	}

	return _keyHandler;
}