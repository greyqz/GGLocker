/**************************
 * GG Folder Unlock
 * Au: GG
 **************************/

#include <algorithm>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <direct.h>
#include <fstream>
#include <io.h>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

string DATA_NAME = "password";
string LOCK_STRING = ".{645FF040-5081-101B-9F08-00AA002F954E}"; // Trashbin
// Control Panel: .{21EC2020-3AEA-1069-A2DD-08002B30309D}
string FOLDER_PATH;
string FOLDER_NAME;
int ques;

bool dirExists(const string& dirName_in) {
    int result = _access(dirName_in.c_str(), 0);
    if (result == 0) return true;   // this is a directory!
    else return false;    // this is not a directory!
}

void vMain() {
	system("cls");
	cout << "+-----------------------------------+\n";
	cout << "| GG Folder Locker                  |\n";
	cout << "+-----------------------------------+\n";
	cout << "| Author: GG                        |\n";
	cout << "| (for private use only)            |\n";
	cout << "+-----------------------------------+\n";
}

void vNotLockedMenu() {
	cout << "+-----------------------------------+\n";
	cout << "| MENU                              |\n";
	cout << "|    1. Set password & LOCK         |\n";
	cout << "|    0. Exit                        |\n";
	cout << "+-----------------------------------+\n";
}

void vLockedMenu() {
	cout << "+-----------------------------------+\n";
	cout << "| MENU                              |\n";
	cout << "|    1. Unlock once                 |\n";
	cout << "|    2. Rename                      |\n";
	cout << "|    3. Unlock forever              |\n";
	cout << "|    4. ! Delete                    |\n";
	cout << "|    5. ! Delete & Renew            |\n";
	cout << "|    0. Exit                        |\n";
	cout << "+-----------------------------------+\n";
}

void addex() {
	string command_line = "rename \"";
	command_line += FOLDER_PATH;
	command_line += "\" \"";
	command_line += FOLDER_NAME + LOCK_STRING;
	command_line += "\"";
	system(command_line.c_str());
}

void delex() {
	string command_line = "rename \"";
	command_line += FOLDER_PATH + LOCK_STRING;
	command_line += "\" \"";
	command_line += FOLDER_NAME;
	command_line += "\"";
    system(command_line.c_str());
}

void dirRename(string newname) {
	string command_line = "rename \"";
	command_line += FOLDER_PATH + LOCK_STRING;
	command_line += "\" \"";
	command_line += newname + LOCK_STRING;
	command_line += "\"";
    system(command_line.c_str());
}

void dirDelete() {
	string command_line = "del \"";
	command_line += FOLDER_PATH + LOCK_STRING;
	command_line += "\"";
    system(command_line.c_str());
}

void dirMake() {
	string command_line = "mkdir \"";
	command_line += FOLDER_PATH;
	command_line += "\"";
    system(command_line.c_str());
}

