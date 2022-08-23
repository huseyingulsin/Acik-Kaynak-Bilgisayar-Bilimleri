#include <iostream> // used for cout
#include <string>   // used for string
#include <vector>   // used for vector
#include <fstream>  // used for file I/O
#include <algorithm>// used for reverse algorithm

using namespace std; // neccessary for using some functions without spacifyng std in their front.

class Relation // My class for this set
{
private:
    /* data */
    int pairNum;
    string elements;        // elements in the set
    vector<string> pairs;   // pairs in relation
    string info = "Yes, all elements are present.";   // keep info for writing file
    
public:
    bool setValues(ifstream&);      // read data from file
    void writeValues(ofstream&);    // write finding values to file 
    bool checkValid() const;        // check if there is invalid element or pair in givens
    bool reflexive();               // check reflexie, if true return true
    bool symmetric();               // check symatric, if true return true
    bool antisymmetric();           // check antisymatric, if true return true
    bool transitive();              // check transitive, if true return true
    void setInfo(string info){this->info = info;}; // inline function, assign value to string

};

bool Relation::setValues(ifstream& fp)
{

    fp >> pairNum;          // read file and get pairNum
    fp >> elements;         // read file and get element in string
    if(elements.size() == 0) return false; // if elemnets == 0, return false it means there is nothing, it is end of file

    for (int i = 0; i < pairNum; i++)       // go to all pairs with file input 
    {
        string temp;
        fp >> temp;
        pairs.push_back(temp);      // add temp to pairs list
    }

    return true;
}

void Relation::writeValues(ofstream& fp)
{
    fp << "n" << endl;                  // starting spacifier

    for (int i = 0; i < pairNum; i++)   // print all pairs of element in file
        fp << "(" << pairs[i] << ") ";
    fp << endl;

    fp <<  "Reflexive: ";                   // write name of method, and execute function
    if (reflexive()) fp << info << endl;
    else             fp << info << endl;
    fp << "Symmetric: ";
    if (symmetric()) fp << info << endl;
    else             fp << info << endl;
    fp << "Antisymmetric: ";
    if (antisymmetric()) fp << info << endl;
    else                 fp << info << endl;
    fp << "Transitive: ";
    if (transitive()) fp << info << endl;
    else              fp << info << endl;

    return;
}

bool Relation::checkValid() const
{
    int elemenetSize = elements.size();         // take size of the elemenets
    bool left = true, right = true;             // create values
    for (int i = 0; i < pairNum; i++)           // check for every pair
    {
        if (!left || !right) break;             // if nothing of them is false, than break.
        for (int j = 0; j < elemenetSize; j+=2) // go trough all elements
        {
            
            if (pairs[i][0] == elements[j])         // check for left
            {
                left = true;                        // if all is well, than assign true and break the loop
                break;
            }
            else
                left = false;
        }
        for (int j = 0; j < elemenetSize; j+=2)        // same as left part
        {
            if (pairs[i][2] == elements[j])
            {
                right = true;
                break;
            }
            else
                right = false;
        }
    }
    if (!left || !right) return false;      // if one of them is not containing elemenets, it returns false
    else return true;
}

bool Relation::reflexive()
{
    int checkValue = 0;
    int elementNum = (elements.size() + 1) / 2;   // it contains "," so from that it could find.
    string tempElements = elements;         // create temp elements for keeeping value
    for (int i = 0; i < pairNum; i++)
        if (pairs[i][0] == pairs[i][2])  // remove char from string operation
            tempElements.erase(remove(tempElements.begin(), tempElements.end(), pairs[i][0]), tempElements.end());

    if (tempElements.size() == elementNum - 1) return true;     // still nothing is bad, than return true;
    else
    {
        string found;               
        for (int i = 0; i < tempElements.size(); i++)           // look for which element is not found and write it
            if (tempElements[i] != ',')
                found = tempElements[i];

        string tmp = "(" +found+ "," +found+ ")";
        setInfo("No, " +tmp +  " is not found");
        return false;  
    } 
}

bool Relation::symmetric()
{
    string reversePair = "";
    int checkValue = 0; int goodValue = 0; int flag = 0;
    for (int i = 0; i < pairNum; i++)
    {
        if (checkValue != 0) break;                     // if value is not zero than break the loop
        if (pairs[i][0] == pairs[i][2]) continue;       // if elemetns is (x,x), look next elemenet
        reversePair = ""; reversePair += pairs[i][2];   // reverse method
        reversePair += ','; reversePair += pairs[i][0];
        for (int j = 0; j < pairNum; j++)               // itearate on all pairs
            if (j != i)
            {
                if (reversePair == pairs[j])        // if it matches with a reverse string
                {
                    if (flag == 0)                  // define some values for using later
                    {
                        goodValue = i; flag = 1;
                    }
                    checkValue = 0;
                    break;
                }

                else checkValue = i;            // there is nothing to match than it means it is not smyetric
            }
    }
    if (checkValue == 0)
    {
        reversePair = ""; reversePair += pairs[goodValue][2];
        reversePair += ','; reversePair += pairs[goodValue][0]; // reverse the string again.

        if (pairs[goodValue][0] != pairs[goodValue][2])     // look for reverse item and print
            setInfo("Yes, (" + reversePair + ") is found where (" + pairs[goodValue] + ") is found and all other values adapt this rule.");
        else
            setInfo("Yes, because all values are reflexive.");
        return true;
    }
    else
    {
        setInfo("No, (" + reversePair + ") is not found where (" + pairs[checkValue] + ") is found.");
        return false;
    }
     
}

