
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


struct Entry{
   string key;
   string value;
};


//Function prototype
int hashindex(string t, int p);
int Insert(string german, string english, Entry Dictionary[], int p);
void Translate(string german, Entry Dictionary[], int p);
int CreateDict(string filename, Entry Dictionary[], int p);


//****************   TASK 6: MAIN FUNCTION ****************
int main()
{
    //Initialize hash table
    int p;
    cout<<"please input value for (prime) number p: ";
    cin>>p;
    Entry Dictionary[p];

    //Importing data from file to hash table
    string filename = "tiere_animals.txt";
    cout<<filename<<" opened..."<<endl;
    int total_collision=CreateDict(filename,Dictionary,p);
    cout<<filename<<" closed..."<<endl;
    cout<<total_collision<<" collision(s) during insert"<<endl;
    cout<<endl;


   // Outputting our dictionary
   cout<<"******  GERMAN - ENGLISH DICTIONARY  ******"<<endl;
    int count_entries=0;
        for (int i=0; i<p; i++){
              if (Dictionary[i].key.compare("")!=0)
              {
                            cout<<i<<":  "<<Dictionary[i].key<<" -> "<<Dictionary[i].value<<endl;
                            count_entries+=1;
              }
                }
              cout<<count_entries<<" entries in array"<<endl;
              cout<<endl;


    //Translate words
    cout<<"******  PLEASE ENTER A WORD TO BE TRANSLATED  ******"<<endl;
    string word_to_translate="";
      do {
         cout << "translate (0 for end): ";
         cin>>word_to_translate;
         if (word_to_translate.compare("0")==0) break;
         Translate(word_to_translate,Dictionary, p);
       } while (word_to_translate.compare("0")!=0);

    return 0;
}

//****************   TASK 2: FUNCTION H(t) ****************
int hashindex(string t, int p){
    int strlength= t.length();
    int index=int(t[0]);
    for (int i=0; i<strlength-1;i++)
              {
                 index=(index*128+int(t[i+1])) % p;
              };
    return index;
};

//****************   TASK 3: FUNCTION TO INSERT ENTRY INTO HASH TABLE ****************
int Insert(string german, string english, Entry Dictionary[], int p){
          int original_index=hashindex(german,p);
          int index=original_index;
          int collision_count=0;
          cout<<"insert: "<<german<<" -> "<<english<< " at index: "<<original_index<<endl;
          bool inserted;
          if (Dictionary[original_index].key.length()==0){
                              Dictionary[original_index].key=german;
                              Dictionary[original_index].value=english;
                              inserted=true;
                                      }
          else{
              while (!inserted){
                 if (Dictionary[index].key.length()==0){
                       Dictionary[index].key=german;
                       Dictionary[index].value=english;
                       inserted=true;
                       cout<<"        linear collision strategy results with index: "<<index<<endl;
                                  }
                 else{
                     inserted=false;
                     collision_count+=1;
                     cout<<"        collision with "<<Dictionary[index].key<<endl;
                     index+=1;
                     if (index>p-1){
                        index=0;
                     }
                     }
                                }
              }
return collision_count;
}

//****************   TASK 4: FUNCTION TO SEARCH AND TRANSLATE ****************
void Translate(string german, Entry Dictionary[], int p){
              bool found=false;
              string english="";
              int index=0;
              while (index<=p && !found){
                      if(Dictionary[index].key.compare(german) ==0) {
                          found = true;
                          english= Dictionary[index].value;}
                      else index+=1;
                            }
              if (english.length()==0){
                  cout<< "sorry not known"<<endl;
              }
              else cout<<german<<" -> "<<english<<endl;
}
//****************   TASK 5: FUNCTION TO INSERT VOCAB FROM FILE TO HASH TABLE ****************
int CreateDict(string filename, Entry Dictionary[], int p)
{
  ifstream inputFile;
  inputFile.open(filename);
  string wordpair, german, english;
  int total_collision=0;
  int sub_collision;
  if(!inputFile.is_open()){
   cout << "Cannot open File\n";
   exit(1);
  }
   else{
     while (! inputFile.eof()) {
              getline(inputFile,wordpair);
              german   = wordpair.substr(0, wordpair.find(";")); ;
              english  =  wordpair.substr(wordpair.find(";") + 1);
              sub_collision=Insert(german, english, Dictionary,p);
              total_collision+=sub_collision;
              }
       }
    inputFile.close();
    return total_collision;
}

