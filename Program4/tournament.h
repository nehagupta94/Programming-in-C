#ifndef TOUR_H_FILE
#define TOUR_H_FILE

//Definition of struct Player
typedef struct Player{
	int offensive;
	int defensive;
	int number;
	int team;
	char * first;
	char * last;
}Player;

//Definition of struct Team
typedef struct Team{
	char * name;
	Player * players;
	void (*delete)(struct Team *);
}Team;

//Function Declaration
Player * draftPlayers(char * filename, int team, int noPlayers);
Team * initializeTeam(char * name, Player * players);
Team * game(Team *, Team *);
Team * tournament(Team **, int);
void deleteTeam(Team *);

#endif
