#include <stdio.h>

struct Player {
	char name[50];
	int matches;
	int runs;
	int not_out;
	float average; 
};

int main() {
	int n, top_idx = 0; 
	printf("Enter the number of players: "); 
	scanf("%d",&n);
	struct Player players[n];

	for(int i=0; i<n; i++) {
		printf("Enter details of player %d\n", i+1);
		printf("Enter player name: "); scanf(" %[^\n]s", players[i].name);
		printf("Enter matches played: "); scanf("%d", &players[i].matches);
		printf("Enter total runs/goals scored: "); scanf("%d", &players[i].runs);
		printf("Enter the number of times not out: "); scanf("%d", &players[i].not_out);

		int denominator = players[i].matches - players[i].not_out;
		if (denominator == 0) players[i].average = 0;
		else players[i].average = (float)players[i].runs / denominator; 

		if (players[i].average > players[top_idx].average) top_idx = i; 
	}

	printf("\n--- Player with highest betting average ---\n"); 
	printf("Player name: %s\n", players[top_idx].name);
	printf("Matches played: %d\n", players[top_idx].matches);
	printf("Total runs: %d\n", players[top_idx].runs);
	printf("Not out: %d\n", players[top_idx].not_out);
	printf("Betting average: %.2f\n", players[top_idx].average);

	return 0;
} 
