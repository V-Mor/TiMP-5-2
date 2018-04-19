#include"Header.h"

int main()
{
	// ������� ���������, ���������� ������� ����������������� ����. 
	// ��� ���������� ���������� � ������������ � ��������� �������.

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

	// ������������� ��� �� �������� ���������

	sort(dq->begin(), dq->end(), greater<UserType>());

	// ����������� ���������

	cout << "First container:\n";
	for (auto i = dq->begin(); i != dq->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;

	// ��������� ���������� ��������, ����� � ���������� �������, ��������������� ��������� �������

	bool pred(const UserType &T);
	deque<UserType>::iterator findedEl = find_if(dq->begin(), dq->end(), pred);

	// ����������� ��������, ��������������� ��������� ������� � ������ (�������������� ������) ���������

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

	// ����������� ������ ���������

	cout << "Second container:\n";
	for (auto i = mst->begin(); i != mst->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;

	// ������������� ������ � ������ ���������� �� ����������� ���������

	sort(dq->begin(), dq->end());
	unique_ptr<multiset<UserType>> msts(Multisorter<UserType>::increaseSort(mst.get()));

	// ����������� ��

	cout << "First container:\n";
	for (auto i = dq->begin(); i != dq->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;
	cout << "Second container:\n";
	for (auto i = msts->begin(); i != msts->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;

	// �������� ������ ��������� ����� ������� ������ ����

	unique_ptr<deque<UserType>> dq3(new deque<UserType>);
	merge(dq->begin(), dq->end(), msts->begin(), msts->end(), back_inserter(*dq3));

	// ����������� ������ ���������

	cout << "Third container:\n";
	for (auto i = dq3->begin(); i != dq3->end(); ++i)
		cout << i->x << " " << i->c << " " << i->d[0] << "..." << endl;
	cout << endl;

	// ����������, ������� ���������, ��������������� ��������� �������, �������� ������ ���������

	int count = count_if(dq3->begin(), dq3->end(), pred);
	cout << "Third container consist " << count << " special elements\n";

	// ����������, ���� �� � ������� ���������� �������, ��������������� ��������� �������.

	if (find_if(dq3->begin(), dq3->end(), pred) != dq3->end())
		cout << "Third container consist special element\n";

	return 0;
}

bool pred(const UserType &T)
{
	if (T.x < 10)
		return true;
	return false;
}
