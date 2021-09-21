using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

//This is where I will be defining the methods and variables used in the Powerbox class.
//A variable, the 'PowerBox' will keep track of how much power is being drawn from it by multiple devices


namespace Multithread_cSharp
{
    class Powerbox
    {
            int max = 5730; // Represents the max amount of power we can distribute to multiple processes
            int current = 0; //tracks current amount of power being used.
            Boolean full = false;
            public int getMax()
            {
                return max;
            }

            public void editCurrent(int input, char method) //a bit more complex 'setCurrent', so I tried to name it to fit this.
            { 
                if((input + current) <= max)
                { 
                    if(method == 'p') //if we are adding the input number to the current, take this branch
                    {
                        current += input;
                    }

                    else if(method == 'm') // if we subtract the input number from the current, take this branch
                    {
                        current -= input;
                    }

                    else
                    {
                        Console.WriteLine("Invalid character received. Ending program due to bug.");
                        System.Environment.Exit(1);
                    }
                }

                else
                {
                    Console.Write("Due to the current electrical load, we cannot turn this device on! We can wait or reset the box. \n");
                    Console.WriteLine("What would you like to do? (Enter 0 to wait, or 1 to reset.");
                }
            }

            public int getCurrent()
            {
                return current;
            }

            public Boolean limitChecker() // compare max and current
            {
                if(max == current)
                {
                    full = true;
                    Console.WriteLine("We've hit the limit on power! Any additional processes will now have to wait, or the box must be reset.");
                    return full;
                }
                else
                {
                    return full;
                }
            }
    }



    class Device
    {
        string deviceName = "Filler";
        int powerReq; // this will hold the amount of power the object requires to function
        int runTime; //holds the amount of time the device takes to complete.
        int linePosition = 0; // if we have to start waiting on processes
        Boolean finished = false;

        public void setName(string name)
        {
            deviceName = name;
        }

        public string getName()
        {
            return deviceName;
        }

        public void setReq(int req)
        {
            powerReq = req;
        }

        public int getReq()
        {
            return powerReq;
        }

        public void setTime(int time)
        {
            runTime = time;
        }

        public int getTime()
        {
            return runTime;
        }


        public void set
        public void switchFinishState()
        {
            if (finished == false)
                finished = true;
            else if (finished == true)
                finished = false;
        }

        public void setPostion(int pos)
        {
            linePosition = pos;
            Console.WriteLine("Device named '{0}' is now in position {1}.", deviceName, linePosition);
        }

        public int getPosition()
        {
            return linePosition;
        }

    }
}
