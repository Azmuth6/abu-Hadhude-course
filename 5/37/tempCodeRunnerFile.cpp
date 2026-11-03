
class Student{
private:
    int id;
    string name;
    double degree;
public:
    Student( int id1, string name2, double degree2 ){
        id = id1;
        name = name2;
        degree = degree2;
    }
    void setId(int id1){
        id=id1;

    }
    int getId(){
        return id;

    }
     void setName(string name1){
        name=name1;

    }
    string getName(){
        return name;

    }
     void setDegree(double degree1){
        degree=degree1;

    }
    double getDegree(){
        return degree;

    }
    string computeGrade(int degree){
        if(degree>=85){
                return "excellent";
        }
        if(degree>=75){
                return "very good";
        }
        if(degree>=65){
                return "good";
        }
        if(degree>=50){
                return "acceptable";
        }
        else{
            return "fail";
        }
    }
    void print(){
        cout<<"Id: "<<id<<"\n"<<"Name: "<<name<<"\n"<<"Degree: "<<degree<<"\n"<<"Grade: "<<computeGrade(degree)<<endl;


    }


};
int main()
{
    Student s1(5,"Abdo",90);
    s1.print();

    return 0;
}