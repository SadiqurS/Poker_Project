#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>
void setcolor(unsigned short color){//Creates function for setting color
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}
using namespace std;



//num of function
int numof(int c)
{
	int ncard;
	ncard=c%13;
	return ncard;
}
//rank of function
int rankof(int c)
{
	int rcard;
	rcard=c/13;
	return rcard;
}

//straightflush function
bool straightflush(int sorted[5]){
	int spade = 0;
	int clover = 0;
	int diamond = 0;
	int heart = 0;
	int temp = 0;
	int count = 1;
	for(int i = 0;i<5;i++){
			if(sorted[i]/13 == 0){
			spade = spade +1;
			}
			if(sorted[i]/13 == 1){
			clover = clover +1;
			}
			if(sorted[i]/13 == 2){
			diamond = diamond +1;
			}
			if(sorted[i]/13 == 3){
			heart = heart +1;
			}	
	}
	if(spade == 5 or clover ==5 or diamond ==5 or heart == 5){
		for(int i = 0;i<5;i++){
			temp = sorted[i]%13;
			for(int j = 0; j<5;j++){
				if(temp + 1 == sorted[j]%13 and i!=j){
					temp = sorted[j]%13;
					count = count + 1;	
				}
			}
			if(count != 5){
			count = 1;}
			if(count == 5){
			return true;
		}
	}
	if(count == 5){
			return true;
		}
	}
	else
	return false;
}

//pair function
bool pairs(int hand[5]) //name of pair function
{
	int two = 0; //count variable
	for(int i = 0; i<=4; i++) //goes thru the entire hand
	{
		if(hand[i] == hand[i+1]) //checks hand to see if there are same cards
		{
			two++;
		}	
	}
if(two == 2) //if there are 2 same cards then it is pair
{
	return true;
}
	return false;
}

//four of a kind function
bool fourofakind(int hand [5]) //name of function
{
	int four = 0; //counts for 4 same cards
	for(int i = 0; i<=4; i++)
	{
		if(hand[i] == hand[i+1]) //checks to see if 4 cards r similar
		{
			four++; //adds by 1 based on how many same cards there are
		}	
	}
if(four == 4) // if the count hits 4 then there are four same cards
{
	return true;
}
	return false;
}

