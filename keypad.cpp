//mobile keypad program
#include <iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;

void displaykeypad(){
	cout<<"1 \t\t";
	cout<<"2 abc\t\t";
	cout<<"3 def"<<endl;
	cout<<"4 ghi\t\t";
	cout<<"5 jkl\t\t";
	cout<<"6 mno"<<endl;
	cout<<"7 pqrs\t\t";
	cout<<"8 tuv\t\t";
	cout<<"9 wxyz"<<endl;
	cout<<"* \t\t";
	cout<<"0 \t\t";
	cout<<"# #"<<endl;
}
void printSentence(string str)
{
	// Store the mobile keypad mappings
	char nums[][10]
		= { "", "", "ABC2", "DEF3", "GHI4","JKL5", "MNO6", "PQRS7", "TUV8","WXYZ9" };
	int i = 0;
	while (str[i] != '\0') {//loop until end of string

		// If the current character is '.', then continue to the next iteration
		if (str[i] == ' ') {
			i++;
			continue;
		}

		// Stores the number of continuous clicks
		int count = 0;

		//loop to find the count of same characters
		while (str[i + 1] && str[i] == str[i + 1]) {

			// 2, 3, 4, 5, 6 and 8 keys will have maximum of 4 letters
			if (count == 3 && ((str[i] >= '2'&& str[i] <= '6') || (str[i] == '8')))
				break;

			// 7 and 9 keys will have maximum of 5 keys
			else if (count == 4 && (str[i] == '7'|| str[i] == '9'))
				break;
			count++;
			i++;

			// Handle the end condition
			if (str[i] == '\0')
				break;
		}

		// Check if the current pressed key is 7 or 9
		if (str[i] == '7' || str[i] == '9') {
			cout << nums[str[i]-48][count % 5];
		}

		// Else, the key pressed is either 2, 3, 4, 5, 6 or 8
		else {
			cout << nums[str[i]-48][count % 4];
		}
		i++;
	}
}

int main()
{
	displaykeypad();
	string str;
	cout<<"enter your number sequence: ";
	getline(cin,str);
	cout<<"Your corresponding sentence for number sequence is: ";
	printSentence(str);
	return 0;
}

