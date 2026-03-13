#include <iostream>

using namespace std;

// Ivanova-Nekrasova Kateryna, 26637

void AufgabeP2A();
void printBinDivide(char word);
void printBinShift(char word);

void AufgabeP2B();
void enterInfo(char* word, char* index);
void clearBit(char* word, char index);
void setBit(char* word, char index);

void AufgabeP2C();
char control(char ctrl);

void aufgabeP1();


int main()
{
	int key;

	while (1)
	{
		system("cls");
		cout << "\t\t======MENU======\n\n1.Char to bit string\n2.Setting or clear bit in char\n3.Ventil\n4.Two’s complement\n5.Exit\n\nKey:";
		cin >> key;
		switch (key)
		{
		case 1: {AufgabeP2A(); break; }
		case 2: {AufgabeP2B(); break; }
		case 3: {AufgabeP2C(); system("pause"); break; }
		case 4: {aufgabeP1(); break; }
		case 5: {exit(0); break; }
		}
	}

	return 0;
	
}




void aufgabeP1() 
{
	char a, b, res;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	if (b > a)
	{
		res = b - a;
		res = ~res;
		res++;

		cout << "\nResult: " << res << "\nBit string: ";
		printBinShift(res);
	}
	else
	{
		res = a - b;
		cout << "\nResult (a>b => the result is not in two’s complement form): " << res << "\nBit string: ";
		printBinShift(res);
	}
}
void AufgabeP2C() 
{
	system("cls");
	char finalWord = 0, ctrl;
	char dev[8];
	memset(dev, 0, 8);

	string temp[5] = { "M1", "M2", "V1", "V2", "V3" };
	cout << "M stands for motor, V stands for ventil;\nnone==0\n\nBits\t||\tDevice"
		<< "\n==================== \n0 -------------- M1\n1 -------------- none\n2 -------------- M2\n3 -------------- V1\n4 -------------- none\n5 -------------- V2\n6 -------------- none\n7 -------------- V3\n8 -------------- none"
		<< "\n\nEnter value of devices:\n";
		for (int i = 0, j=0; i < 5; i++) 
		{
			if (i == 3) j = i;
			cout << temp[i] << " = ";
			cin >> ctrl;
			dev[j] = control(ctrl);
			j += 2;
		}

		cout << "\n\nBit string: ";
		for (int i = 0; i < 8; i++) 
		{
			if (dev[i] == (char)1) setBit(&finalWord, i);
		}
		printBinShift(finalWord);
		cout << "\n\nCharacter: " << finalWord;
		
}

char control(char ctrl) {
	if (ctrl == 48)  return 0;
	else if (ctrl == 49) return 1;
	else
	{
		cout << "Invalid enter. The value will be set to 1\n";
		return 1;
	}
}

void AufgabeP2B()
{
	char word, index;
	int key;

	while (1)
	{
		system("cls");
		cout << "\t\t======MENU======\n\n1.Set bit\n2.Clear bit\n3.Exit\n\nKey: ";
		cin >> key;
		switch (key)
		{
		case 1: {enterInfo(&word, &index); setBit(&word, index); cout << "\n"; printBinShift(word); break; }
		case 2: {enterInfo(&word, &index); clearBit(&word, index); cout << "\n"; printBinShift(word);  break; }
		case 3: {return;  break; }
		}
	}
}

void enterInfo(char* word, char* index)
{
	cout << "Enter character: ";
	cin >> *word;
	cout << "\nEnter index of bit(1..): ";
	cin >> *index;
	*index -= 1;
}

void clearBit(char* word, char index) 
{
	 *word &= ~(1 << index);
}

void setBit(char* word, char index)
{
	*word |= 1 << index;
}

void AufgabeP2A() 
{
	char asd;
	cout << "Enter the character :";
	cin >> asd;
	cout << "\nCharacter in bits: ";

	printBinDivide(asd);
	//printBinShift(asd);
}

void printBinShift(char word)
{
	bool temp;
	char tempC;
	for(int i= 8; i>0; i--)
	{
		bool temp = (word>>7);    /*Mit dieser Operation können wir den Wert des
							       ersten Bits erhalten (wir verschieben das Wort um 7 Bits
							       nach rechts und als Ergebnis 0 oder 1 erhalten)*/
		if (temp == true) tempC = 1;
		else tempC = 0;

		printf("%d", tempC);
		cout << "";

		word <<= 1;

	}
	system("pause");
}

void printBinDivide(char word) 
{
	char tempArr[8];
	for (int i = 7; i >= 0; i--)
	{
		if (word % 2 == 0) tempArr[i] = 0;
		else tempArr[i] = 1;

		printf("%d", tempArr[i]);
		cout << "";

		word /= 2;
	}
	system("pause");
}