//flush function
bool flush(int hand[5])
{
	//counter for the check
	int flush;
	//checks to see if the entire hand shares the same rank
	for(int i=0;i<4;i++)
	{
		if(rankof(hand[i])==rankof(hand[i+1]))
		{
			flush++;
		}
	}
	//if flush equals to four then it returns true, if not then return false
	if(flush == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//three of a kind function
bool threeofkind(int hand[5])
{
	//counter for the check
	int three=0;
	//checks to see if the hand has three cards that share the same number 
	for(int i=0;i<3;i++)
	{
		if(numof(hand[i]) == numof(hand[i+1]) and numof(hand[i+1]) == numof(hand[i+2]))
		{
		three++;
		}
	}
	//If three returns one it is three of kind, return anything else and it is false
	if(three == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//fullhouse function
bool fullhouse(bool handbool[52],int copy[7]){ //handbool = player hand and table = cards on the table and copy is where i can edit array without affecting table.
	int count = 0;
	for(int i = 0;i<52;i++){
		if(handbool[i] == true){
			copy[count] = i;
			count = count + 1;
		}
	}
	count = 0;
	int count2 = 0; //count2 for couting duplicates of 2 pairs or 3
	int count3 = 0;
	int card = 0;
	bool duplicate = false;
	bool duplicate2 = false;
	
	for(int i = 0; i<7;i++){
		card = copy[i] % 13;
		for(int j = 0; j<7;j++){		
		if(card == copy[j] % 13 and i != j){//finding duplicates
			if(duplicate == false and duplicate2 == false){
			count = count + 1;}
		}
		if(duplicate == true and card == copy[j] % 13 and i !=j){
			count2 = count2 + 1;	
		}
		if(duplicate2 == true and card == copy[j] % 13 and i !=j){
			count3 = count3 +1;		
		}
	}
		if(count != 1 and count != 2 and count != 3){
			count = 0;
		}
		if(count == 3){
		return false;
		}
		if(count == 1){ //for if there is 2 cards found
			duplicate = true;
		}
		if(count == 2) //3 pair found
			duplicate2 = true; 
		if(count2 == 1 and count == 2){ //3 pair found
			return true;
		}
		if(count2 == 2 and count == 1){ //3 pair found
			return true;
		}
		count2 = 0;
		count3 = 0;
	}
	return false;
}

//twopair function
bool twopair(int hand [5], int Table [5]) //name of pair function
{
	int fourofakind = 0;
	int twopairs = 0; //count variable
	while (twopairs !=2 && fourofakind == false){//while there are no 4 of a kind and 2 pairs to prevent the 2 pairs being 4 of a kind
	for(int i = 0; i<=2; i++){ //goes through hand
		for(int j = 0; i<=5; j++){ //goes through table
		if(hand[i] == hand[i+1] or hand[i] == Table[j] or Table[j] == Table[j+1]){ //checks hand to hand, hand to table, and table to table for pairs
			twopairs++;
			}
		}
	}
}
if(twopairs == 2){ //if there are 2 pairs returns true
	return true;
}
	else			//if there isnt 2 pairs return flase
	return false;
}

//high card function
bool high_card(int a[5]){
	for(int i=0; i<5; i++){
		if(a[4]>a[i-1] &&
		a[4]>a[i-2 &&
		a[4]>a[i-3]] &&
		a[4]>a[i-4]){
			return true;
		}
	}
	return false;
}

//straight function
bool straight(int hand[5])
{
	int num = hand[0];
	for(short i = 1; i < 5; i++)
	{
		if(hand[i] < num )
		{
			num = hand [i];
		}
	}
 
	int num2= num + 1;
	int i = 0;
	while(i < 5)
	{
		if(hand[i] == num2)
		{
			num2++;
			i=0;
		}
		else
		{
			i++;
		}
	}
if(num2 == (num+5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//royalflush function
bool royal_flush(int hand[5]){
	for(int i = 0; i<5; i++){
		if(rankof(hand[0]) == rankof(hand[1]) and
			rankof(hand[1]) == rankof(hand[2]) and
			rankof(hand[2]) == rankof(hand[3]) and
			rankof(hand[3]) == rankof(hand[4])
		){
			int suit = rankof(hand[1]);
		}
		else{
			return false;
		}
		if(numof(hand[0]) == 0 and numof(hand[1]) == 10 and numof(hand[2]) == 11 and numof(hand[3]) == 12 and numof(hand[4]) == 9){
			return true;
		}
	}
}

//sort function
void sort(int a[5]){
int temp;
//determines size of array
int size = sizeof(a)/sizeof(a[0]);

//sorts out array from lowest to largest
for(int j=size; j>=1; j--){
	for(int i=0; i<size; i++){
		if(a[i] > a[i+1]){
		temp = a[i+1];
		a[i+1] = a[i];
		a[i] = temp;
		}
	}
}
}

//simple printdeck function
void simpleprint(int hand[5]){
	string ranks[13] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};//Stating ranks
    string suits[4] = {"Spades","Hearts","Clubs","Diamonds"};//Stating suits
    cout<<"Card 1: "<<ranks[numof(hand[0])]<<" of "<<suits[rankof(hand[0])]<<endl;
    cout<<"Card 2: "<<ranks[numof(hand[1])]<<" of "<<suits[rankof(hand[1])]<<endl;
    cout<<"Card 3: "<<ranks[numof(hand[2])]<<" of "<<suits[rankof(hand[2])]<<endl;
    cout<<"Card 4: "<<ranks[numof(hand[3])]<<" of "<<suits[rankof(hand[3])]<<endl;
    cout<<"Card 5: "<<ranks[numof(hand[4])]<<" of "<<suits[rankof(hand[4])]<<endl;
}
int main(){
	string suits[4] = {"Spades","Hearts","Clubs","Diamonds"};//Stating suits
	srand(time(0));
	bool handbool[52];
	int tempcount = 0;
	int copy[7] = {0,0,0,0,0,0,0};
	int hand[5];
	int table[5];
	for(int i = 0; i < 52; i++){
		handbool[i] = false;
	}
	for(int i = 0; i <5; i++){
		
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[i] == true);
		tempcount++;
	}
	simpleprint(hand);
	sort(hand);
	cout<<"What two cards would you like to replace? Enter card number for replacement, enter 0 for no replacement\n";
	cout<<"1st replacement: ";
	int replacement1;
	cin>>replacement1;
	cout<<"2nd replacement: ";
	int replacement2;
	cin>>replacement2;
	if(replacement1 == 0){
		cout<<"No replacement!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement1 == 1){
		tempcount = 0;
		int numb;
		numb = hand[0];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[0] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement1 == 2){
		tempcount = 1;
		int numb;
		numb = hand[1];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[1] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement1 == 3){
		tempcount = 2;
		int numb;
		numb = hand[2];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[2] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement1 == 4){
		tempcount = 3;
		int numb;
		numb = hand[3];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[3] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement1 == 5){
		tempcount = 4;
		int numb;
		numb = hand[4];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[4] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	if(replacement2 == 0){
		cout<<"No replacement!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement2 == 1){
		tempcount = 0;
		int numb;
		numb = hand[0];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[0] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement2 == 2){
		tempcount = 1;
		int numb;
		numb = hand[1];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[1] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement2 == 3){
		tempcount = 2;
		int numb;
		numb = hand[2];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[2] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement2 == 4){
		tempcount = 3;
		int numb;
		numb = hand[3];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[3] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	else if(replacement2 == 5){
		tempcount = 4;
		int numb;
		numb = hand[4];
		handbool[numb] = false;
		do{
			int num = rand() % 52;
			hand[tempcount] = num;
			table[tempcount] = num;
			handbool[num] = true;
		}while(handbool[4] == true);
		cout<<"Replacement complete!";
		cout<<endl;
		system("PAUSE");
		system("CLS");
		sort(hand);
		simpleprint(hand);
	}
	
	
	if(royal_flush(hand) == true)
		cout<<"This is a royal flush!";
	else if(straightflush(hand) == true)
		cout<<"This is a straight flush!";
	else if(fourofakind(hand) == true)
		cout<<"This is a four of a kind!";
	else if(fullhouse(handbool,copy) == true)
		cout<<"This is a fullhouse!";
	else if(flush(hand) == true)
		cout<<"This is a flush!";
	else if(straight(hand) == true)
		cout<<"This is a straight!";
	else if(threeofkind(hand) == true)
		cout<<"This is a three of a kind!";
	else if(twopair(hand,hand) == true)
		cout<<"This is a two pair!";
	else if(pairs(hand) == true)
		cout<<"This is a pair!";
	else if(high_card(hand) == true)
		cout<<"This is a highcard!";
	else
		cout<<"This is nothing!";
	
}
