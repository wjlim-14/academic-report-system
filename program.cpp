#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>
using namespace std;

/**************************************************************
Programmer:		Chang See Jie
Name: 			clrScr

Task:			Clear screen.
Data in:		-			
Data returned:	-
Referred to:	-
**************************************************************/
void clrScr()
	{
		cout << endl;
		cout << "Press any key to continue." << endl;
		getch();
		system("cls");
} 

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			Data

Task:			Make variables accessible
Data in:		Declare variables
Data returned: -
Referred to:	https://www.w3schools.com/cpp/cpp_access_specifiers.asp
**************************************************************/
class Data
{
public:
	int totalColumns;
	int totalRows;
	string *columnNames;
	int **data;

	Data()
	{
		totalRows = totalRows = 0;
		columnNames = nullptr;
		data = nullptr;
	};
		
/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			print 

Task:			Take data from the CSV file and display them in 
				tabular form.
Data in:		No data in
Data returned:	Display data
Referred to:	https://www.programiz.com/cpp-programming/examples/multiplication-table
**************************************************************/
	void print() //Function to display data in tabular form
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                      Display Data                      " << endl;
		cout << "========================================================" << endl;
		cout << endl;

		cout << "+";
		for (int i = 0; i < totalColumns; i++)
		{
			cout << "----------+";
		}
		cout << endl;
		cout << "|";
		for (int i = 0; i < totalColumns; ++i)
		{
			printf("%-10s|", columnNames[i].c_str());
		}
		cout << endl;
		cout << "+";
		for (int i = 0; i < totalColumns; i++)
		{
			cout << "----------+";
		}
		cout << endl;
		for (int r = 0; r < totalRows; ++r)
		{
			cout << "|";
			for (int c = 0; c < totalColumns; ++c)
			{
				printf("%-10d|", data[r][c]);
			}
			printf("\n");
			cout << "+";
			for (int i = 0; i < totalColumns; i++)
			{
				cout << "----------+";
			}
			cout << endl;
		}
		clrScr();
	}

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			HTML

