#include "User.h"
//define user methods in here
//Some examples: set/get username/ user's name/password/joindate/summary
#include <stdio.h>
#include <iostream>

UserProfile::UserProfile()
{
	Username = "New";
	Password = "New";
	Name = "John Doe";
	UserID = "0000000";
	JoinDate = "00/00/1997";
	login = false;
};

UserProfile::~UserProfile()
{


};

