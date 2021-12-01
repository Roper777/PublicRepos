#pragma once
#include <iostream>
#include <stdio.h>

class UserProfile
{
public:
	UserProfile();
	~UserProfile();
	std::string getID();
	void setID(std::string input);
	std::string getUsername();
	void setUsername(std::string input);
	std::string getName();
	void setName(std::string input);
	std::string getJoinDate();
	void setJoinDate(std::string input);
	void alterLogin();
	bool getLogin();


private:
	std::string Username; //Display name that a user 
	std::string Password; //Password for user to login to their corresponding profile, paired with username
	std::string Name; //user's real name
	std::string UserID; //seven digit code unique to users
	std::string JoinDate; // date the user profile was created.
	bool login = false; //denotes whether this profile is logged in or not.
};