Task:			Generate HTML file template 
Data in:		functions totalColumns
Data returned: 	Generate HTML file
Referred to:	-
**************************************************************/
	string HTML()
	{
		string ret = "";
		ret.append("<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'>");
		ret.append("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
		ret.append("<title>Acedemic Report System</title>");
		ret.append("<link rel='stylesheet' href='./bootstrap.css'>");
		ret.append("<link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css");
		ret.append("<body>");
		ret.append("<div class='container jumbotron'><h1>Statistics Report</h1></div>");
		ret.append("<div class='container'>");
		ret.append("<table class='table'>");
		ret.append("<tr>");
		ret.append("<th>Column Name</th>");
		ret.append("<th>Minimum</th>");
		ret.append("<th>Maximun</th>");
		ret.append("<th>Median</th>");
		ret.append("<th>Mean</th>");
		ret.append("<th>Variance</th>");
		ret.append("<th>Standard Daviation</th>");
		ret.append("</tr>");

		for (int i = 1; i < totalColumns; i++)
		{
			ret.append("<tr>");
			ret.append("<td>" + columnNames[i] + "</td>");
			ret.append("<td>" + to_string(Minimum(i)) + "</td>");
			ret.append("<td>" + to_string(Maximum(i)) + "</td>");
			ret.append("<td>" + to_string(Median(i)) + "</td>");
			ret.append("<td>" + to_string(Mean(i)) + "</td>");
			ret.append("<td>" + to_string(Variance(i)) + "</td>");
			ret.append("<td>" + to_string(StandardDeviation(i)) + "</td>");
			ret.append("</tr>");
		}
		ret.append("</table>");
		ret.append("</div>");

		ret.append("<div class='container jumbotron'><h1>Table</h1></div>");
		ret.append("<div class='container'>");
		ret.append("<table class='table'>");
		ret.append("<tr>");
		for (int i = 0; i < totalColumns; i++)
		{
			ret.append("<th>" + columnNames[i] + "</th>");
		}
		ret.append("</tr>");
		for (int r = 0; r < totalRows; r++)
		{
			ret.append("<tr>");
			for (int c = 0; c < totalColumns; c++)
			{
				ret.append("<td>" + to_string(data[r][c]) + "</td>");
			}
			ret.append("</tr>");
		}
		ret.append("</table>");
		ret.append("</div>");
		ret.append("</body>");
		return ret;
	}

/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			Minimum

Task:			Take data from GetColumn() and find minimum value
Data in:		Get data from column
Data returned: 	Data out minimum
Referred to:	-
**************************************************************/
	double Minimum(int columnNo) //Function find mininum value
	{
		int sum = 0;
		double res = data[0][columnNo];
		for (int r = 0; r < totalRows; ++r)
		{
			if (res > data[r][columnNo])
				res = data[r][columnNo];
		}
		return res;
	}
	
/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			Maximum

Task:			Take data from GetColumn() and find maximum value
Data in:		Get data from column
Data returned: 	Data out maximum 
Referred to:	-
**************************************************************/
	double Maximum(int columnNo) //Function find maximum value
	{
		int sum = 0;
		double res = data[0][columnNo];
		for (int r = 0; r < totalRows; ++r)
		{
			if (res < data[r][columnNo])
				res = data[r][columnNo];
		}
		return res;
	}

/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			mean

Task:			Take data from GetColumn() and find mean value
Data in:		Get data from column
Data returned: 	Data out mean
Referred to:	-
**************************************************************/
	double Mean(int columnNo) //Function find mean value
	{
		int sum = 0;
		for (int r = 0; r < totalRows; ++r)
		{
			sum += data[r][columnNo];
		}
		double res = (double)sum / (double)totalRows;
		return res;
	}

/**************************************************************
Programmer:		Tee Ming Yuan
Name:			Median

Task:			Take data from GetColumn() and find median value
Data in:		Get data from column
Data returned: 	Data out median
Referred to:	-
**************************************************************/
	double Median(int columnNo)
	{
		sort(columnNo);
		int index = 0;
		double ret;
		if (totalRows % 2 == 0)
		{
			index = totalRows / 2;
			ret = data[index][columnNo] + data[index + 1][columnNo];
			ret = ret / 2;
		}
		else
		{
			ret = data[index][columnNo];
		}
		return ret;
	}

/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			Variance

Task:			Take data from GetColumn() and find variance value		
Data in:		Get data from column
Data returned: 	Data out variance
Referred to:	-
**************************************************************/
	double Variance(int columnNo)
	{
		double sum = 0;
		double mean = Mean(columnNo);
		for (int r = 0; r < totalRows; ++r)
		{
			sum += (data[r][columnNo] - mean) * (data[r][columnNo] - mean);
		}
		double res = (double)sum / ((double)totalRows - 1);
		return res;
	}

/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			StandardDeviation

Task:	 		Find standard deviation value	
Data in:		Square root of variance
Data returned: 	Data out standard deviation
Referred to:	-
**************************************************************/
	double StandardDeviation(int columnNo)
	{
		return sqrt(Variance(columnNo));
	}

/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			GetColumn 

Task:			Lets user choose their preferred column
Data in:		No data in
Data returned:	User's input
Referred to:	-
**************************************************************/
	int GetColumn()
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                     Select By Column                   " << endl;
		cout << "========================================================" << endl;

		for (int i = 1; i < totalColumns; i++)
		{
			printf("|| %1d. %-48s||\n", i, columnNames[i].c_str());
		}
		cout << "========================================================" << endl;
		int input;
		cout << "Please input selection between 1 - " << (totalColumns - 1) << ": ";
		cin >> input;
		system("cls");
		if (!(input >= 0 && input < totalColumns))
		{
			cout << "Invalid input." << endl;
			return -1;
		}
		return input;
	}
/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			GetColumnTwo 

Task:			Lets user choose 2 of their preferred columns 
Data in:		No data in
Data returned:	User's input
Referred to:	-
**************************************************************/
	void GetColumnTwo(int &c1, int &c2)
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                     Select By Column                   " << endl;
		cout << "========================================================" << endl;

		for (int i = 1; i < totalColumns; i++)
		{
			printf("|| %1d. %-48s||\n", i, columnNames[i].c_str());
		}
		cout << "========================================================" << endl;
		int input1, input2;
		cout << "Please input Subject 1: ";
		cin >> input1;
		cout << "Please input Subject 2: ";
		cin >> input2;
		system("cls");
		if (!(input1 >= 0 && input1 < totalColumns) || !(input2 >= 0 && input2 < totalColumns))
		{
			cout << "Invalid input." << endl;
			c1 = -1;
			c2 = -1;
			return;
		}
		c1 = input1;
		c2 = input2;
	}
	
/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			Sort

