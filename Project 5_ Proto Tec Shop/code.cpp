/*
Task: H5
Family Name: Tong
Given Name: Bao Tran
Matriculation number: 3086478
Uni-Email: bao.tong@stud.uni-due.de
Course of Studies: ISE CE
*/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// ********************************************** TASK 1: ARTICLE  ***************************
class Article{
private:
              string model;
              float netprice, taxRate;   //taxRate in percent
public:
              Article(string imodel, float inetprice, const float itaxRate = 19):
                            model(imodel),
                            netprice(inetprice),
                            taxRate(itaxRate)
                            {}

              virtual ~Article(){
                          cout<<" ~Article() "<<model<<endl;
              }

              void set_model(string imodel){
                            model=imodel;
              }

              void set_netPrice(float inetprice){
                            netprice=inetprice;
              }

              string get_model(){
                            return model;
              }

              float get_netPrice(){
                            return netprice;
              }

              float get_grossPrice(){
                            return netprice*(1+ taxRate/100);
              }

             void virtual print()=0;
};


// ******************************************* TASK 2: ACCESSORY  ***************************
class Accessory: public Article{
private:
              bool original;
public:
              Accessory(string imodel, float inetprice, bool ioriginal=true):
                            Article(imodel,inetprice),
                            original(ioriginal)
                            {}
              virtual ~Accessory(){
                          cout<<" ~Accessory() ";
              }

              virtual void print(){
                            cout<<Article::get_model();
                            if (original) {
                                 cout<<" (original accessory)";
                            }
              }

};


// *********************************************** TASK 3: OPERATING SYTEM  ***************************
enum class OperatingSystem{
              unknown ,
              android,
              iOS,
              macOS,
              linux,
              proprietary,
              unix,
              windows
};


ostream& operator<< (ostream& out, OperatingSystem op)
{
    switch(op)
    {
        case (OperatingSystem::unknown) : return out << "unknown OS" ;
        case (OperatingSystem::android) : return out << "Android OS" ;
        case (OperatingSystem::iOS) : return out << "iOS" ;
        case (OperatingSystem::macOS) : return out << "MacOS" ;
        case (OperatingSystem::linux) : return out << "Linux OS" ;
        case (OperatingSystem::unix) : return out << "Unix OS" ;
        case (OperatingSystem::proprietary) : return out << "proprietary OS" ;
        case (OperatingSystem::windows) : return out << "MS Windows OS" ;
    }
}


// ***************************************************** TASK 4: DEVICE  ***************************

class Device: public Article{
private:
              int main_memory;
              OperatingSystem os;
public:
              Device(string imodel, float inetprice, int isize, OperatingSystem op=OperatingSystem::unknown):
                            Article(imodel,inetprice),
                            main_memory(isize),
                            os(op)
                            {}

              virtual ~Device(){
                          cout<<" ~Device() ";
              }

              OperatingSystem get_os(){
                            return os;
              }

              virtual void print(){
                            cout<<Article::get_model()<<", RAM "<<main_memory<<"GB, "<<get_os();
              }

};

// ******************************************** TASK 5: NOTEBOOK  ***************************
class Notebook: public Device{
private:
              string drive;
              bool convertible;
public:
              Notebook(string imodel, float inetprice, int isize, string idrive, OperatingSystem op=OperatingSystem::linux, bool iconvertible=false):
                            Device(imodel,inetprice,isize,op),
                            drive(idrive),
                            convertible(iconvertible)
                            {}

              virtual ~Notebook(){
                          cout<<" ~Notebook() ";
              }


              bool is_a_convertible(){
                            if (convertible) return true;
                            else return false;
              }

              void virtual print(){
                            Device::print();
                            if (is_a_convertible())
                                          {cout<<" (convertible), ";}
                            cout<<drive<<endl;
              }

};

// *********************************************************** TASK 6: PHONE  ***************************
class Phone: public Device{
public:
              Phone(string imodel, float inetprice, int isize=4, OperatingSystem op=OperatingSystem::android):
                            Device(imodel,inetprice,isize,op)
                            {}

              virtual ~Phone(){
                          cout<<" ~Phone() ";
              }

              void virtual print(){
                            Device::print();
                            cout<<" phone"<<endl;
              }

};

// ******************************************************** TASK 7: INCART  ***************************
class InCart{
private:
              Article *article;
              int amount;
              InCart *next;
public:
              InCart(Article *iarticle, int iamount=0, InCart *inext=nullptr):
                            article(iarticle),
                            amount(iamount),
                            next(inext)
                            {}


              virtual ~InCart(){
                            cout<<" ~InCart() "<<amount;
                            delete article;
              }


