#ifndef TOUR_C_FILE
#define TOUR_C_FILE
#include "tournament.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define NUM_TEAMS 32
#define NUM_PLAYERS 10
#define ATTEMPTS 10

//Function to create a player
Player * draftPlayers(char * filename, int team, int noPlayers){
	int count=0;
	char line[50]; 
	Player *plyer = malloc(noPlayers * sizeof(Player));
	FILE *fp = fopen(filename,"r");
	//Read in player details from the data file and assign it to the struct elements
	while(fgets(line,sizeof(line),fp)!= NULL){
		char * team_num =strtok(line,",");
		if(team == atoi(team_num)){		
			plyer[count].team  = atoi(team_num);
			plyer[count].first = strdup(strtok(NULL,","));
			plyer[count].last = strdup(strtok(NULL,","));
			plyer[count].number = atoi(strtok(NULL,","));
			plyer[count].offensive = atoi(strtok(NULL,","));
			plyer[count].defensive = atoi(strtok(NULL,","));
			count++;
		}	
	}
	fclose(fp);
	return plyer;	
}

//free up memory
void deleteTeam(Team * ptr){
	int i = 0;
	do{
		free(ptr->players[i].first);
		free(ptr->players[i].last);
		i++;
	}while(i<NUM_PLAYERS);
	free(ptr->players);
	free(ptr->name);
	free(ptr);
}

//Create team
Team * initializeTeam(char * tname, Player * players){
	Team * team = malloc(sizeof(Team));
	team->players = players; //Player reference 
	team->name = malloc(strlen(tname) + 2); //Allocate space to team-> name
	strcpy(team->name,tname);
	team->delete = deleteTeam; //Free up the space allocated
	return team;
}

//Calculate Defensive score for team
int calculateDefensive(int cal, Team * t){
	for(int i = 0;i<NUM_PLAYERS;i++){
		cal = cal + t->players[i].defensive;
	}
	return cal;
}

//Calculate Offensive score for team
int calculateOffensive(int cal, Team * t){
	for(int i = 0;i<NUM_PLAYERS;i++){
		cal = cal + t->players[i].offensive;
	}
	return cal;
}

int checkNullValidity(Team *team1, Team *team2){
	//Check if both the teams are null
	if(team1 == NULL && team2 == NULL){
		return 0;
	}
	//Check if either of the teams are null
	if(team1 == NULL || team2 == NULL){
		return 0;
	}
	return 1;
}

//Game function
Team * game(Team * team1, Team * team2){
	int check = 0;
	check = checkNullValidity(team1,team2);
	if(check==1){
		if(team1 == team2) {
        return team1;
    }
	int t1TotalDefensive = 0, t2TotalDefensive = 0, t1TotalOffensive = 0, t2TotalOffensive = 0;
	
	t2TotalDefensive = calculateDefensive(t2TotalDefensive,team2);
	t1TotalDefensive = calculateDefensive(t1TotalDefensive,team1);
	t2TotalOffensive = calculateOffensive(t2TotalOffensive,team2);
	t1TotalOffensive = calculateOffensive(t1TotalOffensive,team1);
	
	int team1Score = 0, team2Score = 0;
	int random1, random2;
	for(int i = 0;i < ATTEMPTS; i++){
		random1 = rand() % t1TotalOffensive;
		if(random1 > t2TotalDefensive)
			team1Score++; 
		else
			team2Score++; 
	}
	
	for(int i = 0;i < ATTEMPTS; i++){
		random2 = rand() % t2TotalOffensive;
		if(random2 > t1TotalDefensive)
			team2Score++;
		else
			team1Score++;
	}

	if(team1Score >= team2Score)
		return team1;
	else 
		return team2;
	}else{
		return NULL;
	}
}

//Check if team is power of 2
int isTeamValid(int i) {
  if(i == 0 || i == 1){
		return 0;
	}
  while(i != 1){
		if(i % 2 != 0){
			return 0;
		}
		i = i/2;
	}
  return 1;
}

//Function implementing the entire tournament
Team * tournament(Team ** team, int numTeams){
	//This condition checks to see if the number of teams is  a  power of two or not. If it is not a power of 2, it displays a message and returns null.
	int check = 0;
	check = isTeamValid(numTeams);
	if(check != 0){
        Team * finalWinner[numTeams];
        int i = 0;
    	while(i < numTeams){
        	finalWinner[i] = team[i];
        	i++;
    	}
    	while(numTeams > 1){
        	for(i = 0; i < (numTeams / 2); i++) {
        		finalWinner[i] = game(finalWinner[i], finalWinner[(numTeams / 2) + i]);
        	}
        	if(numTeams > 2) {
                numTeams = numTeams / 2;
            } else {
                break;
            }
        }
        Team *winner = finalWinner[0];
        return winner;
	}
	else{
		printf("The number of teams is INVALID!!!!!!\n");
        return NULL;
	}
}
#endif
