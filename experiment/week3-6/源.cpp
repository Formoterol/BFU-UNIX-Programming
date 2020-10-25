#include<iostream>
#include<fstream>

using namespace std;

//有穷状态集：
string STATUS[100];
/*
void StatusInit()
{
	for (int i = 0; i < 100; i++)
	{
		STATUS[i] = 'p';
	}
}
*/
int StatusCounter=0;

//输入字母表:
string inputAlphbet[50];
/*
void inputAlphabetInit()
{
	for (int i = 0; i < 50; i++)
	{
		inputAlphbet[i] = '?';
	}
}
*/
int inputAlphbetSum=0;

//读写头可操作字母表:
string operableAlphabet[51];
/*
void operableAlphabetInit()
{
	for (int i = 0; i < 51; i++)
	{
		operableAlphabet[i] = '?';
	}
}
*/
int operableAlphabetSum=0;

//函数:(程序
struct  program
{
	string currentStatus;
	string instringcter;
	string outstringacter;
	string headMove;
	string nextStatus;
}programList[100];
int programCounter=-1;

//初始状态:
//计算成功状态 :
//计算失败状态 :
string initialStatus;
string computeSuccessStatus;
string computeFailedStatus;


//定义读七元组的文件
void sevenTupleRead()
{
	fstream tupleInfo;
	tupleInfo.open("7tuple_minus.txt", ios::in);
	if (!tupleInfo) {
		cout << "cannot open test.txt\n";
		exit(0);
	}
	int tupleOrder = 0;
	int tupleOrderRecoder = 0;
	int lineGuider = 0;
	while (!tupleInfo.eof())
	{
		//每次取一个字符
		char s;
		tupleInfo.get(s);
		string temp;
		temp.push_back(s);
		//cout << temp;
		//开始对数据结构操作,tupleOrder是标记七元组第几组的
		//tupleOrderRecoder是记录tupleOrder的

		//开始判断并且往数据结构输入
		//有穷状态集
		if (tupleOrder == 1)
		{
			if (temp == "\n")
			{
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				if (temp == ",")
				{
					StatusCounter++;
				}
				else
				{
					STATUS[StatusCounter] = STATUS[StatusCounter] + temp;
				}
			}
		}
		//输入字母表
		else if (tupleOrder == 2)
		{
			if (temp == "\n")
			{
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				if (temp == ",")
				{
					inputAlphbetSum++;
				}
				else
				{
					inputAlphbet[inputAlphbetSum] = inputAlphbet[inputAlphbetSum] + temp;
				}
			}
		}
		//读写头可操作字母表
		else if (tupleOrder == 3)
		{
			if (temp == "\n")
			{
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				if (temp == ",")
				{
					operableAlphabetSum++;
				}
				else
				{
					operableAlphabet[operableAlphabetSum] = operableAlphabet[operableAlphabetSum] + temp;
				}
			}
		}
		//函数
		else if (tupleOrder == 4)
		{
			if (temp == "\n")
			{
				programCounter++;
				lineGuider = 0;
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				if (temp == ",")
				{
					lineGuider++;
				}
				else
				{
					if (lineGuider == 0)
					{
						programList[programCounter].currentStatus = programList[programCounter].currentStatus + temp;
					}
					else if (lineGuider == 1)
					{
						programList[programCounter].instringcter = programList[programCounter].instringcter + temp;
					}
					else if (lineGuider == 2)
					{
						programList[programCounter].outstringacter = programList[programCounter].outstringacter + temp;
					}
					else if (lineGuider == 3)
					{
						programList[programCounter].headMove = programList[programCounter].headMove + temp;
					}
					else if (lineGuider == 4)
					{
						programList[programCounter].nextStatus = programList[programCounter].nextStatus + temp;
					}
				}
			}
		}
		//初始状态
		else if (tupleOrder == 5)
		{
			if (temp == "\n")
			{
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				initialStatus = initialStatus + temp;
			}
		}
		//计算成功状态
		else if (tupleOrder == 6)
		{
			if (temp == "\n")
			{
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				computeSuccessStatus = computeSuccessStatus + temp;
			}
		}
		//计算失败状态
		else if (tupleOrder == 7)
		{
			if (temp == "\n")
			{
				continue;
			}
			else if (temp == ";")
			{
				tupleOrder = 0;
				continue;
			}
			else
			{
				computeFailedStatus = computeFailedStatus + temp;
			}
		}
		if (temp == ":")
		{
			tupleOrderRecoder++;
			tupleOrder = tupleOrderRecoder;
			//cout << tupleOrder << endl;
		}
	}
	StatusCounter++;
	inputAlphbetSum++;
	operableAlphabetSum++;
	programCounter++;
}

//定义纸带内容
string TAPE[50];
int tapeCharterCounter = 0;
//定义读纸带文件
void typeRead()
{
	fstream tape;
	int i = 0;
	tape.open("tape1.txt", ios::in);
	if (!tape) {
		cout << "cannot open test.txt\n";
		exit(0);
	}
	while (!tape.eof())
	{
		TAPE[i] = tape.get();
		i++;
	}
	tapeCharterCounter = i-1;
	tape.close();
}

//定义写纸带文件
void typeWrite()
{
	fstream tape;
	tape.open("tape1.txt", ios::out);
	if (!tape) {
		cout << "cannot open test.txt\n";
		exit(0);
	}
	for (int i = 0; i < tapeCharterCounter; i++)
	{
		tape << TAPE[i];
	}
	tape.close();
}

//定义通用图灵机执行：
string presentStatus;
int headPosition = 0;
void turingMachine()
{
	presentStatus = initialStatus;
	int applyProgramPointer = 0;
	while (presentStatus != computeSuccessStatus && presentStatus != computeFailedStatus)
	{
		for (int i = 0; i < programCounter; i++)
		{
			if (presentStatus == programList[i].currentStatus && TAPE[headPosition] == programList[i].instringcter)
			{
				//cout << presentStatus << " " << TAPE[headPosition] << endl;
				//cout << programList[i].currentStatus << " " << programList[i].instringcter << endl;
				//cout << "----" << endl;
				applyProgramPointer = i;
			}
		}
		//cout << applyProgramPointer << endl;
		presentStatus = programList[applyProgramPointer].nextStatus;
		TAPE[headPosition] = programList[applyProgramPointer].outstringacter;
		if (programList[applyProgramPointer].headMove == "R")
		{
			headPosition++;
		}
		else if (programList[applyProgramPointer].headMove == "L")
		{
			headPosition--;
		}
		//applyProgramPointer = 0;
	}
}

//定义七元组展示函数
void show()
{
	for (int i = 0; i < tapeCharterCounter; i++)
	{
		cout << TAPE[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < StatusCounter; i++)
	{
		cout << STATUS[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < inputAlphbetSum; i++)
	{
		cout << inputAlphbet[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < operableAlphabetSum; i++)
	{
		cout << operableAlphabet[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < programCounter; i++)
	{
		cout << programList[i].currentStatus << "," << programList[i].instringcter << "," << programList[i].outstringacter << "," << programList[i].headMove << "," << programList[i].nextStatus << endl;
	}
	cout << initialStatus << endl;
	cout << computeSuccessStatus << endl;
	cout << computeFailedStatus << endl;
	cout << endl;
}

int main()
{
	typeRead();
	sevenTupleRead();
	turingMachine();
	typeWrite();
	show();
	return 0;
}