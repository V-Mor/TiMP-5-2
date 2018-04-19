#include<iostream>
#include<algorithm>
#include<iterator>
#include<deque>
#include<set>
#include<functional>
#include<memory>

using namespace std;

class UserType	// Интерфейс пользовательского типа данных
{
public:
	int x;
	char c;
	double d[50];

	bool operator> (const UserType secondArg) const;

	bool operator< (const UserType secondArg) const;

	bool operator== (UserType secondArg);
};

template<class T>
class Multisorter	// Класс, содержащий меоды для сортировки контейнеров Multiset
{
	public:
		static multiset<T, less<T>>* increaseSort(multiset<T, greater<T>> *mts)
		{
			multiset<T, less<T>> *sorted = new multiset<T, less<T>>;
			for (multiset<T>::iterator i = mts->begin(); i != mts->end(); ++i)
				sorted->insert(*i);
			return sorted;
		}
		static multiset<T, greater<T>>* decreaseSort(multiset<T, less<T>> *mts)
		{
			multiset<T, greater<T>> *sorted = new multiset<T, greater<T>>;
			for (multiset<T>::iterator i = mts->begin(); i != mts->end(); ++i)
				sorted->insert(*i);
			return sorted;
		}
};