Task:			Sort the data
Data in:		get data from column 
Data returned:  sorted data
Referred to:	-
**************************************************************/
	void sort(int columnNo, bool reverse = false)
	{
		int i, j, min;
		int *temp;
		for (i = 0; i < totalRows - 1; i++)
		{
			min = i;
			for (j = i + 1; j < totalRows; j++)
				if ((data[j][columnNo] < data[min][columnNo]) ^ reverse)
					min = j;
			temp = data[i];
			data[i] = data[min];
			data[min] = temp;
		}
	}

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			WriteHTML

Task:			Create html file name and export the data
Data in:		file_name
Data returned:  write and link to html fucntion to generate report
Referred to:	-
**************************************************************/
	void WriteHTML(string file_name)
	{
		ofstream out(file_name);
		if (out.is_open())
		{
			out << HTML();
		}
	}

/**************************************************************
Programmer:		Tee Ming Yuan
Name: 			Frequency

Task:			Find the frequency distribution		
Data in:		Get data from column
Data returned: frequency distribution
Referred to:	-
**************************************************************/
	void Frequency(int columnNo)
	{
		this->sort(columnNo);
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                  Frequency Distribution                " << endl;
		cout << "========================================================" << endl;
		vector<bool> visited(totalRows, false);
		cout << "Subject: " << columnNames[columnNo] << endl;
		cout << endl;
		cout << "+-----------+-----------+" << endl;
		cout << "|  NUMBER   |   COUNT   |" << endl;
		cout << "+-----------+-----------+" << endl;

		for (int i = 0; i < totalRows; i++)
		{
			if (visited[i] == true)
				continue;
			int count = 1;
			for (int j = i + 1; j < totalRows; j++)
			{
				if (data[i][columnNo] == data[j][columnNo])
				{
					visited[j] = true;
					count++;
				}
			}
			printf("|%-11d|%-11d|\n", data[i][columnNo], count);
			cout << "+-----------+-----------+" << endl;
		}
		clrScr();
	}
	
/**************************************************************
Programmer:		Lim Wei Jie
Name: 			Correlation

Task:			Calculate Pearson's Correlation with the output of table
Data in:		From user input c1 and c2 (taking column data)
Data returned: Result of Pearson Correlation and print table
Referred to:	https://www.geeksforgeeks.org/program-find-correlation-coefficient/
**************************************************************/
	void Correlation(int c1, int c2)
	{
		double x_ = Mean(c1);
		double y_ = Mean(c2);
		double sumx = 0;
		double sumy = 0;
		double sum = 0;
		cout << endl;
		cout << "=========================================================================" << endl;
		cout << "                          Pearson's Correlation                          " << endl;
		cout << "=========================================================================" << endl;
		cout << "Let " << columnNames[c1].c_str() << " = X and " << columnNames[c2].c_str() << " = Y" << endl << endl;
		cout << "+----------+----------+----------+----------+----------+----------+" << endl;
		cout << "| ID       |     X    |     Y    |    X*Y   |    X*X   |    Y*Y   |" << endl;
		cout << "+----------+----------+----------+----------+----------+----------+" << endl;
		int sx = 0, sy = 0, sxy = 0, sxx = 0, syy = 0;
		for (int i = 0; i < totalRows; i++)
		{
			sum += (data[i][c1] - x_) * (data[i][c2] - y_);
			sumx += (data[i][c1] - x_) * (data[i][c1] - x_);
			sumy += (data[i][c2] - y_) * (data[i][c2] - y_);
			int x = data[i][c1];
			int y = data[i][c2];

			sxy += x * y;
			sxx += x * x;
			syy += y * y;
			printf("|%10d|%10d|%10d|%10d|%10d|%10d|\n", i + 1, x, y, x * y, x * x, y * y);
			cout << "+----------+----------+----------+----------+----------+----------+" << endl;
		}
		printf("|Total     |%10d|%10d|%10d|%10d|%10d|\n", sx, sy, sxy, sxx, syy);
		cout << "+----------+----------+----------+----------+----------+----------+" << endl;

		double res = sum / (sqrt(sumx) * sqrt(sumy));
		cout << "Pearson's Correlation between " << columnNames[c1] << " and " << columnNames[c2] << " is " << res << endl;
		clrScr();
	}

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			LinearRegression

