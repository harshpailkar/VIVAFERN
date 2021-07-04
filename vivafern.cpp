/* ========================================================================================
                            PROJECT : V I V A F E R N 
   ========================================================================================
   Code Authors : 1. Aditya Patil - aditya142002@gmail.com
                  2. Harsh Pailkar - harsh.pailkar@gmail.com

   Date : 03rd July 2021
   ========================================================================================
*/

#include <iostream>
#include <cctype>
#include<vector>
#include <string>
using namespace std;

// Function Prototypes 
void mainMenu(char &choice, int &choice2, char &var,vector<vector <string>> &database); 
void actions(char &var, int &choice2,vector<vector <string>> &database);
void selection(int &choice2, char &var,vector<vector <string>> &database);
void UserInput(vector<vector <string>> &database, int &choice2);
void fruits(vector<vector <string>> &database);
void flowers(vector<vector <string>> &database);
void crops(vector<vector <string>> &database);
void vegetables(vector<vector <string>> &database);
void suggest(double &temp,vector<string> &types_of_soil, int &soil_type, int &choice, vector<vector <string>> &database);


// ========================================================================================

// Main Function
int main()
{
    int choice2{};
    char choice{};

    char var{}; // Convert the User Input to UpperCase Letter

    vector<vector<string>>database
    {
        {"Ladyfingers","Loamy","10","35","Vegetables","11"},{"Cauliflowers"	,"Loamy",	"15",	"25",	"Vegetables",	"6"},{"Bittergourds"	,"Sandy",	"25",	"30",	"Vegetables"	,"3"},
        {"FrenchBeans",	"Loamy",	"10",	"20",	"Vegetables",	"52"},{"Cabbage",	"Clay"	,"15",	"20"	,"Vegetables",	"12"},{"Spinach",	"Loamy"	,"5",	"20",	"Vegetables",	"1"},
        {"Fenugreek",	"Loamy",	"10",	"30"	,"Vegetables",	"104"},{"Potatoes"	,"Silty",	"15",	"20",	"Vegetables"	,"12"},{"Carrot",	"Loamy",	"15"	,"20"	,"Vegetables"	,"5"},
        {"Tomatoes",	"Clay"	,"20",	"25"	,"Vegetables"	,"24"},{"Onion"	,"Silty"	,"10"	,"35",	"Vegetables"	,"24"},{"Lemon"	,"Loamy",	"20"	,"40"	,"Vegetables",	"4"},
        {"Cilantro",	"Loamy"	,"10"	,"30",	"Vegetables",	"7"},{"Peppers"	,"Sandy",	"15",	"30",	"Vegetables",	"104"},{"Eggplant",	"Sandy"	,"25",	"35",	"Vegetables",	"3"},
        {"Strawberries",	"Sandy",	"5"	,"25",	"Fruits",	"156"},{"Figs"	,"Clay",	"15",	"20",	"Fruits"	,"1820"},{"Apples"	,"Clay",	"15",	"25",	"Fruits"	,"1820"},
        {"Mangoes",	"Sandy"	,"25",	"30",	"Fruits",	"15600"},{"Pomegranetes"	,"Loamy"	,"20"	,"35"	,"Fruits"	,"1040"},{"Plums",	"Loamy",	"5",	"45"	,"Fruits",	"520"},
        {"Pears",	"Loamy",	"5",	"45"	,"Fruits"	,"2600"},{"Grapes"	,"Loamy"	,"10"	,"40"	,"Fruits"	,"2704"},{"Bananas",	"Loamy"	,"15",	"35",	"Fruits",	"1300"},
        {"Watermelon",	"Sandy",	"20",	"25",	"Fruits",	"16"},{"Passion Fruit",	"Sandy"	,"20"	,"30"	,"Fruits"	,"312"},{"Pineapple",	"Sandy",	"20",	"30"	,"Fruits"	,"364"},
        {"JackFruit",	"Sandy",	"20",	"35",	"Fruits",	"208"},{"Papaya"	,"Loamy",	"20",	"30",	"Fruits",	"156"},{"Oranges"	,"Loamy",	"10",	"35",	"Fruits",	"2600"},
        {"Fuchsia",	"Clay",	"15",	"20",	"Flowers",	"1300"},{"Red Rose",	"Loamy",	"15",	"30",	"Flowers",	"780"},{"SnapDragons",	"Silty",	"10",	"25",	"Flowers",	"2"},
        {"Daisies",	"Loamy",	"20",	"25",	"Flowers",	"104"},{"Hydrangeas",	"Silty",	"5",	"20",	"Flowers",	"2600"},{"Foxgloves",	"Sandy",	"20",	"25",	"Flowers",	"104"},
        {"Carnations",	"Loamy",	"15",	"25",	"Flowers",	"208"},{"Hibiscus",	"Silty",	"15",	"30",	"Flowers",	"2600"},{"Stargazer Lilies",	"Loamy",	"25",	"30",	"Flowers",	"2"},
        {"Begonias Peaty",	"40",	"45",	"Flowers",	"104"},{"Amaranthus",	"Loamy",	"15",	"25",	"Flowers",	"24"},{"Garden Cosmos",	"Sandy",	"20",	"25",	"Flowers",	"52"},
        {"California Poppies",	"Sandy",	"10",	"20",	"Flowers",	"10"},{"Petunias",	"Sandy",	"15",	"20",	"Flowers",	"104"},{"Astilbe",	"Clay",	"15",	"25",	"Flowers",	"780"},
        {"Asparagus",	"Sandy",	"15",	"30",	"Crops",	"520"},{"Barley",	"Loamy",	"5",	"35",	"Crops",	"52"},{"Basil",	"Loamy",	"25",	"30",	"Crops",	"48"},
        {"Beetroots",	"Sandy",	"15",	"25",	"Crops",	"12"},{"Broccoli",	"Silty",	"15",	"25",	"Crops",	"104"},{"Chamomile",	"Sandy",	"15",	"20",	"Crops",	"52"},
        {"Corn",	"Loamy",	"0",	"45",	"Crops",	"104"},{"Garlic",	"Sandy",	"0",	"10",	"Crops",	"16"},{"Ginger",	"Loamy",	"20",	"30",	"Crops",	"36"},
        {"GreenBeans",	"Clay",	"15",	"30",	"Crops",	"52"},{"Kale",	"Sandy",	"15",	"20",	"Crops",	"59"},{"Lettuce",	"Loamy",	"10",	"20",	"Crops"	"19"},
        {"Mint",	"Loamy",	"15",	"20",	"Crops",	"156"},{"Wheat",	"Silty",	"20",	"35",	"Crops",	"52"},{"Rice",	"Clay",	"10",	"45",	"Crops",	"24"}
    };

    do
    {
        mainMenu(choice,choice2,var,database);
    }while(choice != 'Q' && choice != 'q');
    return 0;
}

