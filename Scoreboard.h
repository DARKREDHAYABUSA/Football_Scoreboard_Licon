//Dr_T helping students get started on Unit 4 scoreboard
//Using object oriented coding for a scoreboard:  Basketball
//classes Team, Scoreboard //PRIVATE TEAM class members
#include <iostream>
#include <unistd.h> //for sleep command
#include <string>
#include <iomanip> //for setw

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

//#include "Team.h"

using namespace std; 




class Team
{
  private: 
    int score; 
    int fouls; 
    string name; 
    string coach; //
    string homeCity;

    bool bonusFirstHalf;
    bool bonusSecondHalf; 
  public: 
    Team()//default constructor  
    {
      score = 0;
      fouls = 0; 
      name = "Team Name";
      coach = "Coach Name";
      homeCity ="Home City";

      bonusFirstHalf = false; 
      bonusSecondHalf = false; 
    }  
    void setScore(int s) { score = s; }
    void setFouls(int f) { fouls = f; }
    void setName(string n) { name = n; }
    void setCoach(string c) { coach = c; }
    void setHomeCity(string hC) { homeCity = hC; }

    void setBonusFirstHalf(bool bFH) { bonusFirstHalf = bFH; }
    void setBonusSecondHalf(bool bSH) { bonusSecondHalf = bSH; }

    double getScore() const { return score; }
    //double getFouls() const { return fouls; }
    string getName() const { return name; }
    string getCoach() const { return coach; }
    string getHomeCity() const { return homeCity; }

    //bool getBonusFirstHalf() const { return bonusFirstHalf; }
    //bool getBonusSecondHalf() const { return bonusSecondHalf; }
};

class Scoreboard
{
  private: 
    int quarter;
    int down;
    int toGo;
    bool poss; //true = home, false = visitor 
    Team team1; //double dot notation to get its data
    Team team2; //double dot notation to get its data

    int playerNumber;
    int playerFouls; 
    int minutes;
    int seconds; 
  public:
    Scoreboard() //default constructor 
    {
      quarter = 0;
      poss = true; //home team has the ball intially 
      playerNumber = 0;
      playerFouls = 0; 
      minutes = 11;
      seconds = 59; 
    }  
    void setQuarter(int q) { quarter = q; }
    void setToGo(int t) { toGo = t; }
    void setDown(int d) { down = d; }
    void setPoss(bool po) { poss = po; }
    void setTeam1(Team t1) { team1 = t1; } //remember when the object changes
    void setTeam2(Team t2) {team2 = t2; } //remember when the object changes
    void setPlayerNumber(int pn) { playerNumber = pn; }
    void setPlayerFouls(int pf) { playerFouls = pf; }
    void setMinutes(int m) { minutes = m; }
    void setSeconds(int s) { seconds = s; }
    int getQuarter() const { return quarter; }
    int getToGo() const { return toGo; }
    int getDown() const { return down; }
    bool getPoss() const { return poss; }
    Team getTeam1() const { return team1; }
    Team getTeam2()  const { return team2; }
    int getPlayerNumber() const { return playerNumber; }
    int getPlayerFouls() const { return playerFouls; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    void showScoreboard()
    { 
      string color = ""; 
      string reset = "\x1b[0m";
        
        system("clear"); //clear the screen 
        
        //Show Scoreboard
        color = "\x1b[32;1m"; //green 
        cout << color << "\t\t\t\tFootball Scoreboard\n"<< reset;
        color = "\x1b[91;1m"; //red
        for(int i = 0; i < 50; i++) { cout << color << "_" << reset; }
        cout << endl; 

      cout << "\n\t\t\t\t\t ００∶００ ";//For looks

        cout << "\n     (Home)\t\t\t\t\t\t\t(Visitor)" << endl; 

        cout << setw(13) << team1.getName() 
                         << "\t\t\t\t" 
             << setw(8)  << "\t" 
                         <<team2.getName() 
                         << endl;

        color = "\x1b[91;1m"; //red 

        cout << color 
             << setw(9)  << team1.getScore() 
             << reset    << "\t\t\t\t\t" 
             << color
             << setw(13) <<  team2.getScore() 
             << reset    << endl;
 




        //dealing with Boolean data

        if(poss == true)

        { cout << "\n\t【● Home】\t\t\t\t\t   【Visitor ○】\n" << endl; }

        else

        { cout << "\n\t【○ Home】\t\t\t\t\t   【Visitor ●】\n" << endl; }

        color = "\x1b[93;1m"; // yellow


        cout << "\t\t\t\t\t QTR: 【" 
             << color 
             << quarter 
             << reset 
             << "】\n"  
             << endl;






        color = "\x1b[91;1m"; //red    

        for(int i = 0; i < 50; i++) { cout << color << "_" << reset; }

        cout << "\n\n";  

        cout << setw(10) << team1.getHomeCity() << ", "
                         << team1.getName() 
                       /*<< " Coach:" */
                         << "\t||\t " 
           /*<< setw(5)*/<< " "  
                         <<team2.getHomeCity() << ", "
                         <<team2.getName() 
                       /*<< " Coach:\n"*/ 
                         << "\n"
                         << endl; 

        cout << setw(8)  << " Coach: " 
                         << team1.getCoach() 
                       /*<< "\t\t" */
                         << "\t\t||\t " 
           /*<< setw(5)  << "  " */
                         << " Coach: "
                         <<team2.getCoach() 
                         << endl;

      /*cout << setw(15) << team1.getHomeCity() 
                         << "\t\t" 
             << setw(5)  << "\t\t\t " 
                         <<team2.getHomeCity() 
                         << endl; */

    

        color = "\x1b[91;1m"; //red    

      for(int i = 0; i < 50; i++) { cout << color << "_" << reset; }
    }
};

