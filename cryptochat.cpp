#include <string>
#include <iostream>

#include "mine.cc"

using namespace std;

int main()
{
	ios::sync_with_stdio(false); //speedhack
	string input, output, key, raw_input;
	
	cout << "Enter Key : "; getline(cin, key);
	key.resize(32, '0');	//32 character key is needed for AES-128
	
	mine::AES aesManager;	//initialize AES manager
	
	while (true)
	{
		cout << "\n>>> "; getline(cin, raw_input);
		
		if (raw_input == "enc")
		{
			while (true)
			{
				cout << "... ";
				getline(cin, raw_input);
				
				if (raw_input.empty())
				{
					break;
				}
				else
				{
					input.append(raw_input+'\n');
				}
			}
			
			try
			{
				output = aesManager.encrypt(input, key, mine::MineCommon::Encoding::Raw, mine::MineCommon::Encoding::Base64, true);
				input.clear();
				cout << "\nOutput :-\n\n" << output << endl;
			}
			catch (exception &e)
			{
				cout << "Error, " << e.what() << endl;
				continue;
			}
		}
		
		else if (raw_input == "dec")
		{
			try
			{
				cout << "<paste> "; getline(cin, input);
				output = aesManager.decrypt(input, key, mine::MineCommon::Encoding::Base64, mine::MineCommon::Encoding::Raw);
				input.clear();
				cout << "\nOutput :-\n\n" << output << endl;
			}
			catch (exception &e)
			{
				cout << "Error, " << e.what() << endl;
				continue;
			}
		}
		
		else if (raw_input == "setkey")
		{
			cout << "Enter Key : "; getline(cin, key);
		}
		
		else if (raw_input == "clear")
		{
			cout.flush();
			cout << "\033c";
		}
		
		else if (raw_input == "exit")
		{
			break;
		}
		
		else
		{
			cout << "Unrecognised Option !" << endl;
			continue;
		}
	}
	
	return 0;
}