// ========================================================================================

// Will display the (MAIN MENU or the LANDING MENU) and accept User Input
void mainMenu(char &choice, int &choice2, char &var,vector<vector <string>> &database)
{
    cout << "============================================================================" << endl;
    cout << "                  W E L C O M E   T O   V I V A F E R N                     " << endl;
    cout << "                  stimulate      beautify       enhance                     " << endl;
    cout << "============================================================================" << endl;
    cout << "A - Suggest plants based on Temperature, Water Requirement and Soil Type" << endl;
    cout << "B - Explore plants of your choice" << endl;
    cout << "Q - Quit" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    var = toupper(choice);
    // Calling (actions) function to reveal: WHAT NEXT?
    actions(var,choice2,database);

}

// ========================================================================================

// Perform actions according to the User Input
void actions(char &var, int &choice2,vector<vector <string>> &database)
{
    switch(var)
    {
        case 'A': // suggestion
        {
            cout << "You chose for suggestion of plants!" << endl;
            selection(choice2,var,database);
        } 
        break;

        case 'B': // exploration
        {
            cout << "You chose to explore plants!" << endl;
            selection(choice2,var,database); 
        }
        break;

        case 'Q': // quit
        {
            cout << "\n\n\n=============================================================" << endl;
            cout << "    Thank you for using V I V A F E R N! See you again! :)" << endl; // Exit Main Menu
            cout << "=============================================================" << endl << endl;
        }
        break;

        default:
        {
            cout << "Illegal Input! Please enter choice as per the menu*\n\n" << endl; // Illegal User Input
        }
        
    }
}

// ========================================================================================

