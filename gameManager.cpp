#include "monster.h"
#include "player.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;


stack<int> cardsBin0;//Player 0's deck
stack<int> cardsBin1;//Player 0's deck

vector<player> players;


queue<monster> atk_que0;//Player 0's attack queue
queue<monster> def_que0;//Player 0's defense queue
queue<monster> atk_que1;//Player 1's attack queue
queue<monster> def_que1;//Player 1's defense queue

monster m1[30];
monster m2[30];


void addCard(int player_id)//Add to the hand from the deck
{
	int needadd = 5 - players[player_id].cards.size();
	if (player_id == 0)
	{
		
		for (int i = 0; i < needadd; i++)
		{
			//cout << "size:" << players[player_id].cards.size() << "  i:" << i << endl;
			players[player_id].cards.push_back(m1[cardsBin0.top()]);
			
			cout << "player" << player_id << " Add to the hand" << cardsBin0.top() << endl;
			cardsBin0.pop();

		}
		
			cout << "Player 0's hand reaches the upper limit of 5 and cannot be added again" << endl;
		
			
	}
	else
	{
		for (int i = 0; i < needadd; i++)
		{
			players[player_id].cards.push_back(m2[cardsBin1.top()]);

			cout << "player" << player_id << " Add to the hand" << cardsBin1.top() << endl;
			cardsBin1.pop();

		}

		cout << "Player 1's hand reaches the upper limit of 5 and cannot be added again" << endl;
	}
}


//Set the deck
void InitCards()
{

	/*string name[30] = { "anew", "any","del","liu","zhg","li","lin","fen","ka","niu","bi","cin","go","fan","dsd","gse","gwz","gew","hdfh","hert","hht","dad",
		"hrr","kyu","kuy","dhhg","dhj","jte","jxf","fj",};*/
	for (int j = 0; j < 30; j++)
	{
		m1[j].name = j;
		cout << "card:"<<j<<"'s name£º" << m1[j].name<<"\t";
		m1[j].atk = 200*j;
		cout << "atk:" << m1[j].atk << "\t";
		m1[j].def = 10 * j + 2000;
		cout << "\tdef:" << m1[j].def <<"\n";
		m1[j].type = 'm';
		cardsBin0.push(j);
		//cards0.push_back(m1[j]);
	}

	for (int i = 0; i < 30; i++)
	{
		m2[i] = m1[29 - i];
	}
	for (int j = 29; j >= 0; j--)
	{
		cardsBin1.push(j);
		//cards1.push_back(m2[j]);
	}



	/*for (int i = 0; i < 30; i++)
	{
		cardsBin.push(m[i]);
		addCard(0);
	}
	
	for (int i = 0; i < 30; i++)
	{
		cardsBin.push(m[i]);
		addCard(1);
	}*/
	cout << "player0's cards are:" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << m1[i].name << "\t" << m1[i].atk << "\t" << m1[i].def << "\n";
	}
	cout << "player1's cards are:" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << m2[i].name << "\t" << m2[i].atk << "\t" << m2[i].def << "\n";

	}
}


//set players
void InitPlayers()
{
	player player0 =  player("John");
	players.push_back(player0);
	
	player player1 = player("Kros");
	players.push_back(player1);
	
	players[0].life = 8000;
	players[1].life = 8000;

	cout << "player0:" << players[0].name << "  Go!" << endl;
	cout << "player1:" << players[1].name << "  Go!" << endl;
}







//
void tradeCard(int trade0, int trade1)
{
	swap(players[0].cards.at(trade0), players[1].cards.at(trade1));
	cout << "Successful transaction£¡" << endl;
}


//
void battle()
{
	//a atk and the other def  (i
	if ((def_que0.front().act && atk_que1.front().act) || (def_que1.front().act && atk_que0.front().act))
	{
		if (def_que0.front().act && atk_que1.front().act)//0 def 1 atk
		{
			players[0].life = players[0].life + (atk_que1.front().atk - def_que0.front().def);
			def_que0.pop();
			atk_que1.pop();
		}
			
		else
		{
			players[1].life = players[1].life + (atk_que0.front().atk - def_que1.front().def);
			def_que1.pop();
			atk_que0.pop();
		}
			
		

	}
	else if (def_que0.front().act && def_que1.front().act)//both def (ii
	{
		def_que0.pop();
		def_que1.pop();
		//moveCard(players[0].cards, def_que0);
		//moveCard(players[1].cards, def_que1);
	}
	else//both atk (iii
	{
		if (atk_que0.front().atk > atk_que1.front().atk)
			players[1].life = players[1].life - (atk_que0.front().atk - atk_que1.front().atk);
		else
			players[0].life = players[0].life - (atk_que1.front().atk - atk_que0.front().atk);
		atk_que0.pop();
		atk_que1.pop();
	}

	
}


void moveCard(int player_id,int cardname,char mode)//Move from hand to queue
{
	if (player_id == 0)
	{
		if (mode == 'a')
		{
			atk_que0.push(m1[cardname]);
			//players[player_id].atk_que.push(players[player_id].cards[cardname]);
			players[player_id].cards.erase(players[player_id].cards.begin()+cardname);
			cout << "Player 0 successfully added cards to the attack queue£¡" << endl;
		}
		else
		{
			def_que0.push(players[player_id].cards[cardname]);
			//players[player_id].def_que.push(players[player_id].cards[cardname]);
			players[player_id].cards.erase(players[player_id].cards.begin() + cardname);
			cout << "Player 0 successfully added cards to the defense queue£¡" << endl;
		}

	}
	else
	{
		if (mode == 'a')
		{
			atk_que1.push(players[player_id].cards[cardname]);
			//players[player_id].atk_que.push(players[player_id].cards[cardname]);
			players[player_id].cards.erase(players[player_id].cards.begin() + cardname);
			cout << "Player 1 successfully added cards to the attack queue£¡" << endl;
		}
		else
		{
			def_que1.push(players[player_id].cards[cardname]);
			//players[player_id].def_que.push(players[player_id].cards[cardname]);
			players[player_id].cards.erase(players[player_id].cards.begin() + cardname);
			cout << "Player 1 successfully added cards to the defense queue£¡" << endl;
		}
	}
	
	//card_que.push(cards_.end);
	//cards_.pop_back();
}