int main() {
	vMain();

	char buf[1000003];
	getcwd(buf, 1000000);
	FOLDER_PATH.assign(buf);

	cout << "Type folder name: ";
	getline(cin, FOLDER_NAME); if (FOLDER_NAME.empty()) cout << "[WARNING] You are trying to lock the parent folder. Don't try to continue!!! CLOSE THE WINDOW!!!\n";
	FOLDER_PATH += "\\" + FOLDER_NAME;
	if (!dirExists(FOLDER_PATH) && !dirExists(FOLDER_PATH + LOCK_STRING)) {
		cout << "(doesn't exist)\n\nPress any key to continue...\n";
		getch(); return 0;
	}
	cout << "Current working folder:\n    " << FOLDER_PATH;

	ifstream in(FOLDER_NAME + LOCK_STRING + "\\" + DATA_NAME);
	string line; bool FirstTime = true;
	if (in) { // file exist
		cout << " (locked)\n";
		vLockedMenu();
		int ope; cin >> ope;
		if (ope == 0) return 0; // 0. Exit
		else if (ope == 1) { // 1. Unlock once
			string password_line; int line_number = 0;
			cout << "Type password (the password may be more than one line):\n";
			while (getline(in, line)) {
				line_number++;
				cout << "Line " << line_number << "> ";
				getline(cin, password_line);
				if (FirstTime && password_line.empty()) getline(cin, password_line);
				FirstTime = false;
				if (password_line != line) {
					printf("Incorrect line!\n");
					line_number = -1; break;
				}
			}
			in.close();
			if (line_number != -1) {
				cout << "Password checked.";
				delex();
				cout << " Unlock succeed!\n";
				cout << "Press any key to lock again... ";
				getch();
				addex();
				cout << "Locked.\n";
			}
		} else if (ope == 2) { // 2. Rename
			in.close();
			cout << "Type new name: ";
			getline(cin, line);
			if (FirstTime && line.empty()) getline(cin, line); 
			FirstTime = false;
			if (!line.empty()) dirRename(line);
			else printf("Renaming cancelled.\n");
		} else if (ope == 3) { // 3. Unlock forever
			string password_line; int line_number = 0;
			cout << "Type password (the password may be more than one line):\n";
			while (getline(in, line)) {
				line_number++;
				cout << "Line " << line_number << "> ";
				getline(cin, password_line);
				if (FirstTime && password_line.empty()) getline(cin, password_line);
				FirstTime = false;
				if (password_line != line) {
					printf("Incorrect line!\n");
					line_number = -1; break;
				}
			}
			in.close();
			if (line_number != -1) {
				cout << "Password checked.";
				delex();
				cout << " Unlock succeed!\n";
			}
		} else if (ope == 4) { // 4. ! Delete
			in.close();
			bool SURE_DELETE = true;
			for (int i = 0; i < 3; i++) {
				cout << "Do you ";
				for (int j = 0; j <= i; j++) cout << "really ";
				cout << "want to delete the folder? Type \"yes\" to delete: ";
				cin >> line; 
				if (line != "yes") {SURE_DELETE = false; break;}
			}
			if (SURE_DELETE) {
				dirDelete(); cout << "Deleted. (In some cases, the folder still exists, but is totally empty. You can believe files are deleted because you can never unlock it again. Delete this folder manually.)\n";
			}
		} else if (ope == 5) { // 5. ! Delete & Renew
			in.close();
			bool SURE_DELETE = true;
			for (int i = 0; i < 3; i++) {
				cout << "Do you ";
				for (int j = 0; j <= i; j++) cout << "really ";
				cout << "want to delete the folder? Type \"yes\" to delete: ";
				cin >> line; 
				if (line != "yes") {SURE_DELETE = false; break;}
			}
			if (SURE_DELETE) {
				dirDelete(); cout << "Deleted. (In some cases, the old locked folder still exists, but is totally empty. You can believe files are deleted because you can never unlock it again. Delete this folder manually.)\n";
				dirMake(); cout << "New empty folder created.\n";
			}
		} else cout << "The command is invalid.\n";
	} else { // file not exist
		cout << " (didn't lock)\n";
		vNotLockedMenu();
		int ope; cin >> ope;
		if (ope == 0) return 0; // 0. Exit
		else if (ope == 1) { // 1. Set password & LOCK
			int line_number = 0;
			cout << "Type password (the password may be more than one line. Password ends with a line \"!!!\"):\n";
			ofstream out(FOLDER_NAME + "\\" + DATA_NAME);
			while (true) {
				line_number++;
				cout << "Line " << line_number << "> ";
				getline(cin, line);
				if (FirstTime && line.empty()) getline(cin, line);
				FirstTime = false;
				if (line == "!!!") break;
				out << line << endl;
			}
			out.close();
			cout << "Password saved.";
			addex();
			cout << " Lock succeed!\n";
		} else cout << "The command is invalid.\n";
	}

	cout << "\nPress any key to continue...\n";
	getch();
	return 0;
}
