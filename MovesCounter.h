#pragma once

class MovesCounter // class that has all static methods which operate with private member *count*
{
private:
	static int count;
public:   
	static int IncreaseCount(); //method for increasing count by one
	static void ResetCount(); //method for reseting count (make it zero)
	static int Getcount();  //method for getting current count value
};

