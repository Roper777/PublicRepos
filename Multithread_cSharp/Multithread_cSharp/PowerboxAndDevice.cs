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
            
            public int GetMax()
            {
                return max; 
            }

            public void EditCurrent(int input, char method) //a bit more complex 'setCurrent', so I tried to name it to fit this.
            {
                Boolean executed = false;
                do
                {
                    if (method == 'p' && (input + current) <= max) //if we are adding the input number to the current, take this branch
                    {
                        current += input;
                        executed = true;
                    }


                    else if (method == 'm') // if we subtract the input number from the current, take this branch
                    {
                        current -= input;
                        executed = true;
                    }

                    else if (method != 'm' || method != 'p')
                    {
                        Console.WriteLine("Uh oh. Oh no. Invalid character received. Ending program due to bug.");
                        System.Environment.Exit(1);
                        break;
                    }
                    else
                    {
                        Console.Write("Due to the current electrical load, we cannot turn this device on! We'll have to wait on the other devices to finish up.\n");

                    }
                } while (executed == false);
            }

            public int GetCurrent()
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

        public void SetName(string name)
        {
            deviceName = name;
        }

        public string GetName()
        {
            return deviceName;
        }

        public void SetReq(int req)
        {
            powerReq = req;
        }

        public int GetReq()
        {
            return powerReq;
        }

        public void SetTime(int time)
        {
            runTime = time;
        }

        public int GetTime()
        {
            return runTime;
        }


        public Device()
        {
            Console.WriteLine("New device being created... Please give the device a name.");
            deviceName = Console.ReadLine();
            Boolean valid = false;
            while (valid == false)
            {
                Console.WriteLine("Device named '[0]'. Select a power usage between: 375 (A), 560 (B), or 721 (C). Type A, B, or C (Case Sensitive).", deviceName);

                char nrgInput = Console.ReadLine()[0];
                Console.Write($"You inputted {nrgInput}. ");
                switch (nrgInput)
                {
                    case 'A':
                        Console.WriteLine("This device will use 375 power.");
                        powerReq = 375;
                        valid = true;
                        break;
                    case 'B':
                        Console.WriteLine("This device will use 560 power.");
                        powerReq = 560;
                        valid = true;
                        break;
                    case 'C':
                        Console.WriteLine("This device will use 721 power.");
                        powerReq = 721;
                        valid = true;
                        break;
                    default:
                        Console.WriteLine("You did not input a valid answer. Perhaps it wasn't capitalized?");
                        break;
                }
            }
        }
        public void SwitchFinishState()
        {
            if (finished == false)
                finished = true;
            else if (finished == true)
                finished = false;
        }

        //public void SetPostion(int pos)
        //{
        //    linePosition = pos;
        //    Console.WriteLine("Device named '{0}' is now in position {1} and waiting for availability.", deviceName, linePosition);
        //}

        //public int GetPosition()
        //{
        //    return linePosition;
        //}

        public void updatePosition()
        {
            switch (linePosition)
            {
                case 0:
                    Console.WriteLine("This isn't waiting at all. We'll just progress normally.");
                    break;
                case 1:
                    Console.WriteLine("Time to set this one to be next!");
                    linePosition = 0;
                    break;
                case linePosition >= 2:

                    break;
            }
            // These end up not being used due to the numbers I chose, but I'm keeping them in if I want to add more devices to be active

        public int grab


    }
}