              InCart* get_next(){
                            return this->next;
              }


              void print(){
                            cout<<" "<<amount<<" ";
                            article->print();
                            cout<<endl;
                            cout<<left<<setw(63)<<setfill(' ')<<right<<fixed <<setprecision(2)<<article->get_grossPrice()<<" EUR";
                            cout<<left<<setw(20)<<setfill(' ')<<right<<fixed <<setprecision(2)<<amount*article->get_grossPrice()<<" EUR"<<endl;
              }
};



// ********************************************** TASK 8: SHOPPINGCART  ***************************
class ShoppingCart{
private:
              InCart *articles;
              float minFressShipping, sumNetPrice, sumGrossPrice;
public:
              ShoppingCart():
                            articles(nullptr),
                            minFressShipping(1000),
                            sumNetPrice(0),
                            sumGrossPrice(0)
                            {}


              ~ShoppingCart(){
                            cout<<" ~ShoppingCart() "<<endl;
                            InCart *current = articles; //current is at the beginning of linked List InCart
                            InCart* next_article;
                            while (current != nullptr)
                                          {
                                              next_article = current->get_next();
                                              cout<<" delete article: ";
                                              delete current;
                                              current = next_article;
                                          }
                            }


              void set_minFreeShipping(float iminFressShipping){
                            minFressShipping=iminFressShipping;
              }

              void add_article(int iamount, Article *new_article){
                            InCart *temp= new InCart(new_article,iamount,articles);
                            articles = temp;
                            sumNetPrice += iamount*new_article->get_netPrice();
                            sumGrossPrice += iamount*new_article->get_grossPrice();
                            }

              void print(){
                            cout<<setw(92)<<setfill('+')<<"+"<<endl;
                            cout<<"+"<<setw(58)<<right<<setfill(' ')<<"P R O T O - T E C - S H O P"<<setw(33)<<right<<"+"<<endl;
                            cout<<"+"<<setw(61)<<right<<setfill(' ')<<"Y O U R   S H O P P I N G C A R T"<<setw(30)<<right<<"+"<<endl;
                            cout<<setw(92)<<setfill('+')<<"+"<<endl;

                            InCart *current = articles; //current is at the beginning of linked List InCart
                                          while (current != nullptr)
                                          {
                                              current->print();
                                              current = current->get_next();
                                          }

                            cout<<setw(91)<<setfill(' ')<<"-------------"<<endl;
                            cout<<setw(76)<<right<<"sum net price:"<<setw(10)<<right<<sumNetPrice<<"  EUR"<<endl;
                            cout<<setw(76)<<right<<"tax:"<<setw(10)<<right<<sumGrossPrice-sumNetPrice<<"  EUR"<<endl;
                            cout<<setw(76)<<right<<"sum gross price:"<<setw(10)<<right<<sumGrossPrice<<"  EUR"<<endl;
                            cout<<setw(91)<<setfill(' ')<<"-------------"<<endl;
                            if (sumGrossPrice>= minFressShipping)
                                          {cout<<setw(76)<<right<<"shipping:"<<setw(10)<<right<<"0.00"<<"  EUR"<<endl;}
                            else
                                          {cout<<setw(76)<<right<<"shipping:"<<setw(10)<<right<<"5.90"<<"  EUR"<<endl;}
                            cout<<setw(91)<<setfill(' ')<<"-------------"<<endl;
                            cout<<setw(76)<<right<<"total:"<<setw(10)<<right<<sumGrossPrice+5.9<<"  EUR"<<endl;
                            cout<<setw(91)<<setfill(' ')<<"============="<<endl<<endl<<endl;
              }
};

// ****************************************** TASK 9: MAIN FUNCTION  ***************************
int main()
{
    Accessory *first_article= new Accessory("YOOLOX 10k Wireless Powerbank Qi", 31.08, false);
    Phone *second_article= new Phone("Samsung Galaxy S10+ SM-G975F/DS Dual SIM",661.67,8, OperatingSystem::android);
    Phone *third_article= new  Phone("Apple iPhone 11 Pro 256GB",1097.47,4,OperatingSystem::iOS);
    Notebook *forth_article= new Notebook("ASUS ROG Strix Scar III G731", 1586.55, 16, "512GB SSD + 1TB SSHD", OperatingSystem::windows, true);

    ShoppingCart shoppingcart;
    shoppingcart.set_minFreeShipping(500);
    shoppingcart.add_article(3,first_article);
    shoppingcart.print();

    shoppingcart.add_article(1,second_article);
    shoppingcart.add_article(2,third_article);
    shoppingcart.add_article(1, forth_article);
    shoppingcart.print();
    return 0;
}
