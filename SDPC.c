// Names: Jack Reardon, Tanner Mulhern
// PokFEHmon
// Software Design Project


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Define a struct stats for the pokemon */

struct statistics
{
	float level; // Level of the "Pokemon"
	float attack; // attack stat for the pokemon
	float hp; // Amount of HP that the pokemon has
	float heal_value; // How much hp the pokemon's heal move gives
};

/* Create a second struct for the name that includes the first struct */
struct Pokemon
{
	char major[10]; // Name of the major
	struct statistics stats; // Includes the stats struct
};

/* Display Game Stats Function Prototype */
void display_game_stats(int, int, int);

/* Display Credits Function Prototype */
void display_credits();

/* Display Rules Function Prototype */
void display_rules();

/* Display stats Function Prototype */
void display_stats(char [], float, float, float, float);


/* Main Function */
int main() 

{

	/* Declare some variables */
	int wins = 0, losses = 0, championships = 0;

	/* Main Menu (do-while loop) */
	char menu_choice;
	do
	{
		/* Main Menu Choices */
		printf("WELCOME TO POKFEHMON\n\n\n");
		printf("What would you like to do?\n");
		printf("A: Play the game\n");
		printf("B: See the Rules\n");
		printf("C: Display Statistics\n");
		printf("D: See Credits\n");
		/* Get user input for the choice */
		printf("\nPlease Enter the letter of your choice: ");
		scanf(" %c", &menu_choice);

		/* Switch case to determine what to do */
		switch(menu_choice)
		{
			// A should do nothing
			case 'A':
				break;
			case 'B': // B should display the rules
				display_rules();
				break;
			case 'C': // C should display the game statistics
				display_game_stats(wins, losses, championships);
				break;
			case 'D': // D should display the credits
				display_credits();
				break;
			default:
				printf("Invalid Menu Selection\n");
		}
	} while(menu_choice != 'A');


	/* Main Game Inside While Loop */
	char decision = 'A';
	while(decision != 'E')
	{
		/* Instantiate Player Object as a data type of struct Pokemon */
		struct Pokemon Player;
		Player.stats.level = 1.0;

		/* Major Select */
		char major_choice; // Get a major choice variable
		// Ask for Major Choice Variable
		printf("Select your Major!!!\n");
		// Give Major Choices
		printf("A: Mechanical Engineering\n");
		printf("B: Chemical Engineering\n");
		printf("C: Biomedical Engineering\n");
		printf("D: Electrical and Computer Engineering\n");
		// If statements to simulate unlock
		if(championships > 0)
		{
			printf("E: Civil Engineering\n");
		}
		// Prompt for Input
		printf("Enter the letter of your selection :");
		scanf(" %c", &major_choice);

		// Switch case to set variables for each major
		switch(major_choice)
		{
			case 'A':
				printf("\n\nYou have selected MechE!!!\n");
				strcpy(Player.major, "MechE");
				Player.stats.hp = 100.0;
				Player.stats.attack = 25.0;
				Player.stats.heal_value = 8.0;
				break;
			case 'B': 
				printf("\n\nYou have selected ChemE!!!\n");
				strcpy(Player.major, "ChemE");
				Player.stats.hp = 90.0;
				Player.stats.attack = 33.0;
				Player.stats.heal_value = 7.5;
				break;
			case 'C':
				printf("\n\nYou have selected BME!!!\n");
				strcpy(Player.major, "BME");
				Player.stats.hp = 150.0;
				Player.stats.attack = 18.0;
				Player.stats.heal_value = 12.0;
				break;
			case 'D':
				printf("\n\nYou have selected ECE!!!\n");
				strcpy(Player.major, "ECE");
				Player.stats.hp = 70.0;
				Player.stats.attack = 38.0;
				Player.stats.heal_value = 4.0;
				break;
			case 'E':
				printf("\n\nYou have selected CivE!!!\n");
				strcpy(Player.major, "CivE");
				Player.stats.hp = 95.0;
				Player.stats.attack = 28.0;
				Player.stats.heal_value = 9.0;
				break;
			default:
				printf("\nInvalid Major Choice");
		}

		/* Display Pokemon Statistics */
		printf("Your stats are: \n");
		display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);

		/* Battle 1 */
		// Instantiate the enemy 1 object
		struct Pokemon enemy1;
		strcpy(enemy1.major, "MechE");
		enemy1.stats.hp = 40.0;
		enemy1.stats.level = 1.0;
		enemy1.stats.attack = 13.0;
		enemy1.stats.heal_value = 3.5;

		// Let the player know who they are facing
		printf("Round 1: Here's is what you are up against!!\n\n");
		display_stats(enemy1.major, enemy1.stats.level, enemy1.stats.attack, enemy1.stats.hp, enemy1.stats.heal_value);
		printf("Let the Battle Begin!!!\n");
		// While loop for the battle
		char move_select; // Declare Move Select Variable
		float turn = 0; // Declare and initialize turn variable for the purpose of exp and leveling.
		float rand_move; // Declare variable to store random values so that the enemy can select moves
		srand(time(0)); // Initialize time so random numbers can be generated
		while(Player.stats.hp > 0 && enemy1.stats.hp > 0)
		{
			printf("Select a move: \n");
			printf("A: Physical Attack\n");
			printf("B: Heal\n");
			printf("C: Special Attack\n");
			// prompt for user input
			printf("Enter Letter of desired move: ");
			scanf(" %c", &move_select);
			turn++; // Increment turn

			switch(move_select)
			{
				case 'A':
					printf("You used Physical Attack!!!\n");
					printf("You dealt %.2f damage\n", Player.stats.attack);
					enemy1.stats.hp -= Player.stats.attack;
					if(enemy1.stats.hp <= 0)
					{
						printf("The enemy has been defeated!!!\n");
					}
					break;
				case 'B':
					printf("You used Heal!!!\n");
					printf("You gained %.2f HP\n", Player.stats.heal_value);
					Player.stats.hp += Player.stats.heal_value;
					break;
				case 'C':
					printf("You used Special Attack!!!\n");

					// Super Effective
					if( major_choice == 'D')
					{
						printf("It was super effective!!!\n");
						printf("You dealt %.2f damage!!!\n", 1.5*Player.stats.attack);
						enemy1.stats.hp = enemy1.stats.hp - (1.5*Player.stats.attack);
					}

					else if(major_choice == 'B')
					{
						printf("It wasn't very effective\n");
						printf("You dealt %.2f damage!\n", 0.5*Player.stats.attack);
						enemy1.stats.hp = enemy1.stats.hp - (0.5*Player.stats.attack);
					}
					else
					{
						printf("You dealt %.2f damage!!!\n", Player.stats.attack);
						enemy1.stats.hp -= Player.stats.attack;
					}
					break;
				default:
					printf("Invalid Move Selection\n");
			}

			if(enemy1.stats.hp <= 0)
			{
				printf("Enemy has been defeated!!!\n");
				printf("Congratulations!!!\n\n");
			}

			if(enemy1.stats.hp > 0) // If statement to check if the enemy gets to move
			{
				rand_move = rand() % 1000 + 1;

				if(rand_move < 1000/3) // Physical Attack
				{
					printf("\nThe enemy used Physical Attack!!!\n");
					printf("You took %.2f damage.\n", enemy1.stats.attack);
					Player.stats.hp -= enemy1.stats.attack;
				}

				else if(rand_move > 2000/3) // Special Attack
				{
					printf("\nThe enemy used Special Attack!!!\n");

					if(major_choice == 'B') // Attack was super effective
					{
						printf("It was super effective!!!\n");
						printf("You took %.2f damage.\n", 1.5*enemy1.stats.attack);
						Player.stats.hp -= 1.5*enemy1.stats.attack;
					}

					else if(major_choice == 'D') // Not very effective
					{
						printf("It wasn't very effective\n");
						printf("You took %.2f damage.\n", 0.5*enemy1.stats.attack);
						Player.stats.hp -= 0.5*enemy1.stats.attack;
					}

					else // Some other major selection
					{
						printf("You took %.2f damage. \n", enemy1.stats.attack);
						Player.stats.hp -= enemy1.stats.attack;
					}
				}

				else // Enemy chooses the heal move
				{
					printf("\nThe enemy used Heal!!!\n");
					printf("%.2f HP was restored!\n", enemy1.stats.heal_value);
					enemy1.stats.hp += enemy1.stats.heal_value;
				}
			}

			if(Player.stats.hp <= 0.0) // Check if the player's hp is 0 or below 0
			{
				printf("\nYou have been defeated\n");
				losses++;
			}


		}

		/* Post Battle Adjustments */
		/* Adjustsments are based on how quickly the battle was won */
		if(Player.stats.hp > 0)
		{
			wins++; // Increment Wins
			Player.stats.level += 5/turn; // Increase level
			Player.stats.hp += 12/turn; // Increase HP
			Player.stats.attack += 8/turn; // Increase Attack
			Player.stats.heal_value += 8/turn; // Increase Heal Value

			printf("\nYour stats are now: \n");
			display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);
		}

		/* Upgrade 1 */
		
		char upgrade_choice;
		char minor_choice;
		int math_minor = 0, bus_minor = 0, bio_minor = 0, history_minor = 0; // Give the minor variables
		// false values so they can be later checked to see if they already have that minor
		if(Player.stats.hp > 0)
		{
		printf("\n\nYou can now improve your fighter!!\n");
		printf("Select one of the Following Options\n"); // Let the users know whats going on
		printf("A: Add a minor\n");
		printf("B: Take a nap and restore some HP\n");
		printf("C: Get an internship\n"); // Here are the options
		printf("D: Do Nothing\n");
		printf("Enter letter of choice: "); // Prompt for input
		scanf(" %c", &upgrade_choice); // Receive User Input

		// Switch Case to do something based on selection

		switch(upgrade_choice)
		{
			case 'A':
				printf("\n\nSelect a minor!\n"); // Tell them to select their minor
				printf("\nA: Math Minor\n");
				printf("B: Biology Minor\n");
				printf("C: Business Minor\n");
				printf("D: History Minor\n"); // Give them the options
				printf("Enter letter of choice: "); // Prompt for input
				scanf(" %c", &minor_choice); // Receive user input

				// Switch case to give effects based on minor choice

				switch(minor_choice)
				{
					case 'A':
						printf("\nYou have acquired a math minor!\n");
						printf("Your attack has been raised by 20!\n");
						Player.stats.attack += 20.0;
						math_minor = 1;
						break;
					case 'B':
						printf("\nYou have acquired a biology minor!\n");
						printf("Your heal value has been raised by 8!\n");
						Player.stats.heal_value += 8.0;
						Player.stats.hp += 30;
						bio_minor = 1;
						break;
					case 'C':
						printf("\nYou have acquired a business minor!\n");
						printf("Your level has been raised by 6!\n");
						Player.stats.level += 6.0;
						Player.stats.attack += 6.0;
						Player.stats.hp += 10.0;
						Player.stats.heal_value += 2.5;
						bus_minor = 1;
						break;
					case 'D':
						printf("\nYou have acquired a history minor!\n");
						printf("Nothing was increased because history minor are really just for fun\n");
						history_minor = 1;
						break;

				}
					break;
			case 'B':
				printf("\nYou took a much needed nap and gained some HP!\n");
				printf("Your HP has been raised by 60.0!\n");
				Player.stats.hp += 60.0;
				break;
			case 'C':
				printf("\nYou got an internship and gained some real world experience!!!\n");
				printf("Your level has been raised by 5!!!\n");
				Player.stats.level += 5.0;
				Player.stats.attack += 10.0;
				Player.stats.hp += 9.0;
				Player.stats.heal_value += 5.0;
				break;
			case 'D':
				printf("\nSometimes it's good to just do nothing!\n");
				break;
		}
		
		printf("\nYour stats are now: ");
		display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);

		}
		
		/* Battle 2 */
		if(Player.stats.hp > 0)
		{
			// Instantiate the Enemy Object
			struct Pokemon enemy2;
			strcpy(enemy2.major, "ChemE");
			enemy2.stats.hp = 70.0;
			enemy2.stats.level = 7.0;
			enemy2.stats.attack = 23.0;
			enemy2.stats.heal_value = 9.0; // Set the stats more difficult than the first battle

			turn = 0; // Reset the turn variable to 0

			printf("Round 2: Here's is what you are up against!!\n\n"); // Display Enemy stats
			display_stats(enemy2.major, enemy2.stats.level, enemy2.stats.attack, enemy2.stats.hp, enemy2.stats.heal_value);
			printf("Let the Battle Begin!!!\n");

			// While Loop for the battle
			while(Player.stats.hp > 0 && enemy2.stats.hp > 0)
			{
				printf("Select a move: \n");
				printf("A: Physical Attack\n");
				printf("B: Heal\n");
				printf("C: Special Attack\n");
				// prompt for user input
				printf("Enter Letter of desired move: ");
				scanf(" %c", &move_select);
				turn++; // Increment turn

				switch(move_select)
				{
					case 'A':
						printf("You used Physical Attack!!!\n");
						printf("You dealt %.2f damage\n", Player.stats.attack);
						enemy2.stats.hp -= Player.stats.attack;
						break;
					case 'B':
						printf("You used Heal!!!\n");
						printf("You gained %.2f HP\n", Player.stats.heal_value);
						Player.stats.hp += Player.stats.heal_value;
						break;
					case 'C':
						printf("You used Special Attack!!!\n");

						// Super Effective
						if( major_choice == 'A')
						{
							printf("It was super effective!!!\n");
							printf("You dealt %.2f damage!!!\n", 1.5*Player.stats.attack);
							enemy2.stats.hp = enemy2.stats.hp - (1.5*Player.stats.attack);
						}

						else if(major_choice == 'C')
						{
							printf("It wasn't very effective\n");
							printf("You dealt %.2f damage!\n", 0.5*Player.stats.attack);
							enemy2.stats.hp = enemy2.stats.hp - (0.5*Player.stats.attack);
						}
						else
						{
							printf("You dealt %.2f damage!!!\n", Player.stats.attack);
							enemy2.stats.hp -= Player.stats.attack;
						}
						break;
					default:
						printf("Invalid Move Selection\n");
				}

				if(enemy2.stats.hp <= 0)
				{
					printf("Enemy has been defeated!!!\n");
					printf("Congratulations!!!\n\n");
				}

				if(enemy2.stats.hp > 0) // If statement to check if the enemy gets to move
				{
					rand_move = rand() % 1000 + 1;

					if(rand_move < 1000/3) // Physical Attack
					{
						printf("\nThe enemy used Physical Attack!!!\n");
						printf("You took %.2f damage.\n", enemy2.stats.attack);
						Player.stats.hp -= enemy2.stats.attack;
					}

					else if(rand_move > 2000/3) // Special Attack
					{
						printf("\nThe enemy used Special Attack!!!\n");

						if(major_choice == 'C') // Attack was super effective
						{
							printf("It was super effective!!!\n");
							printf("You took %.2f damage.\n", 1.5*enemy2.stats.attack);
							Player.stats.hp -= 1.5*enemy2.stats.attack;
						}

						else if(major_choice == 'A') // Not very effective
						{
							printf("It wasn't very effective\n");
							printf("You took %.2f damage.\n", 0.5*enemy2.stats.attack);
							Player.stats.hp -= 0.5*enemy2.stats.attack;
						}

						else // Some other major selection
						{
							printf("You took %.2f damage. \n", enemy2.stats.attack);
							Player.stats.hp -= enemy2.stats.attack;
						}
					}

					else // Enemy chooses the heal move
					{
						printf("\nThe enemy used Heal!!!\n");
						printf("%.2f HP was restored!\n", enemy2.stats.heal_value);
						enemy2.stats.hp += enemy2.stats.heal_value;
					}
				}	

				if(Player.stats.hp <= 0.0) // Check if the player's hp is 0 or below 0
				{
					printf("\nYou have been defeated\n");
					losses++;
				}


			}


		}

		/* Post Battle Adjustments */
		if(Player.stats.hp > 0)
		{
			wins++; // Increment Wins
			Player.stats.level += 8/turn; // Increase level
			Player.stats.hp += 12/turn; // Increase HP
			Player.stats.attack += 10/turn; // Increase Attack
			Player.stats.heal_value += 8/turn; // Increase Heal Value

			printf("\nYour stats are now: \n");
			display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);
		}

		/* Upgrade 2 */

		if(Player.stats.hp > 0)
		{
		printf("\n\nYou can now improve your fighter!!\n");
		printf("Select one of the Following Options\n"); // Let the users know whats going on
		printf("A: Add a minor\n");
		printf("B: Take a nap and restore some HP\n");
		printf("C: Get an internship\n"); // Here are the options
		printf("D: Do Nothing\n");
		printf("Enter letter of choice: "); // Prompt for input
		scanf(" %c", &upgrade_choice); // Receive User Input

		// Switch Case to do something based on selection

		switch(upgrade_choice)
		{
			case 'A':
				printf("\n\nSelect a minor!\n"); // Tell them to select their minor
				printf("\nA: Math Minor\n");
				printf("B: Biology Minor\n");
				printf("C: Business Minor\n");
				printf("D: History Minor\n"); // Give them the options
				printf("Enter letter of choice: "); // Prompt for input
				scanf(" %c", &minor_choice); // Receive user input

				// Switch case to give effects based on minor choice

				switch(minor_choice)
				{
					case 'A':
						printf("\nYou have acquired a math minor!\n");
						printf("Your attack has been raised by 20!\n");
						Player.stats.attack += 20.0;
						math_minor = 1;
						break;
					case 'B':
						printf("\nYou have acquired a biology minor!\n");
						printf("Your heal value has been raised by 8!\n");
						Player.stats.heal_value += 8.0;
						Player.stats.hp += 30;
						bio_minor = 1;
						break;
					case 'C':
						printf("\nYou have acquired a business minor!\n");
						printf("Your level has been raised by 6!\n");
						Player.stats.level += 6.0;
						Player.stats.attack += 6.0;
						Player.stats.hp += 10.0;
						Player.stats.heal_value += 2.5;
						bus_minor = 1;
						break;
					case 'D':
						printf("\nYou have acquired a history minor!\n");
						printf("Nothing was increased because history minor are really just for fun\n");
						history_minor = 1;
						break;

				}
					break;
			case 'B':
				printf("\nYou took a much needed nap and gained some HP!\n");
				printf("Your HP has been raised by 60.0!\n");
				Player.stats.hp += 60.0;
				break;
			case 'C':
				printf("\nYou got an internship and gained some real world experience!!!\n");
				printf("Your level has been raised by 5!!!\n");
				Player.stats.level += 5.0;
				Player.stats.attack += 10.0;
				Player.stats.hp += 9.0;
				Player.stats.heal_value += 5.0;
				break;
			case 'D':
				printf("\nSometimes it's good to just do nothing!\n");
				break;
		}
		
		printf("\nYour stats are now: ");
		display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);

		}

		/* Battle 3 */

		if(Player.stats.hp > 0)
		{
			// Instantiate the Enemy Object
			struct Pokemon enemy3;
			strcpy(enemy3.major, "BME");
			enemy3.stats.hp = 130.0;
			enemy3.stats.level = 16.0;
			enemy3.stats.attack = 23.0;
			enemy3.stats.heal_value = 20.0; // Set the stats more difficult than the second battle

			turn = 0; // Reset the turn variable to 0

			printf("Round 3: Here's is what you are up against!!\n\n"); // Display Enemy stats
			display_stats(enemy3.major, enemy3.stats.level, enemy3.stats.attack, enemy3.stats.hp, enemy3.stats.heal_value);
			printf("Let the Battle Begin!!!\n");

			// While Loop for the battle
			while(Player.stats.hp > 0 && enemy3.stats.hp > 0)
			{
				printf("Select a move: \n");
				printf("A: Physical Attack\n");
				printf("B: Heal\n");
				printf("C: Special Attack\n");
				// prompt for user input
				printf("Enter Letter of desired move: ");
				scanf(" %c", &move_select);
				turn++; // Increment turn

				switch(move_select)
				{
					case 'A':
						printf("You used Physical Attack!!!\n");
						printf("You dealt %.2f damage\n", Player.stats.attack);
						enemy3.stats.hp -= Player.stats.attack;
						break;
					case 'B':
						printf("You used Heal!!!\n");
						printf("You gained %.2f HP\n", Player.stats.heal_value);
						Player.stats.hp += Player.stats.heal_value;
						break;
					case 'C':
						printf("You used Special Attack!!!\n");

						// Super Effective
						if( major_choice == 'B')
						{
							printf("It was super effective!!!\n");
							printf("You dealt %.2f damage!!!\n", 1.5*Player.stats.attack);
							enemy3.stats.hp = enemy3.stats.hp - (1.5*Player.stats.attack);
						}

						else if(major_choice == 'D')
						{
							printf("It wasn't very effective\n");
							printf("You dealt %.2f damage!\n", 0.5*Player.stats.attack);
							enemy3.stats.hp = enemy3.stats.hp - (0.5*Player.stats.attack);
						}
						else
						{
							printf("You dealt %.2f damage!!!\n", Player.stats.attack);
							enemy3.stats.hp -= Player.stats.attack;
						}
						break;
					default:
						printf("Invalid Move Selection\n");
				}

				if(enemy3.stats.hp <= 0)
				{
					printf("Enemy has been defeated!!!\n");
					printf("Congratulations!!!\n\n");
				}

				if(enemy3.stats.hp > 0) // If statement to check if the enemy gets to move
				{
					rand_move = rand() % 1000 + 1;

					if(rand_move < 1000/3) // Physical Attack
					{
						printf("\nThe enemy used Physical Attack!!!\n");
						printf("You took %.2f damage.\n", enemy3.stats.attack);
						Player.stats.hp -= enemy3.stats.attack;
					}

					else if(rand_move > 2000/3) // Special Attack
					{
						printf("\nThe enemy used Special Attack!!!\n");

						if(major_choice == 'D') // Attack was super effective
						{
							printf("It was super effective!!!\n");
							printf("You took %.2f damage.\n", 1.5*enemy3.stats.attack);
							Player.stats.hp -= 1.5*enemy3.stats.attack;
						}

						else if(major_choice == 'B') // Not very effective
						{
							printf("It wasn't very effective\n");
							printf("You took %.2f damage.\n", 0.5*enemy3.stats.attack);
							Player.stats.hp -= 0.5*enemy3.stats.attack;
						}

						else // Some other major selection
						{
							printf("You took %.2f damage. \n", enemy3.stats.attack);
							Player.stats.hp -= enemy3.stats.attack;
						}
					}

					else // Enemy chooses the heal move
					{
						printf("\nThe enemy used Heal!!!\n");
						printf("%.2f HP was restored!\n", enemy3.stats.heal_value);
						enemy3.stats.hp += enemy3.stats.heal_value;
					}
				}	

				if(Player.stats.hp <= 0.0) // Check if the player's hp is 0 or below 0
				{
					printf("\nYou have been defeated\n");
					losses++;
				}


			}


		}


		/* Post Battle Adjustments */

		if(Player.stats.hp > 0)
		{
			wins++; // Increment Wins
			Player.stats.level += 8/turn; // Increase level
			Player.stats.hp += 12/turn; // Increase HP
			Player.stats.attack += 10/turn; // Increase Attack
			Player.stats.heal_value += 8/turn; // Increase Heal Value

			printf("\nYour stats are now: \n");
			display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);
		}



		/* Upgrade 3 */


		if(Player.stats.hp > 0)
		{
		printf("\n\nYou can now improve your fighter!!\n");
		printf("Select one of the Following Options\n"); // Let the users know whats going on
		printf("A: Add a minor\n");
		printf("B: Take a nap and restore some HP\n");
		printf("C: Get an internship\n"); // Here are the options
		printf("D: Do Nothing\n");
		printf("Enter letter of choice: "); // Prompt for input
		scanf(" %c", &upgrade_choice); // Receive User Input

		// Switch Case to do something based on selection

		switch(upgrade_choice)
		{
			case 'A':
				printf("\n\nSelect a minor!\n"); // Tell them to select their minor
				printf("\nA: Math Minor\n");
				printf("B: Biology Minor\n");
				printf("C: Business Minor\n");
				printf("D: History Minor\n"); // Give them the options
				printf("Enter letter of choice: "); // Prompt for input
				scanf(" %c", &minor_choice); // Receive user input

				// Switch case to give effects based on minor choice

				switch(minor_choice)
				{
					case 'A':
						printf("\nYou have acquired a math minor!\n");
						printf("Your attack has been raised by 20!\n");
						Player.stats.attack += 20.0;
						math_minor = 1;
						break;
					case 'B':
						printf("\nYou have acquired a biology minor!\n");
						printf("Your heal value has been raised by 8!\n");
						Player.stats.heal_value += 8.0;
						Player.stats.hp += 30;
						bio_minor = 1;
						break;
					case 'C':
						printf("\nYou have acquired a business minor!\n");
						printf("Your level has been raised by 6!\n");
						Player.stats.level += 6.0;
						Player.stats.attack += 6.0;
						Player.stats.hp += 10.0;
						Player.stats.heal_value += 2.5;
						bus_minor = 1;
						break;
					case 'D':
						printf("\nYou have acquired a history minor!\n");
						printf("Nothing was increased because history minor are really just for fun\n");
						history_minor = 1;
						break;

				}
					break;
			case 'B':
				printf("\nYou took a much needed nap and gained some HP!\n");
				printf("Your HP has been raised by 60.0!\n");
				Player.stats.hp += 60.0;
				break;
			case 'C':
				printf("\nYou got an internship and gained some real world experience!!!\n");
				printf("Your level has been raised by 5!!!\n");
				Player.stats.level += 5.0;
				Player.stats.attack += 10.0;
				Player.stats.hp += 9.0;
				Player.stats.heal_value += 5.0;
				break;
			case 'D':
				printf("\nSometimes it's good to just do nothing!\n");
				break;
		}
		
		printf("\nYour stats are now: ");
		display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);

		}

		/* Battle 4 */

		if(Player.stats.hp > 0)
		{
			// Instantiate the Enemy Object
			struct Pokemon enemy4;
			strcpy(enemy4.major, "ECE");
			enemy4.stats.hp = 140.0;
			enemy4.stats.level = 22.0;
			enemy4.stats.attack = 51.0;
			enemy4.stats.heal_value = 13.0; // Set the stats more difficult than the second battle

			turn = 0; // Reset the turn variable to 0

			printf("Round 4: Here's is what you are up against!!\n\n"); // Display Enemy stats
			display_stats(enemy4.major, enemy4.stats.level, enemy4.stats.attack, enemy4.stats.hp, enemy4.stats.heal_value);
			printf("Let the Battle Begin!!!\n");

			// While Loop for the battle
			while(Player.stats.hp > 0 && enemy4.stats.hp > 0)
			{
				printf("Select a move: \n");
				printf("A: Physical Attack\n");
				printf("B: Heal\n");
				printf("C: Special Attack\n");
				// prompt for user input
				printf("Enter Letter of desired move: ");
				scanf(" %c", &move_select);
				turn++; // Increment turn

				switch(move_select)
				{
					case 'A':
						printf("You used Physical Attack!!!\n");
						printf("You dealt %.2f damage\n", Player.stats.attack);
						enemy4.stats.hp -= Player.stats.attack;
						break;
					case 'B':
						printf("You used Heal!!!\n");
						printf("You gained %.2f HP\n", Player.stats.heal_value);
						Player.stats.hp += Player.stats.heal_value;
						break;
					case 'C':
						printf("You used Special Attack!!!\n");

						// Super Effective
						if( major_choice == 'C')
						{
							printf("It was super effective!!!\n");
							printf("You dealt %.2f damage!!!\n", 1.5*Player.stats.attack);
							enemy4.stats.hp = enemy4.stats.hp - (1.5*Player.stats.attack);
						}

						else if(major_choice == 'A')
						{
							printf("It wasn't very effective\n");
							printf("You dealt %.2f damage!\n", 0.5*Player.stats.attack);
							enemy4.stats.hp = enemy4.stats.hp - (0.5*Player.stats.attack);
						}
						else
						{
							printf("You dealt %.2f damage!!!\n", Player.stats.attack);
							enemy4.stats.hp -= Player.stats.attack;
						}
						break;
					default:
						printf("Invalid Move Selection\n");
				}

				if(enemy4.stats.hp <= 0)
				{
					printf("Enemy has been defeated!!!\n");
					printf("Congratulations!!!\n\n");
				}

				if(enemy4.stats.hp > 0) // If statement to check if the enemy gets to move
				{
					rand_move = rand() % 1000 + 1;

					if(rand_move < 1000/3) // Physical Attack
					{
						printf("\nThe enemy used Physical Attack!!!\n");
						printf("You took %.2f damage.\n", enemy4.stats.attack);
						Player.stats.hp -= enemy4.stats.attack;
					}

					else if(rand_move > 2000/3) // Special Attack
					{
						printf("\nThe enemy used Special Attack!!!\n");

						if(major_choice == 'A') // Attack was super effective
						{
							printf("It was super effective!!!\n");
							printf("You took %.2f damage.\n", 1.5*enemy4.stats.attack);
							Player.stats.hp -= 1.5*enemy4.stats.attack;
						}

						else if(major_choice == 'C') // Not very effective
						{
							printf("It wasn't very effective\n");
							printf("You took %.2f damage.\n", 0.5*enemy4.stats.attack);
							Player.stats.hp -= 0.5*enemy4.stats.attack;
						}

						else // Some other major selection
						{
							printf("You took %.2f damage. \n", enemy4.stats.attack);
							Player.stats.hp -= enemy4.stats.attack;
						}
					}

					else // Enemy chooses the heal move
					{
						printf("\nThe enemy used Heal!!!\n");
						printf("%.2f HP was restored!\n", enemy4.stats.heal_value);
						enemy4.stats.hp += enemy4.stats.heal_value;
					}
				}	

				if(Player.stats.hp <= 0.0) // Check if the player's hp is 0 or below 0
				{
					printf("\nYou have been defeated\n");
					losses++;
				}


			}


		}

		/* Post Battle Adjustments */

		if(Player.stats.hp > 0)
		{
			wins++; // Increment Wins
			Player.stats.level += 8/turn; // Increase level
			Player.stats.hp += 12/turn; // Increase HP
			Player.stats.attack += 10/turn; // Increase Attack
			Player.stats.heal_value += 8/turn; // Increase Heal Value

			printf("\nYour stats are now: \n");
			display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);
		}

		/* Upgrade 4 */

		if(Player.stats.hp > 0)
		{
		printf("\n\nYou can now improve your fighter!!\n");
		printf("Select one of the Following Options\n"); // Let the users know whats going on
		printf("A: Add a minor\n");
		printf("B: Take a nap and restore some HP\n");
		printf("C: Get an internship\n"); // Here are the options
		printf("D: Do Nothing\n");
		printf("Enter letter of choice: "); // Prompt for input
		scanf(" %c", &upgrade_choice); // Receive User Input

		// Switch Case to do something based on selection

		switch(upgrade_choice)
		{
			case 'A':
				printf("\n\nSelect a minor!\n"); // Tell them to select their minor
				printf("\nA: Math Minor\n");
				printf("B: Biology Minor\n");
				printf("C: Business Minor\n");
				printf("D: History Minor\n"); // Give them the options
				printf("Enter letter of choice: "); // Prompt for input
				scanf(" %c", &minor_choice); // Receive user input

				// Switch case to give effects based on minor choice

				switch(minor_choice)
				{
					case 'A':
						printf("\nYou have acquired a math minor!\n");
						printf("Your attack has been raised by 20!\n");
						Player.stats.attack += 20.0;
						math_minor = 1;
						break;
					case 'B':
						printf("\nYou have acquired a biology minor!\n");
						printf("Your heal value has been raised by 8!\n");
						Player.stats.heal_value += 8.0;
						Player.stats.hp += 30;
						bio_minor = 1;
						break;
					case 'C':
						printf("\nYou have acquired a business minor!\n");
						printf("Your level has been raised by 6!\n");
						Player.stats.level += 6.0;
						Player.stats.attack += 6.0;
						Player.stats.hp += 10.0;
						Player.stats.heal_value += 2.5;
						bus_minor = 1;
						break;
					case 'D':
						printf("\nYou have acquired a history minor!\n");
						printf("Nothing was increased because history minor are really just for fun\n");
						history_minor = 1;
						break;

				}
					break;
			case 'B':
				printf("\nYou took a much needed nap and gained some HP!\n");
				printf("Your HP has been raised by 60.0!\n");
				Player.stats.hp += 60.0;
				break;
			case 'C':
				printf("\nYou got an internship and gained some real world experience!!!\n");
				printf("Your level has been raised by 5!!!\n");
				Player.stats.level += 5.0;
				Player.stats.attack += 10.0;
				Player.stats.hp += 9.0;
				Player.stats.heal_value += 5.0;
				break;
			case 'D':
				printf("\nSometimes it's good to just do nothing!\n");
				break;
		}
		
		printf("\nYour stats are now: ");
		display_stats(Player.major, Player.stats.level, Player.stats.attack, Player.stats.hp, Player.stats.heal_value);

		}

		/* Championship Battle */

		if(Player.stats.hp > 0)
		{
			// Instantiate the Enemy Object
			struct Pokemon enemy5;
			strcpy(enemy5.major, "GTA KELLY");
			enemy5.stats.hp = 200.0;
			enemy5.stats.level = 100.0;
			enemy5.stats.attack = 55.0;
			enemy5.stats.heal_value = 25.0; // Set the stats more difficult 

			turn = 0; // Reset the turn variable to 0

			printf("FINAL ROUND: Here's is what you are up against!!\n\n"); // Display Enemy stats
			display_stats(enemy5.major, enemy5.stats.level, enemy5.stats.attack, enemy5.stats.hp, enemy5.stats.heal_value);
			printf("Let the Battle Begin!!!\n");

			// While Loop for the battle
			while(Player.stats.hp > 0 && enemy5.stats.hp > 0)
			{
				printf("Select a move: \n");
				printf("A: Physical Attack\n");
				printf("B: Heal\n");
				printf("C: Special Attack\n");
				// prompt for user input
				printf("Enter Letter of desired move: ");
				scanf(" %c", &move_select);
				turn++; // Increment turn

				switch(move_select)
				{
					case 'A':
						printf("You used Physical Attack!!!\n");
						printf("You dealt %.2f damage\n", Player.stats.attack);
						enemy5.stats.hp -= Player.stats.attack;
						break;
					case 'B':
						printf("You used Heal!!!\n");
						printf("You gained %.2f HP\n", Player.stats.heal_value);
						Player.stats.hp += Player.stats.heal_value;
						break;
					case 'C':
						printf("You used Special Attack!!!\n");

						// Super Effective
						if( major_choice == 'B')
						{
							printf("It was super effective!!!\n");
							printf("You dealt %.2f damage!!!\n", 1.5*Player.stats.attack);
							enemy5.stats.hp = enemy5.stats.hp - (1.5*Player.stats.attack);
						}

						else if(major_choice == 'A')
						{
							printf("It wasn't very effective\n");
							printf("You dealt %.2f damage!\n", 0.5*Player.stats.attack);
							enemy5.stats.hp = enemy5.stats.hp - (0.5*Player.stats.attack);
						}
						else
						{
							printf("You dealt %.2f damage!!!\n", Player.stats.attack);
							enemy5.stats.hp -= Player.stats.attack;
						}
						break;
					default:
						printf("Invalid Move Selection\n");
				}

				if(enemy5.stats.hp <= 0)
				{
					printf("Enemy has been defeated!!!\n");
					printf("Congratulations!!!\n\n");
				}

				if(enemy5.stats.hp > 0) // If statement to check if the enemy gets to move
				{
					rand_move = rand() % 1000 + 1;

					if(rand_move < 1000/3) // Physical Attack
					{
						printf("\nThe enemy used Physical Attack!!!\n");
						printf("You took %.2f damage.\n", enemy5.stats.attack);
						Player.stats.hp -= enemy5.stats.attack;
					}

					else if(rand_move > 2000/3) // Special Attack
					{
						printf("\nThe enemy used Special Attack!!!\n");

						if(major_choice == 'D') // Attack was super effective
						{
							printf("It was super effective!!!\n");
							printf("You took %.2f damage.\n", 1.5*enemy5.stats.attack);
							Player.stats.hp -= 1.5*enemy5.stats.attack;
						}

						else if(major_choice == 'C') // Not very effective
						{
							printf("It wasn't very effective\n");
							printf("You took %.2f damage.\n", 0.5*enemy5.stats.attack);
							Player.stats.hp -= 0.5*enemy5.stats.attack;
						}

						else // Some other major selection
						{
							printf("You took %.2f damage. \n", enemy5.stats.attack);
							Player.stats.hp -= enemy5.stats.attack;
						}
					}

					else // Enemy chooses the heal move
					{
						printf("\nThe enemy used Heal!!!\n");
						printf("%.2f HP was restored!\n", enemy5.stats.heal_value);
						enemy5.stats.hp += enemy5.stats.heal_value;
					}
				}	

				if(Player.stats.hp <= 0.0) // Check if the player's hp is 0 or below 0
				{
					printf("\nYou have been defeated\n");
					losses++;
				}


			}


		}

		

		

		/* Ask to play again */
		if(Player.stats.hp > 0) // Playing again if you have won!!!
		{
			printf("\nCongratulations!!! You are the champion!!!\n\n"); // Let them know they
			// are the champion
			championships++; // Increment championships
			
			do
			{
			/* Main Menu Choices */
	
			printf("What would you like to do now?\n");
			printf("A: Play again\n");
			printf("B: Display Rules\n");
			printf("C: Display Statistics\n");
			printf("D: See Credits\n");
			printf("E: Quit Game\n");
			/* Get user input for the choice */
			printf("\nPlease Enter the letter of your choice: ");
			scanf(" %c", &decision);

				/* Switch case to determine what to do */
				switch(decision)
				{
				// A should do nothing
				case 'A':
					break;
				case 'B': // B should display the rules
					display_rules();
					break;
				case 'C': // C should display the game statistics
					display_game_stats(wins, losses, championships);
					decision = 'B';
					break;
				case 'D': // D should display the credits
					display_credits();
					decision = 'B';
					break;
				case 'E': // Case E should not do anything, it should exit the while loop for the game
					printf("Goodbye!\n");
					break;
				default:
					printf("Invalid Menu Selection\n");
				}
			} while(decision == 'B');


		}

	/* Ask to play again on a loss condition */
		if(Player.stats.hp <= 0) // Loss
		{
			printf("\nUnfortunately you have lost :(\n\n"); // Let them know they
			// have lost
			
			do
			{
			/* Main Menu Choices */
	
			printf("What would you like to do now?\n");
			printf("A: Play again\n");
			printf("B: Display Rules\n");
			printf("C: Display Statistics\n");
			printf("D: See Credits\n");
			printf("E: Quit Game\n");
			/* Get user input for the choice */
			printf("\nPlease Enter the letter of your choice: ");
			scanf(" %c", &decision);

				/* Switch case to determine what to do */
				switch(decision)
				{
				// A should do nothing
				case 'A':
					break;
				case 'B': // B should display the rules
					display_rules();
					break;
				case 'C': // C should display the game statistics
					display_game_stats(wins, losses, championships);
					decision = 'B';
					break;
				case 'D': // D should display the credits
					display_credits();
					decision = 'B';
					break;
				case 'E': // Case E should not do anything, it should exit the while loop for the game
					printf("Goodbye!\n");
					break;
				default:
					printf("Invalid Menu Selection\n");
				}
			} while(decision == 'B');
		}

	/* End While Loop */
	}


}

/* Display Credits Definition */
void display_credits()
{
	printf("Source Code Written by Jack Reardon\n\n");
}

/* Display Rules Function Definition */
void display_rules()
{
	printf("Here are the rules\n\n");
}

/* Display Game Stats Function Definition */
void display_game_stats(int a, int b, int c)
{
	printf("You have won %i battles\n", a);
	printf("You have lost %i battles\n", b);
	printf("You have won the championship %i times\n\n\n", c);
}

/* Display Stats Function Definition */
void display_stats(char nm[], float a, float b, float c, float d)
{
	printf("\nMajor: ");
	puts(nm);
	printf("Level: %.2f\n", a);
	printf("Attack: %.2f\n", b);
	printf("HP: %.2f\n",c);
	printf("Heal Value: %.2f\n\n",d);
}