Task:			Calculate linear regression with the output of table
Data in:		User input from c1 and c2 
Data returned: 	Calculation occurs and print out calculation data
Referred to:	-
**************************************************************/
	void LinearRegression(int c1, int c2)
	{	
		double x_ = Mean(c1);
		double y_ = Mean(c2);
		double sumx = 0;
		double sumy = 0;
		double sum = 0;
		cout << endl;
		cout << "=========================================================================" << endl;
		cout << "                            Linear Regression                            " << endl;
		cout << "=========================================================================" << endl;
		cout << "Let " << columnNames[c1].c_str() << " = X and " << columnNames[c2].c_str() << " = Y" << endl << endl;
		cout << "+----------+----------+----------+----------+----------+----------+" << endl;
		cout << "| ID       |     X    |     Y    |    X*Y   |    X*X   |    Y*Y   |" << endl;
		cout << "+----------+----------+----------+----------+----------+----------+" << endl;
		int sx = 0, sy = 0, sxy = 0, sxx = 0, syy = 0;
		for (int i = 0; i < totalRows; i++)
		{
			sum += (data[i][c1] - x_) * (data[i][c2] - y_);
			sumx += (data[i][c1] - x_) * (data[i][c1] - x_);
			sumy += (data[i][c2] - y_) * (data[i][c2] - y_);
			int x = data[i][c1];
			int y = data[i][c2];

			sxy += x * y;
			sxx += x * x;
			syy += y * y;
			printf("|%10d|%10d|%10d|%10d|%10d|%10d|\n", i + 1, x, y, x * y, x * x, y * y);
		}
		printf("|Total     |%10d|%10d|%10d|%10d|%10d|\n", sx, sy, sxy, sxx, syy);
		cout << "+----------+----------+----------+----------+----------+----------+" << endl;

		double xmean = Mean(c1);
		double ymean = Mean(c2);
		double Sxx = 0;
		double Sxy = 0;
		for (int i = 0; i < totalRows; i++)
		{
			Sxx += (data[i][c1] - xmean) * (data[i][c1] - xmean);
			Sxy += (data[i][c1] - xmean) * (data[i][c2] - ymean);
		}
		double B = Sxy / Sxx;
		double A = ymean - (B * xmean);
		string res = "Y = " + to_string(A) + " + " + to_string(B) + "X";
		cout << "The Regression Line Between " << columnNames[c1] << " and " << columnNames[c2] << " is " << res << endl;
		clrScr();
	}

/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			Histogram

Task:			To generate a histogram
Data in:		Take data from the selected column which will be generated into a histogram
Data returned:	The histogram 
Referred to:	-
**************************************************************/
	void Histogram(int columnNo)
	{
		vector<bool> visited(totalRows, false);
		vector<int> value;
		vector<int> countValue;
		int maxCount = 0;
		sort(columnNo);
		for (int i = 0; i < totalRows; i++)
		{
			if (visited[i] == true)
				continue;
			int count = 1;
			for (int j = i + 1; j < totalRows; j++)
			{
				if (data[i][columnNo] == data[j][columnNo])
				{
					visited[j] = true;
					count++;
				}
			}
			if (maxCount < count)
				maxCount = count;
			value.push_back(data[i][columnNo]);
			countValue.push_back(count);
		}
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                        Histogram                       " << endl;
		cout << "========================================================" << endl;
		cout << "Subject: " << columnNames[columnNo] << endl;
		cout << endl;
		cout << "One (*) means for one point." << endl;
		cout << "+----------+--------------------------------------------+" << endl;
		cout << "|  NUMBER  |                  FREQUENCY                 |" << endl;
		cout << "+----------+--------------------------------------------+" << endl;
		for (int i = 0; i < value.size(); i++)
		{
			string starts = "";
			for (int j = 0; j < countValue[i]; j++)
				starts.append(" *");
			printf("|%-10d|%-44s|\n", value[i], starts.c_str());
			cout << "+----------+--------------------------------------------+" << endl;
		}
		clrScr();
	}

/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			Above and Below Mean

Task:			To display the data above and below the mean
Data in:		Get the data of the columns to calculate above and below of the mean
Data returned:  The data above and below the mean
Referred to:	-
**************************************************************/
	void AboveAndBelowMean(int columnNo)
	{
		int mean = Mean(columnNo);
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                   Above and Below Mean                 " << endl;
		cout << "========================================================" << endl;
		cout << "Subject: " << columnNames[columnNo] << endl;

		cout << "Mean: " << mean << endl << endl;
		cout << "ABOVE Mean: " << endl;
		cout << "+----------+----------+" << endl;
		cout << "|    ID    |   Mark   |" << endl;
		cout << "+----------+----------+" << endl;
		for (int i = 0; i < totalRows; ++i)
		{
			if (data[i][columnNo] > mean) 
			{
				printf("|%10d|%10d|\n", data[i][0], data[i][columnNo]);
				cout << "+----------+----------+" << endl;
			}
		}
		cout << endl;
		cout << "BELOW Mean: " << endl;
		cout << "+----------+----------+" << endl;
		cout << "|    ID    |   Mark   |" << endl;
		cout << "+----------+----------+" << endl;

		for (int i = 0; i < totalRows; ++i)
		{
			if (data[i][columnNo] < mean) 
			{
				printf("|%10d|%10d|\n", data[i][0], data[i][columnNo]);
				cout << "+----------+----------+" << endl;
			}
		}	
		clrScr();
	}

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			printData