// Selection between types of Plants
void selection(int &choice2, char &var, vector<vector <string>> &database)
{
    // int choice2{};
    do
    {
        // Menu for sub-selection of plants
        cout << "\n\n----------------------------------------------------------------------------" << endl;
        cout << "Select one of the following types:" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "1 - Flowers" << endl;
        cout << "2 - Fruits" << endl;
        cout << "3 - Vegetables" << endl;
        cout << "4 - Crops" << endl;
        cout << "5 - BACK" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice2;
        cout << "\n" << endl;
        
        switch(choice2)
        {
            case 1: 
            case 2: 
            case 3:
            case 4:
            {
                if(var == 'A')
                UserInput(database,choice2);
                else if(var == 'B' && choice2 == 1)
                flowers(database);
                else if(var == 'B' && choice2 == 2)
                fruits(database);
                else if(var == 'B' && choice2 == 3)
                vegetables(database);
                else if(var == 'B' && choice2 == 4)
                crops(database);
     
            }
            break;
            case 5:
            break;
            default:
            cout << "ERROR ! Kindly enter a valid choice !" << endl;
        }
    }while(choice2 != 5);
}
// ========================================================================================

// UserInput
void UserInput(vector<vector <string>> &database, int &choice2)
{
    vector <string> plants{};
    
    double temp {};
    cout << "Enter temperature (in C): ";
    cin >> temp;

    if(temp > 45 || temp < 0)
    cout << "Sorry! The temperatures are too high or too low!" << endl;
    else
    {
    cout << endl;


    int soil_type {};
    vector <string> types_of_soil {"Clay", "Sandy", "Peaty", "Loamy", "Silty"};
    cout << "Choose the type of soil: " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "1 - Clay" << endl;
    cout << "2 - Sandy" << endl;
    cout << "3 - Peaty" << endl;
    cout << "4 - Loamy" << endl;
    cout << "5 - Silty" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> soil_type;
    cout << endl;


    int water_requirements {};
    vector <string> water {"Low", "Moderately", "High"};
    cout << "Choose the water availability: " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "1 - Low" << endl;
    cout << "2 - Moderate" << endl;
    cout << "3 - High" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> water_requirements;

    cout << "\n------------------------CONDITIONS YOU CHOSE-------------------------------" << endl;
    cout << "Temperature: " << temp << " C" << endl;
    cout << "Type of Soil: " << types_of_soil.at(soil_type-1) << endl;
    cout << "Water Availibility: " << water.at(water_requirements-1) << endl;
    cout << "============================================================================" << endl;
    cout << endl;

    cout << "THE FAVOURABLE PLANT CHOICES FOR YOU ARE :\n" << endl;
    suggest(temp,types_of_soil,soil_type,choice2, database);
    }

}

// ========================================================================================

// SUGGEST FUNCTION
void suggest(double &temp, vector<string> &types_of_soil, int &soil_type, int &choice2, vector<vector <string>> &database)
{

if (choice2 == 1 )
{
// ========================================================================================
    if(soil_type == 1)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else 
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
        
// ========================================================================================
    else if(soil_type == 2)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;


    }
// ========================================================================================

    else if(soil_type == 3)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high ot too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 4)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 5)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Flowers")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
// ========================================================================================
}

else if (choice2 == 2)
{
// ========================================================================================
    if(soil_type == 1)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high ot too low!" << endl;
        
    }
        
// ========================================================================================
    else if(soil_type == 2)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;


    }
// ========================================================================================

    else if(soil_type == 3)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 4)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 5)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
                    //else
                    //cout << "Sorry, no such plant is available at this moment!" << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
// ========================================================================================
}

else if (choice2 == 3)
{
// ========================================================================================
    if(soil_type == 1)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Vegetables")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
        
// ========================================================================================
    else if(soil_type == 2)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;


    }
// ========================================================================================

    else if(soil_type == 3)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 4)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 5)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Fruits")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
// ========================================================================================
}

else if (choice2 == 4)
{
// ========================================================================================
    if(soil_type == 1)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Clay" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
        
// ========================================================================================
    else if(soil_type == 2)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Sandy" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;


    }
// ========================================================================================

    else if(soil_type == 3)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Peaty" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 4)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Loamy" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;

    }
// ========================================================================================

    else if(soil_type == 5)
    {
        if(temp >= 0 && temp<= 15)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 15 && temp <= 30)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }

        else if(temp > 30 && temp <= 45)
        {
            for(int i=0;i<60;i++)
            {
                    if(database.at(i).at(1) == "Silty" && database.at(i).at(4) == "Crops")
                    cout << "---> " << database.at(i).at(0) << endl;
            }
        }
        else
        cout << "Sorry! The temperatures are too high or too low!" << endl;
        
    }
// ========================================================================================
}
}


// ========================================================================================

// CASE : B