 //A void function to instantiate and control scoreboard data 
void scoreboardControls()
{
  Scoreboard s; //instantiate the the scoreboard object s
  Team tOneMain; //team Object that will become a member of scoreboard S
  Team tTwoMain; //team Object that will become a member of scoreboard S
  char decision = '\0';
  int newScore = 0; 
  int teamChoice = 0;
  int teamCoach = 0;
  int teamCity = 0;
  int newQuarter = 0;
  int newDown = 0;
  int newToGo = 0;
  bool teamPoss;
  string newName = "";
  string newCoach = ""; 
  string newCity ="";

  s.setTeam1(tOneMain); // placed update Team1 object in s
  s.setTeam1(tTwoMain); // placed update Team2 object in s
  s.setQuarter(newQuarter);

  //Access the data outside of the class 
  /*cout << "\n Period here " << s.getPeriod() << endl; 
  cout << "\n Team 1 intial name: " << s.getTeam1().getName() << endl; 
  */

  //work with the scoreboard and menu 
  do
  {
        //show the scoreboard and clear the screen each time 
        s.showScoreboard();
       
       //Menu options for the user 
        cout << "\n\nMenu: " << endl; 
        cout << "A. Update Team Score" << endl; 
        cout << "B. Update Team Name\n" << endl; 
        cout << "C. Update Coach Name\n" << endl;
        cout << "D. Update Downs\n" << endl;
        cout << "E. Update To Go\n" << endl;
        cout << "F. Update Time Out\n" << endl;
        cout << "H. Update Home City\n" << endl;
        cout << "Q. Update Quarter\n" << endl; 
        cout << "P. Update Ball Possession\n" << endl; 
        cout << "X. To Exit\n\n" << endl; 
        cin >> decision; 


        if(decision == 'a' || decision == 'A')
      {
          cout << "\nPress 1 to update Team 1 \nPress 2 to update Team 2: ";

          cin >> teamChoice;

        if(teamChoice == 1)

        { cout << "\nTeam 1 score update. \n";
          cout << "\nWhat is the new score? > ";
          cin >> newScore; 
          tOneMain.setScore(newScore);
          cout << "\nUpdating new score for Team 1 to..." << tOneMain.getScore() << endl;   
          sleep(3); }//pause 3 seconds.

        else if(teamChoice == 2)

        { cout << "\nTeam 2 score update. \n";
          cout << "\nWhat is the new score? > ";
          cin >> newScore; 
          tTwoMain.setScore(newScore);
          cout << "\nUpdating new score for Team 2 to..." << tTwoMain.getScore() << endl;   
          sleep(3); }//pause 3 seconds.
      }


        else if(decision == 'b' || decision == 'B')
    {
         cout << "\nPress 1 to update Team 1 \nPress 2 to update Team 2: ";

         cin >> teamChoice;

        if(teamChoice == 1)
        
        { cout << "\nTeam 1 NAME update. \n";
          cout << "\nWhat is the new Name? > ";
          cin >> newName; 
          tOneMain.setName(newName);
          cout << "\nUpdating new name for Team 1 to..." << tOneMain.getName() << endl;
          sleep(3); }//pause 3 seconds.

        else if(teamChoice == 2)
        { cout << "\nTeam 2 NAME update. \n";
          cout << "\nWhat is the new Name? > ";
          cin >> newName; 
          tTwoMain.setName(newName);
          cout << "\nUpdating new name for Team 2 to..." << tTwoMain.getName() << endl;
          sleep(3); }//pause 3 seconds.
    }




        if(decision == 'c' || decision == 'C')
      {
          cout << "\nPress 1 to update Team 1 \nPress 2 to update Team 2: ";

          cin >> teamCoach;

        if(teamCoach == 1)

        { cout << "\nTeam 1 Coach update. \n";
          cout << "\nWhat is the Coach's name? > ";
          cin >> newCoach; 
          tOneMain.setCoach(newCoach);
          cout << "\nUpdating new score for Team 1 to..." << tOneMain.getCoach() << endl;   
          sleep(3); }//pause 3 seconds.

        else if(teamCoach == 2)

        { cout << "\nTeam 2 Coach update. \n";
          cout << "\nWhat is the Coach's name? > ";
          cin >> newCoach; 
          tTwoMain.setCoach(newCoach);
          cout << "\nUpdating new score for Team 2 to..." << tTwoMain.getCoach() << endl;   
          sleep(3); }//pause 3 seconds.
      }

        else if(decision == 'd' || decision == 'D')
        { cout << "\nUpdate Down \n";
          cout << "\nWhat is the new Down? ...>";
          cin >> newDown;
          s.setDown(newDown);
          cout << "\nUpdating Down To ..." << s.getDown() << endl; sleep(3); } //pause 3 seconds.

        else if(decision == 'e' || decision == 'E')
        
        { cout << "\nUpdate To Go \n";
          cout << "\nWhat is the new To Go? ...>";
          cin >> newToGo;
          s.setToGo(newToGo);
          cout << "\nUpdating To Go to ..." << s.getToGo() << endl; sleep(3); } //pause 3 seconds.





        else if(decision == 'h' || decision == 'H')
    {
         cout << "\nPress 1 to update Team 1 \nPress 2 to update Team 2: ";

         cin >> teamCity;

        if(teamCity == 1)
        
        { cout << "\nTeam 1 NAME update. \n";
          cout << "\nWhat is the City? > ";
          cin >> newCity; 
          tOneMain.setHomeCity(newCity);
          cout << "\nUpdating City for Team 1 to..." << tOneMain.getName() << endl;
          sleep(3); }//pause 3 seconds.

        else if(teamCity == 2)
        { cout << "\nTeam 2 City update. \n";
          cout << "\nWhat is the City? > ";
          cin >> newCity; 
          tTwoMain.setHomeCity(newCity);
          cout << "\nUpdating City for Team 2 to..." << tTwoMain.getName() << endl;
          sleep(3); }//pause 3 seconds.
    }







        else if( decision == 'q' || decision == 'Q')

        {
          cout << "\nQuarter update.";
          cout << "\nWhat Quarter is it. > ";
          cin >> newQuarter;
          s.setQuarter(newQuarter);
          cout << "\nUpdating the Quarter ..." << s.getQuarter() << endl;
          sleep(3); //pause 3 seconds.
        }
        




        else if(decision == 'p' || decision == 'P')

        {
          cout << "\nWho has Ball Possession. \n";
          cout << "1 Home || 0 Visitor. \n > ";
          cin >> teamPoss;
          s.setPoss(teamPoss);
          cout << "\nUpdating Possesssion To ... " << s.getPoss() << endl; //pause 3 seconds.
          sleep(3);
        }


        else if(decision == 'x' || decision == 'X')
        {
          cout << "\nEXIT. Go Team!!!" << endl; 
        }

        s.setTeam1(tOneMain); //setTeam1 to the latest data 
        s.setTeam2(tTwoMain); //setTeam2 to the latest data 
      
  }while(decision != 'x' && decision != 'X');     



};

#endif