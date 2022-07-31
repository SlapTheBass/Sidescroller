#pragma once

#include <iostream>


#ifdef _DEBUG

	#define DBG_MSG(x) (std::cout << #x << " = " << x << std::endl)
	#define DBG_LOG(x) (std::cout << x << std::endl)

#endif //_DEBUG

typedef enum E_keys
{
	eNONE = 0,
	eSPACE,
	eUP,
	eUP_LEFT,
	eUP_RIGHT,
	eDOWN,
	eDOWN_LEFT,
	eDOWN_RIGHT,
	eLEFT,
	eRIGHT,
	eESC,
	eSHIFT,
	eCTRL
};
