#include<iostream>
using namespace std;

class DoublyList {
private:
	struct Node
	{
		int score;
		Node* next;
		Node* pre;
	};
	typedef Node* ptr;
	ptr head;
public:
	DoublyList() {
		head = NULL;
	}
	//---------------------------------------------------------------
	void ADD_Runs_At_start(int score) {
		ptr p;
		p = new Node();
		if (head == NULL) 
		{
			p->score = score;
			p->next = head;
			p->pre = NULL;
			head = p;
			return;
		}
		p->score = score;
		head->pre = p;
		p->next = head;
		head = p;
	}
	//---------------------------------------------------------------
	void ADD_Runs_At_End(int score) {
		ptr p , q;
		p = new Node();
		q = new Node();
		if (head == NULL)
		{
			p->score = score;
			p->next = head;
			p->pre = NULL;
			head = p;
			return;
		}
		for (p = head; p != 0 && p->next != nullptr; p = p->next)
			;
		q->next = p->next;
		p->next = q;
		q->pre = p;
		q->score = score;
	}
	//---------------------------------------------------------------
	bool checkDuplicate(int Value) {
		ptr p = new Node();ptr before = new Node();ptr after = new Node();
		bool con = false;
		for (p = head; p != nullptr && p->score == Value; p = p->next)
		{
			con = true;
			before = p->pre;
			after = p->next;
			before->next = after;
			after->pre = before;
		}
		if (con)
			return true;
		return false;
	}

	//---------------------------------------------------------------
	void Display() {
		ptr p = new Node();
			cout << "========================================" << endl;
			cout << "        Scores Record of Matches        " << endl;
			int i = 1;
		for (p = head; p != nullptr && p->next != nullptr; p = p->next) {
			cout << i << ".Match Score: " << p->score << endl;
			i++;
		}
		if (p->next == nullptr)
		{
			cout << i << ".Match Score: " << p->score << endl;
		}
		if (p == 0)
		{
			cout << "No Matches Record Yet!!" << endl;
			system("Pause");
		}
	}

};
int Input() {
	int Value;
	cout << "========================================" << endl;
	cout << "Enter the Value: ";
	cin >> Value;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please Enter the Match Score in Integer: " << endl;
		system("pause");
		Value = Input();
	}
	return Value;
}
void outputScreen_Edits() {
	cout << "========================================" << endl;
	cout << "             Matches Record            " << endl;
	cout << "========================================" << endl;
}
int main() {
	DoublyList Record;
	do
	{
		system("cls");
		outputScreen_Edits();
		char option;
		cout << "1.Insert At Start." << endl;
		cout << "2.Insert At End." << endl;
		cout << "3.Delete All specific Record." << endl;
		cout << "7.Display." << endl;
		cout << "0.Exit." << endl;
		cout << "Option: ";
		cin >> option;
		if (option == '1')
		{
			system("cls");
			outputScreen_Edits();
			int Score;
			Score = Input();
			Record.ADD_Runs_At_start(Score);
		}
		else if (option == '2')
		{
			system("cls");
			outputScreen_Edits();
			int Score;
			Score = Input();
			Record.ADD_Runs_At_End(Score);
		}
		else if (option == '3') {
			int Score;
			Score = Input();
			if (Record.checkDuplicate(Score))
			{
				cout << "Deleted!" << endl;
				system("pause");
			}
			else
			{
				cout << "Not Found." << endl;
				system("pause");
			}
		}
		else if (option == '7') {
			system("cls");
			outputScreen_Edits();
			Record.Display();
			system("pause");
		}
		else if (option == '0') {
			exit(1);
		}
		else {
			cout << "Invalid Input!!" << endl;
			system("pause");
		}

	} while (true);
}