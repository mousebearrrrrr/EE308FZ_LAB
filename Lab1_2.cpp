#include<bits/stdc++.h>
using namespace std;

string keyword[32] = {
	"auto","break","case","char","const","continue","default","double",
	"do","else","enum","extern","while","float","for","goto","if","int","long",
	"register","return","switch","short","signed","sizeof","static","struct",
	"typedef","union","unsigned","void","volatile"
};

int keyword_num = 0;
int switch_num = 0;
int case_num[100] = {0};
int ifelse_num = 0;
int if_elseif_else_num = 0;

int Verify(string str, string keyword1);			
void Lv1(string searchword);		
void Lv2(string searchword);		
void Lv3and4(string searchword);	 

int Verify(string str, string keyword1)	
{
	int text(char str);
	int exist = str.find(keyword1, 0);
	int len = keyword1.length();	
	if(exist != string::npos)
		return 1;
	else
		return 0;
}

void Lv1(string searchword)		
{
	for(int j = 0; j < 32; j++)			
	{
		if(Verify(searchword, keyword[j])==1){
			keyword_num++;
			break;
		}
	}
}

void Lv2(string searchword)		
{
	if(Verify(searchword, "switch") == 1)	{
		switch_num++;
	}
	
	if(Verify(searchword, "case") == 1){
		case_num[switch_num]++;
	}
	
}

int a=0;
void Lv3and4(string searchword)		
{
	
	if(Verify(searchword, "else if")==1){
		a = 2;
	}
	else
	{
		if(Verify(searchword, "if")==1){
			a = 1;
		}
        if(Verify(searchword, "else")==1)
		{
			if(a == 1){
				ifelse_num++;
			}
			else	
			{
				if(a == 2){
					if_elseif_else_num++;
				}
			}
		}
	}
}

int main ()
{
	string file_name;
	int lv;
	string temp;
	cout << "Please enter the address of the file: ";				
	cin >> file_name;						
	cout << "Please enter the level: ";
	cin >> lv;
	ifstream file(file_name.c_str(), ios::in);		
	
	
	while(getline(file, temp))
	{
		istringstream is(temp);	
		string s;
		
		
		while(is >> s){
			if(lv >= 1)
				Lv1(s);
			if(lv >= 2)
				Lv2(s);
			if(lv >= 3)                    
				Lv3and4(s);
		}
	}
	
	if(lv >= 1)
		cout << endl << "total num = " << keyword_num << endl;
	
	if(lv >= 2){
		cout << "switch num = " << switch_num << endl;
		for(int j = 1; j <= switch_num; j++)
			cout << "case num of switch " << j << " = " << case_num[j] << endl;
	}
	
	if(lv >= 3){
		cout << "if-else num = " << ifelse_num << endl;
	}
	
	if(lv >= 4){
		cout << "if-elseif-else num = " << if_elseif_else_num;
	}
	
}