Task:			Set up table form to display calculation data
Data in:		Call out calculation data and print out data
Data returned: 	Result of calculation data with table form
Referred to:	-
**************************************************************/
	void printData(int c) //Fucntions from the choose column
	{
		cout << endl;
		cout << "========================================================" << endl;
		printf("||                       %-29s||\n", columnNames[c].c_str()); // Grab the data from column selected
		cout << "========================================================" << endl;
		cout << "|| Minimum                 ||" << setw(15) << Minimum(c) << "          ||" << endl;
		cout << "|| Maximum                 ||" << setw(15) << Maximum(c) << "          ||" << endl;
		cout << "|| Median                  ||" << setw(15) << Median(c) << "          ||" << endl;
		cout << "|| Mean                    ||" << setw(15) << Mean(c) << "          ||" << endl;
		cout << "|| Variance                ||" << setw(15) << Variance(c) << "          ||" << endl;
		cout << "|| Standard Deviation      ||" << setw(15) << StandardDeviation(c) << "          ||" << endl;
		cout << "========================================================" << endl;
		clrScr();
	}
/**************************************************************
Programmer:		Lim Wei Jie
Name: 			TEXT

Task:			create text fiile and print out data in txt file
Data in:		create fileName for txt				
Data returned:	output table and result of calculation data
Referred to:	-
**************************************************************/
	void TEXT(string fileName)
	{
		ofstream out(fileName);
		string ret;
		if (out.is_open())
		{
			for (int i = 1; i < totalColumns; i++)
			{
				ret.append("----------------------------------------------------\n");
				ret.append("SUBJECT            : " + columnNames[i] + "\n");
				ret.append("Minumum Mark       : " + to_string(Minimum(i)) + "\n");
				ret.append("Maximum Mark       : " + to_string(Maximum(i)) + "\n");
				ret.append("Median             : " + to_string(Median(i)) + "\n");
				ret.append("Mean               : " + to_string(Mean(i)) + "\n");
				ret.append("Variance           : " + to_string(Variance(i)) + "\n");
				ret.append("Standard Daviation :" + to_string(StandardDeviation(i)) + "\n");
				ret.append("----------------------------------------------------\n");
			}
			out << ret;
		}
		else
		{
			perror(fileName.c_str());
		}
	}

	
/**************************************************************
Programmer:		Lim Wei Jie
Name: 			~Data

Task:			Fucntion that delete the memory that free out spaces
Data in:		Data files columnNames 
Data returned: 	-
Referred to:	https://www.geeksforgeeks.org/destructors-c/
				https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
**************************************************************/
	~Data() //Guaranteed call out functions Data
	{
		if (columnNames != nullptr)
			delete[] columnNames;
		if (data != nullptr)
		{
			for (int i = 0; i < totalRows; ++i)
			{
				delete[] data[i];
			}
			delete data;
		}
	}
};

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			Data *readfile

Task:			Function to let user input file and validate the file
Data in:		Declare pointer to readfile and store the data
Data returned: 	Store data inside Data
Referred to:	http://www.cplusplus.com/doc/tutorial/pointers/
				https://stackoverflow.com/questions/24175186/c-pointer-dereferenced-assignment/24175314
**************************************************************/
Data *readFile()
{
	string fileName;
	cout << "Enter data file name to proceed: ";
	cin >> fileName; 				//User input fileName
	system("cls");
	ifstream in(fileName);
	//Validate file start here
	if (in.is_open())
	{
		Data *data = new Data();
		in >> data->totalColumns;
		data->columnNames = new string[data->totalColumns];
		char buffer[1000];
		for (int i = 0; i < data->totalColumns; ++i)
		{
			if (i != data->totalColumns - 1)
				in.getline(buffer, 1000, ',');
			else
				in.getline(buffer, 1000, '\n');
			data->columnNames[i].assign(buffer);
			data->columnNames[i].erase(std::remove(data->columnNames[i].begin(), data->columnNames[i].end(), '\n'), data->columnNames[i].end());
			;
		}
		in >> data->totalRows;
		data->data = new int *[data->totalRows];
		for (int r = 0; r < data->totalRows; ++r)
		{
			data->data[r] = new int[data->totalColumns];
			for (int c = 0; c < data->totalColumns; ++c)
			{
				in >> data->data[r][c];
				if (c != data->totalColumns - 1)
					in.ignore(1);
			}
		}
		system("cls");
		return data;
	}
	system("cls");
	perror(fileName.c_str()); // If file not found, prompt error message
	return nullptr;
}


