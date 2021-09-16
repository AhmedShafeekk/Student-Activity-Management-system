#include <iostream>
using namespace std;

class contributer
{
protected:
	string name;
	string ID;
    int no_of_tasks;
public:
	contributer() : name("unknown"), ID("0000"), no_of_tasks(0){}
	contributer(string n, string id, int nT) : name(n), ID(id), no_of_tasks(nT) {}

	void set_no_of_tasks(int n)
	{
		no_of_tasks = n;
	}
	int get_no_of_tasks()
	{
		return no_of_tasks;
	}

	void set_name(string n)
	{
		name = n;
	}
	string get_name()
	{
		return name;
	}

	void set_id(string i)
	{
		ID = i;
	}
	string get_id()
	{
		return ID;
	}

	void increment_task()
	{
		no_of_tasks++;
	}

	virtual void print()
	{
		cout << "name of contributer is: " << name << endl;
		cout << " no. of tasks of the contributer is: " << no_of_tasks << endl;
	}
	virtual void assign_task(contributer* a, string task)
    {

    }
};
class instructor : public contributer
{
public:
	instructor(string n, string id, int nt) : contributer(n, id, nt) {}
	static int no_of_instructors;
	instructor() { }

	void print()
	{
		contributer::print();
		cout << "Type of contributer: instructor" << endl;
		cout << "*****************************************" << endl;
	}

	void assign_task(contributer* a, string task)
	{
		contributer* p = dynamic_cast<instructor*>(a);
		if (p==nullptr)
		{
			cout << task << endl;
			a->increment_task();
		}
		else 
			cout << "invalid assignment" << endl;
	}
	//~instructor() { no_of_instructors--;}

};
int instructor::no_of_instructors = 0;

class participant : public contributer
{
public:
	static int no_of_participants;
	participant() { }
	participant(string n, string id, int nt):contributer(n,id,nt){}
	void print()
	{
		contributer::print();
		cout << "Type of contributer: " << "participant" << endl;
		cout << "*****************************************" << endl;
	}
	void assign_task(contributer *a, string task)
	{
		cout << "invalid assignment" << endl;
	}
	//~participant() { no_of_participants--;}
};
int participant::no_of_participants = 0;

class student_activity
{
private:
	contributer* a[40];
	static int actual_num_of_contri;
public:
	student_activity() : a{ 0 } { }
	void Add_contri(contributer* m)
	{
		
		contributer*p = dynamic_cast<instructor*>(m);
		if (p != nullptr) instructor::no_of_instructors++;
		else participant::no_of_participants++;
		a[actual_num_of_contri] = m;
		actual_num_of_contri++;
	}
	void Drop_contributer(int index)
	{
		contributer* m = dynamic_cast<instructor*>(a[index]);
		if (m != nullptr) instructor::no_of_instructors--;
		else participant::no_of_participants--;
		a[index] = NULL;
		index=40;
		actual_num_of_contri--;
	}
	void printInfo()
	{	
		cout << "no. of instructors is: " <<instructor:: no_of_instructors << endl;
		cout << "no. of participants is: " << participant::no_of_participants << endl;
	}
};
int student_activity:: actual_num_of_contri=0;

int main()
{
	contributer* instructor1 = new instructor("yassin", "220", 5);
	contributer* instructor2 = new instructor("omar", "232", 3);
	contributer* participant1 = new participant("zeina", "238", 3);
	contributer* participant2 = new participant("yasmin", "230", 4);
	contributer* participant3 = new participant("ahmed", "249", 6);


	student_activity a;
	a.Add_contri(instructor1);
	a.Add_contri(instructor2);
	a.Add_contri(participant1);
	a.Add_contri(participant2);
	a.Add_contri(participant3);

	a.printInfo();
	cout << endl;
	instructor1->print();
	cout << endl;
	instructor2->print();
	cout << endl;
	participant1->print();
	cout << endl;
	participant2->print();
	cout << endl;
	participant3->print();
	cout << endl;
	
	a.Drop_contributer(4);
	cout << endl;
	a.printInfo();
	instructor1 ->assign_task(participant2, "ismail");
	participant1->assign_task(participant1, "hello");
	instructor1->assign_task(instructor2, "hello");
}