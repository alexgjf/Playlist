#include "Playlist.h"
#include <iostream>
using namespace std;

class menu {
	public: 
		string name;
		void PrintMenu(string name);
};
int main()
{
	menu menu1;
	string title;
	cout << "Enter playlist's title:" << endl;
	getline(cin, title);
	cout << endl;
	menu1.PrintMenu(title);
	
}

void menu::PrintMenu(string title) {
	string id;
	string sname;
	string aname;
	char option;
	int slength;
	PlaylistNode *List;
	List = new PlaylistNode;
	while (true){
		cout << title << " PLAYLIST MENU\na - Add song\nd - Remove song\nc - Change position of song\n";
		cout << "s - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n\nChoose an option:\n";
		cin >> option;
		if(option == 'a'){
			cout << "ADD SONG\nEnter song's unique ID:";
			cin.ignore();
			getline(cin, id);
			cout << "\nEnter song's name:";
			getline(cin, sname);
			cout << "\nEnter artist's name:";
			getline(cin, aname);
			cout << "\nEnter song's length (in seconds):";
			cin >> slength;
			cout << endl;
			List->InsertAfter(new PlaylistNode(id,sname,aname,slength));
			cout << endl;
		}
		
		if(option == 'd'){
			List->RemoveSong();		
		}
		if(option == 'c'){
			List->ChangePosition();
		}
		if(option == 's'){
			List->OutputSongsByArtist();
		}
		if(option == 't'){
			List->OutputTotalTime();
		}
		if(option == 'o'){
			cout << title;
			List->PrintPlaylistNode();
		}
		if(option == 'q'){
			break;
		}
	} 
}
