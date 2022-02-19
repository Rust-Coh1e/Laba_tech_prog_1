#include <iostream>
#include "Queue.h"
#include "Queue_child.h"

using namespace std;

template <class T>
void chosen_class(T* q, int n_q)
{
	int c;
	int flag = 1;
	int value; //введенное значение пользователем
	int index = 0; //номер очереди, с которой работаем
	int count = 1; //кол-во очередей, с которыми работает пользователь
	float res4 = 0; //переменная для выполнения пункта задания
	int chosen_q; //номер выбранной очереди
	while (flag == 1)
	{
		cout << "1 - Adding a queue item" << endl;
		cout << "2 - Extracting a queue item" << endl;
		cout << "3 - Queue output to the screen" << endl;
		cout << "4 - Average value" << endl;
		cout << "5 - Creating a copy of the queue" << endl;
		cout << "6 - Merging two queues" << endl;
		cout << "7 - Choosing a different queue" << endl;
		cout << "8 - Which queue am I working with now?" << endl;
		cout << "0 - Return to the selection of the successor class" << endl;
		cout << "-> ";
		cin >> c;

		switch (c)

		{

		case 1: 
			system("cls");
			cout << "Enter value: ";
			cin >> value;
			q[index].push(value);
			cout << "Value add in queue.\n " << endl;
			break;
		case 2: 
			if (q[index].isEmpty())
			{
				cout << "The queue is empty.\n " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				value = q[index].pop();
				cout << "Extracted element: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: 
			if (q[index].isEmpty())
			{
				cout << "The queue is empty.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				q[index].print();
				cout << "\n";
			}
			break;
		case 4: 
			if (q[index].isEmpty())
			{
				cout << "The queue is empty.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				res4 = q[index].average();
				cout << "Avarage value: " << res4 << endl;
				cout << "\n";
			}
		break;
		case 5: //
			if (q[index].isEmpty())
			{
				cout << "The queue is empty.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				if (count == n_q)
				{
					cout << "It is not possible to create a copy of the queue because the number of queues has reached the maximum.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[count].copy(q[index]);
				cout << "The queue has been copied successfully. Now there are two equal queues.\n" << endl;
				count++; 
			}
			break;
		case 6: 
			if (count == 1)
			{
				cout << "There is only one queue.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Which queue to merge with?" << endl;
				cin >> chosen_q;
				if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
				{
					cout << "Invalid value!\n" << endl;
					system("pause");
					break;
				}
				if (q[chosen_q].isEmpty())
				{
					cout << "It is not possible to merge because the second queue is empty.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[index].merge(q[chosen_q]);
				//count++; 
				cout << "\n";
			}
			break;
		case 7: 
			system("cls");
			cout << "You are currently working with queue number " << index << endl;
			cout << "Enter the queue number (from 0 to " << n_q - 1 << ") that you want to switch to: ";
			cin >> chosen_q;
			if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
			{
				cout << "Invalid value or the number of queues exceeded!\n" << endl;
				system("pause");
			}
			else
			{
				index = chosen_q;
				count++;
				system("cls");
				cout << "You switched to queue number" << index << endl;
				cout << "\n";
			}
			break;
		case 8:
			system("cls");
			cout << "Are you currently working with a queue number" << index << endl;
			cout << "\n";
			break;
		case 0:
			cout << "\n";
			flag = 0;
			break;
		}
	}
}



int main()
{
	int count_queue;
	int c;
	int flag = 1;

	Queue_private* q1 = NULL;
	Queue_protected* q2 = NULL;
	Queue_public* q3 = NULL;

	cout << "Enter count of queue: ";
	cin >> count_queue;
	system("cls");
	cout << "Which successor class do you want to work with?: " << endl;

	while (flag == 1)
	{
		cout << "1 - Private" << endl;
		cout << "2 - Protected" << endl;
		cout << "3 - Public" << endl;
		cout << "0 - Quit" << endl;
		cout << "-> ";
		cin >> c;
		switch (c)
		{
		case 1:
			q1 = new Queue_private[count_queue];
			system("cls");
			chosen_class(q1, count_queue);
			delete[] q1;
			break;
		case 2:
			q2 = new Queue_protected[count_queue];
			system("cls");
			chosen_class(q2, count_queue);
			delete[] q2;
			break;
		case 3:
			q3 = new Queue_public[count_queue];
			system("cls");
			chosen_class(q3, count_queue);
			delete[] q3;
			break;
		case 0:
			flag = 0;
			break;
		default:
			system("cls");
			cout << "Uncorrect!" << endl;
			break;
		}
	}
	return 0;
}