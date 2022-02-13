#include <iostream>
#include <string>
#include <exception>
#include <vector> 
#include<iterator>
#include <algorithm>
using namespace std;
class Employee
{				
private:			
  int password;
public:
  string name;
  int ProjectsCompleted;
  int noOfdays;
  int ID;
  double salary;
  // Friend function 
  friend int getpassword (Employee);	
  void GetData() 
  {
    cout << "enter name of employee " << endl;
    cin >> name;
    cout<<"enter id of employee "<<endl;
    cin>>ID;
    cout << "enter no of projects completed " << endl;
    cin >> ProjectsCompleted;
    cout << "enter no. of days present " << endl;
    cin>> noOfdays;
    cout << "enter salary of the employee" << endl;
    cin >> salary;
  }
  void show ()
  {
    cout << salary << endl;
  }
  void putData()
  {
      cout<<"\n"<<name<<"\t"<<ProjectsCompleted<<"\t"<<noOfdays<<"\t"<<salary;
  }
  // Destructor
   ~Employee ()
  {
  } 
};
// Pure virtual function
class Department
 { 
    public:  
    int ID;
    string dep_name ;
    virtual void display() 
    {
        cout<<"name of department is "<<dep_name<<endl;
        cout<<"ID of department is "<<ID<<endl;
    }
};
class CSDepartment : public Department
{
    public :
    void display()
    {
        cout<<"name of department is CS"<<endl;
        cout<<"ID of department is 2368"<<endl;
    }
};
// Friend function
int getpassword (Employee e)		
{
  e.password = 1678;
  return e.password;
}
// User defined exception 
class AppraisalException 
{
public:
    int errorCode;
public:
     AppraisalException(int code)
     {
    this->errorCode = code;
}
string toString()
{
   if(errorCode==10)
   {
 return "Employee cannot be appraised because he is present for less than 50%\n";
}
}
};
class NotSignedUpException: public AppraisalException
{
  public:
  NotSignedUpException(int code):AppraisalException(code){
  this->errorCode = code;
  }
 string toString(){
      if(errorCode==20){
return "Employee can be appraised but fine of Rs. 5000 can be deducted from his salary\n";
}
}
};
// Driver code 
int main ()
{
  CSDepartment cs;
    Department &de = cs;
    de.display();
    Employee e;			//code for friend function
    cout << "password of office is " << getpassword (e) << endl;
    int i;
    int n;
    cout<<"enter the no. of employees "<<endl;
    cin>>n;
    Employee E[n]; //n employee objects 
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter details of Employee Number " << i + 1 << endl; 
        E[i].GetData();                                           
    }
    cout << "\nDetails of Employees"; 
    for (i = 0; i < n; i++) 
    {
        E[i].putData();
    }
    double max = E[0].salary; // search for the employee object with highest salary
    for (i = 0; i < n; i++)
    {
        if (E[i].salary > max)
        {
            max = E[i].salary;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (E[i].salary == max)
         {
            cout << "\n"
                 << E[i].name << " has Maximun Salary";
            cout << "\n And Salary is : " << E[i].salary;
        }
    }
    //vectors 
    vector<Employee> emp;  
    for (int i=0 ; i<n ; i++)
    {
    Employee e = Employee();
    emp.push_back(e);
    }
    auto iter = emp.begin();  
    for ( ; iter !=  emp.end(); iter++)  
    (*iter).show(); 
    
    //user defined exception 
    int workingDays = 0 , notSignedupWorkingDays=0;
    cout<<"Enter the working days of an employee to check : ";
    cin>>workingDays;
    cout<<"\nEnter the not signedup working days of the employee to check : ";
    cin>>notSignedupWorkingDays;
    try
    {
      if(workingDays<=100)
    {
    throw AppraisalException(10);
    }
    else if(notSignedupWorkingDays>=1)
    {
    throw NotSignedUpException(20);
   }
 }  
    catch(NotSignedUpException e)
    {
    cout<<"I am here\n";
    cout<<e.toString();
   return 0;
  } 
   catch(AppraisalException e)
   {
   cout<<e.toString();
   return 0;
}
  cout<<"Employee can be appraised now!\n";
    return 0;
} 
