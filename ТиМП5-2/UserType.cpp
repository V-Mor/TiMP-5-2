/* ���������� �������� ��������� ��� ����������������� ���� */

#include"Header.h"

bool UserType::operator< (UserType secondArg)
{
	return (this->x < secondArg.x);
}

bool UserType::operator> (UserType secondArg)
{
	return (this->x > secondArg.x);
}