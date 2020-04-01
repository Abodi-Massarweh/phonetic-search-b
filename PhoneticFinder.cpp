#include <iostream>
#include <string>
#include <cctype>
using namespace std;
namespace phonetic{
    bool same_set( int x,int y)
    {
        char a=(char) x;
        char b=(char) y;
     if(((a=='v'||a=='w')&&(b=='v'||b=='w'))||((a=='b'||a=='f'||a=='p')&&(b=='b'||b=='f'||b=='p'))
     ||((a=='g'||a=='j')&&(b=='g'||b=='j'))||((a=='c'||a=='k'||a=='q')&&(b=='c'||b=='k'||b=='q'))
     ||((a=='s'||a=='z')&&(b=='s'||b=='z'))||((a=='d'||a=='t')&&(b=='d'||b=='t'))
     ||((a=='o'||a=='u')&&(b=='o'||b=='u'))||((a=='i'||a=='y')&&(b=='i'||b=='y')))
     {
         return true;
     }
      return false;  
    }    
    bool check_similarity(string &current,string &target)
    {   int min_size;
        if(current.length()<target.length())min_size=current.length();
        else min_size=target.length();
        bool set=false;
        for (int i = 0; i < min_size; i++) {
            if((same_set(tolower(current[i]),tolower(current[i]))==false)&&(same_set(tolower(target[i]),tolower(target[i]))==false))
            {
                continue;
            }
            else if(same_set(tolower(current[i]),tolower(target[i]))==true) //belong to da same suspect set
            {
              set=true;  
            }
            else
            {
               return false;
            }
        }
        if(current.length()>target.length())
        {
            throw std::invalid_argument( "not a full word" );
        }
       
        return true;
    }
    void fix_space_start(string & str)
    {
        int counter=0;
        for (int i = 0; i < str.length()&&str[i]==' '; i++)
        {
            counter++;
        }
        str=str.substr(counter,str.length()-counter-1);
    }
    void fix_space_end(string & str)
    {
        int counter=0;
        for (int i = str.length()-1; i >= 0 &&str[i]==' '; i--)
        {
            counter++;
        }
        str=str.substr(str.length()-counter-1,counter);
    }
string find(string text,string target)
{
    if(target==""||target.find(" ")!= std::string::npos) throw std::invalid_argument( "you've entered an empty word/ a sentence" );
    bool check=false;
    string temp="";
    // if(target[0]==' ')fix_space_start(target);
    // else if(target[target.length()-1]==' ')fix_space_end(target);
    // else if(text[0]==' ')fix_space_start(text);
    // else if(text[target.length()-1]==' ')fix_space_end(text);
    for (int i = 0; i < text.length()+1; i++) {
        if(text[i]==' '||i==text.length())
        {      // if(temp.compare(" ")!=0){
               if(check_similarity(temp,target))
                {
                    return temp;
                }
       // }
            temp.clear();
        }
        else
        temp+=text[i];
    }
        throw std::invalid_argument( "not found" );
}
};
