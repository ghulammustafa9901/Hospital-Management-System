#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<iomanip>
using namespace std;

float time(){
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);

  cout<<endl<<"\t"<< asctime (timeinfo);
  return 0;
}

int main() {
  system("CLS");
  system("COLOR 3F");

  char fname[20];

  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);

  cout<<endl<<endl;
  cout<<"\t********************************************************"<<endl<<endl;
  cout<<"\t\t  WELCOME TO HOSPITAL MANAGEMENT SYSTEM"<<endl<<endl;
  cout<<"\t********************************************************"<<endl<<endl<<"\t";
  system("PAUSE");
  system("CLS");

  int login();
  login();

  //giving option to the user for their choice
  b:
  cout<<endl<<endl;
  cout<<"\t  HOSPITAL MANAGEMENT SYSTEM"<<endl<<endl;	
  cout<<"\tPlease, Choose from the following Options: "<<endl<<endl;
  cout<<"\t1--> Add New Patient Record"<<endl<<endl;
  cout<<"\t2--> Add Diagnosis Information"<<endl<<endl;
  cout<<"\t3--> Full History of the Patient"<<endl<<endl;
  cout<<"\t4--> Information About the Hospital"<<endl<<endl;
  cout<<"\t5--> Exit the Program"<<endl<<endl;

  int i;
  a:cout<<"\tEnter your choice: ";
  cin>>i;

  if(i<1 || i>5) {
    cout<<"\tInvalid Choice"<<endl;
    cout<<"\tTry again..........."<<endl;
    goto a;
  }
  
  system("CLS");

  //Adding the record of the new patient..................option 3
  if(i==1) {
    time();
    ofstream pat_file;
    char fname[20];
    cout<<endl<<"\tEnter the patient's file name: ";
    cin.ignore();
    gets(fname);
    pat_file.open(fname);
		if(!fname) {
		  cout<<endl<<"\tError while opening the file"<<endl<<"\t";
      system("PAUSE");
      system("CLS");
      goto b;
		} else {
      struct patient_info {
        char name[20];
        char address[100];
        char contact[10];
        char age[5];
        char sex[8];
        char blood_gp[5];
        char disease_past[50];
        char id[15];
      };

      patient_info ak;
      cout<<endl<<"\t********************************************************"<<endl;
      pat_file<<endl<<"\t********************************************************"<<endl;

      cout<<endl<<"\tName: ";
      pat_file<<endl<<"\tName: ";
      gets(ak.name);
      pat_file<<ak.name<<endl;

      cout<<endl<<"\tAddress: ";
      pat_file<<endl<<"\tAddress: ";
      gets(ak.address);
      pat_file<<ak.address<<endl;

      cout<<endl<<"\tContact Number: ";
      pat_file<<endl<<"\tContact Number: ";
      gets(ak.contact);
      pat_file<<ak.contact<<endl;

      cout<<endl<<"\tAge: ";
      pat_file<<endl<<"\tAge: ";
      gets(ak.age);
      pat_file<<ak.age<<endl;

      cout<<endl<<"\tSex: ";
      pat_file<<endl<<"\tSex: ";
      gets(ak.sex);
      pat_file<<ak.sex<<endl;

      cout<<endl<<"\tBlood Group: ";
      pat_file<<endl<<"\tBlood Group: ";
      gets(ak.blood_gp);
      pat_file<<ak.blood_gp<<endl;

      cout<<endl<<"\tAny Major disease suffered earlier: ";
      pat_file<<endl<<"\tAny Major disease suffered earlier: ";
      gets(ak.disease_past);
      pat_file<<ak.disease_past<<endl;

      cout<<endl<<"\tPatient ID: ";
      pat_file<<endl<<"\tPatient ID: ";
      gets(ak.id);
      pat_file<<ak.id<<endl;

      cout<<endl<<"\t********************************************************"<<endl;
      pat_file<<endl<<"\t********************************************************"<<endl;
      cout<<endl<<"\tInformation Saved Successfully"<<endl<<endl<<"\t";
    }
    system("PAUSE");
    system("CLS");
    goto b;
  }

  //Appending diagnosis information of patient datewise.................option 2
  if(i==2) {

    fstream pat_file;
    cout<<endl<<endl<<"\tEnter the patient's file name to be opened: ";
    cin.ignore();
    gets(fname);
    system("CLS");
    pat_file.open(fname, ios::in);
		if(!pat_file) {
      cout<<endl<<"\tError while opening the file"<<endl<<"\t";
      system("PAUSE");
      system("CLS");
      goto b;
		} else {
      cout<<endl<<endl<<"\t........................... Information about "<<fname<<" ..........................."<<endl<<endl;
      string info;
			while(pat_file.good()) {
  			getline(pat_file,info);
  			cout<<info<<endl;
			}
			cout<<endl;
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
			cout<<endl<<"\tAdding more information in patient's file................on: "<<asctime (timeinfo);
      pat_file<<endl<<"\tDescription of "<<asctime (timeinfo)<<endl;
      struct app {
        char symptom[500];
        char diagnosis[500];
        char medicine[500];
        char addmission[30];
        char ward[15];
      };

      app add;
      cout<<endl<<"\tSymptoms: ";
      pat_file<<endl<<"\tSymptoms: ";
      gets(add.symptom);
      pat_file<<add.symptom<<endl;

      cout<<endl<<"\tDiagnosis: ";
      pat_file<<endl<<"\tDiagnosis: ";
      gets(add.diagnosis);
      pat_file<<add.diagnosis<<endl;

      cout<<endl<<"\tMedicines: ";
      pat_file<<endl<<"\tMedicines: ";
      gets(add.medicine);
      pat_file<<add.medicine<<endl;

      cout<<endl<<"\tAddmission Required: ";
      pat_file<<endl<<"\tAddmission Required: ";
      gets(add.addmission);
      pat_file<<add.addmission<<endl;

      cout<<endl<<"\tType of ward: ";
      pat_file<<endl<<"\tType of ward: ";
      gets(add.ward);
      pat_file<<add.ward<<endl;

      cout<<endl<<"\t********************************************************"<<endl;
      pat_file<<endl<<"\t********************************************************"<<endl;
      cout<<endl<<"\t"<<add.ward<<" ward is alloted Successfully"<<endl<<endl<<"\t";
			pat_file.close();
			system("PAUSE");
      system("CLS");
			goto b;
		}
  }

  //For displaying the full medical history of patient in that hospital............option 3
  if(i==3) {

    fstream pat_file;
    cout<<endl<<endl<<"\tEnter the patient's file name to be opened: ";
    cin.ignore();
    gets(fname);
    system("CLS");
    pat_file.open(fname, ios::in);
		if(!pat_file) {
      cout<<endl<<"\tError while opening the file"<<endl<<"\t";
      system("PAUSE");
      system("CLS");
      goto b;
		} else {
		    cout<<endl<<endl<<"\t........................... Full Medical History of "<<fname<<" ..........................."<<endl<<endl;
		    string info;
  			while(pat_file.good()) {
    			getline(pat_file,info);
    			cout<<info<<endl;
  			}
      }
      cout<<"\t";
      system("PAUSE");
      system("CLS");
      goto b;
  }

  //displaying the information about the hospital........option 4
  if(i==4) {

    ifstream file;
    file.open("hos1.txt");
    if(!file) {
      cout<<endl<<"\tError while opening the file"<<endl<<endl<<"\t";
      system("PAUSE");
      system("CLS");
      goto b;
    } else {
      cout<<endl<<endl;
      cout<<"\t\t\t ...........................Information about the Hospital............................."<<endl<<endl;
      string line;
      while(file.good()) {
        getline(file,line);
        cout<<line<<"\n\t";
      }
      cout<<endl<<endl<<"\t";
      system("PAUSE");
      system("CLS");
      goto b;
    }
  }

  //Exiting Through the system with a Thank You note........................option 5
  if(i==5) { 
    system("CLS");
    cout<<endl<<endl<<endl<<endl<<"\tTHANK YOU FOR USING";
    cout<<endl<<endl<<"\tHOSPITAL MANAGEMENT SYSTEM"<<endl<<endl<<"\t";
    system("PAUSE");
  }
}

int login() {

  string pass ="";
  
  cout<<endl<<endl;
  cout<<"\t  HOSPITAL MANAGEMENT SYSTEM"<<endl<<endl;
  cout<<"\t------------------------------"<<endl;
  cout<<"\t\t    LOGIN "<<endl; 
  cout<<"\t------------------------------"<<endl<<endl;  
  cout<<"\tEnter Password: ";

  char ch;
  ch = _getch();
  while(ch != 13){//character 13 is enter
    pass.push_back(ch);
    cout << '*';
    ch = _getch();
  }

  if(pass == "pass") {
    cout<<endl<<endl<<"\tAccess Granted!"<<endl<<endl<<"\t";
    system("PAUSE");
    system ("CLS");
  } else {
    cout<<endl<<endl<<"\tAccess Aborted..."<<endl<<"\tPlease Try Again"<<endl<<endl<<"\t";
    system("PAUSE");
    system("CLS");
    login();
  }

  return 0;
}

