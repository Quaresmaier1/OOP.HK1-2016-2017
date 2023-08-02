#include <iostream>
using namespace std;

class gate{
public:
    virtual float checknumber(float number)=0;
    gate(){};
    ~gate(){};

};
class academic: public gate{
 private:
    float brain;
 public:
    academic(float b){brain=b;};
    float checknumber(float bpp);

};
float academic::checknumber(float bpp)
{
    if(bpp>=this->brain){
        return bpp;}


}

class business: public gate{
private:
    float ca,bill;
public:
    business(float c,float b){ca=c;bill=b;};
    float checknumber(float goods);

};

float business::checknumber(float goods){
    return goods - (this->ca * this->bill);
}


class power: public gate{
private:
    float pP;
public:
    power(float p){pP=p;};
    float checknumber(float pop);

};
float power::checknumber(float pop){
    return pop - this->pP;
}

void nhap(float&cash, float& bpp,float& pop,int& Listofgate,gate**&block){
cout<<"Input number of gate: "<<endl;
cin>>Listofgate;
block = new gate*[Listofgate];
for(int i=0; i<Listofgate;i++){
    char type;
    cout<<"Input type of gate: "<<"(B/A/P)"<<endl;
    cin>>type;
    if(type=='B'||type=='b'){
        float g,b;
        cout<<"Input goods: ";
        cin>>g;
        cout<<"Input bill: ";
        cin>>b;
        block[i]=new business(g,b);
        }
    else if(type=='A'||type=='a'){
        float b;
        cout<<"Input brain: ";
        cin>>b;
        block[i]=new academic(b);
    }
    else if(type=='P'||type=='p'){
        float p;
        cout<<"Input power: ";
        cin>>p;
        block[i]=new power(p);
    }
    else{
        cout<<"Type of gate don't fit"<<endl;
        break;
    }
    }
cout<<"Input cash of prince: ";
cin>>cash;
cout<<"Input brain power of prince: ";
cin>>bpp;
cout<<"Input power of prince: ";
cin>>pop;

}
void xuat(int n,bool &success,float& pop,float& cash,float& bpp,gate**&block){

for(int i=0;i<n;i++){
    if(((block[i]->checknumber(cash)))<0){
        success=false;
        break;
    }
    if(((block[i]->checknumber(bpp)))<0){
        success=false;
        break;
    }
    if(((block[i]->checknumber(pop)))<0){
        success=false;
        break;
    }
}
if(success==true){
    cout<<"Can save the princess "<<endl;
    cout<<"Properties of prince: "<<endl;
    cout<<"Cash: "<<cash<<endl;
    cout<<"Brain: "<<bpp<<endl;
    cout<<"Power: "<<pop<<endl;
}else{
    cout<<"Can't save the princess";
}

}

int main(){
float pop,cash,bpp;
bool success=true;
int listofgate;


gate ** block = nullptr;

nhap(cash,bpp,pop,listofgate,block);
xuat(listofgate,success,pop,cash,bpp,block);

for (int i = 0; i < listofgate; i++) {
        delete block[i];
    }
    delete[] block;

return 0;
}
