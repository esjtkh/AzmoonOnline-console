

#include<ctime>
#include<fstream>
#include <iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	ofstream sabtda("sabtdaneshjoo.dat", ios::app);
	ofstream ostadenroll("ostadenroll.dat", ios::app);


loginpage:	cout << "*******************************Welcome To Login Page***************************" << endl << endl;

	cout << "Choose Your Position : " << endl << endl;;

	cout << "Daneshjoo<d>\t\t" << "Ostad<o>\t" << "Modirkol<m>" << endl;

	char n[2];

	char modiruser[12];

	char modirpass[12];

	cin >> n;

	int m = 0;

	if (strcmp(n, "m") == 0)

	{	/////////////////////////////////////////////////////////////////////////////////////////////////////modir kol enter

	s:
		
		cout << "Enter Your Username & Password :" << endl;

		cout << "User :";

		cin >> modiruser;

		cout << endl;

		cout << "Password :";

		cin >> modirpass;

		if (strcmp(modiruser, "esjkhademi") == 0 && strcmp(modirpass, "esjkhademi1") == 0)
		{
			system("cls");

			getchar();

			m = 1;
		}
		else
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!Wrong entry!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

			cin.ignore();

			goto s;
		}
		struct enrollos
		{
			char username[20];
			char password[20];
			char dars[15];
		};

		enrollos enroll[100];

		struct daneshsabt
		{
			char name[15];
			char family[15];
			char	username[20];
			char password[15];
		};

		daneshsabt sabt[100];

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////modir kol pageeeeeeeeeeeeee

		if (m == 1)
		{
		modirkolpage:

			cout << "***************************Welcome To  ModirKol Page***************************" << endl << endl;

			cout << "Sabtenam e Ostad<so> :" << endl << endl;                                                                                      //////safhe asli modir

			cout << "Log out<l>" << endl << endl;

			cout << "Sabtenam e Daneshjoo<sd> :" << endl << endl;

			cout << "Liste nataije azmoonha :";

			ifstream nataiej("nataiej.dat", ios::in);


			while (!nataiej.eof())
			{
				char name[10];

				char stduser[20];

				int score;

				nataiej >> name;


				if (name[0] == NULL)
				{
					nataiej.close();

					//cout << "\n Not Found ! ";

					goto listeasatid;
				}

				nataiej >> stduser;

				nataiej >> score;

				cout << endl << name << "\t" << stduser << "\t" << score << endl << "*************" << endl;

			}

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		listeasatid:

			cout << "\n\nListe asatid :" << endl;

			ifstream ostadenroll("ostadenroll.dat", ios::in);

			if (!ostadenroll)cout << "file couldnt be opened";

			int i = 0;

			while (!ostadenroll.eof())         ///// liste asatid                                                                                   //list e asatid
			{
				ostadenroll >> enroll[i].username;

			

				ostadenroll >> enroll[i].password;

				ostadenroll >> enroll[i].dars;

				cout << enroll[i].username << endl << enroll[i].password << endl << enroll[i].dars << endl << "*************" << endl;
				i++;
			}
			ostadenroll.close();

			listedanesh:

			cout << "\nListe Daneshjooha :\n";     ////->                                                                                         //////////list e daneshjooha

			ifstream sabtdan("sabtdaneshjoo.dat", ios::in);

			i = 0;

			while (!sabtdan.eof())
			{
				sabtdan >> sabt[i].name >> sabt[i].family >> sabt[i].username >> sabt[i].password;

				if (sabt[i].name == NULL)
				{
					nataiej.close();
					cout << "\n Not Found ! ";
					goto con ;
				}
			
				cout << sabt[i].name << endl << sabt[i].family << endl << sabt[i].username << endl << sabt[i].password << endl << "*************" << endl;

				i++;
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
		con:
			cout << endl;

			cin >> n;

			if (strcmp(n, "l") == 0)//log out                                                                                                           ///////////////log out modir
			{

				system("cls");

				goto loginpage;

			}
			////////////////////open ostad file

			ofstream ostdenroll("ostadenroll.dat", ios::app);

			int a;

			/*if (!ostdenroll)
			{
				cout << "!!!!!!!!!! File couldnt be opened !!!!!!!!!!!!!!! ";

			}*/

			if (strcmp(n, "so") == 0)////////////                                                                ////////sabte nam ostad
			{

				cout << "Enter Ostad number :" << endl;

				cin >> m;

				enrollos *enroll = new enrollos[m];/////////                                                     ////////structure array ostad

				for (int i = 0; i < m; i++)
				{
					cout << "Enter Ostad Username and Password :" << endl;

					cout << "User :";

					cin >> enroll[i].username;

					cout << endl << "Password :";

					cin >> enroll[i].password;

					cout << endl << "Dars :";                                                                 ///////write info  in ostad file  and close

					cin >> enroll[i].dars;

					ostdenroll << enroll[i].username << endl << enroll[i].password << endl << enroll[i].dars << endl;

				}

				if (EOF)cout << "!!!!!!!!Successfully Enrolled!!!!!!!!!";

				else { cout << " !!!!!!!!!!!!!!!!!!!!!!!!!Lost!!!!!!!!!!!!!!!!!!"; }

				ostdenroll.close();

				ostadenroll.close();

				cout << "\nPlease enter any key :\n";

				cin.ignore();

				system("cls");

				goto modirkolpage;
			}


			if (strcmp(n, "sd") == 0)                                                                         ///////////////////////////////////Sabtenam Daneshjoo
			{
				struct daneshsabt
				{
					char name[15];
					char family[15];
					char	username[20];
					char password[15];
				};

				cout << "Enter daneshjoo numbers :\n";

				cin >> m;

				daneshsabt *sabt = new daneshsabt[m];


				ofstream sabtda("sabtdaneshjoo.dat", ios::app);


				for (int i = 0; i < m; i++)
				{
					cout << "Enter Daneshjoo  informaion\n";

					cout << "Name :";

					cin >> sabt[i].name;

					cout << "\nFamily :";

					cin >> sabt[i].family;

					cout << "\nUsername :";

					cin >> sabt[i].username;

					cout << "\nPassword :";

					cin >> sabt[i].password;

					sabtda << "\n" << sabt[i].name << endl << sabt[i].family << endl << sabt[i].username << endl << sabt[i].password;

				}
				sabtda.close();

				system("cls");

				goto modirkolpage;
			}
		}
	}


	////////////////////////////////////////////asatid main page////////////////////////////////////////////////////////////////////////////////////////asatid main pageeeeeeeeeeee

	if (strcmp(n, "o") == 0)
	{
		ifstream asatid("ostadenroll.dat");       ///////check user pass                              //////////////////check ostad user n pass


		struct ostad
		{
			char user[15];
			char pass[15];
			char dars[10];;
		};

		ostad ostd;

		char ostaduser[15], ostadpass[15];

		cout << "Enter Your Username & Password :" << endl;

		cout << "User :";

		cin >> ostaduser;

		cout << endl;

		cout << "Password :";

		cin >> ostadpass;

		while (!asatid.eof())
		{
			asatid >> ostd.user >> ostd.pass >> ostd.dars;

			if (strcmp(ostaduser, ostd.user) == 0 && strcmp(ostadpass, ostd.pass) == 0)
			{
				system("cls");



				goto ostadpage;
			}
		}
		cout << "!!!!!User and Password not found!!!!!\n";

		cout << "Enter any key to continue....";
		char e;

		cin >> e;

		goto loginpage;

		////////////////////////////////////////////////////////
	ostadpage:

		struct emtehan
		{
			char name[15];

			int num;
			char soalat[400];
			char gozine1[200];
			char gozine2[200];
			char gozine3[200];
			char gozine4[200];
		};
		emtehan emtehan[100];

		struct pasokh
		{
			int pasokh;
		};


		cout << "**********************************Welcome To Asatid Page**********************" << endl << endl;



		cout << "<<<<<<<Welcome Dear " << ostaduser << " >>>>>>>" << "<<<<<<<<<< Dars :" << ostd.dars << ">>>>>>>>>>>" << endl << endl;

		cout << "Taarif e Emtehan<t> :" << endl;

		cout << "Log out <l>\n";

		cout << "Nataieje Emtehan :\n";

		char name[10];

		ifstream nataiej("nataiej.dat", ios::in);

		while (!nataiej.eof())
		{
			nataiej >> name;

			if (name[0] == NULL)
			{
				//cout << "\n Not Found ! ";

				goto ostad;
			}


			if (ostd.dars[0] == name[0])
			{
				char stduser[20];

				int score;

				nataiej >> stduser;

				nataiej >> score;

				cout << name << "\t" << stduser << "\t" << score << endl << endl;

			}


		}


	ostad:

		cin >> n;

		if (strcmp(n, "l") == 0)/////log out                                                                                               ///////////////log out asatid
		{
			system("cls");

			goto loginpage;
		}




		ofstream emtehanat("emtehan.dat", ios::app);//name,number,soal,gozine,

		ofstream pasokhha("pasokhha.dat", ios::app);


		if (strcmp(n, "t") == 0)                         /////////// taarif e emtehan                                                              //////taarif emtehan
		{
			cout << "Enter test name :\t";

			cin >> emtehan[0].name;

			emtehanat << emtehan[0].name;


			cout << endl << "Enter question number :\t";

			cin >> emtehan[0].num;

			emtehanat << endl << emtehan[0].num << endl;



			cout << endl << "Enter test time :";



			struct tm time1;

			ofstream testtime("testtime.dat", ios::app);

			testtime << endl<<emtehan[0].name;

			cout << "\nyear :";

			cin >> time1.tm_year;

			testtime << endl << time1.tm_year;

			cout << "\n month :";

			cin >> time1.tm_mon;

			testtime << endl << time1.tm_mon;

			cout << endl << "day :";

			cin >> time1.tm_mday;
			testtime << endl << time1.tm_mday;

			cout << endl << "hour :";

			cin >> time1.tm_hour;
			testtime << endl << time1.tm_hour;

			cout << endl << "minute :";

			cin >> time1.tm_min;

			testtime << endl << time1.tm_min;

			cout << endl << "Payane Emtehan :";

			cout << endl << "Hour :";

			cin >> time1.tm_hour;

			testtime << endl << time1.tm_hour;

			cout << endl << "Minute :";

			cin >> time1.tm_min;

			testtime << endl << time1.tm_min << endl;


			pasokh *pasokh1 = new pasokh[emtehan[0].num];

			pasokhha << emtehan[0].name << endl;


			for (int i = 0; i < emtehan[0].num; i++)
			{
				cout << "soale" << i + 1 << ":\t";

				cin >> emtehan[i].soalat;

				emtehanat << emtehan[i].soalat << endl;

				cout << endl << "gozine 1 :\t";

				cin >> emtehan[i].gozine1;

				emtehanat << "\n1)" << emtehan[i].gozine1;


				cout << endl << "gozine 2 :\t";

				cin >> emtehan[i].gozine2;

				emtehanat << "\n2)" << emtehan[i].gozine2;

				cout << endl << "gozine 3 :\t";

				cin >> emtehan[i].gozine3;

				emtehanat << "\n3)" << emtehan[i].gozine3;

				cout << endl << "gozine 4 :\t";

				cin >> emtehan[i].gozine4;

				emtehanat << "\n4)" << emtehan[i].gozine4 << endl;

				cout << "Pasokh :\n";

				cin >> pasokh1[i].pasokh;

				pasokhha << pasokh1[i].pasokh << endl;
			}
			pasokhha.close();

			emtehanat.close();

			char e;

			cout << "Operation is done..... ";

			cout << endl << "Press any key to continue....";

			cin >> e;

			system("cls");

			goto ostadpage;
		}
	}

	//////////////////////////////////////////////////////////////daneshjoo entry//////////////////////////////////////////////////////
	if (strcmp(n, "d") == 0)                                                                                                           /////////////////daneshjoo entry
	{
		ifstream students("sabtdaneshjoo.dat");                                                     //////////////////check user & pass

		struct student
		{
			char name[20];
			char famil[20];
			char user[15];
			char pass[15];
		};

		student std[1];

		char stduser[15], stdpass[15];

		cout << "Enter Your Username & Password :" << endl;

		cout << "User :";

		cin >> stduser;

		cout << endl;

		cout << "Password :";

		cin >> stdpass;

		while (!students.eof())
		{
			students >> std[0].name >> std[0].famil >> std[0].user >> std[0].pass;

			if (strcmp(stduser, std[0].user) == 0 && strcmp(stdpass, std[0].pass) == 0)
			{
				system("cls");

				goto studentpage1;
			}
		}
		cout << "Username or Password not found . ";

		char e;

		cout << "\nEnter any key to continue....\n";

		cin >> e;

		system("cls");
		goto loginpage;




		////////////////////////////////////////student page/////////////////////////////////////////////////////////////////////////////////////student pageeeeeeeeeeeeeeee
	studentpage1:

		bool state1 = false;

	studentpage:

		cout << "****************************Welcome To Student Page**************************" << endl << endl;

		cout << "<<<<<<<Welcome Dear " << stduser << " >>>>>>>" << endl << endl;

		cout << "Log out<\l>\n";

		cout << "\nListe Emtehanat :\n";

		

		ifstream testtime("testtime.dat", ios::in);
		
		int sign = 0;

		int o = 0;

		while (!testtime.eof())
		{
			char testname[20];

			testtime >> testname;

			if (testname[0] == NULL && testname[1]==NULL)
			{
				//cout << "\n Not Found ! ";
				goto stlogout;
			}

		

			time_t now = time(0);/////current time

			tm *time1 = new tm{};

			localtime_s(time1, &now);/////convert time_t format to tm_struct 

			int year = time1->tm_year + 1900;
			int month = time1->tm_mon + 1;
			int day = time1->tm_mday;
			int hour = time1->tm_hour;
			int min = time1->tm_min;

			int year2, month2, day2, hour2, min2, endh, endmin;

		


			testtime >> year2;  /////ostad time
			testtime >> month2;
			testtime >> day2;
			testtime >> hour2;
			testtime >> min2;
			testtime >> endh;   //ending hour
			testtime >> endmin;

			///////barresi sharaiete zamani                                                                               ///////barresi sharaiete zamani

			if (year < year2 && month < month2 && day2 >= day && hour <= hour2 && min2 >= min)

			{

				cout << endl << testname << " : ";  /////name e azmoon

				cout << "<<<Zaman Fara Nareside>>>";

				char e;
				cin >> e;
				if (e == 'l')////log out
				{
					system("cls");

					goto loginpage;
				}

				goto q;
			}

			if (year == year2 && month == month2 && day2 == day && (hour2 <= hour && hour <= endh))			      //show exam                 //show exam
			{
				if (hour2 !=endh)
				{
					if (min2 <= min+60 && min <= endmin + 60)goto x;

					else goto q;

				}

				else if (min2 <= min && min <= endmin)
				{
				x:

					cout << endl << testname << " : ";  /////name e azmoon

					cout << "\n!!!!! Dar Hale Bargozari !!!!! ";

					cout << endl << "ENTER \e\ TO ENTER EXAM :";

					char e;
					cin >> e;


					if (e == 'l')////log out
					{
						system("cls");

						goto loginpage;
					}

					if (e == 'e')
					{
						if (state1 == true)
						{
							cout << "!!!!!!nemitavanid vared shavid!!!!!!";

							char p;
							cin >> p;

							goto stlogout;
						}
						else
						{
							system("cls");

							ifstream emtehanat("emtehan.dat", ios::in);
							ifstream pasokhha("pasokhha.dat", ios::in);
							ofstream nataiej("nataiej.dat", ios::app);

							struct emtehan
							{
								char name[15];
								int num;
								char soalat[400];
								char gozine1[200];
								char gozine2[200];
								char gozine3[200];
								char gozine4[200];
							};

							emtehan emtehan[100];

							struct pasokh
							{
								int pasokh;
							};

							while (!emtehanat.eof())
							{
								emtehanat >> emtehan[0].name;

								if (strcmp(emtehan[0].name ,testname)==0)
									goto h;

								else
								{
									emtehanat >> emtehan[0].num;

									for (int i = 0; i < emtehan[0].num; i++)
									{
										emtehanat >> emtehan[0].soalat;
										emtehanat >> emtehan[0].gozine1;
										emtehanat >> emtehan[0].gozine2;
										emtehanat >> emtehan[0].gozine3;
										emtehanat >> emtehan[0].gozine4;
									}
								}

							}


						h:
							cout << "Name : " << emtehan[0].name;

							emtehanat >> emtehan[0].num;


							cout << endl << "Questions number :" << emtehan[0].num;

							time_t now = time(0);/////current time

							localtime_s(time1, &now);

							//-//-//-//-//-//-//-//-//-//-//-//-//

							time_t now1 = time(0);/////current time

							localtime_s(time1, &now1);

							int correct = 0;
							int incorrect = 0;


							for (int i = 0; i < emtehan[0].num; i++)////show exam to student                                                               //////show exam to student
							{
								if (time1->tm_hour >= endh && time1->tm_min >= endmin)
								{
									system("cls");

									cout << "!!!!!Time has been ended!!!!!";

									cout << endl << "ENTER ANY KEY TO CONTINUE :";
									char q;

									cin >> q;

									goto studentpage;
								}

								emtehanat >> emtehan[i].soalat;

								cout << endl << emtehan[i].soalat;

								emtehanat >> emtehan[i].gozine1;

								cout << endl << emtehan[i].gozine1;

								emtehanat >> emtehan[i].gozine2;

								cout << endl << emtehan[i].gozine2;

								emtehanat >> emtehan[i].gozine3;

								cout << endl << emtehan[i].gozine3;

								emtehanat >> emtehan[i].gozine4;

								cout << endl << emtehan[i].gozine4;

								cout << endl;


								int pasokh[100];

							
								if (sign == 0)
								{
									while (!pasokhha.eof())   ////find proper pasokh                                      ////find proper pasokh
									{
										char emtehanname[20];

										pasokhha >> emtehanname;

										if (strcmp(emtehan->name, emtehanname) == 0)
										{
											 sign = 1;
											goto a;
										}
									}
								}
							a:
								

								pasokhha >> pasokh[o];
								

								cout << "Enter 5 if no answer :";

								cout << "\nEnter Answer :";

								int answer;

								

								cin >> answer;

								if (answer == pasokh[i])correct++; ////tashih e emtehan

								if (answer != 5 && answer != pasokh[i])incorrect++;

								o++;

								////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								if (answer == 5)
								{
									time_t now = time(0);/////current time

									localtime_s(time1, &now);

									system("cls");
								}

								else
								{
									char n;

									if (i < emtehan[0].num - 1)
									{
										cout << "\nEnter any key to continue :";

										time_t now = time(0);/////current time

										localtime_s(time1, &now);

										cin >> n;

										system("cls");

										continue;
									}

									else 
									{
										cout << "\n Press any key to End test :";

										if (incorrect != 0 && incorrect >= 3)
										{
											incorrect = incorrect / 3;    ////nomre manfi
											
											correct = correct - incorrect;
											
										}																								   /////////////////nomre manfi
										

										nataiej << testname;

										nataiej << endl << stduser;

										nataiej << endl << correct << emtehan->num << endl;


										bool state1 = true;


										cin >> n;
										system("cls");

										cout << "!!Azmoon be payan resid !!" << endl << endl << "Natije Azmoon :" << correct << endl << endl;

										cout << ".... Press any key to continue to student page ...." << endl;

										char q;
										cin >> q;

										system("cls");
										goto studentpage;
									}

								}
							}
						}
					}
				}


			}

		q:
			char g;
		}


	stlogout:

	
	
	char n;

	cout << "\n\nLog out<\l>\n";

	cout << endl;

	cin >> n;

	if (n == 'l')////log out
	{
		system("cls");

		goto loginpage;
	}
	
































	}



}