// FRUITS MENU
void fruits(vector<vector <string>> &database)
{
    int fruit{};
    cout << "Choose which fruit you wish to grow: " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << " 1 - Strawberries" << "     2 - Figs" << "             3 - Apples" << endl;
    cout << " 4 - Mangoes" << "          5 - Pomegranetes" << "     6 - Plums" << endl;
    cout << " 7 - Pears" << "            8 - Grapes" << "           9 - Bananas" << endl;
    cout << "10 - Watermelons" << "     11 - Passion Fruit" << "   12 - Pineapple" << endl;
    cout << "13 - Jackfruit" << "       14 - Papaya" << "          15 - Oranges" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> fruit;

    cout << database.at(fruit+14).at(0) << ": " << endl;
    cout << "Soil Type: " << database.at(fruit+14).at(1) << endl;
    cout << "Minimum temperature: " << database.at(fruit+14).at(2) << " C" << endl;
    cout << "Maximum temperature: " << database.at(fruit+14).at(3) << " C" << endl;
    cout << "Type of plant: " << database.at(fruit+14).at(4) << endl;
    cout << "Life expectancy: " << database.at(fruit+14).at(5) << " weeks" <<endl;

}

// VEG MENU
void vegetables(vector<vector <string>> &database)
{
    int veggie{};
    cout << "Choose which veggies you wish to grow: " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << " 1 - Ladyfingers" << "       2 - Cauliflower" << "       3 - Bittergourds" << endl;
    cout << " 4 - Frenchbeans" << "       5 - Cabbage" << "           6 - Spinach" << endl;
    cout << " 7 - Fenugreek" << "         8 - Potatoes" <<  "          9 - Carrot" << endl;
    cout << "10 - Tomatoes" <<  "         11 - Onions" << "           12 - Lemon" << endl;
    cout << "13 - Cilantro" << "         14 - Pepper" << "           15 - Eggplant" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> veggie;

    cout << database.at(veggie-1).at(0) << ": " << endl;
    cout << "Soil Type: " << database.at(veggie-1).at(1) << endl;
    cout << "Minimum temperature: " << database.at(veggie-1).at(2) << endl;
    cout << "Maximum temperature: " << database.at(veggie-1).at(3) << endl;
    cout << "Type of plant: " << database.at(veggie-1).at(4) << endl;
    cout << "Life expectancy: " << database.at(veggie-1).at(5) << " weeks" << endl;
    
}

// FLOWERS MENU
void flowers(vector<vector <string>> &database)
{
    int flower{};
    cout << "Choose which flowers you wish to grow: " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << " 1 - Fuchsia" << "                   2 - Red Rose" << "             3 - Snapdragons" << endl;
    cout << " 4 - Daisies" << "                   5 - Hydrangeas" << "           6 - Foxgloves" << endl;
    cout << " 7 - Carnatians" << "                8 - Hibiscus" <<  "             9 - Stargazer Lilies" << endl;
    cout << "10 - Begonias" <<  "                 11 - Amaranthus" << "          12 - Garden Cosmos" << endl;
    cout << "13 - Californai Poppies" << "       14 - Petunias" << "            15 - Astelbe" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> flower;

    cout << database.at(flower+29).at(0) << ": " << endl;
    cout << "Soil Type: " << database.at(flower+29).at(1) << endl;
    cout << "Minimum temperature: " << database.at(flower+29).at(2) << endl;
    cout << "Maximum temperature: " << database.at(flower+29).at(3) << endl;
    cout << "Type of plant: " << database.at(flower+29).at(4) << endl;
    cout << "Life expectancy: " << database.at(flower+29).at(5) << " weeks" << endl;
    
}

// CROPS MENU
void crops(vector<vector <string>> &database)
{
    int crop{};
    cout << "Choose which crops you wish to grow: " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << " 1 - Asparagus" << "                   2 - Barley" << "              3 - Basil" << endl;
    cout << " 4 - Beetroots" << "                   5 - Brocolli" << "            6 - Chamomile" << endl;
    cout << " 7 - Corn" << "                        8 - Garlic" <<  "              9 - Ginger" << endl;
    cout << "10 - Greenbeans" <<  "                 11 - Kale" << "               12 - Lettuce" << endl;
    cout << "13 - Mint" << "                       14 - Wheat" << "              15 - Rice" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> crop;
    
    cout << database.at(crop+44).at(0) << ": " << endl;
    cout << "Soil Type: " << database.at(crop+44).at(1) << endl;
    cout << "Minimum temperature: " << database.at(crop+44).at(2) << endl;
    cout << "Maximum temperature: " << database.at(crop+44).at(3) << endl;
    cout << "Type of plant: " << database.at(crop+44).at(4) << endl;
    cout << "Life expectancy: " << database.at(crop+44).at(5) << " weeks" << endl;
}


