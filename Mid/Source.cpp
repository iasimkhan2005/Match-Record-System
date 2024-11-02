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
	int count = 0;
	typedef Node* ptr;
	ptr head,tail;
public:
	DoublyList() {
		head = NULL;
		tail = NULL;
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
			count++;
			return;
		}
		p->score = score;
		head->pre = p;
		p->next = head;
		head = p;
		count++;
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
			tail = p;
			count++;
			return;
		}
		for (p = head; p != 0 && p->next != nullptr; p = p->next)
			;
		q->next = p->next;
		p->next = q;
		q->pre = p;
		q->score = score;
		tail = q;
		count++;
	}
	//---------------------------------------------------------------
	bool checkDuplicate(int Value) {
		ptr p = new Node();ptr before = new Node();ptr after = new Node();
		bool con = false;
		p = head;
		while (p != nullptr) {
			if (p->score == Value) {
				if (p == head) {
					//before = NULL;
					head = p->next;
					p = p->next;
					con = true;
					count--;
					continue;
				}
				before = p->pre;
				if (p->next == nullptr) {
					before->next = nullptr;
					tail = before;
					con = true;
					count--;
					break;
				}
				after = p->next;
				before->next = after;
				after->pre = before;
				con = true;
				count--;
			}
			p = p->next;
		}
		if (con)
			return true;
		return false;
	}
	//---------------------------------------------------------------
	void DisplayInSequence() {
		ptr p = new Node();
		p = head;
			//cout << "========================================" << endl;
			cout << "        Scores Record of Matches  (In Sequence)      " << endl;
			int i = 1;
			if (p == nullptr)
			{
				cout << "No Matches Record Yet!!" << endl;
				system("Pause");
			}
		while (p != nullptr) {
			cout << i << ".Match Score: " << p->score << endl;
			i++;
			p = p->next;
		}
		
	}
	//---------------------------------------------------------------
	void DisplayINReverseOrder() {
		ptr p = new Node();
		p = tail;
		//cout << "========================================" << endl;
		cout << "        Scores Record of Matches  (In Reverse Order)      " << endl;
		int i = count;
		if (p == nullptr)
		{
			cout << "No Matches Record Yet!!" << endl;
			system("Pause");
		}
		while (p != nullptr) {
			cout << i << ".Match Score: " << p->score << endl;
			i--;
			p = p->pre;
		}
	}
	//---------------------------------------------------------------
	int HighestSCORE() {
		ptr p = new Node(); p = head;
		int Highest = 0;
		if (p == nullptr) {
			return 0;
		}
		if (count == 1) {
			return 1;
		}
		while (p != nullptr) {
			if (Highest < p->score) {
				Highest = p->score;
			}
			p = p->next;
		}
		return Highest;

 	}
	//---------------------------------------------------------------
	int LowestSCORE() {
		ptr p = new Node(); p = head;
		int Lowest = p->score;
		while (p != nullptr) {
			if (Lowest >= p->score) {
				Lowest = p->score;
			}
			p = p->next;
		}
		return Lowest;
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
		cout << "4.Display Scores In Sequence." << endl;
		cout << "5.Display Score In Reverse Order." << endl;
		cout << "6.Highest and Lowest Score in Record." << endl;
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
			cout << "ADDED" << endl;
			system("pause");
		}
		else if (option == '2')
		{
			system("cls");
			outputScreen_Edits();
			int Score;
			Score = Input();
			Record.ADD_Runs_At_End(Score);
			cout << "ADDED" << endl;
			system("pause");
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
		else if (option == '4') {
			system("cls");
			outputScreen_Edits();
			Record.DisplayInSequence();
			system("pause");
		}
		else if (option == '5') {
			system("cls");
			outputScreen_Edits();
			Record.DisplayINReverseOrder();
			system("pause");
		}
		else if (option == '6') {
			system("cls");
			outputScreen_Edits();
			if (Record.HighestSCORE() == 0)
			{
				cout << "No Record Found!" << endl;
				system("pause");
				continue;
			}
			if (Record.HighestSCORE() == 1)
			{
				cout << "Only One Match Score Record Found , So there will be no Highest and Lowest in the Record." << endl;
				system("pause");
				continue;
			}
			int Highest = Record.HighestSCORE();
			int Lowest = Record.LowestSCORE();
			cout << "Highest Score IN Record is: " << Highest << endl;
			cout << "Lowest Score IN Record is: " << Lowest << endl;
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