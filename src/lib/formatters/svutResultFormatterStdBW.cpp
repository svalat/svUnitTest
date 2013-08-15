/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterStdBW.h"
#include <iomanip>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Constructor of the class.
 * @param out Define the output stream to use.
**/
svutResultFormatterStdBW::svutResultFormatterStdBW(std::ostream& out)
	: svutResultFormatterStd(out)
{
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStdBW::printMethodAndStatus(std::ostream& out, std::string name, svutStatus status)
{
	//sprintf(buffer," * %-40s     [ %s ]\n",testName.c_str(),statusName.c_str());

	out << " * " << setw(40) << left << name
		<< "     [ " << svutStatusInfo::getStatusName(status) << " ]" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStdBW::printSummaryStat(std::ostream& out, svutStatus status, unsigned int nb, unsigned int tot)
{
	 //sprintf(buffer,"|  %-9s: %4d (%3d %%)  |\n",name,nb,100*nb/tot);
	 unsigned int perc;

	 //calc percentage
	 if (tot == 0)
		 perc = 0;
	 else
		 perc = (100*nb)/tot;

	 //display
	 out << "|  " << setw(9) << left << svutStatusInfo::getStatusName(status) << ": "
		<< setw(4) << right << nb << " (" << setw(3) << right << perc << " %)  |" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStdBW::printSummaryFinalStatus(std::ostream& out, svutStatus status)
{
	//sprintf(buffer,"|  STATUS   : %-12s  |\n",name);
	out << "|  STATUS   : " << setw(12) << left << svutStatusInfo::getStatusName(status) << "  |" << endl;
}

}