bool Relation::antisymmetric()
{
                                                // SAME AS SMYETRIC
    string reversePair = "";
    int checkValue = 0; int goodValue = 0; int flag = 0;
    for (int i = 0; i < pairNum; i++)
    {
        if (checkValue != 0) break;
        if (pairs[i][0] == pairs[i][2]) continue;
        reversePair = "";  reversePair += pairs[i][2];  
        reversePair += ','; reversePair += pairs[i][0];
        for (int j = 0; j < pairNum; j++)
            if (j != i)
            {
                if (reversePair != pairs[j])
                {
                    if (flag == 0)
                    {
                        goodValue = i, flag = 1;
                    }
                    checkValue = 0;
                }
                else 
                {
                    checkValue = i;
                    break;
                }
            }
    }
    if (checkValue == 0)
    {
        reversePair = "";  reversePair += pairs[goodValue][2];  
        reversePair += ','; reversePair += pairs[goodValue][0];
        if (pairs[goodValue][0] != pairs[goodValue][2])
            setInfo("Yes, (" + reversePair + ") is not found where (" + pairs[goodValue] + ") is found and all other values adapt this rule.");
        else
            setInfo("Yes, because all values are reflexive.");
        return true;
    }
    else
    {
        setInfo("No, (" + reversePair + ") is found where (" + pairs[checkValue] + ") is found");
        return false;
    }
}

bool Relation::transitive()
{
    string temp;
    int checkValue[3] = {}; int goodValue[3] = {}; int flag = 0; // create a int array for keeping 3 value
    for (int i = 0; i < pairNum; i++)
    {
        if (checkValue[0] != 0) break;          // if value is not zero than break;
        if (pairs[i] [0] == pairs[i][2]) continue;  // if values are reflexive than skip
        
        for (int j = 0; j < pairNum; j++)
        {
            if (pairs[j][0] == pairs[j][2]) continue; // if values are reflexive than skip

            if (pairs[i][2] == pairs[j][0]) // if both are equals than do
            {
                char tempLeft = pairs[i][0];
                char tempRight = pairs[j][2];
                for (int k = 0; k < pairNum; k++)
                {
                    if (pairs[k][0] == tempLeft && pairs[k][2] == tempRight) // if all is well than do some assignments and break
                    {
                        checkValue[0] = 0;
                        if (flag == 0)
                        {
                            flag = 1;
                            goodValue[0] = i; goodValue[1] = j; goodValue[2] = k;
                        }
                        break;
                    }
                    else        // if there is a problem for being transitive, than asign values for printing.
                    {
                        checkValue[0] = i; checkValue[1] = j; checkValue[2] = k;
                    }
                }
            }
        }
    }
    if (checkValue[0] == 0)     // if this value not changed and keeped like this, this means all is well.
    {
        if (goodValue[0] == 0 && goodValue[1] == 0 && goodValue[2] == 0)        // printing sequences for printing more clever.
            setInfo("Yes, because all values are reflexive.");
        else
            setInfo("Yes, (" + pairs[goodValue[2]] + ") is found where (" + pairs[goodValue[0]] + ") and (" + pairs[goodValue[1]]  + ") are found");
        return true;
    }
    else
    {
        string found0; found0.push_back(pairs[checkValue[0]][0]);
        string found1; found1.push_back(pairs[checkValue[1]][2]);
        string tmp = "(" +found0+ "," +found1+ ")";     // for converting chars to a string. It works properly like this.
        setInfo("No, " + tmp + " is not found where (" + pairs[checkValue[0]] + ") and (" + pairs[checkValue[1]]  + ") are found");
        return false;
    }
}

int main(void)
{
    vector<Relation> relations;                 // create a vector of myClass
    ifstream fp("input.txt");                   // open input.txt
	if(!fp)                                     // if file can not oppened than give error
    {
		cerr << "Couldn't open file.\n";
		return -1;
	}
    while(true)
    {
        Relation temp;                          // create temp class object
        if(!temp.setValues(fp))                 // read values and assign to temp
            break;                              // If EOF than break
        if(!temp.checkValid())                  // if there is an error, write help massage and quit
        {
            cerr << "There is invalid value in set. Quiting..." << endl;
            return -1;
        }
        relations.push_back(temp);              // add to vecor of myObjct
    }
    fp.close();                 // close file reading pointer

    cout << "File Succesfully Readed." << endl;

    ofstream fp_write("output.txt");            // open output in writing mode.
    if(!fp_write)
    {
		cerr << "Couldn't open file.\n";
		return -1;
	}

    for (int i = 0; i < relations.size(); i++)          // write all values to file with for loop
        relations[i].writeValues(fp_write);

    fp_write.close();                                   // file succesfly created probably.

    cout << "File Succesfully Created. " << endl;

    return 0;
}
