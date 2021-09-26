//I need to change where I put the click any empty box message
//I need to add cross out lines

#include "ccc_win.h"
#include <cstdlib>
#include <ctime>


int ccc_win_main() {

	srand((int)time(0));

	bool play_game = true;
	bool repeat = true, cycle = true;
	bool first_player_win = false;
	bool ai_status = false;

	string zone1 = "1", zone2 = "2", zone3 = "3", zone4 = "4", zone5 = "5", zone6 = "6", zone7 = "7", zone8 = "8", zone9 = "9";



	//START GAME LOOP WITH REPEAT OPTION

	while (play_game)
	{


		Message Title(Point(-9.0, -9.5), "Tic-Tac-Toe by Eugene Mondkar (2018)");
		Message Welcome1(Point(-3.5, 0.0), "Welcome to Tic-Tac-Toe! Let's Start!");
		Message Welcome2(Point(-5.0, -1.0), "Please Follow the Instructions at the top of the screen.");
		Message Exit(Point(0.0, 4.0), "Would you like to exit?");

		Line H1(Point(-9.0, 3.00), Point(9.0, 3.00));
		Line H2(Point(-9.0, -3.00), Point(9.0, -3.00));
		Line V1(Point(-3.00, 9.0), Point(-3.00, -9.0));
		Line V2(Point(3.00, 9.0), Point(3.00, -9.0));



		int count = 0;

		string any_key;
		string response = "y";
		string ai_response = "n";

		Point P;

		//ERASE PREVIOUS GAME
		cwin.clear();

		//GAME TITLE
		cwin << Title;

		//PROMPT PLAYER WITH WELCOME
		cwin << Welcome1 << Welcome2;
		Point C = cwin.get_mouse("Click anywhere on the screen to start the game!");
		cwin.clear();

		//PROMPT PLAYER WITH CHOICE TO PLAY AI

		ai_response = cwin.get_string("Would you like to play against the computer? Type 'y' to play the computer, otherwise type 'n'");
		if ((ai_response == "y") || (ai_response == "Y"))
			ai_status = true;
		else
			ai_status = false;

		cwin.clear();

		//DRAW GRID
		cwin << H1 << H2 << V1 << V2; //Horizontal Lines

									  //Start the alternating turn sequence

		while (cycle)
		{

			while (repeat)
			{
				P = cwin.get_mouse("Place an X!");

				if ((P.get_x() < -3) && (P.get_x() >= -9) && (P.get_y() > 3) && (P.get_y() <= 9) && (zone1 == "1")) //ZONE 1
				{
					cwin << Line(Point(-8, 8), Point(-4, 4)) << Line(Point(-8, 4), Point(-4, 8));
					zone1 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < 3) && (P.get_x() >= -3) && (P.get_y() > 3) && (P.get_y() <= 9) && (zone2 == "2"))
				{
					cwin << Line(Point(-2, 8), Point(2, 4)) << Line(Point(-2, 4), Point(2, 8));
					zone2 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < 9) && (P.get_x() >= 3) && (P.get_y() > 3) && (P.get_y() <= 9) && (zone3 == "3"))
				{
					cwin << Line(Point(4, 8), Point(8, 4)) << Line(Point(4, 4), Point(8, 8));
					zone3 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < -3) && (P.get_x() >= -9) && (P.get_y() > -3) && (P.get_y() <= 3) && (zone4 == "4"))
				{
					cwin << Line(Point(-8, 2), Point(-4, -2)) << Line(Point(-8, -2), Point(-4, 2));
					zone4 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < 3) && (P.get_x() >= -3) && (P.get_y() > -3) && (P.get_y() <= 3) && (zone5 == "5"))
				{
					cwin << Line(Point(-2, 2), Point(2, -2)) << Line(Point(-2, -2), Point(2, 2));
					zone5 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < 9) && (P.get_x() >= 3) && (P.get_y() > -3) && (P.get_y() <= 3) && (zone6 == "6"))
				{
					cwin << Line(Point(4, 2), Point(8, -2)) << Line(Point(4, -2), Point(8, 2));
					zone6 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < -3) && (P.get_x() >= -9) && (P.get_y() > -9) && (P.get_y() <= -3) && (zone7 == "7"))
				{
					cwin << Line(Point(-8, -8), Point(-4, -4)) << Line(Point(-8, -4), Point(-4, -8));
					zone7 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < 3) && (P.get_x() >= -3) && (P.get_y() > -9) && (P.get_y() <= -3) && (zone8 == "8"))
				{
					cwin << Line(Point(-2, -8), Point(2, -4)) << Line(Point(-2, -4), Point(2, -8));
					zone8 = "x";
					count++;
					repeat = false;
				}
				else if ((P.get_x() < 9) && (P.get_x() >= 3) && (P.get_y() > -9) && (P.get_y() <= -3) && (zone9 == "9"))
				{
					cwin << Line(Point(4, -8), Point(8, -4)) << Line(Point(4, -4), Point(8, -8));
					zone9 = "x";
					count++;
					repeat = false;
				}
				else
				{
					cwin << Message(Point(0.0, -9.5), "Please click within one of the empty squares");
				}
			}

			repeat = true;

			if ((zone1 == zone2) && (zone2 == zone3))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(-9, 6), Point(9, 6));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone4 == zone5) && (zone5 == zone6))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(-9, 0), Point(9, 0));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone7 == zone8) && (zone8 == zone9))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(-9, -6), Point(9, -6));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone1 == zone5) && (zone5 == zone9))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(-9, 9), Point(9, -9));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone3 == zone5) && (zone5 == zone7))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(9, 9), Point(-9, -9));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone1 == zone4) && (zone4 == zone7))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(-6, 9), Point(-6, -9));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone2 == zone5) && (zone5 == zone8))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins");
				cwin << Line(Point(0, 9), Point(0, -9));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if ((zone3 == zone6) && (zone6 == zone9))
			{
				cwin << Message(Point(-1.0, -2.0), "1st Player Wins!");
				cwin << Line(Point(6, 9), Point(6, -9));
				cycle = false;
				repeat = false;
				first_player_win = true;
			}
			else if (count == 9)
			{
				cwin << Message(Point(-1.0, -2.0), "No more turns, Cat Game!");
				cycle = false;
				repeat = false;
				first_player_win = true;
			}

			if (!first_player_win)
			{
				while (repeat)
				{
					//If AI is selected these are the strategies it will follow, it will prioritize blocking and winning.
					if (ai_status)
					{
						if ((zone8 == zone5) && (zone2 == "2"))
						{
							P = Point(0.0, 6.0);
						}
						else if ((zone4 == zone5) && (zone6 == "6"))
						{
							P = Point(6.0, 0.0);
						}
						else if ((zone6 == zone5) && (zone4 == "4"))
						{
							P = Point(-6.0, 0.0);
						}
						else if ((zone2 == zone5) && (zone8 == "8"))
						{
							P = Point(0.0, -6.0);
						} // Bookmark
						else if (((zone1 == zone2) || (zone7 == zone5) || (zone6 == zone9)) && (zone3 == "3"))
						{
							P = Point(6.0, 6.0);
						}
						else if (((zone4 == zone5) || (zone3 == zone9)) && (zone6 == "6"))
						{
							P = Point(6.0, 0.0);
						}
						else if (((zone7 == zone8) || (zone1 == zone5) || (zone3 == zone6)) && (zone9 == "9"))
						{
							P = Point(6.0, -6.0);
						}
						else if (((zone1 == zone3) || (zone8 == zone5)) && (zone2 == "2"))
						{
							P = Point(0.0, 6.0);
						}
						else if (((zone4 == zone6) || (zone2 == zone8) || (zone7 == zone3) || (zone1 == zone9)) && (zone5 == "5"))
						{
							P = Point(0.0, 0.0);
						}
						else if (((zone7 == zone9) || (zone2 == zone5)) && (zone8 == "8"))
						{
							P = Point(0.0, -6.0);
						}
						else if (((zone2 == zone3) || (zone4 == zone7) || (zone5 == zone9)) && (zone1 == "1"))
						{
							P = Point(-6.0, 6.0);
						}
						else if (((zone1 == zone7) || (zone5 == zone6)) && (zone4 == "4"))
						{
							P = Point(-6.0, 0.0);
						}
						else if (((zone3 == zone5) || (zone1 == zone4) || (zone9 == zone8)) && (zone7 == "7"))
						{
							P = Point(-6.0, -6.0);
						}
						else if ( ((zone1 == "x") || (zone3 == "x") || (zone7 == "x") || (zone9 == "x")) && (zone5 == "5") )
						{
							P = Point(0.0, 0.0);
						}
						else if (((zone1 == zone9) || (zone3 == zone7)) && (zone2 == "2"))
						{
							int x = 1 + rand() % 4;
							if ( x == 1 )
								P = Point(6.0, 0.0); // zone6
							else if (x == 2 )
								P = Point(0.0, 6.0); // zone2
							else if (x == 3 )
								P = Point(-6.0, 0.0); // zone4
							else
								P = Point(0.0, -6.0); // zone8
						}
						else if ( (zone5 == "x") && (zone1 == "1") && (zone3 == "3") && (zone7 == "7") && (zone9 == "9") )
						{
							int x = 1 + rand() % 4;
							if (x == 1)
								P = Point(-6.0, 6.0); // zone1
							else if (x == 2)
								P = Point(6.0, 6.0); // zone3
							else if (x == 3)
								P = Point(-6.0, -6.0); // zone7
							else
								P = Point(6.0, -6.0); // zone9
						}
						/*else if ( (zone8 == zone5) && (zone2 == "2") )
						{
							P = Point(0.0, 6.0);
						}
						else if ((zone4 == zone5) && (zone6 == "6"))
						{
							P = Point(6.0, 0.0);
						}
						else if ((zone6 == zone5) && (zone4 == "4"))
						{
							P = Point(-6.0, 0.0);
						}
						else if ((zone2 == zone5) && (zone8 == "8"))
						{
							P = Point(0.0, -6.0);
						}*/
						else if (((zone2 == "x") || (zone6 == "x") || (zone8 == "x") || (zone4 == "x")) && (zone5 == "5"))
						{
							P = Point(0.0, 0.0);
						}
						else
						{
							string zoneArray[9] = { zone1, zone2, zone3, zone4, zone5, zone6, zone7, zone8, zone9 };
							bool found = false;

							while (!found) {

								int i = rand() % 9;
								if (!(zoneArray[i] == "x" || zoneArray[i] == "o"))
								{
									switch (i)
									{
									case 0: // Zone1
										found = true;
										P = Point(-6.0, 6.0);
										break;
									case 1: // Zone2
										found = true;
										P = Point(0.0, 6.0);
										break;
									case 2: // Zone3
										found = true;
										P = Point(6.0, 6.0);
										break;
									case 3: // Zone4
										found = true;
										P = Point(-6.0, 0.0);
										break;
									case 4: // Zone5
										found = true;
										P = Point(0.0, 0.0);
										break;
									case 5: // Zone6
										found = true;
										P = Point(6.0, 0.0);
										break;
									case 6: // Zone7
										found = true;
										P = Point(-6.0, -6.0);
										break;
									case 7: // Zone8
										found = true;
										P = Point(0.0, -6.0);
										break;
									case 8: // Zone9
										found = true;
										P = Point(6.0, -6.0);
										break;
									default:
										break;
									}
								}

							}
						}

					}
					else
						P = cwin.get_mouse("Place an O!");

					if ((P.get_x() < -3) && (P.get_x() >= -9) && (P.get_y() > 3) && (P.get_y() <= 9) && (zone1 == "1"))
					{
						cwin << Circle(Point(-6.0, 6.0), 2.0);
						zone1 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < 3) && (P.get_x() >= -3) && (P.get_y() > 3) && (P.get_y() <= 9) && (zone2 == "2"))
					{
						cwin << Circle(Point(0.0, 6.0), 2.0);
						zone2 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < 9) && (P.get_x() >= 3) && (P.get_y() > 3) && (P.get_y() <= 9) && (zone3 == "3"))
					{
						cwin << Circle(Point(6.0, 6.0), 2.0);
						zone3 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < -3) && (P.get_x() >= -9) && (P.get_y() > -3) && (P.get_y() <= 3) && (zone4 == "4"))
					{
						cwin << Circle(Point(-6.0, 0.0), 2.0);
						zone4 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < 3) && (P.get_x() >= -3) && (P.get_y() > -3) && (P.get_y() <= 3) && (zone5 == "5"))
					{
						cwin << Circle(Point(0.0, 0.0), 2.0);
						zone5 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < 9) && (P.get_x() >= 3) && (P.get_y() > -3) && (P.get_y() <= 3) && (zone6 == "6"))
					{
						cwin << Circle(Point(6.0, 0.0), 2.0);
						zone6 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < -3) && (P.get_x() >= -9) && (P.get_y() > -9) && (P.get_y() <= -3) && (zone7 == "7"))
					{
						cwin << Circle(Point(-6.0, -6.0), 2.0);
						zone7 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < 3) && (P.get_x() >= -3) && (P.get_y() > -9) && (P.get_y() <= -3) && (zone8 == "8"))
					{
						cwin << Circle(Point(0.0, -6.0), 2.0);
						zone8 = "o";
						count++;
						repeat = false;
					}
					else if ((P.get_x() < 9) && (P.get_x() >= 3) && (P.get_y() > -9) && (P.get_y() <= -3) && (zone9 == "9"))
					{
						cwin << Circle(Point(6.0, -6.0), 2.0);
						zone9 = "o";
						count++;
						repeat = false;
					}
					else
					{
						if (!ai_status)
							cwin << Message(Point(0.0, -9.5), "Please click within one of the empty squares");
						repeat = true;
					}
				}


				//CHECK FOR WINNER

				repeat = true;

				if ((zone1 == zone2) && (zone2 == zone3))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(-9, 6), Point(9, 6));
					cycle = false;
					repeat = false;
				}
				else if ((zone4 == zone5) && (zone5 == zone6))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(-9, 0), Point(9, 0));
					cycle = false;
					repeat = false;
				}
				else if ((zone7 == zone8) && (zone8 == zone9))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(-9, -6), Point(9, -6));
					cycle = false;
					repeat = false;
				}
				else if ((zone1 == zone5) && (zone5 == zone9))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(-9, 9), Point(9, -9));
					cycle = false;
					repeat = false;
				}
				else if ((zone3 == zone5) && (zone5 == zone7))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(9, 9), Point(-9, -9));
					cycle = false;
					repeat = false;
				}
				else if ((zone1 == zone4) && (zone4 == zone7))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(-6, 9), Point(-6, -9));
					cycle = false;
					repeat = false;
				}
				else if ((zone2 == zone5) && (zone5 == zone8))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(0, 9), Point(0, -9));
					cycle = false;
					repeat = false;
				}
				else if ((zone3 == zone6) && (zone6 == zone9))
				{
					cwin << Message(Point(-1.0, -2.0), "2nd Player Wins!");
					cwin << Line(Point(6, 9), Point(6, -9));
					cycle = false;
					repeat = false;
				}
				else if (count == 9)
				{
					cwin << Message(Point(-1.0, -2.0), "No more turns, Cat Game!");
					cycle = false;
					repeat = false;
				}
			}
		}


		response = cwin.get_string("If you would like to play again, type 'y' or type 'n' to exit!");

		if ((response == "y") || (response == "Y"))
		{
			play_game = true;
			//Setting intial conditions
			cycle = true;
			repeat = true;
			zone1 = "1", zone2 = "2", zone3 = "3", zone4 = "4", zone5 = "5", zone6 = "6", zone7 = "7", zone8 = "8", zone9 = "9";
			first_player_win = false;
			ai_response = "n";
			ai_status = false;
		}
		else
			play_game = false;
	}


	cwin.clear();

	cwin << Message(Point(-1.0, 0.0), "Thank you for Playing!");

	return 0;


}