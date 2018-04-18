/* Реализация операторов сравнения для пользовательского типа данных */

#include"Header.h"

bool UserType::operator> (const UserType secondArg) const
{
return (x > secondArg.x);
}

bool UserType::operator< (const UserType secondArg) const
{
	return (x < secondArg.x);
}

bool UserType::operator== (UserType secondArg)
{
	return (x == secondArg.x);
}