/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			exitProgram

Task:			Terminates the program.
Data in:		-			
Data returned:	-
Referred to:	-
**************************************************************/
void exitProgram() //Function exit message
{
    cout << endl;
    cout << "========================================================" << endl;
    cout << "                       Thank You !!                     " << endl;
	cout << "                  Press any key to exit.                " << endl;
    cout << "========================================================" << endl;
	getch();
	exit(0);
}

/**************************************************************
Programmer:		Chang See Jie
Name: 			invalid

Task:			Print “Invalid input.” message when user’s 
				input is invalid.
Data in:		-			
Data returned:	-
Referred to:	-
**************************************************************/
void invalid()
{
    cout << endl;
    cout << "Invalid input." << endl;
}

/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			WriteFile

Task:			Write the data into html and txt file
Data in:		The name of the file and calculated data 
Data returned:	-
Referred to:	-
**************************************************************/
void WriteFile(string fileName, Data *data)
{
	ofstream out(fileName);
	if (out.is_open())
	{
		out << data->totalColumns << endl;
		for (int i = 0; i < data->totalColumns; i++)
		{
			out << data->columnNames[i];
			if (i != data->totalColumns - 1)
				out << ',';
		}
		out << endl
			<< data->totalRows << endl;
		for (int r = 0; r < data->totalRows; r++)
		{
			for (int c = 0; c < data->totalColumns; c++)
			{
				out << data->data[r][c];
				if (c != data->totalColumns - 1)
					out << ',';
			}
			if (r != data->totalRows - 1)
				out << endl;
		}
	}
	else
	{
		perror(fileName.c_str());
	}
}

/**************************************************************
Programmer:		Chang See Jie
Name: 			correlationLinearMenu

Task:			Display a menu and prompt the user to input 
				selection for deciding to calculate 
				Pearson's Correlation or Linear Regression.
Data in:		To get the data from imported CSV file.
Data returned:	-
Referred to:	-
**************************************************************/
void correlationLinearMenu(Data *data)
{
	do
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "        Pearson's Correlation/Linear Regression         " << endl;
		cout << "========================================================" << endl;
		cout << "|| 1. Pearson's Correlation                           ||" << endl;
		cout << "|| 2. Linear Regression                               ||" << endl;
		cout << "|| 3. Back to Computation Data Menu                   ||" << endl;
		cout << "|| 4. Exit                                            ||" << endl;
		cout << "========================================================" << endl;
		cout << "Please input a selection between 1 - 4: ";
		string option;
		cin >> option;
		system("cls");
		if (option == "1")
		{
			int c1, c2;
			data->GetColumnTwo(c1, c2);
			if (c1 >= 0 && c2 >= 0)
			{
				data->Correlation(c1, c2);
			}
		}
		else if (option == "2")
		{
			int c1, c2;
			data->GetColumnTwo(c1, c2);
			if (c1 >= 0 && c2 >= 0)
			{
				data->LinearRegression(c1, c2);
			}
		}
		else if (option == "3")
		{
			break;
		}
		else if (option == "4")
		{
			exitProgram();
		}
		else
		{
			invalid();
		}
	} while (true);
}

