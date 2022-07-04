#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string printFirst3IP(int ip[3])
{
  return to_string(ip[0]) + "." + to_string(ip[1]) + "." + to_string(ip[2]) + ".";
};

class StoreIP
{
  public:
  StoreIP(string userIP, int userIncrease);
  void printIP();

  private:
  int ip[4]={0,0,0,0};
  int increaseAm = 0;
  float result = 0;
  int trunResult = 0.;
};

StoreIP::StoreIP(string userIP, int userIncrease)
{
  for(int x = 0; x < 4; x++)
  {
    ip[x] += stoi(userIP.substr(0, userIP.find('.')));
    userIP.erase(0, userIP.find('.') + 1);
    //cout << "31 "  << userIP << endl;
    // cout << "32 " << ip[x] << endl;
    // cout << "33 " << stoi(userIP.substr(0, userIP.find('.'))) << endl;
  }
  increaseAm = userIncrease;
  result = log2(increaseAm);
  trunResult = log2(increaseAm);
  // cout << "result = " << result << endl;
  // cout << "trunResult = " << trunResult << endl;
}

void StoreIP::printIP()
{
  try
    {
      for(int i = 0; i < 3; i++)
        {
          if (ip[i] > 255 && ip[3] + increaseAm < 255)
          {
            cout << "43" << "    " << i << "     " << ip[i] << endl;
            throw(255);
          }
        }
      cout << ip[3] << endl;
      // if(ip[3] > 255)
      // {
      //   cout << "49 " << ip[3] << endl;
      //   throw(4);
      // }
      if(ip[3] + increaseAm > 255)
      {
        //redo this as a while loop
        // not sure of best way to do this
        ip[3] = ip[3] + increaseAm;
        while(ip[3] > 255)
          {
            ip[2]++;
            ip[3] -= 255;
            if(ip[2] > 255)
            {
              while(ip[2] > 255)
                {
                  ip[1]++;
                  ip[2] -= 255;
                  if(ip[1] > 255)
                  {
                    while(ip[1] > 255)
                      {
                        ip[0]++;
                        ip[1] -= 255;
                        if(ip[0] > 255)
                        {
                          throw(256);
                        }
                      }
                  }
                }
            }
          }
      }
      if(result - trunResult == 0)
      {
        for(int i = 1; i <= increaseAm; i++)
          {
            cout << printFirst3IP(ip) << ip[3] + i << endl;
          }
      }
      else
      {
        throw(-1);
      }
    }
    catch(int x)
    {
      if (x == 255)
      {
        cout << "Error number " << x << " Exception - invalid IP number." << endl;
      }
      if( x == 256)
      {
        cout << "Error number " << x << " Exception - invalid range."<< endl;
      }
      if( x == -1)
      {
        cout << "Error number" << x << " Exception - invalid increase number" << endl;
      }
      if(x == 4){
        cout << "Error number " << x << " Exception - invalid IP number." << endl;
      }
    }
}

int main() {
  int ip[4];
  string command = "";
  string ipAddress;
  int increase;
  while(command != "quit")
    {
      cout << "Please enter the ip address and the number range you want (type quit if you wish to exit)" << endl;
  getline(cin, command);
      if(command != "quit")
      {
      ipAddress = command.substr(0, command.find(" "));
      increase = stoi(command.substr(command.find(" ") + 1));
      StoreIP ipv4(ipAddress, increase);
      ipv4.printIP();
      }
    }
  return 0; 
}