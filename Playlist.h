
#include <string>
using namespace std;

class PlaylistNode {
	private:
		string uniqueID;
		string songName;
		string artistName;
		int songLength;
		PlaylistNode* nextNodePtr;
	
	public: 
		PlaylistNode();
		PlaylistNode(string id, string sname, string aname, int slegnth);
		void InsertAfter(PlaylistNode*);
		void SetNext(PlaylistNode*);
		string GetID();
		string GetSongName();
		string GetArtistName();
		int GetSongLength();
		PlaylistNode* GetNext();
		void PrintPlaylistNode();
		void RemoveSong();	
		void ChangePosition();
		void OutputSongsByArtist();
		void OutputTotalTime();
};