/**************************************************************
Programmer:		Chang See Jie
Name: 			computeStatsMenu

Task:			Display the compute stats menu and prompt user 
				to input selection then call out next function 
				according to user’s input for calculation purpose.
Data in:		To get the data from imported CSV file.			
Data returned:	-
Referred to:	-
**************************************************************/
void computeStatsMenu(Data *data)
{
	do
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                     Compute Stats                      " << endl;
		cout << "========================================================" << endl;
		cout << "|| 1. Minimum                                         ||" << endl;
		cout << "|| 2. Maximum                                         ||" << endl;
		cout << "|| 3. Median                                          ||" << endl;
		cout << "|| 4. Mean                                            ||" << endl;
		cout << "|| 5. Variance                                        ||" << endl;
		cout << "|| 6. Standard Deviation                              ||" << endl;
		cout << "|| 7. All                                             ||" << endl;
		cout << "|| 8. Back to Computation Data Menu                   ||" << endl;
		cout << "|| 9. Exit                                            ||" << endl;
		cout << "========================================================" << endl;
		string option;
		cout << "Please input a selection between 1 - 9: ";
		cin >> option;
		system("cls");
		if (option == "1")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				cout << endl;
				cout << "========================================================" << endl;
				printf( "||                       %-29s||\n", data->columnNames[c].c_str());
				cout << "========================================================" << endl;
				cout << "|| Minimum                 ||" << setw(15) << data->Minimum(c) << "          ||" << endl;
				cout << "========================================================" << endl;
				cout << endl;
				clrScr();
			}
		}
		else if (option == "2")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				cout << endl;
				cout << "========================================================" << endl;
				printf( "||                       %-29s||\n", data->columnNames[c].c_str());
				cout << "========================================================" << endl;
				cout << "|| Maximum                 ||" << setw(15) << data->Maximum(c) << "          ||" << endl;
				cout << "========================================================" << endl;
				cout << endl;
				clrScr();
			}
		}
		else if (option == "3")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				cout << endl;
				cout << "========================================================" << endl;
				printf( "||                       %-29s||\n", data->columnNames[c].c_str());
				cout << "========================================================" << endl;
				cout << "|| Median                  ||" << setw(15) << data->Median(c) << "          ||" << endl;
				cout << "========================================================" << endl;
				cout << endl;
				clrScr();
			}
		}
		else if (option == "4")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				cout << endl;
				cout << "========================================================" << endl;
				printf( "||                       %-29s||\n", data->columnNames[c].c_str());
				cout << "========================================================" << endl;
				cout << "|| Mean                    ||" << setw(15) << data->Mean(c) << "          ||" << endl;
				cout << "========================================================" << endl;
				cout << endl;
				clrScr();
			}
		}
		else if (option == "5")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				cout << endl;
				cout << "========================================================" << endl;
				printf( "||                       %-29s||\n", data->columnNames[c].c_str());
				cout << "========================================================" << endl;
				cout << "|| Variance                ||" << setw(15) << data->Variance(c) << "          ||" << endl;
				cout << "========================================================" << endl;
				cout << endl;
				clrScr();
			}
		}
		else if (option == "6")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				cout << endl;
				cout << "========================================================" << endl;
				printf( "||                       %-29s||\n", data->columnNames[c].c_str());
				cout << "========================================================" << endl;
				cout << "|| Standard Deviation      ||" << setw(15) << data->StandardDeviation(c) << "          ||" << endl;
				cout << "========================================================" << endl;
				cout << endl;
				clrScr();
			}
		}
		else if (option == "7")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				data->printData(c);
			}
		}	
		else if (option == "8")
		{
			break;
		}
		else if (option == "9")
		{
			exitProgram();
		}
		else
		{
			invalid();
		}
	} while (true);
}

/**************************************************************
Programmer:		Chang See Jie
Name: 			computationData

Task:			Display the computation data menu and prompt user 
				to input selection then call out next function 
				according to user’s input.
Data in:		To get the data from imported CSV file.				
Data returned:	-
Referred to:	-
**************************************************************/
void computationData(Data *data)
{
	do
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                   Computation Data                     " << endl;
		cout << "========================================================" << endl;
		cout << "|| 1. Compute Stats                                   ||" << endl;
		cout << "|| 2. Frequency Distribution                          ||" << endl;
		cout << "|| 3. Histogram                                       ||" << endl;
		cout << "|| 4. Data Above and Below mean                       ||" << endl;
		cout << "|| 5. Pearson's Correlation/Linear Regression         ||" << endl;
		cout << "|| 6. Back to Main Menu                               ||" << endl;
		cout << "|| 7. Exit                                            ||" << endl;
		cout << "========================================================" << endl;
		string option;
		cout << "Please input a selection between 1 - 7: ";
		cin >> option;
		system("cls");
		if (option == "1")
		{
			computeStatsMenu(data);
		}
		else if (option == "2")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				data->Frequency(c);
			}
		}
		else if (option == "3")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				data->Histogram(c);
			}
		}
		else if (option == "4")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				data->AboveAndBelowMean(c);
			}
		}
		else if (option == "5")
		{
			correlationLinearMenu(data);
		}
		else if (option == "6")
		{
			break;
		}
		else if (option == "7")
		{
			exitProgram();
		}
		else
		{
			invalid();
		}
	} while (true);
}

