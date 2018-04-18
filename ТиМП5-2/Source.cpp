#include"Header.h"

int main()
{
	// Создать контейнер, содержащий объекты пользовательского типа. 
	// Тип контейнера выбирается в соответствии с вариантом задания.

	/*unique_ptr<multiset<UserType>> mst = make_unique<multiset<UserType>>();
	mst->insert({ 1, 'z', {0.1, 0.5, 0.15} });
	mst->insert({ -15, 'e', { 0.1, 0.5, 0.15, -0.333, 0.9 } });
	mst->insert({ 87, 'h', { 0.1 } });
	mst->insert({ 15, 'z', NULL });
	mst->insert({ -1689, 'a', { 0.0, 0.0, 0.00001, 1e+15 } });*/

	unique_ptr<deque<UserType>> dq = make_unique<deque<UserType>>();
	dq->push_back({ 1, 'z',{ 0.12358, 0.5, 0.15 } });
	dq->push_back({ -15, 'e',{ 0.7, 0.5, 0.15, -0.333, 0.9 } });
	dq->push_back({ 87, 'h',{ 0.1 } });
	dq->push_back({ 15, 'z', NULL });
	dq->push_back({ -1689, 'a',{ 0.0, 0.0, 0.00001, 1e+15 } });

	// Отсортировать его по убыванию элементов

	sort(dq->begin(), dq->end(), greater<UserType>());

	// Просмотреть контейнер

	cout << "First container:\n";
	for (auto i = dq->begin(); i != dq->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;

	// Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию

	bool pred(const UserType &T);
	deque<UserType>::iterator findedEl = find_if(dq->begin(), dq->end(), pred);

	// Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер

	unique_ptr<multiset<UserType, greater<UserType>>> mst = make_unique<multiset<UserType, greater<UserType>>>();

	for(;;)
	{
		/*if ((findedEl == dq->end()) && pred(*(findedEl))
		{
			mst->insert(*findedEl);
			break;
		}
		if ((findedEl == dq->end()) && !(pred(*findedEl)))
			break;*/
		if ((findedEl == dq->end()))
			break;
		mst->insert(*findedEl);
		findedEl = find_if(findedEl + 1, dq->end(), pred);
	}

	// Просмотреть второй контейнер

	cout << "Second container:\n";
	for (auto i = mst->begin(); i != mst->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;

	return 0;
}

bool pred(const UserType &T)
{
	if (T.x < 100)
		return true;
	return false;
}
