// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
#include<random>
#include<vector>
using namespace std;
enum  Colour{RED, GREEN, BLUE, YELLOW};

class point{
    public:
    float x;
    float y;
    
    
    
    Colour colour;
    point(float x, float y, Colour colour){
        this->x=x;
        this->y=y;
        this->colour=colour;
    }
     point(float x, float y){
        this->x=x;
        this->y=y;
        
    }
    point(){};
    
    float distance(point P1){
        float compX= (P1.x) - (this->x);
        float compY= (P1.y) - (this->y);
        compX = compX*compX;
        compY = compY*compY;
        
    
        return( sqrt(compX+compY));
        
    }
    
    
    Colour nearestNeighbour(vector<point> Veky){
        int red,green,blue,yellow=0;
        int size=Veky.size();
        cout<<size;
        int kNaj=size/2+1;
     
        
        
        
        for(int i=0; i< size;i++){
            float minDis=distance(Veky[i]);
            int pos=i;
            for(int j=i;j<size;j++){
                if(distance(Veky[j])<minDis){
                    minDis=distance(Veky[j]);
                    pos=j;
                }}
            point pomoc;
            pomoc.x=Veky[pos].x;
            pomoc.y=Veky[pos].y;
            Veky[pos]=Veky[i];
            Veky[i]=pomoc;
            
            
        }
        
        
        for(int i=0;i<kNaj;i++){
            if(Veky[i].colour == RED){
                red++;
            }
             if(Veky[i].colour == BLUE){
                blue++;
            }
             if(Veky[i].colour == GREEN){
                green++;
            }
             if(Veky[i].colour == YELLOW){
                yellow++;
            }}
        
        
    
        int bojeTezina[4]={red,blue,yellow,green};
        bool count=true;
        while(count==true){
            count = false;
        
        for(int i=0;i<3;i++){
            
            if(bojeTezina[i]>bojeTezina[i+1]){
                int pom;
                pom=bojeTezina[i];
                bojeTezina[i]=bojeTezina[i+1];
                bojeTezina[i+1]=pom;
                count=true;
            }
            
        }}
        
        if(bojeTezina[3] == red){return RED;} 
        if(bojeTezina[3] == blue){return BLUE;} 
        if(bojeTezina[3] == yellow){return YELLOW;} 
        if(bojeTezina[3] == green){return GREEN;}
        
        
    }
    
    
};



int main() {
   point P(0.0,0.0);
   vector<point> veky= {  point(1.0,1.0,RED),point(2.0,2.0,BLUE),point(4.0,5.0,BLUE) } ;
   
   P.colour= P.nearestNeighbour(veky);
  
  if(P.colour==BLUE){
      
       std::cout << "Blue";
      
  }
   if(P.colour==RED){
      
       std::cout << "Red";
      
  }
    

    return 0;
}