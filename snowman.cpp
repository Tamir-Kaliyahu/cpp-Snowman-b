#include <iostream>
#include <string>
#include <array>
#include "snowman.hpp"

namespace ariel{
    
const int hatUsr = 0;
const int noseUsr = 1;
const int leftEyeUsr = 2;
const int rightEyeUsr = 3;
const int leftHandUsr = 4;
const int rightHandUsr = 5;
const int torsoUsr = 6;
const int baseUsr = 7;

const int userMin=11111111;
const int userMax=44444444;
const int hatIndex= 0;
const int noseIndex = 1;
const int leftEye = 2;
const int rightEye = 3;
const int leftHandUp = 4;
const int leftHandDown = 5;
const int rightHandUp = 6;
const int rightHandDown = 7;
const int torsoIndex = 8;
const int baseIndex = 9;
const int ten = 10;
const int numParts = 10;
const int numOfLines = 4;
const int NumOptions = 4;
const int DigSize = 8;
const int row1= 0;
const int row2= 1;
const int row3= 2;
const int row4= 3;

const int zero = 0;
const int one = 1;


string snowman(int userInput)
{
    if(userInput<userMin || userInput>userMax)
    {
        throw invalid_argument("not a valid input!");
        return "";
    }
    std :: array <int,DigSize> userChoise={};
    int temp=0;
    int temp2=0;
    for (int i = 0; i < DigSize; i++)
    {
        temp = userInput%ten;
        if(temp<1||temp>4)
        {
            throw invalid_argument("not a valid input!");
            return "";
        }
        userChoise.at(DigSize-i-1)= temp;
        temp2=userInput/ten;
        userInput=temp2;
    }
    // for (int i = 0; i < DigSize; i++)
    // {
    //     cout << "user(i) = ";
    //     cout << userChoise.at(i)<< endl;
    // }
    
    
    std::array<string, NumOptions>Hat = { "_===_", " ___\n.....","  _  \n /_\\ ", " ___ \n(_*_)" };
    std::array<string, NumOptions>SpaceHat = { " _===_", "  ___\n .....","   _  \n  /_\\ ", "  ___ \n (_*_)" };
    std::array<string, NumOptions>Nose = { ",", ".","_", " " };
    std::array<string, NumOptions>Eye = { ".", "o","O", "-" };
    std::array<string, NumOptions>Lup = { " ", "\\"," ", "" }; //if space
    std::array<string, NumOptions>Ldn = { "<", " ","/", "" };
    std::array<string, NumOptions>Rup = { " ", "/"," ", " " };
    std::array<string, NumOptions>Rdn = { ">", " ","\\", " " };
    std::array<string, NumOptions>Torso = { " : ", "] [","> <", "   " };
    std::array<string, NumOptions>Base = { " : ", "\" \"", "___", "   " };
    std::array<string, numParts> SnowParts;
    SnowParts.at(hatIndex) = Hat.at(userChoise.at(hatUsr)-one);
    SnowParts [noseIndex] = Nose.at(userChoise[noseUsr]-one);
    SnowParts [rightEye] = Eye.at(userChoise[rightEyeUsr]-one);
    SnowParts [leftEye] = Eye.at(userChoise[leftEyeUsr]-one);
    SnowParts [leftHandUp] = Lup.at(userChoise[leftHandUsr]-one); //for Lup
    SnowParts [leftHandDown] = Ldn.at(userChoise[leftHandUsr]-one);//for Ldn
    SnowParts [rightHandUp] = Rup.at(userChoise[rightHandUsr]-one);// for Rup
    SnowParts [rightHandDown] = Rdn.at(userChoise[rightHandUsr]-one);// for Rdn
    SnowParts [torsoIndex] = Torso.at(userChoise[torsoUsr]-one);
    SnowParts [baseIndex] = Base.at(userChoise[baseUsr]-one);
    std::array<string, numOfLines> lines={"","","",""};
    if(userChoise[leftHandUsr]!=4)
    {
        SnowParts.at(hatIndex) = SpaceHat.at(userChoise.at(hatUsr)-one);
        lines[row4]=" ";
    }
    lines[row1]=SnowParts[hatIndex];
    lines[row2]=SnowParts[leftHandUp]+"("+SnowParts[leftEye]+SnowParts[noseIndex]+SnowParts[rightEye]+")"+SnowParts[rightHandUp];
    lines[row3]=SnowParts[leftHandDown]+"("+SnowParts[torsoIndex]+")"+SnowParts[rightHandDown];
    lines[row4]+="("+SnowParts[baseIndex]+")";
    
    std :: string ans;
    for (int i = 0; i < numOfLines; i++)
        {
            ans+=lines.at(i)+"\n"; 
        }
    return ans;
}

int goSnowman()
{
    int ans=0;
    int temp=0;
    cout << "In order to build your snowman please select eight parts: (1 to 4)" <<endl ;

    cout << "please choose a hat from the following:"<< endl;
    cout << "1. Straw Hat :\n _===_ \n2. Mexican Hat :\n  ___\n..... \n3. Fez :\n  _  \n /_\\ \n4. Russian Hat :\n  ___ \n(_*_)" <<endl;
    cin >> temp;
    ans = ans*ten+temp;

    cout << "please choose a nose from the following:"<< endl;
    cout << "1. Normal:\n , \n2. Dot:\n . \n3. Line \n _ \n4. None:\n \" \" "<<endl;
    cin >> temp;
    ans = ans*ten+temp;

    cout << "please choose a left Eye from the following:"<< endl;
    cout << "1. Dot:\n . \n2. Bigger Dot:\n o \n3. Biggest Dot \n O \n4. Closed:\n - "<<endl;
    cin >> temp;
    
    ans = ans*ten+temp;

    cout << "please choose a right Eye from the following:"<< endl;
    cout << "1. Dot:\n . \n2. Bigger Dot:\n o \n3. Biggest Dot \n O \n4. Closed:\n - "<<endl;
    cin >> temp;
    ans = ans*ten+temp;

    cout << "please choose a left hand from the following:"<< endl;
    cout << "1. Normal Arm:\n  \n < \n2. Upwards Arm:\n \\ \n \n3. Downwards Arm: \n \n / \n4. None:\n \n "<<endl;
    cin >> temp;
    ans = ans*ten+temp;

    cout << "please choose a right hand from the following:"<< endl;
    cout << "1. Normal Arm:\n  \n > \n2. Upwards Arm:\n  / \n \n3. Downwards Arm: \n \n \\ \n4. None:\n \n "<<endl;
    cin >> temp;
    ans = ans*ten+temp;
    
    cout << "please choose a torso from the following:"<< endl;
    cout << "1. Buttons:\n : \n2. Vest:\n ][ \n3. Inward Arms \n > < \n4. None:\n  "<<endl;
    cin >> temp;
    ans = ans*ten+temp;

    cout << "please choose a base from the following:"<< endl;
    cout << "1. Buttons:\n : \n2. Feet: \n \" \" \n3. Flat \n ___ \n4. None:\n   "<<endl;
    cin >> temp;
    ans = ans*ten+temp;

    cout << "finishing...  your choise was:";
    cout << ans <<endl;
    return ans;
}
};
