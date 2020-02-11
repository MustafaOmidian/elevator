// elevator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
const int FLOOR_MAX = 6;
const int FLOOR_MIN = 1;
const int PASS_MAX = 10;
const int PASS_MIN = 0;
const int WEIGHT_MAX = 250;
const int WEIGHT_MIN = 0;
int PASS_NUM=0;
int GOAL_FLOOR=1;
int Current_FLOOR=0;
int PASS_WEIGHT=1;
int WHOLE_WEIGHT=0;
int Get_PASSWeight();
int Get_PASSGoal();
int Get_Current_FLOOR();
int GOAL_LENGTH;
bool Calc_Values(int PASS_NUM,int PASS_WEIGHT);
//int Move(int Current_FLOR,int GOAL_FLOR[10],int GOAL_LEGNTH,int PASS_NUM);

int main()
{
	cout<<"==========================================================="<<"\n"<<"ELEVATOR PROJECT WITH WEIGHT LIMIT CODED BY @NICOTEENE";
	cout<<"\n==========================================================="<<"\n";
	int i=0;
	int GOAL_FLO[10];
	Current_FLOOR =  Get_Current_FLOOR();
	while(GOAL_FLOOR !=0 || PASS_WEIGHT !=0)
	{
		GOAL_FLOOR = Get_PASSGoal();
		PASS_WEIGHT = Get_PASSWeight();
		WHOLE_WEIGHT += PASS_WEIGHT;
		PASS_NUM+=1;
		GOAL_FLO[i]=GOAL_FLOOR;
		i++;
		//cout<<"Goal Floor is"<<GOAL_FLOOR;
	}
	//cout<<"\n out of while";
	int GOAL_LEGNTH = i-1;
	PASS_NUM --;
	cout<<"\n Number OF Passengers is : "<<PASS_NUM<<"\n";
	cout<<"\n Whole Weight is "<<WHOLE_WEIGHT<<"\n";
	for(int i=0;i<GOAL_LEGNTH;i++)        //sort
    {
        for(int j=0;j<GOAL_LEGNTH-1;j++)
        {
            if(GOAL_FLO[j+1]>GOAL_FLO[j])
            {
                int temp=GOAL_FLO[j];
                GOAL_FLO[j]=GOAL_FLO[j+1];
                GOAL_FLO[j+1]=temp;
            }
        }
    }
	bool calc = Calc_Values(PASS_NUM,WHOLE_WEIGHT);
	//cout<<"\n calc is : "<<calc;
	//cin.get();
	if(calc==1)
	{
		cout<<"\n Values Before Start => CurrentFloor : "<<Current_FLOOR<<" , PASS NUMBER : "<<PASS_NUM;
	
	 {
		for(int i = 0 ; i<=GOAL_LEGNTH;i++)
		{
		if (Current_FLOOR>GOAL_FLO[i])
	 {
		 Current_FLOOR-=1;
		 cout<<"\n Going Down <= Now We Are In Floor "<<Current_FLOOR<<"\n";
	 }

		 if (Current_FLOOR<GOAL_FLO[i])
	 {
			 Current_FLOOR+=1;
			 cout<<"\n Going Up => Now We Are In Floor "<<Current_FLOOR<<"\n";
	}
		if (Current_FLOOR==GOAL_FLO[i])
	 {
		 cout<<"\n Time To Get Out , Passenger!We Are arrived To Floor "<<Current_FLOOR<<"\n";
		 PASS_NUM-=1;
		}}}
	 }
	cout<<"\n Its Done !!";
	while(1){ }
}
int Get_Current_FLOOR()
{
	cout<<" Please Enter Current Floor *NumberBelow6 : ";
	cin>>Current_FLOOR;
	if(Current_FLOOR>=0 && Current_FLOOR<=6)
		return Current_FLOOR;
	else
		cout<<"\n Invalid Current Floor";
	while(1){ }
};


 int Get_PASSGoal()
{
	cout<<" Please Enter Passenger Goal Floor *ToStopEnter0 *NumbersBelow6: ";
	cin>>GOAL_FLOOR;
	if(GOAL_FLOOR>0&&GOAL_FLOOR<=6)
		return GOAL_FLOOR;
	else
		return 0;
}
 int Get_PASSWeight()
 {
	cout<<" Please Enter Passenger Weight *ToStopEnter0 : ";
	cin>>PASS_WEIGHT;
	if(PASS_WEIGHT>0)
		return PASS_WEIGHT;
	else
		return 0;
 }
 bool Calc_Values(int PASS_NUM,int PASS_WEIGHT)
 {
	 if(PASS_NUM>PASS_MAX || PASS_WEIGHT>WEIGHT_MAX)
	 {
		 cout<<"\n Passenger Numbers OR Passengers Weight is Overload";
		 return false;
	 }
	 else
	 {return true;}
 }