void showPlayerHandCards(int player_id)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "player" << player_id << "'s hand cards are:";
		cout << "name:" << players[player_id].cards[i].name << "\tatk:" << players[player_id].cards[i].atk << "\tdef:" << players[player_id].cards[i].def << endl;
	}
		
}




int main()
{
	InitCards();//Initial deck

	int round = 0;//Game rounds
	bool isBegin = false;//Whether the game starts

	//Feature selected each time
	int option;

	if(!isBegin)
	{
		cout << "Choose one of these 4 options, otherwise exit the game: (1) Create player; (2) Add card to specific player; (3) Trade card; (4) Battle.";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			InitPlayers();//set players
			isBegin = true;
			break;
		}

		case 2:
		{
			int player_id;
			cout << "Which player to add the card to£º";
			cin >> player_id;
			addCard(player_id);//Send the top card to the player id
			break;
		}

		case 3:
		{
			int trade0, trade1;
			showPlayerHandCards(0);
			cout << "player0 The number of cards to trade (input 0-4):";
			cin >> trade0;

			showPlayerHandCards(1);
			cout << "player1 The number of cards to trade (input 0-4):";
			cin >> trade1;
			tradeCard(trade0,trade1);//trade cards
			break;
		}

		case 4:
		{
			//battle(atk_que0, def_que0, atk_que1, def_que1);
			break;
		}

		default:
			break;
		}//
		cout << "Start Battle£¡" << endl;


	}
	while (players[0].life > 0 && players[1].life > 0&&isBegin)
	{
		cout << "Choose one of these 4 options, otherwise exit the game: (1) Create player; (2) Add card to specific player; (3) Trade card; (4) Battle.";
		cin >> option;
		switch (option)
		{
			case 1:
			{
				InitPlayers();//
				break;
			}

			case 2:
			{
				int player_id;
				cout << "Which player to add the card to£º";
				cin >> player_id;
				addCard(player_id);//
				break;
			}

			case 3:
			{
				int trade0, trade1;
				showPlayerHandCards(0);
				cout << "player0 The number of cards to trade (input 0-4):";
				cin >> trade0;

				showPlayerHandCards(1);
				cout << "player1 The number of cards to trade (input 0-4):";
				cin >> trade1;
				tradeCard(trade0, trade1);//
				break;
			}

			case 4:
			{
				int coin = rand()%2;
				cout << "Coins determine player" << coin << "first move" << endl;
				int fir = 0;
				int sec = 1;
				round++;
				cout << "round: " << round << endl;
				//player0 ready
				showPlayerHandCards(fir);
				
				int cardnum0, cardnum1,cardnum2,cardnum3;
				if (atk_que0.empty())
				{
					cout << "Add the number of cards (0-4) to the ATK queue:" << endl;
					cin >> cardnum0;
					moveCard(fir, cardnum0, 'a');
				}
				if (def_que0.empty())
				{
					cout << "Add the number of cards (0-4) to the DEF queue:" << endl;
					cin >> cardnum1;
					moveCard(fir, cardnum1, 'd');
				}
				cout << "Select card to activate(input a/d):";
				char actType;
				cin >> actType;
				if (actType == 'a')
				{
					atk_que0.front().act = true;
					cout << "Player 0 activated the card in ATK mode" << atk_que0.front().name << endl;
				}
				else
				{
					def_que0.front().act = true;
					cout << "Player 0 activated the card in DEF mode" << def_que0.front().name << endl;
				}
				
				//player1 ready
				showPlayerHandCards(sec);
				if (atk_que1.empty())
				{
					cout << "Add the number of cards (0-4) to the ATK queue:" << endl;
					cin >> cardnum2;
					moveCard(sec, cardnum2, 'a');
				}
				if (def_que1.empty())
				{
					cout << "Add the number of cards (0-4) to the DEF queue:" << endl;
					cin >> cardnum3;
					moveCard(sec, cardnum3, 'd');
				}
				cout << "Select card to activate(input a/d):";
				cin >> actType;
				if (actType == 'a')
				{
					atk_que1.front().act = true;
					cout << "Player 1 activated the card in ATK mode" << atk_que1.front().name << endl;
				}
				else
				{
					def_que1.front().act = true;
					cout << "Player 1 activated the card in DEF mode" << def_que1.front().name << endl;
				}

				//Official battle
				//round++;
				//cout << "round: " << round<<endl;
				int oldlife0 = players[0].life;
				int oldlife1 = players[1].life;
				battle();
				

				cout << "round: " << round << endl;
				cout << "player0 loses " << oldlife0 - players[0].life << " LP" << endl;
				cout << "player0 loses " << oldlife1 - players[1].life << " LP" << endl;
				cout << "player0:" << players[0].life << " LP" << endl;
				cout << "player1:" << players[1].life << " LP" << endl;
				break;
			}

			default:
			{
				cout << "EXIT!" << endl;
				break;
			}
				
		}//

	}
	if (players[0].life <= 0)
	{
		cout << "player1 Win!" << endl;
		cout << "EXIT!" << endl;
	}
	else
	{
		cout << "player0 Win!" << endl;
		cout << "EXIT!" << endl;
	}
	


	system("PAUSE");
	return 0;
}
