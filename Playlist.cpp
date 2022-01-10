using namespace std;
#include <iostream>
#include "Playlist.h"

PlaylistNode::PlaylistNode(){
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = 0;
}
PlaylistNode::PlaylistNode(string id, string sname, string aname, int slegnth){
	uniqueID = id;
	songName = sname;
	artistName = aname;
	songLength = slegnth;
	nextNodePtr = NULL;
}

void PlaylistNode::InsertAfter(PlaylistNode* nextNode){
	PlaylistNode *temp;
	if(nextNodePtr==NULL) {
		nextNodePtr=nextNode;
	} else {
		temp=nextNodePtr;
		while (temp->nextNodePtr!=NULL) {
			temp=temp->GetNext();
		}
		temp->nextNodePtr=nextNode;
		SetNext(nextNode);
	}
}
	
void PlaylistNode::SetNext(PlaylistNode* nextNode) {
	nextNode->nextNodePtr=nextNode->GetNext();
}
	
string PlaylistNode::GetID(){
	return uniqueID;
}
	
string PlaylistNode::GetSongName() {
	return songName;
}
	
string PlaylistNode::GetArtistName() {
	return artistName;
}
	
int PlaylistNode::GetSongLength() {
	return songLength;
}
	
PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{
	int i=0;
	PlaylistNode *temp;
	cout << " - OUTPUT FULL PLAYLIST\n";
	if(nextNodePtr==NULL) {
		cout << "Playlist is empty\n\n";
	} else {
		temp=nextNodePtr;
		while (temp!=NULL) {
			i++;
			cout << i << ".\n";
			cout << "Unique ID: " << temp->GetID() << endl;
			cout << "Song Name: " << temp->GetSongName() << endl;
			cout << "Artist Name: " << temp->GetArtistName() << endl;
			cout << "Song Length (in seconds): " << temp->GetSongLength() << endl << endl;
			temp=temp->GetNext();
		}
	}
}

void PlaylistNode::RemoveSong()
{
	string id;
	PlaylistNode *temp, *prev;
	cout << "REMOVE SONG\nEnter song's unique ID:\n";
	cin >> id;
	temp=nextNodePtr;
	if (temp!=NULL && temp->GetID()==id){
		nextNodePtr=temp->GetNext();
	} else {
		while (temp!=NULL && temp->GetID()!=id) {
			prev=temp;
			temp=temp->GetNext();
		}	
		if(temp==NULL) {
			return;
		}
		prev->nextNodePtr=prev->GetNext()->GetNext();
		
	}
	cout << "\"" << temp->GetSongName() << "\"" <<" removed.\n\n";
}

void PlaylistNode::ChangePosition()
{
	int cp, np;
	PlaylistNode *temp, *prev, *cur;
	temp=nextNodePtr;
	cout << "CHANGE POSITION OF SONG\nEnter song's current position:\n";
	cin >> cp;
	cout << "Enter new position for song:\n";
	cin >> np;
	if (cp==1){
		nextNodePtr=temp->GetNext();
	} else {
		for (int i =0; i<cp-1 ; i++) {
			prev=temp;
			temp=temp->GetNext();
		}	
		prev->nextNodePtr=prev->GetNext()->GetNext();		
	}
	cur=nextNodePtr;
	if (np==1){
		temp->nextNodePtr=nextNodePtr;
		nextNodePtr=temp;
	} else {
		for (int i =0; i<np-1 ; i++) {
			prev=cur;
			cur=cur->GetNext();
		}	
		prev->nextNodePtr=temp;
		temp->nextNodePtr=cur;	
	}	
	cout << "\"" << temp->GetSongName() << "\"" << " moved to position "<< np << endl << endl;
}

void PlaylistNode::OutputSongsByArtist()
{
	PlaylistNode *temp;
	temp=nextNodePtr;
	string artist;
	cout << "OUTPUT SONGS BY SPECIFIC ARTIST\nEnter artist's name:\n";
	cin.ignore();
	getline(cin,artist);
	cout << endl;
	for(int i = 0; temp != NULL; i++) {
		if(temp->GetArtistName()==artist) {
			cout <<i+1 << ".\nUnique ID: " << temp->GetID() << "\nSong Name: " << temp->GetSongName() << "\nArtist Name: " << temp->GetArtistName() << "\nSong Length (in seconds): " << temp->GetSongLength() <<endl<<endl;
		} 
		temp=temp->GetNext();
	}
}

void PlaylistNode::OutputTotalTime()
{
	PlaylistNode *temp;
	temp=nextNodePtr;
	int total=0;
	for(int i = 0; temp != NULL; i++) {
		total+=temp->GetSongLength();
		temp=temp->GetNext();
	}
	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: " << total << " seconds\n\n";
}