/**************************************************************
Programmer:		Chang See Jie
Name: 			sortMenu

Task:			Display the sort data menu and prompt user to 
				input selection for deciding to sort the data
				in ascending order or descending order.
Data in:		To get the data from imported CSV file.				
Data returned:	-
Referred to:	-
**************************************************************/
void sortMenu(Data *data)
{
	do
	{
		cout << endl;	
		cout << "========================================================" << endl;
		cout << "                       Sort Data                        " << endl;
		cout << "========================================================" << endl;
		cout << "|| 1. Ascending Order                                 ||" << endl;
		cout << "|| 2. Desending Order                                 ||" << endl;
		cout << "|| 3. Back to Main Menu                               ||" << endl;
		cout << "|| 4. Exit                                            ||" << endl;
		cout << "========================================================" << endl;
		cout << "Please input a selection between 1 - 4: ";
		string option;
		cin >> option;
		system("cls");
		if (option == "1")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				data->sort(c);
				data->print();
			}
		}
		else if (option == "2")
		{
			int c = data->GetColumn();
			if (c >= 0)
			{
				data->sort(c, true);
				data->print();
			}
		}
		else if (option == "3")
		{
			break;
		}
		else if (option == "4")
		{
			exitProgram();
		}
		else
		{
			cout << "Invalid input." << endl;
		}
	} while (true);
}

/**************************************************************
Programmer:		Loo Chen Zhi
Name: 			generateReportMenu(Data *data)

Task:			Function that generate report interface and 
Data in:		user input for html and txt file
Data returned:	TEXT and WriteHTML fucntions
Referred to:	-
**************************************************************/
void generateReportMenu(Data *data)
{
	do
	{	
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                   Generate Report                      " << endl;
		cout << "========================================================" << endl;
		cout << "|| 1. TEXT                                            ||" << endl;
		cout << "|| 2. HTML                                            ||" << endl;
		cout << "========================================================" << endl;
		cout << "Enter input a selection: ";
		string option;
		cin >> option;
		if (option == "1")
		{
			string textFile;
			cout << "Please input txt output file name: ";
			cin >> textFile;
			textFile += ".txt";
			data->TEXT(textFile);
			clrScr();
		}
		else if (option == "2")
		{
			string htmlFIle;
			cout << "Please input html output file name: ";
			cin >> htmlFIle;
			htmlFIle += ".html";
			data->WriteHTML(htmlFIle);
			clrScr();
		}
		else
		{
			invalid();
		}
	} while (true);
	
}

/**************************************************************
Programmer:		Chang See Jie
Name: 			mainMenu

Task:			Display the main menu and prompt user to input 
				selection then call out next function according 
				to user’s input.
Data in:		-				
Data returned:	-
Referred to:	-
**************************************************************/
void mainMenu()
{
	Data *data = nullptr;
	do
	{
		data = readFile();
		if(data == nullptr)
		{
			cout << "Error: Unable to read file." << endl;
		}
	} while (data == nullptr);
	do
	{
		cout << endl;
		cout << "========================================================" << endl;
		cout << "                        Main Menu                       " << endl;
		cout << "========================================================" << endl;
		cout << "|| 1. Display Data                                    ||" << endl;
		cout << "|| 2. Compute Data                                    ||" << endl;
		cout << "|| 3. Sort Data by column                             ||" << endl;
		cout << "|| 4. Generate Report                                 ||" << endl;
		cout << "|| 5. Exit                                            ||" << endl;
		cout << "========================================================" << endl;
		string option;
		cout << "Please input a selection between 1 - 5: ";
		cin >> option;
		cout << "\033[2J\033[0;0H";
		if (option == "1")
		{
			data->print();
		}
		else if (option == "2")
		{
			computationData(data);
		}
		else if (option == "3")
		{
			sortMenu(data);
		}
		else if (option == "4")
		{
			generateReportMenu(data);
		}
		else if (option == "5")
		{
			exitProgram();
		}
		else
		{
			invalid();
		}
	} while (true);
}

/**************************************************************
Programmer:		Lim Wei Jie
Name: 			main

Task:			Debug and identify whole program error and flow
Data in:		All functions
Data returned:	All functions
Referred to:	-
**************************************************************/
int main()
{
	cout << "========================================================" << endl;
	cout << "***         Welcome to Acedemic Report System        ***" << endl;
	cout << "--------------------------------------------------------" << endl;
	mainMenu();
	string option;
	return 0;
}